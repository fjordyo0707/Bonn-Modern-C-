#################### Import the 'io_tools' library here ########################
find_library(TOOLS
             NAMES io_tools
             PATHS ${LIBRARY_OUTPUT_PATH}
            )
#################### Create a library 'image' below this line ##################
add_library (image image.cpp)
target_link_libraries (image ${TOOLS})

add_executable(main.o main.cpp)
target_link_libraries(main.o image)
