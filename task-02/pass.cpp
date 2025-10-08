#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/Constant.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/Type.h"
#include "llvm/Passes/OptimizationLevel.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

using namespace llvm;

StringRef LoggerName{"printInstr"};

FunctionType *getLoggerType(LLVMContext &Ctx)
{
  Type *RetType = Type::getVoidTy(Ctx);
  PointerType *ArgType = Type::getInt8Ty(Ctx)->getPointerTo();
  return FunctionType::get(RetType, ArrayRef<Type *>{ArgType},
                           false);
}

struct InstrLogger final : public PassInfoMixin<InstrLogger>
{
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &FAM) {
    LLVMContext &Ctx = M.getContext();
    FunctionType *LoggerType = getLoggerType(Ctx);
    FunctionCallee FCallee = M.getOrInsertFunction(LoggerName, LoggerType);
    IRBuilder<> Builder(Ctx);

    auto NotLogger = [](const Function &F) {
      return F.getName() != LoggerName;
    };

    auto NotPHI = [](const Instruction &I) {
      return dyn_cast<PHINode>(&I) == nullptr;
    };

    for (auto &F : make_filter_range(M, NotLogger)) {
      for (auto &BB : F) {
        for (auto &I : make_filter_range(BB, NotPHI)) {
          Builder.SetInsertPoint(&I);
          Constant *OpcodeName =
              Builder.CreateGlobalStringPtr(I.getOpcodeName());
          Builder.CreateCall(FCallee, ArrayRef<Value *>{OpcodeName});
        }
      }
    }

    return PreservedAnalyses::none();
  }

  static bool isRequired() { return true; }
};

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  auto callback = [](PassBuilder &PB) {
    PB.registerOptimizerLastEPCallback(
        [](ModulePassManager &MPM, [[maybe_unused]] OptimizationLevel) {
          MPM.addPass(InstrLogger{});
          return true;
        });
  };

  return {LLVM_PLUGIN_API_VERSION, "My instruction logger", "2.2.8", callback};
}
