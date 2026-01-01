# Getting Started with Omnia

Welcome to Omnia! This guide will help you get up and running with the Omnia GUI framework quickly.

## Prerequisites

Before you begin, ensure you have the following installed:

### Required

- **Rust**: Version 1.72 or higher

  ```bash
  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
  ```

- **C++ Compiler**: C++17 compatible compiler
  - **Linux**: GCC 9+ or Clang 10+
  - **macOS**: Xcode Command Line Tools (Clang)
  - **Windows**: Visual Studio 2019+ or MinGW-w64

### Build System

- **CMake**: Version 3.16 or higher
- **Ninja** (optional, recommended for faster builds)

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
# Build in debug mode
cargo build

# Build in release mode (recommended for production)
cargo build --release
```

## Your First Omnia Application

Create a new Rust project:

```bash
cargo new hello-omnia
cd hello-omnia
```

Add Omnia to your `Cargo.toml`:

```toml
[dependencies]
omnia = { git = "https://github.com/ledokoz-tech/Omnia.git" }
```

Create your first application in `src/main.rs`:

```rust
use omnia::prelude::*;

fn main() {
    App::new("Hello Omnia")
        .window(Window::new()
            .title("My First Omnia App")
            .size(400, 300)
            .child(
                VStack::new()
                    .spacing(16.0)
                    .children([
                        Text::new("Hello, Omnia!")
                            .font_size(24.0)
                            .bold(true)
                            .into(),
                        Button::new("Click me!")
                            .on_click(|_| {
                                println!("Button clicked!");
                            })
                            .into(),
                    ])
            ))
        .run();
}
```

Run your application:

```bash
cargo run
```

## Project Structure

A typical Omnia project looks like this:

```shell
my-omnia-app/
├── Cargo.toml
├── src/
│   ├── main.rs          # Application entry point
│   ├── app.rs           # Main application logic
│   ├── ui/              # UI components and views
│   │   ├── mod.rs
│   │   └── main_view.rs
│   └── models/          # Data models
│       └── mod.rs
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

- Use `cargo run` for quick iteration
- Enable debug features with `cargo build`
- Hot reload is enabled by default in debug mode

### Production

- Build with `cargo build --release`
- Optimize binary size with `cargo build --release --strip`
- Consider code signing for distribution

---

Congratulations! You now have Omnia up and running. Happy coding! 🚀
