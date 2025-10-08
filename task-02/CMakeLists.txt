add_library(instr_logger_pass SHARED pass.cpp)
target_include_directories(instr_logger_pass PRIVATE ${LLVM_INCLUDE_DIRS})

set(APP_DIR ${PROJECT_SOURCE_DIR}/task-01)
add_library(app_logic_instrumented OBJECT ${APP_DIR}/app.c)
add_dependencies(app_logic_instrumented instr_logger_pass)
target_include_directories(app_logic_instrumented PUBLIC ${APP_DIR})
target_compile_options(app_logic_instrumented PRIVATE -fpass-plugin=$<TARGET_FILE:instr_logger_pass>)

add_executable(raytracing_instrumented ${APP_DIR}/start.c ${APP_DIR}/sim.c logger.cpp)
target_link_libraries(raytracing_instrumented PRIVATE LLVM app_logic_instrumented ${SDL2_LIBRARIES} m)
target_include_directories(raytracing_instrumented PRIVATE ${LLVM_INCLUDE_DIRS} ${APP_DIR})

