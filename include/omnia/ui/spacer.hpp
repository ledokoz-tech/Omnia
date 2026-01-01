#pragma once

#include <omnia/view.hpp>

namespace omnia {

/**
 * Spacer component for adding flexible space in layouts.
 */
class Spacer : public View {
public:
    /**
     * Create a new spacer.
     */
    static std::shared_ptr<Spacer> create();

    /**
     * Set the width of the spacer.
     */
    std::shared_ptr<Spacer> width(float width);

    /**
     * Set the height of the spacer.
     */
    std::shared_ptr<Spacer> height(float height);

    // Getters
    float width() const;
    float height() const;

private:
    Spacer();

    float width_ = 0.0f;
    float height_ = 0.0f;
};

} // namespace omnia
