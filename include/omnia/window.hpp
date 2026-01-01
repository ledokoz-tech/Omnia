#pragma once

#include <string>
#include <memory>

namespace omnia {

class View;

/**
 * Window configuration and management.
 */
class Window {
public:
    /**
     * Create a new window builder.
     */
    static std::unique_ptr<Window> create();

    /**
     * Set the window title.
     */
    Window& title(const std::string& title);

    /**
     * Set the window size.
     */
    Window& size(int width, int height);

    /**
     * Set whether the window is resizable.
     */
    Window& resizable(bool resizable);

    /**
     * Set the window content/view.
     */
    Window& set_child(const std::shared_ptr<View>& child);

    // Getters
    const std::string& title() const;
    int width() const;
    int height() const;
    bool resizable() const;
    std::shared_ptr<View> child() const;

private:
    class Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace omnia
