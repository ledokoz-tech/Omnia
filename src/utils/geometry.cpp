#include <omnia/utils/geometry.hpp>

namespace omnia {

EdgeInsets EdgeInsets::all(float value) {
    return EdgeInsets(value, value, value, value);
}

EdgeInsets EdgeInsets::symmetric(float horizontal, float vertical) {
    return EdgeInsets(horizontal, vertical, horizontal, vertical);
}

EdgeInsets EdgeInsets::only(float left, float top, float right, float bottom) {
    return EdgeInsets(left, top, right, bottom);
}

EdgeInsets::EdgeInsets() : left(0.0f), top(0.0f), right(0.0f), bottom(0.0f) {}

EdgeInsets::EdgeInsets(float left, float top, float right, float bottom)
    : left(left), top(top), right(right), bottom(bottom) {}

} // namespace omnia
