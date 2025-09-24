set(TARGET_NAME task-01)

add_executable(${TARGET_NAME} app.c sim.c start.c)

target_include_directories(${TARGET_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(${TARGET_NAME} PRIVATE ${SDL2_LIBRARIES} m)
