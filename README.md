# Omnia

Omnia is a high-performance, cross-platform GUI framework for C++ developers. It enables you to create modern desktop and mobile applications effortlessly. Inspired by modern GUI frameworks, Omnia focuses on **maximum platform coverage, high performance, and developer-friendly APIs**.

---

## Features

- **Cross-platform support**: Windows, macOS, Linux, Android, iOS
- **Modern C++ API**: Clean, modern C++17 interface
- **High performance**: GPU-accelerated rendering and fast input handling
- **Declarative GUI**: Build interfaces in a modern, intuitive style
- **Plugin system**: Easily extendable with custom components
- **Hot reload**: Instant preview during development
- **Extra features**: Notifications, storage, media support, and more

---

## Getting Started

### Prerequisites

- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2019+)
- CMake >= 3.16
- Git

### Installation

1.Clone the repository

```bash
git clone https://github.com/your-org/omnia.git
cd omnia
```

2.Build the library

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

3.Create a new project

```bash
# Create your project directory
mkdir my_app && cd my_app

# Copy the example CMakeLists.txt or create your own
# Add Omnia as a subdirectory or installed library
```

4.Write your first GUI app

```cpp
#include <omnia/omnia.hpp>

int main() {
    omnia::App app("Hello Omnia");

    auto window = omnia::Window::create()
        .title("Omnia App");

    app.add_window(window);
    return app.run();
}
```

---

## Roadmap

- [ ] Stable desktop support (Windows, macOS, Linux)
- [ ] Mobile support (Android, iOS)
- [ ] Plugin architecture for 3rd-party components
- [ ] Hot reload & live preview
- [ ] Advanced UI components & theming
- [ ] Official documentation & tutorials

---

## Contributing

We welcome contributions! Please read [CONTRIBUTING.md](CONTRIBUTING.md) before submitting PRs.

---

## License

Omnia is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.

---

> Omnia is a trademark of Ledokoz. All rights reserved.
