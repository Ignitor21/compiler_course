set(TARGET_NAME task-03)

execute_process(COMMAND llvm-config-19 --cppflags
                OUTPUT_VARIABLE LLVM_CPPFLAGS
                OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND llvm-config-19 --ldflags
                OUTPUT_VARIABLE LLVM_LDFLAGS
                OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND llvm-config-19 --libs
                OUTPUT_VARIABLE LLVM_LIBS
                OUTPUT_STRIP_TRAILING_WHITESPACE)

separate_arguments(LLVM_CPPFLAGS)
separate_arguments(LLVM_LDFLAGS)
separate_arguments(LLVM_LIBS)

add_executable(${TARGET_NAME} ${CMAKE_SOURCE_DIR}/task-01/sim.c app_ir_gen.cxx)

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/task-01)
target_compile_options(${TARGET_NAME} PRIVATE ${LLVM_CPPFLAGS})
target_link_libraries(${TARGET_NAME} PRIVATE ${LLVM_LDFLAGS} ${LLVM_LIBS} SDL2)
