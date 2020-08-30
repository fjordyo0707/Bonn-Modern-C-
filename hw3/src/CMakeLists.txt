add_subdirectory(igg_image)

add_executable(main.o main.cpp)
target_link_libraries(main.o image)