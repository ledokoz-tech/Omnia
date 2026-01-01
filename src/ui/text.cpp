#include <omnia/ui/text.hpp>

namespace omnia {

std::shared_ptr<Text> Text::create(const std::string& text) {
    return std::shared_ptr<Text>(new Text(text));
}

Text::Text(const std::string& text) : text_(text) {}

std::shared_ptr<Text> Text::font_size(float size) {
    font_size_ = size;
    return std::static_pointer_cast<Text>(shared_from_this());
}

std::shared_ptr<Text> Text::bold(bool bold) {
    bold_ = bold;
    return std::static_pointer_cast<Text>(shared_from_this());
}

std::shared_ptr<Text> Text::color(const Color& color) {
    color_ = color;
    return std::static_pointer_cast<Text>(shared_from_this());
}

const std::string& Text::text() const { return text_; }
float Text::font_size() const { return font_size_; }
bool Text::bold() const { return bold_; }
const Color& Text::color() const { return color_; }

} // namespace omnia
