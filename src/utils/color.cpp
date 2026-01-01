#include <omnia/utils/color.hpp>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cctype>

namespace omnia {

Color Color::from_rgb(float r, float g, float b) {
    return Color(r, g, b, 1.0f);
}

Color Color::from_rgba(float r, float g, float b, float a) {
    return Color(r, g, b, a);
}

Color Color::from_hex(const std::string& hex) {
    if (hex.empty() || hex[0] != '#') {
        throw std::invalid_argument("Invalid hex color format");
    }

    std::string hex_value = hex.substr(1);
    if (hex_value.length() != 6 && hex_value.length() != 8) {
        throw std::invalid_argument("Hex color must be 6 or 8 characters");
    }

    // Simple hex parsing without stoul
    unsigned int value = 0;
    for (char c : hex_value) {
        value *= 16;
        if (c >= '0' && c <= '9') {
            value += c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value += c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value += c - 'a' + 10;
        } else {
            throw std::invalid_argument("Invalid hex character");
        }
    }

    float r = ((value >> 16) & 0xFF) / 255.0f;
    float g = ((value >> 8) & 0xFF) / 255.0f;
    float b = (value & 0xFF) / 255.0f;
    float a = (hex_value.length() == 8) ? ((value >> 24) & 0xFF) / 255.0f : 1.0f;

    return Color(r, g, b, a);
}

Color::Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f) {}

Color::Color(float r, float g, float b, float a)
    : r(std::clamp(r, 0.0f, 1.0f))
    , g(std::clamp(g, 0.0f, 1.0f))
    , b(std::clamp(b, 0.0f, 1.0f))
    , a(std::clamp(a, 0.0f, 1.0f)) {}

} // namespace omnia
