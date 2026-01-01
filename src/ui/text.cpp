#include <omnia/ui/text.hpp>

namespace omnia {

std::shared_ptr<Text> Text::create(const std::string& text) {
    return std::shared_ptr<Text>(new Text(text));
}

Text::Text(const std::string& text) : text_(text) {}

Text& Text::font_size(float size) {
    font_size_ = size;
    return *this;
}

Text& Text::bold(bool bold) {
    bold_ = bold;
    return *this;
}

Text& Text::color(const Color& color) {
    color_ = color;
    return *this;
}

const std::string& Text::text() const { return text_; }
float Text::font_size() const { return font_size_; }
bool Text::bold() const { return bold_; }
const Color& Text::color() const { return color_; }

} // namespace omnia
