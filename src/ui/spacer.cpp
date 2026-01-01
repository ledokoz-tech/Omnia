#include <omnia/ui/spacer.hpp>

namespace omnia {

std::shared_ptr<Spacer> Spacer::create() {
    return std::shared_ptr<Spacer>(new Spacer());
}

Spacer::Spacer() = default;

std::shared_ptr<Spacer> Spacer::width(float width) {
    width_ = width;
    return std::static_pointer_cast<Spacer>(shared_from_this());
}

std::shared_ptr<Spacer> Spacer::height(float height) {
    height_ = height;
    return std::static_pointer_cast<Spacer>(shared_from_this());
}

float Spacer::width() const { return width_; }
float Spacer::height() const { return height_; }

} // namespace omnia
