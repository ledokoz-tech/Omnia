#include <omnia/ui/spacer.hpp>

namespace omnia {

std::shared_ptr<Spacer> Spacer::create() {
    return std::shared_ptr<Spacer>(new Spacer());
}

Spacer::Spacer() = default;

Spacer& Spacer::width(float width) {
    width_ = width;
    return *this;
}

Spacer& Spacer::height(float height) {
    height_ = height;
    return *this;
}

float Spacer::width() const { return width_; }
float Spacer::height() const { return height_; }

} // namespace omnia
