# Omnia Examples

This directory contains examples demonstrating various features and use cases of the Omnia GUI framework.

## Running Examples

To run an example, use the following command:

```bash
cargo run --example <example_name>
```

For example, to run the hello world example:

```bash
cargo run --example hello_world
```

## Available Examples

### hello_world.rs
A basic "Hello World" application demonstrating:
- Creating windows
- Basic layout with VStack and HStack
- Text rendering with styling
- Button components with click handlers
- State management with reactive updates
- Custom components

**Run with:**
```bash
cargo run --example hello_world
```

## Example Categories

### Basic Examples
- `hello_world.rs` - Getting started with basic UI components

### Advanced Examples (Coming Soon)
- `todo_app.rs` - A complete todo application with data persistence
- `calculator.rs` - A calculator with custom styling
- `file_browser.rs` - File system browser with tree view
- `chat_app.rs` - Real-time chat application example
- `drawing_app.rs` - Canvas-based drawing application

### Platform-Specific Examples (Coming Soon)
- `windows_integration.rs` - Windows-specific features
- `macos_integration.rs` - macOS-specific features
- `mobile_ui.rs` - Mobile-optimized UI patterns

## Contributing Examples

We welcome contributions of new examples! When adding examples:

1. **Follow naming conventions**: Use snake_case for file names
2. **Add documentation**: Include doc comments explaining the example
3. **Keep it simple**: Focus on demonstrating specific features
4. **Test thoroughly**: Ensure examples work on all supported platforms
5. **Update this README**: Add your example to the list above

## Learning Path

If you're new to Omnia, we recommend following this learning path:

1. Start with `hello_world.rs` - Basic concepts
2. Explore the API documentation
3. Look at more complex examples as you progress
4. Build your own application using examples as reference

## Example Structure

Each example follows a similar structure:

```rust
use omnia::prelude::*;

fn main() {
    App::new("Example Name")
        .window(Window::new()
            .title("Window Title")
            .child(/* Your UI here */))
        .run();
}
```

## Need Help?

- Check the [documentation](../docs/) for detailed guides
- Open an [issue](https://github.com/ledokoz-tech/Omnia/issues) if you find a bug
- Ask questions in [discussions](https://github.com/ledokoz-tech/Omnia/discussions)

Happy coding with Omnia! 🚀
