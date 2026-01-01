# Getting Started with Omnia

Welcome to Omnia! This guide will help you get up and running with the Omnia GUI framework quickly.

## Prerequisites

Before you begin, ensure you have the following installed:

### Required

- **C++ Compiler**: C++17 compatible compiler
  - **Linux**: GCC 9+ or Clang 10+
  - **macOS**: Xcode Command Line Tools (Clang)
  - **Windows**: Visual Studio 2019+ or MinGW-w64

### Build System

- **CMake**: Version 3.16 or higher
- **Ninja** (optional, recommended for faster builds)
- **Git**: For cloning the repository

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/ledokoz-tech/Omnia.git
cd Omnia
```

### 2. Build Dependencies

**Linux (Ubuntu/Debian):**

```bash
sudo apt update
sudo apt install build-essential cmake ninja-build \
                 libgtk-3-dev libwebkit2gtk-4.0-dev \
                 libappindicator3-dev librsvg2-dev \
                 libasound2-dev
```

**macOS:**

```bash
brew install cmake ninja
```

**Windows (using MSVC):**

```bash
# Install Visual Studio Build Tools with C++ support
# CMake will be downloaded automatically by Cargo
```

### 3. Build Omnia

```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build the library
cmake --build . --config Release
```

## Your First Omnia Application

Create a new C++ project:

```bash
mkdir hello-omnia
cd hello-omnia
```

Create a `CMakeLists.txt` file:

```cmake
cmake_minimum_required(VERSION 3.16)
project(HelloOmnia VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Omnia library (adjust path as needed)
add_subdirectory(path/to/omnia ${CMAKE_BINARY_DIR}/omnia)

# Create executable
add_executable(hello_omnia main.cpp)
target_link_libraries(hello_omnia PRIVATE omnia)
```

Create your first application in `main.cpp`:

```cpp
#include <omnia/omnia.hpp>

int main() {
    omnia::App app("Hello Omnia");

    auto window = omnia::Window::create()
        .title("My First Omnia App")
        .size(400, 300);

    // Create UI components
    auto title_text = omnia::Text::create("Hello, Omnia!")
        .font_size(24.0f)
        .bold(true);

    auto button = omnia::Button::create("Click me!")
        .on_click([]() {
            std::cout << "Button clicked!" << std::endl;
        });

    // Create layout
    auto vstack = omnia::VStack::create()
        .spacing(16.0f)
        .add_child(title_text)
        .add_child(button);

    window.set_child(vstack);
    app.add_window(window);

    return app.run();
}
```

Build and run your application:

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
./hello_omnia
```

## Project Structure

A typical Omnia project looks like this:

```shell
my-omnia-app/
├── CMakeLists.txt       # CMake build configuration
├── src/
│   ├── main.cpp         # Application entry point
│   ├── app.cpp          # Main application logic
│   ├── app.hpp
│   ├── ui/              # UI components and views
│   │   ├── main_view.cpp
│   │   └── main_view.hpp
│   └── models/          # Data models
│       ├── user_model.cpp
│       └── user_model.hpp
└── assets/              # Static assets (images, fonts, etc.)
```

## Next Steps

Now that you have a basic Omnia application running, here are some next steps:

1. **Explore the API**: Check out the [API Reference](api/) for detailed documentation
2. **Follow Tutorials**: See our [Guides](guides/) for in-depth tutorials
3. **Browse Examples**: Look at the [examples](../examples/) directory
4. **Join the Community**: Connect with other Omnia developers

## Common Issues

### Build Errors

**Missing C++ compiler:**

```shell
error: linker `cc` not found
```

**Solution**: Install a C++ compiler (see Prerequisites section)

**Missing system dependencies:**

```shell
error: failed to run custom build command for `omnia v0.1.0`
```

**Solution**: Install required system libraries (see installation steps)

### Runtime Issues

**Application doesn't start:**

- Check that all required dynamic libraries are available
- Ensure you're running on a supported platform
- Try running in debug mode for more detailed error messages

**UI doesn't render correctly:**

- Verify your graphics drivers are up to date
- Check that your system supports OpenGL 3.3+
- Try running with software rendering: `OMNIA_RENDERER=software cargo run`

## Getting Help

- **Documentation**: [docs/](README.md)
- **Issues**: [GitHub Issues](https://github.com/ledokoz-tech/Omnia/issues)
- **Discussions**: [GitHub Discussions](https://github.com/ledokoz-tech/Omnia/discussions)

## Development vs Production

### Development

- Build with `cmake --build .` for quick iteration
- Use `CMAKE_BUILD_TYPE=Debug` for debug features
- Hot reload is enabled by default in debug mode

### Production

- Build with `CMAKE_BUILD_TYPE=Release`
- Enable link-time optimization with `CMAKE_INTERPROCEDURAL_OPTIMIZATION=ON`
- Consider code signing for distribution

---

Congratulations! You now have Omnia up and running. Happy coding! 🚀
