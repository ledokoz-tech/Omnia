#pragma once

namespace omnia {

/**
 * Edge insets for padding and margins.
 */
class EdgeInsets {
public:
    float left, top, right, bottom;

    /**
     * Create edge insets with all sides equal.
     */
    static EdgeInsets all(float value);

    /**
     * Create edge insets with symmetric values.
     */
    static EdgeInsets symmetric(float horizontal, float vertical);

    /**
     * Create edge insets with individual values.
     */
    static EdgeInsets only(float left, float top, float right, float bottom);

    /**
     * Default constructor (zero insets).
     */
    EdgeInsets();

    /**
     * Constructor with individual values.
     */
    EdgeInsets(float left, float top, float right, float bottom);
};

} // namespace omnia
