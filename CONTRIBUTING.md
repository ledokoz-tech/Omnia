# Contributing to Omnia

Thank you for your interest in contributing to Omnia! We welcome contributions from the community. This document provides guidelines and information for contributors.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Development Setup](#development-setup)
- [Project Structure](#project-structure)
- [Contributing Guidelines](#contributing-guidelines)
- [Pull Request Process](#pull-request-process)
- [Reporting Issues](#reporting-issues)

## Code of Conduct

This project follows our [Code of Conduct](CODE_OF_CONDUCT.md). By participating, you are expected to uphold this code.

## Getting Started

### Prerequisites

Before you begin, ensure you have the following installed:

- **Rust**: Version 1.72 or higher
- **C++ Compiler**: C++17 compatible (GCC, Clang, or MSVC)
- **CMake**: For building the C++ core
- **Git**: For version control

### Fork and Clone

1. Fork the repository on GitHub
2. Clone your fork locally:

   ```bash
   git clone https://github.com/your-username/Omnia.git
   cd Omnia
   ```

3. Add the upstream remote:

   ```bash
   git remote add upstream https://github.com/ledokoz-tech/Omnia.git
   ```

## Development Setup

### Building from Source

1. **Clone the repository** (see above)

2. **Build the project**:

   ```bash
   cargo build
   ```

3. **Run tests**:

   ```bash
   cargo test
   ```

4. **Run examples**:

   ```bash
   cargo run --example hello_world
   ```

### Development Workflow

1. Create a feature branch from `main`:

   ```bash
   git checkout -b feature/your-feature-name
   ```

2. Make your changes following our [coding standards](#coding-standards)

3. Run tests and ensure everything passes:

   ```bash
   cargo test
   cargo clippy
   cargo fmt --check
   ```

4. Commit your changes:

   ```bash
   git commit -m "feat: add your feature description"
   ```

5. Push to your fork:

   ```bash
   git push origin feature/your-feature-name
   ```

6. Create a Pull Request

## Project Structure

```shell
Omnia/
├── src/                    # Rust source code
│   ├── core/              # Core GUI functionality
│   ├── widgets/           # UI components
│   └── platform/          # Platform-specific implementations
├── cxx/                   # C++ core implementation
├── examples/              # Example applications
├── docs/                  # Documentation
├── .github/               # GitHub templates and workflows
│   ├── workflows/         # CI/CD pipelines
│   └── ISSUE_TEMPLATE/    # Issue templates
├── Cargo.toml             # Rust dependencies
├── CMakeLists.txt         # C++ build configuration
└── README.md              # Project documentation
```

## Contributing Guidelines

### Coding Standards

- **Rust Code**: Follow the official [Rust Style Guide](https://doc.rust-lang.org/1.0.0/style/)
- **Formatting**: Use `cargo fmt` for consistent formatting
- **Linting**: Ensure `cargo clippy` passes without warnings
- **Documentation**: Document all public APIs with `///` comments
- **Error Handling**: Use `Result` and `Option` types appropriately

### Commit Messages

We follow [Conventional Commits](https://conventionalcommits.org/) specification:

```shell
type(scope): description

[optional body]

[optional footer]
```

Types:

- `feat`: New features
- `fix`: Bug fixes
- `docs`: Documentation changes
- `style`: Code style changes (formatting, etc.)
- `refactor`: Code refactoring
- `test`: Adding or updating tests
- `chore`: Maintenance tasks

Examples:

```shell
feat: add window resizing support
fix(ui): resolve button click handler bug
docs: update API documentation
```

### Testing

- Write unit tests for new functionality
- Ensure all existing tests pass
- Add integration tests for complex features
- Test on all supported platforms when possible

### Documentation

- Update relevant documentation for any API changes
- Add examples for new features
- Keep the changelog updated

## Pull Request Process

1. **Ensure your PR is ready**:
   - All tests pass
   - Code is properly formatted
   - Documentation is updated
   - Commit messages follow conventional format

2. **Create a descriptive PR**:
   - Use a clear, descriptive title
   - Provide context in the description
   - Reference any related issues
   - Include screenshots/videos for UI changes

3. **PR Review Process**:
   - Maintainers will review your PR
   - Address any requested changes
   - Once approved, your PR will be merged

4. **After merge**:
   - Delete your feature branch
   - Pull changes from upstream

## Reporting Issues

### Bug Reports

When reporting bugs, please include:

- **Expected behavior**: What should happen
- **Actual behavior**: What actually happens
- **Steps to reproduce**: Detailed steps
- **Environment**: OS, Rust version, etc.
- **Error messages/logs**: Any relevant output

### Feature Requests

For feature requests, please:

- Describe the problem you're trying to solve
- Explain why this feature would be valuable
- Consider alternative solutions
- Provide use cases or examples

### Security Issues

For security-related issues, please see our [Security Policy](SECURITY.md).

## Recognition

Contributors will be recognized in our changelog and may be invited to join the core team for significant contributions.

Thank you for contributing to Omnia! 🚀
