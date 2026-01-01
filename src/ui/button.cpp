#include <omnia/ui/button.hpp>

namespace omnia {

std::shared_ptr<Button> Button::create(const std::string& text) {
    return std::shared_ptr<Button>(new Button(text));
}

Button::Button(const std::string& text) : text_(text) {}

Button& Button::on_click(std::function<void()> handler) {
    on_click_handler_ = std::move(handler);
    return *this;
}

Button& Button::padding(const EdgeInsets& padding) {
    padding_ = padding;
    return *this;
}

Button& Button::background_color(const Color& color) {
    background_color_ = color;
    return *this;
}

Button& Button::corner_radius(float radius) {
    corner_radius_ = radius;
    return *this;
}

Button& Button::disabled(bool disabled) {
    disabled_ = disabled;
    return *this;
}

const std::string& Button::text() const { return text_; }
const std::function<void()>& Button::on_click_handler() const { return on_click_handler_; }
const EdgeInsets& Button::padding() const { return padding_; }
const Color& Button::background_color() const { return background_color_; }
float Button::corner_radius() const { return corner_radius_; }
bool Button::disabled() const { return disabled_; }

} // namespace omnia
