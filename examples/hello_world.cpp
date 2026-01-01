/**
 * Hello World Example
 *
 * This example demonstrates the basic usage of Omnia to create
 * a simple GUI application with a window, text, and a button.
 */

#include <omnia/omnia.hpp>
#include <iostream>

int main() {
    // Create the main application
    omnia::App app("Hello World");

    // Create a window with title and size
    auto window = omnia::Window::create()
        .title("Omnia Hello World")
        .size(400, 300)
        .resizable(true);

    // Create UI components
    auto title_text = omnia::Text::create("Hello, Omnia!")
        .font_size(24.0f)
        .bold(true)
        .color(omnia::Color::from_rgb(0.2f, 0.4f, 0.8f));

    auto subtitle_text = omnia::Text::create("Welcome to the future of GUI development")
        .font_size(14.0f)
        .color(omnia::Color::from_rgb(0.5f, 0.5f, 0.5f));

    // Create a button with click handler
    auto button = omnia::Button::create("Click Me!")
        .on_click([]() {
            std::cout << "Button was clicked!" << std::endl;
            // In a real app, you might update state here
        })
        .padding(omnia::EdgeInsets::all(12.0f))
        .background_color(omnia::Color::from_rgb(0.2f, 0.6f, 1.0f))
        .corner_radius(8.0f);

    // Create counter component
    auto counter = std::make_shared<CounterExample>();

    // Create vertical layout
    auto vstack = omnia::VStack::create()
        .spacing(16.0f)
        .padding(20.0f)
        .alignment(omnia::Alignment::Center)
        .add_child(title_text)
        .add_child(subtitle_text)
        .add_child(omnia::Spacer::create().height(20.0f))
        .add_child(button)
        .add_child(counter);

    // Set the layout as window content
    window.set_child(vstack);

    // Add window to app
    app.add_window(window);

    // Run the application
    return app.run();
}

/// A simple counter component example
class CounterExample : public omnia::View {
public:
    CounterExample() : count_(0) {}

    std::shared_ptr<omnia::View> build() override {
        // Create count display text
        auto count_text = omnia::Text::create("Count: " + std::to_string(count_))
            .font_size(16.0f);

        // Create decrement button
        auto decrement_button = omnia::Button::create("-")
            .on_click([this]() {
                if (count_ > 0) {
                    count_--;
                    // In a real implementation, this would trigger a re-render
                }
            })
            .disabled(count_ <= 0);

        // Create increment button
        auto increment_button = omnia::Button::create("+")
            .on_click([this]() {
                count_++;
                // In a real implementation, this would trigger a re-render
            });

        // Create horizontal layout for buttons
        auto hstack = omnia::HStack::create()
            .spacing(8.0f)
            .add_child(decrement_button)
            .add_child(increment_button);

        // Create vertical layout for counter
        auto counter_vstack = omnia::VStack::create()
            .spacing(8.0f)
            .add_child(count_text)
            .add_child(hstack);

        return counter_vstack;
    }

private:
    int count_;
};
