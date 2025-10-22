#include "../task-01/sim.h"

#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

int main() {
  LLVMContext context;
  
  // ; ModuleID = 'app.c'
  // source_filename = "app.c"
  Module *module = new Module("app.c", context);
  IRBuilder<> builder(context);
  
  // Basic types
  Type *voidType = Type::getVoidTy(context);
  Type *int32Type = Type::getInt32Ty(context);
  Type *int64Type = Type::getInt64Ty(context);
  Type *int1Type = Type::getInt1Ty(context);
  Type *ptrType = PointerType::get(context, 0);
  
  // ========== DECLARE EXTERNAL FUNCTIONS ==========
  
  // declare i32 @sim_sqrt(i32 noundef) local_unnamed_addr #1
  ArrayRef<Type*> simSqrtParamTypes = {int32Type};
  FunctionType *simSqrtType = FunctionType::get(int32Type, simSqrtParamTypes, false);
  FunctionCallee simSqrtFunc = module->getOrInsertFunction("sim_sqrt", simSqrtType);
  
  // declare void @sim_put_pixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #1
  ArrayRef<Type*> simPutPixelParamTypes = {int32Type, int32Type, int32Type};
  FunctionType *simPutPixelType = FunctionType::get(voidType, simPutPixelParamTypes, false);
  FunctionCallee simPutPixelFunc = module->getOrInsertFunction("sim_put_pixel", simPutPixelType);
  
  // declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #2
  Function *lifetimeStartFunc = Intrinsic::getDeclaration(module, Intrinsic::lifetime_start, {ptrType});
  
  // declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #2
  Function *lifetimeEndFunc = Intrinsic::getDeclaration(module, Intrinsic::lifetime_end, {ptrType});
  
  // declare i32 @get_sin_precise(i32 noundef) local_unnamed_addr #1
  ArrayRef<Type*> getSinPreciseParamTypes = {int32Type};
  FunctionType *getSinPreciseType = FunctionType::get(int32Type, getSinPreciseParamTypes, false);
  FunctionCallee getSinPreciseFunc = module->getOrInsertFunction("get_sin_precise", getSinPreciseType);
  
  // declare i32 @get_cos_precise(i32 noundef) local_unnamed_addr #1
  ArrayRef<Type*> getCosPreciseParamTypes = {int32Type};
  FunctionType *getCosPreciseType = FunctionType::get(int32Type, getCosPreciseParamTypes, false);
  FunctionCallee getCosPreciseFunc = module->getOrInsertFunction("get_cos_precise", getCosPreciseType);
  
  // declare void @sim_draw_line(i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #1
  ArrayRef<Type*> simDrawLineParamTypes = {int32Type, int32Type, int32Type, int32Type, int32Type};
  FunctionType *simDrawLineType = FunctionType::get(voidType, simDrawLineParamTypes, false);
  FunctionCallee simDrawLineFunc = module->getOrInsertFunction("sim_draw_line", simDrawLineType);
  
  // declare i32 @sim_should_quit() local_unnamed_addr #1
  FunctionType *simShouldQuitType = FunctionType::get(int32Type, false);
  FunctionCallee simShouldQuitFunc = module->getOrInsertFunction("sim_should_quit", simShouldQuitType);
  
  // declare void @sim_flush() local_unnamed_addr #1
  FunctionType *simFlushType = FunctionType::get(voidType, false);
  FunctionCallee simFlushFunc = module->getOrInsertFunction("sim_flush", simFlushType);
  
  // declare i32 @llvm.smax.i32(i32, i32) #3
  Function *smaxFunc = Intrinsic::getDeclaration(module, Intrinsic::smax, {int32Type});
  
  // declare i32 @llvm.abs.i32(i32, i1 immarg) #3
  Function *absFunc = Intrinsic::getDeclaration(module, Intrinsic::abs, {int32Type});
  
  
  // ========== DEFINE FUNCTION: calculate_ray_length ==========
  // define dso_local i32 @calculate_ray_length() local_unnamed_addr #0
  FunctionType *calculateRayLengthType = FunctionType::get(int32Type, false);
  Function *calculateRayLengthFunc = Function::Create(
    calculateRayLengthType, Function::ExternalLinkage, "calculate_ray_length", module);
  
  BasicBlock *calcRayBB = BasicBlock::Create(context, "", calculateRayLengthFunc);
  builder.SetInsertPoint(calcRayBB);
  // %1 = tail call i32 @sim_sqrt(i32 noundef 640000) #4
  Value *calcRayVal1 = builder.CreateCall(simSqrtFunc, {builder.getInt32(640000)});
  // ret i32 %1
  builder.CreateRet(calcRayVal1);
  
  
  // ========== DEFINE FUNCTION: draw_circle ==========
  // define dso_local void @draw_circle(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3) local_unnamed_addr #0
  ArrayRef<Type*> drawCircleParamTypes = {int32Type, int32Type, int32Type, int32Type};
  FunctionType *drawCircleType = FunctionType::get(voidType, drawCircleParamTypes, false);
  Function *drawCircleFunc = Function::Create(
    drawCircleType, Function::ExternalLinkage, "draw_circle", module);
  
  // Get function arguments
  auto drawCircleArgs = drawCircleFunc->arg_begin();
  Value *dcArg0 = &*drawCircleArgs++;
  Value *dcArg1 = &*drawCircleArgs++;
  Value *dcArg2 = &*drawCircleArgs++;
  Value *dcArg3 = &*drawCircleArgs++;
  
  // BasicBlocks
  BasicBlock *dcBB4 = BasicBlock::Create(context, "", drawCircleFunc);
  BasicBlock *dcBB6 = BasicBlock::Create(context, "", drawCircleFunc);
  BasicBlock *dcBB10 = BasicBlock::Create(context, "", drawCircleFunc);
  BasicBlock *dcBB15 = BasicBlock::Create(context, "", drawCircleFunc);
  BasicBlock *dcBB16 = BasicBlock::Create(context, "", drawCircleFunc);
  BasicBlock *dcBB19 = BasicBlock::Create(context, "", drawCircleFunc);
  BasicBlock *dcBB25 = BasicBlock::Create(context, "", drawCircleFunc);
  BasicBlock *dcBB27 = BasicBlock::Create(context, "", drawCircleFunc);
  
  // 4:
  builder.SetInsertPoint(dcBB4);
  // %5 = icmp sgt i32 %2, 0
  Value *dcVal5 = builder.CreateICmpSGT(dcArg2, builder.getInt32(0));
  // br i1 %5, label %6, label %15
  builder.CreateCondBr(dcVal5, dcBB6, dcBB15);
  
  // 6:
  builder.SetInsertPoint(dcBB6);
  // %7 = shl nuw i32 %2, 1
  Value *dcVal7 = builder.CreateShl(dcArg2, builder.getInt32(1), "", true, false);
  // %8 = mul nuw nsw i32 %2, %2
  Value *dcVal8 = builder.CreateMul(dcArg2, dcArg2, "", true, true);
  // %9 = tail call i32 @llvm.smax.i32(i32 %7, i32 1)
  Value *dcVal9 = builder.CreateCall(smaxFunc, {dcVal7, builder.getInt32(1)});
  // br label %10
  builder.CreateBr(dcBB10);
  
  // 10:
  builder.SetInsertPoint(dcBB10);
  // %11 = phi i32 [ 0, %6 ], [ %17, %16 ]
  PHINode *dcVal11 = builder.CreatePHI(int32Type, 2);
  // %12 = sub nsw i32 %2, %11
  Value *dcVal12 = builder.CreateNSWSub(dcArg2, dcVal11);
  // %13 = mul nsw i32 %12, %12
  Value *dcVal13 = builder.CreateNSWMul(dcVal12, dcVal12);
  // %14 = add nsw i32 %12, %0
  Value *dcVal14 = builder.CreateNSWAdd(dcVal12, dcArg0);
  // br label %19
  builder.CreateBr(dcBB19);
  
  // 15:
  builder.SetInsertPoint(dcBB15);
  // ret void
  builder.CreateRetVoid();
  
  // 16:
  builder.SetInsertPoint(dcBB16);
  // %17 = add nuw nsw i32 %11, 1
  Value *dcVal17 = builder.CreateAdd(dcVal11, builder.getInt32(1), "", true, true);
  // %18 = icmp eq i32 %17, %9
  Value *dcVal18 = builder.CreateICmpEQ(dcVal17, dcVal9);
  // br i1 %18, label %15, label %10
  builder.CreateCondBr(dcVal18, dcBB15, dcBB10);
  
  // 19:
  builder.SetInsertPoint(dcBB19);
  // %20 = phi i32 [ 0, %10 ], [ %28, %27 ]
  PHINode *dcVal20 = builder.CreatePHI(int32Type, 2);
  // %21 = sub nsw i32 %2, %20
  Value *dcVal21 = builder.CreateNSWSub(dcArg2, dcVal20);
  // %22 = mul nsw i32 %21, %21
  Value *dcVal22 = builder.CreateNSWMul(dcVal21, dcVal21);
  // %23 = add nuw nsw i32 %22, %13
  Value *dcVal23 = builder.CreateAdd(dcVal22, dcVal13, "", true, true);
  // %24 = icmp ugt i32 %23, %8
  Value *dcVal24 = builder.CreateICmpUGT(dcVal23, dcVal8);
  // br i1 %24, label %27, label %25
  builder.CreateCondBr(dcVal24, dcBB27, dcBB25);
  
  // 25:
  builder.SetInsertPoint(dcBB25);
  // %26 = add nsw i32 %21, %1
  Value *dcVal26 = builder.CreateNSWAdd(dcVal21, dcArg1);
  // tail call void @sim_put_pixel(i32 noundef %14, i32 noundef %26, i32 noundef %3) #4
  builder.CreateCall(simPutPixelFunc, {dcVal14, dcVal26, dcArg3});
  // br label %27
  builder.CreateBr(dcBB27);
  
  // 27:
  builder.SetInsertPoint(dcBB27);
  // %28 = add nuw nsw i32 %20, 1
  Value *dcVal28 = builder.CreateAdd(dcVal20, builder.getInt32(1), "", true, true);
  // %29 = icmp eq i32 %28, %9
  Value *dcVal29 = builder.CreateICmpEQ(dcVal28, dcVal9);
  // br i1 %29, label %16, label %19
  builder.CreateCondBr(dcVal29, dcBB16, dcBB19);
  
  // Link PHI nodes for draw_circle
  dcVal11->addIncoming(builder.getInt32(0), dcBB6);
  dcVal11->addIncoming(dcVal17, dcBB16);
  dcVal20->addIncoming(builder.getInt32(0), dcBB10);
  dcVal20->addIncoming(dcVal28, dcBB27);
  
  
  // ========== DEFINE FUNCTION: has_interception ==========
  // define dso_local range(i32 0, 2) i32 @has_interception(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6) local_unnamed_addr #0
  ArrayRef<Type*> hasInterceptionParamTypes = {int32Type, int32Type, int32Type, int32Type, int32Type, int32Type, int32Type};
  FunctionType *hasInterceptionType = FunctionType::get(int32Type, hasInterceptionParamTypes, false);
  Function *hasInterceptionFunc = Function::Create(
    hasInterceptionType, Function::ExternalLinkage, "has_interception", module);
  
  // Get function arguments
  auto hasIntArgs = hasInterceptionFunc->arg_begin();
  Value *hiArg0 = &*hasIntArgs++;
  Value *hiArg1 = &*hasIntArgs++;
  Value *hiArg2 = &*hasIntArgs++;
  Value *hiArg3 = &*hasIntArgs++;
  Value *hiArg4 = &*hasIntArgs++;
  Value *hiArg5 = &*hasIntArgs++;
  Value *hiArg6 = &*hasIntArgs++;
  
  // BasicBlocks
  BasicBlock *hiBB7 = BasicBlock::Create(context, "", hasInterceptionFunc);
  BasicBlock *hiBB24 = BasicBlock::Create(context, "", hasInterceptionFunc);
  BasicBlock *hiBB29 = BasicBlock::Create(context, "", hasInterceptionFunc);
  BasicBlock *hiBB35 = BasicBlock::Create(context, "", hasInterceptionFunc);
  
  // 7:
  builder.SetInsertPoint(hiBB7);
  // %8 = sub nsw i32 %3, %1
  Value *hiVal8 = builder.CreateNSWSub(hiArg3, hiArg1);
  // %9 = mul nsw i32 %8, %4
  Value *hiVal9 = builder.CreateNSWMul(hiVal8, hiArg4);
  // %10 = sub nsw i32 %2, %0
  Value *hiVal10 = builder.CreateNSWSub(hiArg2, hiArg0);
  // %11 = mul nsw i32 %2, %1
  Value *hiVal11 = builder.CreateNSWMul(hiArg2, hiArg1);
  // %12 = mul i32 %3, %0
  Value *hiVal12 = builder.CreateMul(hiArg3, hiArg0);
  // %13 = mul i32 %10, %5
  Value *hiVal13 = builder.CreateMul(hiVal10, hiArg5);
  // %14 = add i32 %13, %12
  Value *hiVal14 = builder.CreateAdd(hiVal13, hiVal12);
  // %15 = add i32 %9, %11
  Value *hiVal15 = builder.CreateAdd(hiVal9, hiVal11);
  // %16 = sub i32 %15, %14
  Value *hiVal16 = builder.CreateSub(hiVal15, hiVal14);
  // %17 = tail call i32 @llvm.abs.i32(i32 %16, i1 true)
  Value *hiVal17 = builder.CreateCall(absFunc, {hiVal16, builder.getInt1(true)});
  // %18 = mul nsw i32 %8, %8
  Value *hiVal18 = builder.CreateNSWMul(hiVal8, hiVal8);
  // %19 = mul nsw i32 %10, %10
  Value *hiVal19 = builder.CreateNSWMul(hiVal10, hiVal10);
  // %20 = add nuw nsw i32 %18, %19
  Value *hiVal20 = builder.CreateAdd(hiVal18, hiVal19, "", true, true);
  // %21 = tail call i32 @sim_sqrt(i32 noundef %20) #4
  Value *hiVal21 = builder.CreateCall(simSqrtFunc, {hiVal20});
  // %22 = sdiv i32 %17, %21
  Value *hiVal22 = builder.CreateSDiv(hiVal17, hiVal21);
  // %23 = icmp sgt i32 %22, %6
  Value *hiVal23 = builder.CreateICmpSGT(hiVal22, hiArg6);
  // br i1 %23, label %35, label %24
  builder.CreateCondBr(hiVal23, hiBB35, hiBB24);
  
  // 24:
  builder.SetInsertPoint(hiBB24);
  // %25 = sub nsw i32 %0, %4
  Value *hiVal25 = builder.CreateNSWSub(hiArg0, hiArg4);
  // %26 = sub nsw i32 %0, %2
  Value *hiVal26 = builder.CreateNSWSub(hiArg0, hiArg2);
  // %27 = mul nsw i32 %25, %26
  Value *hiVal27 = builder.CreateNSWMul(hiVal25, hiVal26);
  // %28 = icmp sgt i32 %27, 0
  Value *hiVal28 = builder.CreateICmpSGT(hiVal27, builder.getInt32(0));
  // br i1 %28, label %35, label %29
  builder.CreateCondBr(hiVal28, hiBB35, hiBB29);
  
  // 29:
  builder.SetInsertPoint(hiBB29);
  // %30 = sub nsw i32 %1, %5
  Value *hiVal30 = builder.CreateNSWSub(hiArg1, hiArg5);
  // %31 = sub nsw i32 %1, %3
  Value *hiVal31 = builder.CreateNSWSub(hiArg1, hiArg3);
  // %32 = mul nsw i32 %30, %31
  Value *hiVal32 = builder.CreateNSWMul(hiVal30, hiVal31);
  // %33 = icmp sgt i32 %32, 0
  Value *hiVal33 = builder.CreateICmpSGT(hiVal32, builder.getInt32(0));
  // %34 = zext i1 %33 to i32
  Value *hiVal34 = builder.CreateZExt(hiVal33, int32Type);
  // br label %35
  builder.CreateBr(hiBB35);
  
  // 35:
  builder.SetInsertPoint(hiBB35);
  // %36 = phi i32 [ 0, %7 ], [ 1, %24 ], [ %34, %29 ]
  PHINode *hiVal36 = builder.CreatePHI(int32Type, 3);
  hiVal36->addIncoming(builder.getInt32(0), hiBB7);
  hiVal36->addIncoming(builder.getInt32(1), hiBB24);
  hiVal36->addIncoming(hiVal34, hiBB29);
  // ret i32 %36
  builder.CreateRet(hiVal36);
  
  
  // ========== DEFINE FUNCTION: calc_interception ==========
  // define dso_local void @calc_interception(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, ptr nocapture noundef writeonly %7, ptr nocapture noundef writeonly %8) local_unnamed_addr #0
  ArrayRef<Type*> calcInterceptionParamTypes = {int32Type, int32Type, int32Type, int32Type, int32Type, int32Type, int32Type, ptrType, ptrType};
  FunctionType *calcInterceptionType = FunctionType::get(voidType, calcInterceptionParamTypes, false);
  Function *calcInterceptionFunc = Function::Create(
    calcInterceptionType, Function::ExternalLinkage, "calc_interception", module);
  
  // Get function arguments
  auto calcIntArgs = calcInterceptionFunc->arg_begin();
  Value *ciArg0 = &*calcIntArgs++;
  Value *ciArg1 = &*calcIntArgs++;
  Value *ciArg2 = &*calcIntArgs++;
  Value *ciArg3 = &*calcIntArgs++;
  Value *ciArg4 = &*calcIntArgs++;
  Value *ciArg5 = &*calcIntArgs++;
  Value *ciArg6 = &*calcIntArgs++;
  Value *ciArg7 = &*calcIntArgs++;
  Value *ciArg8 = &*calcIntArgs++;
  
  // BasicBlocks
  BasicBlock *ciBB9 = BasicBlock::Create(context, "", calcInterceptionFunc);
  BasicBlock *ciBB24 = BasicBlock::Create(context, "", calcInterceptionFunc);
  BasicBlock *ciBB28 = BasicBlock::Create(context, "", calcInterceptionFunc);
  BasicBlock *ciBB48 = BasicBlock::Create(context, "", calcInterceptionFunc);
  
  // 9:
  builder.SetInsertPoint(ciBB9);
  // %10 = sub nsw i32 %4, %0
  Value *ciVal10 = builder.CreateNSWSub(ciArg4, ciArg0);
  // %11 = mul nsw i32 %10, %10
  Value *ciVal11 = builder.CreateNSWMul(ciVal10, ciVal10);
  // %12 = sub nsw i32 %5, %1
  Value *ciVal12 = builder.CreateNSWSub(ciArg5, ciArg1);
  // %13 = mul nsw i32 %12, %12
  Value *ciVal13 = builder.CreateNSWMul(ciVal12, ciVal12);
  // %14 = add nuw nsw i32 %13, %11
  Value *ciVal14 = builder.CreateAdd(ciVal13, ciVal11, "", true, true);
  // %15 = tail call i32 @sim_sqrt(i32 noundef %14) #4
  Value *ciVal15 = builder.CreateCall(simSqrtFunc, {ciVal14});
  // %16 = sub nsw i32 %15, %6
  Value *ciVal16 = builder.CreateNSWSub(ciVal15, ciArg6);
  // %17 = sub nsw i32 %2, %0
  Value *ciVal17 = builder.CreateNSWSub(ciArg2, ciArg0);
  // %18 = sub nsw i32 %3, %1
  Value *ciVal18 = builder.CreateNSWSub(ciArg3, ciArg1);
  // %19 = mul nsw i32 %17, %17
  Value *ciVal19 = builder.CreateNSWMul(ciVal17, ciVal17);
  // %20 = mul nsw i32 %18, %18
  Value *ciVal20 = builder.CreateNSWMul(ciVal18, ciVal18);
  // %21 = add nuw nsw i32 %20, %19
  Value *ciVal21 = builder.CreateAdd(ciVal20, ciVal19, "", true, true);
  // %22 = tail call i32 @sim_sqrt(i32 noundef %21) #4
  Value *ciVal22 = builder.CreateCall(simSqrtFunc, {ciVal21});
  // %23 = icmp slt i32 %6, 0
  Value *ciVal23 = builder.CreateICmpSLT(ciArg6, builder.getInt32(0));
  // br i1 %23, label %48, label %24
  builder.CreateCondBr(ciVal23, ciBB48, ciBB24);
  
  // 24:
  builder.SetInsertPoint(ciBB24);
  // %25 = sub i32 %0, %4
  Value *ciVal25 = builder.CreateSub(ciArg0, ciArg4);
  // %26 = sub i32 %1, %5
  Value *ciVal26 = builder.CreateSub(ciArg1, ciArg5);
  // %27 = mul nuw nsw i32 %6, %6
  Value *ciVal27 = builder.CreateMul(ciArg6, ciArg6, "", true, true);
  // br label %28
  builder.CreateBr(ciBB28);
  
  // 28:
  builder.SetInsertPoint(ciBB28);
  // %29 = phi i32 [ %16, %24 ], [ %46, %28 ]
  PHINode *ciVal29 = builder.CreatePHI(int32Type, 2);
  // %30 = phi i32 [ %15, %24 ], [ %45, %28 ]
  PHINode *ciVal30 = builder.CreatePHI(int32Type, 2);
  // %31 = add nsw i32 %29, %30
  Value *ciVal31 = builder.CreateNSWAdd(ciVal29, ciVal30);
  // %32 = sdiv i32 %31, 2
  Value *ciVal32 = builder.CreateSDiv(ciVal31, builder.getInt32(2));
  // %33 = mul nsw i32 %32, %17
  Value *ciVal33 = builder.CreateNSWMul(ciVal32, ciVal17);
  // %34 = sdiv i32 %33, %22
  Value *ciVal34 = builder.CreateSDiv(ciVal33, ciVal22);
  // %35 = mul nsw i32 %32, %18
  Value *ciVal35 = builder.CreateNSWMul(ciVal32, ciVal18);
  // %36 = sdiv i32 %35, %22
  Value *ciVal36 = builder.CreateSDiv(ciVal35, ciVal22);
  // %37 = add i32 %25, %34
  Value *ciVal37 = builder.CreateAdd(ciVal25, ciVal34);
  // %38 = mul nsw i32 %37, %37
  Value *ciVal38 = builder.CreateNSWMul(ciVal37, ciVal37);
  // %39 = add i32 %26, %36
  Value *ciVal39 = builder.CreateAdd(ciVal26, ciVal36);
  // %40 = mul nsw i32 %39, %39
  Value *ciVal40 = builder.CreateNSWMul(ciVal39, ciVal39);
  // %41 = add nuw nsw i32 %40, %38
  Value *ciVal41 = builder.CreateAdd(ciVal40, ciVal38, "", true, true);
  // %42 = icmp ugt i32 %41, %27
  Value *ciVal42 = builder.CreateICmpUGT(ciVal41, ciVal27);
  // %43 = add nsw i32 %32, -1
  Value *ciVal43 = builder.CreateNSWAdd(ciVal32, builder.getInt32(-1));
  // %44 = add nsw i32 %32, 1
  Value *ciVal44 = builder.CreateNSWAdd(ciVal32, builder.getInt32(1));
  // %45 = select i1 %42, i32 %30, i32 %43
  Value *ciVal45 = builder.CreateSelect(ciVal42, ciVal30, ciVal43);
  // %46 = select i1 %42, i32 %44, i32 %29
  Value *ciVal46 = builder.CreateSelect(ciVal42, ciVal44, ciVal29);
  // %47 = icmp sgt i32 %46, %45
  Value *ciVal47 = builder.CreateICmpSGT(ciVal46, ciVal45);
  // br i1 %47, label %48, label %28
  builder.CreateCondBr(ciVal47, ciBB48, ciBB28);
  
  // 48:
  builder.SetInsertPoint(ciBB48);
  // %49 = phi i32 [ %16, %9 ], [ %46, %28 ]
  PHINode *ciVal49 = builder.CreatePHI(int32Type, 2);
  // %50 = mul nsw i32 %49, %17
  Value *ciVal50 = builder.CreateNSWMul(ciVal49, ciVal17);
  // %51 = sdiv i32 %50, %22
  Value *ciVal51 = builder.CreateSDiv(ciVal50, ciVal22);
  // %52 = add nsw i32 %51, %0
  Value *ciVal52 = builder.CreateNSWAdd(ciVal51, ciArg0);
  // store i32 %52, ptr %7, align 4
  builder.CreateStore(ciVal52, ciArg7);
  // %53 = mul nsw i32 %49, %18
  Value *ciVal53 = builder.CreateNSWMul(ciVal49, ciVal18);
  // %54 = sdiv i32 %53, %22
  Value *ciVal54 = builder.CreateSDiv(ciVal53, ciVal22);
  // %55 = add nsw i32 %54, %1
  Value *ciVal55 = builder.CreateNSWAdd(ciVal54, ciArg1);
  // store i32 %55, ptr %8, align 4
  builder.CreateStore(ciVal55, ciArg8);
  // ret void
  builder.CreateRetVoid();
  
  // Link PHI nodes for calc_interception
  ciVal29->addIncoming(ciVal16, ciBB24);
  ciVal29->addIncoming(ciVal46, ciBB28);
  ciVal30->addIncoming(ciVal15, ciBB24);
  ciVal30->addIncoming(ciVal45, ciBB28);
  ciVal49->addIncoming(ciVal16, ciBB9);
  ciVal49->addIncoming(ciVal46, ciBB28);
  
  
  // ========== DEFINE FUNCTION: draw_rays ==========
  // define dso_local void @draw_rays(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5) local_unnamed_addr #0
  ArrayRef<Type*> drawRaysParamTypes = {int32Type, int32Type, int32Type, int32Type, int32Type, int32Type};
  FunctionType *drawRaysType = FunctionType::get(voidType, drawRaysParamTypes, false);
  Function *drawRaysFunc = Function::Create(
    drawRaysType, Function::ExternalLinkage, "draw_rays", module);
  
  // Get function arguments
  auto drawRaysArgs = drawRaysFunc->arg_begin();
  Value *drArg0 = &*drawRaysArgs++;
  Value *drArg1 = &*drawRaysArgs++;
  Value *drArg2 = &*drawRaysArgs++;
  Value *drArg3 = &*drawRaysArgs++;
  Value *drArg4 = &*drawRaysArgs++;
  Value *drArg5 = &*drawRaysArgs++;
  
  // BasicBlocks
  BasicBlock *drBB6 = BasicBlock::Create(context, "", drawRaysFunc);
  BasicBlock *drBB11 = BasicBlock::Create(context, "", drawRaysFunc);
  BasicBlock *drBB12 = BasicBlock::Create(context, "", drawRaysFunc);
  BasicBlock *drBB25 = BasicBlock::Create(context, "", drawRaysFunc);
  BasicBlock *drBB26 = BasicBlock::Create(context, "", drawRaysFunc);
  BasicBlock *drBB29 = BasicBlock::Create(context, "", drawRaysFunc);
  
  // Allocas for local variables (i32* %7 and %8)
  builder.SetInsertPoint(drBB6);
  AllocaInst *drAlloca7 = builder.CreateAlloca(int32Type, nullptr);
  AllocaInst *drAlloca8 = builder.CreateAlloca(int32Type, nullptr);
  
  // 6:
  // %9 = sdiv i32 1440, %3
  Value *drVal9 = builder.CreateSDiv(builder.getInt32(1440), drArg3);
  // %10 = icmp sgt i32 %3, 0
  Value *drVal10 = builder.CreateICmpSGT(drArg3, builder.getInt32(0));
  // br i1 %10, label %12, label %11
  builder.CreateCondBr(drVal10, drBB12, drBB11);
  
  // 11:
  builder.SetInsertPoint(drBB11);
  // ret void
  builder.CreateRetVoid();
  
  // 12:
  builder.SetInsertPoint(drBB12);
  // %13 = phi i32 [ %30, %29 ], [ 0, %6 ]
  PHINode *drVal13 = builder.CreatePHI(int32Type, 2);
  // %14 = mul nuw nsw i32 %13, %9
  Value *drVal14 = builder.CreateMul(drVal13, drVal9, "", true, true);
  // %15 = tail call i32 @get_sin_precise(i32 noundef %14) #4
  Value *drVal15 = builder.CreateCall(getSinPreciseFunc, {drVal14});
  // %16 = tail call i32 @get_cos_precise(i32 noundef %14) #4
  Value *drVal16 = builder.CreateCall(getCosPreciseFunc, {drVal14});
  // %17 = mul nsw i32 %16, %4
  Value *drVal17 = builder.CreateNSWMul(drVal16, drArg4);
  // %18 = sdiv i32 %17, 65535
  Value *drVal18 = builder.CreateSDiv(drVal17, builder.getInt32(65535));
  // %19 = add nsw i32 %18, %0
  Value *drVal19 = builder.CreateNSWAdd(drVal18, drArg0);
  // %20 = mul nsw i32 %15, %4
  Value *drVal20 = builder.CreateNSWMul(drVal15, drArg4);
  // %21 = sdiv i32 %20, 65535
  Value *drVal21 = builder.CreateSDiv(drVal20, builder.getInt32(65535));
  // %22 = add nsw i32 %21, %1
  Value *drVal22 = builder.CreateNSWAdd(drVal21, drArg1);
  // %23 = tail call i32 @has_interception(i32 noundef %0, i32 noundef %1, i32 noundef %19, i32 noundef %22, i32 noundef 320, i32 noundef 240, i32 noundef %2) #5
  Value *drVal23 = builder.CreateCall(hasInterceptionFunc, {drArg0, drArg1, drVal19, drVal22, builder.getInt32(320), builder.getInt32(240), drArg2});
  // %24 = icmp eq i32 %23, 0
  Value *drVal24 = builder.CreateICmpEQ(drVal23, builder.getInt32(0));
  // br i1 %24, label %25, label %26
  builder.CreateCondBr(drVal24, drBB25, drBB26);
  
  // 25:
  builder.SetInsertPoint(drBB25);
  // tail call void @sim_draw_line(i32 noundef %0, i32 noundef %1, i32 noundef %19, i32 noundef %22, i32 noundef %5) #4
  builder.CreateCall(simDrawLineFunc, {drArg0, drArg1, drVal19, drVal22, drArg5});
  // br label %29
  builder.CreateBr(drBB29);
  
  // 26:
  builder.SetInsertPoint(drBB26);
  // call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %7) #6
  builder.CreateCall(lifetimeStartFunc, {builder.getInt64(4), drAlloca7});
  // store i32 0, ptr %7, align 4
  builder.CreateStore(builder.getInt32(0), drAlloca7);
  // call void @llvm.lifetime.start.p0(i64 4, ptr nonnull %8) #6
  builder.CreateCall(lifetimeStartFunc, {builder.getInt64(4), drAlloca8});
  // store i32 0, ptr %8, align 4
  builder.CreateStore(builder.getInt32(0), drAlloca8);
  // call void @calc_interception(i32 noundef %0, i32 noundef %1, i32 noundef %19, i32 noundef %22, i32 noundef 320, i32 noundef 240, i32 noundef %2, ptr noundef nonnull %7, ptr noundef nonnull %8) #5
  builder.CreateCall(calcInterceptionFunc, {drArg0, drArg1, drVal19, drVal22, builder.getInt32(320), builder.getInt32(240), drArg2, drAlloca7, drAlloca8});
  // %27 = load i32, ptr %7, align 4
  Value *drVal27 = builder.CreateLoad(int32Type, drAlloca7);
  // %28 = load i32, ptr %8, align 4
  Value *drVal28 = builder.CreateLoad(int32Type, drAlloca8);
  // tail call void @sim_draw_line(i32 noundef %0, i32 noundef %1, i32 noundef %27, i32 noundef %28, i32 noundef %5) #4
  builder.CreateCall(simDrawLineFunc, {drArg0, drArg1, drVal27, drVal28, drArg5});
  // call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %8) #6
  builder.CreateCall(lifetimeEndFunc, {builder.getInt64(4), drAlloca8});
  // call void @llvm.lifetime.end.p0(i64 4, ptr nonnull %7) #6
  builder.CreateCall(lifetimeEndFunc, {builder.getInt64(4), drAlloca7});
  // br label %29
  builder.CreateBr(drBB29);
  
  // 29:
  builder.SetInsertPoint(drBB29);
  // %30 = add nuw nsw i32 %13, 1
  Value *drVal30 = builder.CreateAdd(drVal13, builder.getInt32(1), "", true, true);
  // %31 = icmp eq i32 %30, %3
  Value *drVal31 = builder.CreateICmpEQ(drVal30, drArg3);
  // br i1 %31, label %11, label %12
  builder.CreateCondBr(drVal31, drBB11, drBB12);
  
  // Link PHI nodes for draw_rays
  drVal13->addIncoming(builder.getInt32(0), drBB6);
  drVal13->addIncoming(drVal30, drBB29);
  
  
  // ========== DEFINE FUNCTION: app ==========
  // define dso_local void @app() local_unnamed_addr #0
  FunctionType *appFuncType = FunctionType::get(voidType, false);
  Function *appFunc = Function::Create(
    appFuncType, Function::ExternalLinkage, "app", module);
  
  // BasicBlocks
  BasicBlock *appBB0 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *appBB4 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *appBB5 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *appBB8 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *appBB10 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *appBB12 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *appBB14 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *appBB16 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *appBB18 = BasicBlock::Create(context, "", appFunc);
  BasicBlock *appBB20 = BasicBlock::Create(context, "", appFunc);
  
  // 0:
  builder.SetInsertPoint(appBB0);
  // %1 = tail call i32 @sim_sqrt(i32 noundef 640000) #4
  Value *appVal1 = builder.CreateCall(simSqrtFunc, {builder.getInt32(640000)});
  // %2 = tail call i32 @sim_should_quit() #4
  Value *appVal2 = builder.CreateCall(simShouldQuitFunc);
  // %3 = icmp eq i32 %2, 0
  Value *appVal3 = builder.CreateICmpEQ(appVal2, builder.getInt32(0));
  // br i1 %3, label %5, label %4
  builder.CreateCondBr(appVal3, appBB5, appBB4);
  
  // 4:
  builder.SetInsertPoint(appBB4);
  // ret void
  builder.CreateRetVoid();
  
  // 5:
  builder.SetInsertPoint(appBB5);
  // %6 = phi i32 [ %25, %20 ], [ 0, %0 ]
  PHINode *appVal6 = builder.CreatePHI(int32Type, 2);
  // tail call void @sim_flush() #4
  builder.CreateCall(simFlushFunc);
  // %7 = icmp slt i32 %6, 580
  Value *appVal7 = builder.CreateICmpSLT(appVal6, builder.getInt32(580));
  // br i1 %7, label %8, label %10
  builder.CreateCondBr(appVal7, appBB8, appBB10);
  
  // 8:
  builder.SetInsertPoint(appBB8);
  // %9 = add nsw i32 %6, 30
  Value *appVal9 = builder.CreateNSWAdd(appVal6, builder.getInt32(30));
  // br label %20
  builder.CreateBr(appBB20);
  
  // 10:
  builder.SetInsertPoint(appBB10);
  // %11 = icmp ult i32 %6, 1000
  Value *appVal11 = builder.CreateICmpULT(appVal6, builder.getInt32(1000));
  // br i1 %11, label %12, label %14
  builder.CreateCondBr(appVal11, appBB12, appBB14);
  
  // 12:
  builder.SetInsertPoint(appBB12);
  // %13 = add nsw i32 %6, -550
  Value *appVal13 = builder.CreateNSWAdd(appVal6, builder.getInt32(-550));
  // br label %20
  builder.CreateBr(appBB20);
  
  // 14:
  builder.SetInsertPoint(appBB14);
  // %15 = icmp ult i32 %6, 1580
  Value *appVal15 = builder.CreateICmpULT(appVal6, builder.getInt32(1580));
  // br i1 %15, label %16, label %18
  builder.CreateCondBr(appVal15, appBB16, appBB18);
  
  // 16:
  builder.SetInsertPoint(appBB16);
  // %17 = sub nuw nsw i32 1610, %6
  Value *appVal17 = builder.CreateSub(builder.getInt32(1610), appVal6, "", true, true);
  // br label %20
  builder.CreateBr(appBB20);
  
  // 18:
  builder.SetInsertPoint(appBB18);
  // %19 = sub nsw i32 2030, %6
  Value *appVal19 = builder.CreateNSWSub(builder.getInt32(2030), appVal6);
  // br label %20
  builder.CreateBr(appBB20);
  
  // 20:
  builder.SetInsertPoint(appBB20);
  // %21 = phi i32 [ %9, %8 ], [ 610, %12 ], [ %17, %16 ], [ 30, %18 ]
  PHINode *appVal21 = builder.CreatePHI(int32Type, 4);
  // %22 = phi i32 [ 30, %8 ], [ %13, %12 ], [ 450, %16 ], [ %19, %18 ]
  PHINode *appVal22 = builder.CreatePHI(int32Type, 4);
  // tail call void @draw_circle(i32 noundef 320, i32 noundef 240, i32 noundef 60, i32 noundef -16776961) #5
  builder.CreateCall(drawCircleFunc, {builder.getInt32(320), builder.getInt32(240), builder.getInt32(60), builder.getInt32(-16776961)});
  // tail call void @draw_circle(i32 noundef %21, i32 noundef %22, i32 noundef 30, i32 noundef -65536) #5
  builder.CreateCall(drawCircleFunc, {appVal21, appVal22, builder.getInt32(30), builder.getInt32(-65536)});
  // tail call void @draw_rays(i32 noundef %21, i32 noundef %22, i32 noundef 60, i32 noundef 720, i32 noundef %1, i32 noundef -65536) #5
  builder.CreateCall(drawRaysFunc, {appVal21, appVal22, builder.getInt32(60), builder.getInt32(720), appVal1, builder.getInt32(-65536)});
  // %23 = add nsw i32 %6, 4
  Value *appVal23 = builder.CreateNSWAdd(appVal6, builder.getInt32(4));
  // %24 = icmp sgt i32 %6, 1995
  Value *appVal24 = builder.CreateICmpSGT(appVal6, builder.getInt32(1995));
  // %25 = select i1 %24, i32 0, i32 %23
  Value *appVal25 = builder.CreateSelect(appVal24, builder.getInt32(0), appVal23);
  // %26 = tail call i32 @sim_should_quit() #4
  Value *appVal26 = builder.CreateCall(simShouldQuitFunc);
  // %27 = icmp eq i32 %26, 0
  Value *appVal27 = builder.CreateICmpEQ(appVal26, builder.getInt32(0));
  // br i1 %27, label %5, label %4
  builder.CreateCondBr(appVal27, appBB5, appBB4);
  
  // Link PHI nodes for app
  appVal6->addIncoming(builder.getInt32(0), appBB0);
  appVal6->addIncoming(appVal25, appBB20);
  appVal21->addIncoming(appVal9, appBB8);
  appVal21->addIncoming(builder.getInt32(610), appBB12);
  appVal21->addIncoming(appVal17, appBB16);
  appVal21->addIncoming(builder.getInt32(30), appBB18);
  appVal22->addIncoming(builder.getInt32(30), appBB8);
  appVal22->addIncoming(appVal13, appBB12);
  appVal22->addIncoming(builder.getInt32(450), appBB16);
  appVal22->addIncoming(appVal19, appBB18);
  
  
  // ========== DUMP LLVM IR ==========
  module->print(outs(), nullptr);
  outs() << '\n';
  
  bool verif = verifyModule(*module, &outs());
  outs() << "[VERIFICATION] " << (verif ? "FAIL\n\n" : "OK\n\n");
  
  // LLVM IR Interpreter
  outs() << "[EE] Run\n";
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();
  ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
  
  ee->InstallLazyFunctionCreator([](const std::string &fnName) -> void * {
    if (fnName == "sim_sqrt") {
      return reinterpret_cast<void *>(sim_sqrt);
    }
    if (fnName == "sim_put_pixel") {
      return reinterpret_cast<void *>(sim_put_pixel);
    }
    if (fnName == "get_sin_precise") {
      return reinterpret_cast<void *>(get_sin_precise);
    }
    if (fnName == "get_cos_precise") {
      return reinterpret_cast<void *>(get_cos_precise);
    }
    if (fnName == "sim_draw_line") {
      return reinterpret_cast<void *>(sim_draw_line);
    }
    if (fnName == "sim_should_quit") {
      return reinterpret_cast<void *>(sim_should_quit);
    }
    if (fnName == "sim_flush") {
      return reinterpret_cast<void *>(sim_flush);
    }
    return nullptr;
  });
  
  ee->finalizeObject();
  sim_init();
  
  ArrayRef<GenericValue> noargs;
  GenericValue v = ee->runFunction(appFunc, noargs);
  outs() << "[EE] Result: " << v.IntVal << '\n';
  
  sim_exit();
  delete module;
  return EXIT_SUCCESS;
}
