#pragma once

namespace omnia {

/**
 * Color representation with RGBA components.
 */
class Color {
public:
    float r, g, b, a;

    /**
     * Create a color from RGB values (alpha defaults to 1.0).
     */
    static Color from_rgb(float r, float g, float b);

    /**
     * Create a color from RGBA values.
     */
    static Color from_rgba(float r, float g, float b, float a);

    /**
     * Create a color from hex string (e.g., "#FF0000").
     */
    static Color from_hex(const std::string& hex);

    /**
     * Default constructor (transparent black).
     */
    Color();

    /**
     * Constructor with RGBA values.
     */
    Color(float r, float g, float b, float a = 1.0f);
};

} // namespace omnia
