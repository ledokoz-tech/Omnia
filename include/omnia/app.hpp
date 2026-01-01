#pragma once

#include <string>
#include <memory>
#include <vector>

namespace omnia {

class Window;

/**
 * Main application class for Omnia GUI framework.
 */
class App {
public:
    /**
     * Create a new application with the given name.
     */
    explicit App(const std::string& name);
    ~App();

    /**
     * Add a window to the application.
     */
    App& add_window(const Window& window);

    /**
     * Run the application main loop.
     * Returns the exit code.
     */
    int run();

private:
    class Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace omnia
