cmake_minimum_required(VERSION 3.16)
project(Omnia VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable testing
include(CTest)
enable_testing()

# Find packages
find_package(PkgConfig REQUIRED)

# Platform-specific GUI libraries
if(WIN32)
    # Windows GUI libraries
    find_package(OpenGL REQUIRED)
    # For Windows, we'll use a combination of native APIs and cross-platform libraries
elseif(APPLE)
    # macOS GUI libraries
    find_library(COCOA_LIBRARY Cocoa)
    find_library(OPENGL_LIBRARY OpenGL)
    find_library(CORE_FOUNDATION CoreFoundation)
elseif(UNIX AND NOT APPLE)
    # Linux GUI libraries (GTK-based)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    pkg_check_modules(WEBKIT2GTK REQUIRED webkit2gtk-4.1)
    pkg_check_modules(LIBAPPINDICATOR REQUIRED ayatana-appindicator3-0.1)
    pkg_check_modules(LIBRSVG REQUIRED librsvg-2.0)
    pkg_check_modules(LIBASOUND REQUIRED alsa)
endif()

# Create library target
add_library(omnia
    src/core/app.cpp
    src/core/window.cpp
    src/core/view.cpp
    src/ui/text.cpp
    src/ui/button.cpp
    src/ui/stack.cpp
    src/ui/spacer.cpp
    src/utils/color.cpp
    src/utils/geometry.cpp
)

# Include directories
target_include_directories(omnia PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src
)

# Platform-specific link libraries
if(WIN32)
    target_link_libraries(omnia PUBLIC
        OpenGL::GL
        # Windows-specific libraries would go here
    )
elseif(APPLE)
    target_link_libraries(omnia PUBLIC
        ${COCOA_LIBRARY}
        ${OPENGL_LIBRARY}
        ${CORE_FOUNDATION}
    )
elseif(UNIX AND NOT APPLE)
    target_link_libraries(omnia PUBLIC
        ${GTK3_LIBRARIES}
        ${WEBKIT2GTK_LIBRARIES}
        ${LIBAPPINDICATOR_LIBRARIES}
        ${LIBRSVG_LIBRARIES}
        ${LIBASOUND_LIBRARIES}
    )
    target_include_directories(omnia PUBLIC
        ${GTK3_INCLUDE_DIRS}
        ${WEBKIT2GTK_INCLUDE_DIRS}
        ${LIBAPPINDICATOR_INCLUDE_DIRS}
        ${LIBRSVG_INCLUDE_DIRS}
        ${LIBASOUND_INCLUDE_DIRS}
    )
endif()

# Compiler warnings and optimizations
if(MSVC)
    target_compile_options(omnia PRIVATE /W4 /WX)
else()
    target_compile_options(omnia PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# Build examples
option(BUILD_EXAMPLES "Build example programs" ON)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Build tests
option(BUILD_TESTS "Build test programs" ON)
if(BUILD_TESTS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests")
    add_subdirectory(tests)
endif()

# Install targets
install(TARGETS omnia
    EXPORT omnia-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

# Generate and install CMake config files (simplified for now)
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/omnia-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Create a simple config file
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/omnia-config.cmake"
"include(\"\${CMAKE_CURRENT_LIST_DIR}/omnia-targets.cmake\")"
)

install(EXPORT omnia-targets
    FILE omnia-targets.cmake
    NAMESPACE omnia::
    DESTINATION lib/cmake/omnia
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/omnia-config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/omnia-config-version.cmake"
    DESTINATION lib/cmake/omnia
)
