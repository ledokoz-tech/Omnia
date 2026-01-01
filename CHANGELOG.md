# Changelog

All notable changes to Omnia will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Initial project setup and documentation
- Comprehensive contributor guidelines ([CONTRIBUTING.md](CONTRIBUTING.md))
- Code of Conduct ([CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md))
- Security policy ([SECURITY.md](SECURITY.md))
- GitHub issue and pull request templates
- CI/CD workflow configuration
- Project directory structure and examples

### Changed
- Updated README with complete project documentation

## [0.1.0] - 2025-01-01

### Added
- Initial release of Omnia GUI framework
- Core Rust API with C++ backend architecture
- Basic window management functionality
- Cross-platform support foundation (Windows, macOS, Linux, Android, iOS)
- Declarative GUI syntax inspired by Tauri and Flutter
- Plugin system architecture for extensibility
- Hot reload development support
- GPU-accelerated rendering pipeline
- Comprehensive build system with CMake integration

### Technical Details
- Minimum Rust version: 1.72
- C++17 standard compliance
- MIT License

---

## Types of changes
- `Added` for new features
- `Changed` for changes in existing functionality
- `Deprecated` for soon-to-be removed features
- `Removed` for now removed features
- `Fixed` for any bug fixes
- `Security` in case of vulnerabilities

## Version History

For a complete history of changes, see the [Git history](https://github.com/ledokoz-tech/Omnia/commits/main).

## Contributing to the Changelog

When contributing to Omnia:

1. **For each PR**: Update this changelog in the same PR
2. **Section**: Add your changes under the `[Unreleased]` section
3. **Categories**: Use appropriate categories (Added, Changed, Fixed, etc.)
4. **Format**: Keep entries concise but descriptive
5. **References**: Include PR/issue numbers when relevant

Example entry:
```
### Fixed
- Resolved window focus issue on Windows (#123)
```

The changelog will be updated during releases by moving items from `[Unreleased]` to a new version section.
