set(TARGET_NAME task-01)

add_executable(${TARGET_NAME} app.cxx sim.cxx start.cxx)

target_include_directories(${TARGET_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} PRIVATE ${SDL2_LIBRARIES})
