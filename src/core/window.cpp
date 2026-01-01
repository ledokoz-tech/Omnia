#include <omnia/window.hpp>
#include <omnia/view.hpp>

namespace omnia {

class Window::Impl {
public:
    std::string title = "Omnia Window";
    int width = 800;
    int height = 600;
    bool resizable = true;
    std::shared_ptr<View> child;
};

std::unique_ptr<Window> Window::create() {
    auto window = std::make_unique<Window>();
    window->impl_ = std::make_unique<Impl>();
    return window;
}

Window& Window::title(const std::string& title) {
    impl_->title = title;
    return *this;
}

Window& Window::size(int width, int height) {
    impl_->width = width;
    impl_->height = height;
    return *this;
}

Window& Window::resizable(bool resizable) {
    impl_->resizable = resizable;
    return *this;
}

Window& Window::set_child(const std::shared_ptr<View>& child) {
    impl_->child = child;
    return *this;
}

const std::string& Window::title() const { return impl_->title; }
int Window::width() const { return impl_->width; }
int Window::height() const { return impl_->height; }
bool Window::resizable() const { return impl_->resizable; }
std::shared_ptr<View> Window::child() const { return impl_->child; }

} // namespace omnia
