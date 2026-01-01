//! Hello World Example
//!
//! This example demonstrates the basic usage of Omnia to create
//! a simple GUI application with a window, text, and a button.

use omnia::prelude::*;

fn main() {
    // Create the main application
    App::new("Hello World")
        .window(
            // Create a window with title and size
            Window::new()
                .title("Omnia Hello World")
                .size(400, 300)
                .resizable(true)
                .child(
                    // Use a vertical stack layout
                    VStack::new()
                        .spacing(16.0)
                        .padding(20.0)
                        .alignment(Alignment::Center)
                        .children([
                            // Add a title text
                            Text::new("Hello, Omnia!")
                                .font_size(24.0)
                                .bold(true)
                                .color(Color::from_rgb(0.2, 0.4, 0.8))
                                .into(),

                            // Add a subtitle
                            Text::new("Welcome to the future of GUI development")
                                .font_size(14.0)
                                .color(Color::from_rgb(0.5, 0.5, 0.5))
                                .into(),

                            // Add some spacing
                            Spacer::new().height(20.0).into(),

                            // Add a button with click handler
                            Button::new("Click Me!")
                                .on_click(|_| {
                                    println!("Button was clicked!");
                                    // In a real app, you might update state here
                                })
                                .padding(EdgeInsets::all(12.0))
                                .background_color(Color::from_rgb(0.2, 0.6, 1.0))
                                .corner_radius(8.0)
                                .into(),

                            // Add a counter example
                            CounterExample::new().into(),
                        ])
                )
        )
        .run();
}

/// A simple counter component example
struct CounterExample {
    state: State<i32>,
}

impl CounterExample {
    fn new() -> Self {
        Self {
            state: State::new(0),
        }
    }
}

impl View for CounterExample {
    fn build(&self, cx: &mut BuildContext) -> impl IntoView {
        let count = self.state.clone();

        VStack::new()
            .spacing(8.0)
            .children([
                Text::new(format!("Count: {}", count.get()))
                    .font_size(16.0)
                    .into(),

                HStack::new()
                    .spacing(8.0)
                    .children([
                        Button::new("-")
                            .on_click(move |_| {
                                count.update(|c| *c -= 1);
                            })
                            .disabled(count.get() <= 0)
                            .into(),

                        Button::new("+")
                            .on_click(move |_| {
                                count.update(|c| *c += 1);
                            })
                            .into(),
                    ])
                    .into(),
            ])
    }
}
