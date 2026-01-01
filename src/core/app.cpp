#include <omnia/app.hpp>
#include <omnia/window.hpp>
#include <iostream>
#include <vector>

namespace omnia {

class App::Impl {
public:
    std::string name;
    std::vector<std::unique_ptr<Window>> windows;
};

App::App(const std::string& name) : impl_(std::make_unique<Impl>()) {
    impl_->name = name;
}

App::~App() = default;

App& App::add_window(std::unique_ptr<Window> window) {
    impl_->windows.push_back(std::move(window));
    return *this;
}

int App::run() {
    std::cout << "Starting Omnia application: " << impl_->name << std::endl;

    // TODO: Implement actual GUI application loop
    // For now, just print a message and exit
    std::cout << "Application would run here with " << impl_->windows.size() << " window(s)" << std::endl;

    return 0;
}

} // namespace omnia
