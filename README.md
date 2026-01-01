# Omnia

Omnia is a high-performance, cross-platform GUI framework for Rust developers, powered by a fast C++ core. It enables you to create modern desktop and mobile applications effortlessly. Inspired by Tauri and Flutter, Omnia focuses on **maximum platform coverage, high performance, and developer-friendly APIs**.

---

## Features

- **Cross-platform support**: Windows, macOS, Linux, Android, iOS
- **Rust-first API**: Safe, modern Rust interface with a C++ backend
- **High performance**: GPU-accelerated rendering and fast input handling
- **Declarative GUI**: Build interfaces in a Tauri/Flutter-like style
- **Plugin system**: Easily extendable with custom components
- **Hot reload**: Instant preview during development
- **Extra features**: Notifications, storage, media support, and more

---

## Getting Started

### Prerequisites

- Rust >= 1.72  
- C++17 compatible compiler  
- Cargo & Rust toolchains installed  
- CMake or your preferred build system (for C++ core)

### Installation

1.Add Omnia to your Cargo.toml

```toml
[dependencies]
omnia = "0.1.0"
````

2.Create a new project

```bash
cargo new my_app --bin
cd my_app
```

3.Write your first GUI app

```rust
use omnia::prelude::*;

fn main() {
    App::new("Hello Omnia")
        .window(Window::new().title("Omnia App"))
        .run();
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
