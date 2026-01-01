#pragma once

#include <omnia/view.hpp>
#include <omnia/utils/color.hpp>
#include <omnia/utils/geometry.hpp>
#include <functional>
#include <string>

namespace omnia {

/**
 * Button component with click handling.
 */
class Button : public View {
public:
    /**
     * Create a new button component.
     */
    static std::shared_ptr<Button> create(const std::string& text);

    /**
     * Set the click handler function.
     */
    std::shared_ptr<Button> on_click(std::function<void()> handler);

    /**
     * Set the button padding.
     */
    std::shared_ptr<Button> padding(const EdgeInsets& padding);

    /**
     * Set the background color.
     */
    std::shared_ptr<Button> background_color(const Color& color);

    /**
     * Set the corner radius.
     */
    std::shared_ptr<Button> corner_radius(float radius);

    /**
     * Set whether the button is disabled.
     */
    std::shared_ptr<Button> disabled(bool disabled);

    // Getters
    const std::string& text() const;
    const std::function<void()>& on_click_handler() const;
    const EdgeInsets& padding() const;
    const Color& background_color() const;
    float corner_radius() const;
    bool disabled() const;

private:
    Button(const std::string& text);

    std::string text_;
    std::function<void()> on_click_handler_;
    EdgeInsets padding_;
    Color background_color_ = Color::from_rgb(0.9f, 0.9f, 0.9f);
    float corner_radius_ = 0.0f;
    bool disabled_ = false;
};

} // namespace omnia
