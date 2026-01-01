#pragma once

#include <omnia/view.hpp>
#include <omnia/utils/color.hpp>
#include <string>

namespace omnia {

/**
 * Text display component.
 */
class Text : public View {
public:
    /**
     * Create a new text component.
     */
    static Text create(const std::string& text);

    /**
     * Set the font size.
     */
    std::shared_ptr<Text> font_size(float size);

    /**
     * Set whether the text is bold.
     */
    std::shared_ptr<Text> bold(bool bold);

    /**
     * Set the text color.
     */
    std::shared_ptr<Text> color(const Color& color);

    // Getters
    const std::string& text() const;
    float font_size() const;
    bool bold() const;
    const Color& color() const;

private:
    Text(const std::string& text);

    std::string text_;
    float font_size_ = 16.0f;
    bool bold_ = false;
    Color color_ = Color::from_rgb(0.0f, 0.0f, 0.0f);
};

} // namespace omnia
