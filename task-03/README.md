# Task 3 - LLVM IR builder for graphical app

I lost fight with Cmake because of linker problems so this task will be built without CMake :D
## Build steps
```
clang++ $(llvm-config --cppflags --ldflags --libs) app_ir_gen.cxx ../task-01/sim.c -lSDL2 -lm
```

