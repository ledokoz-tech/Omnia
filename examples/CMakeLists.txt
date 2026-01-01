# Examples subdirectory CMakeLists.txt

# Hello World example
add_executable(hello_world hello_world.cpp)
target_link_libraries(hello_world PRIVATE omnia)

# Set output directory for examples
set_target_properties(hello_world PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/examples"
)

# Install examples
install(TARGETS hello_world
    RUNTIME DESTINATION examples
)
