#include <omnia/ui/stack.hpp>

namespace omnia {

// VStack implementation
std::shared_ptr<VStack> VStack::create() {
    return std::shared_ptr<VStack>(new VStack());
}

VStack::VStack() = default;

std::shared_ptr<VStack> VStack::spacing(float spacing) {
    spacing_ = spacing;
    return std::static_pointer_cast<VStack>(shared_from_this());
}

std::shared_ptr<VStack> VStack::padding(float padding) {
    padding_ = EdgeInsets::all(padding);
    return std::static_pointer_cast<VStack>(shared_from_this());
}

std::shared_ptr<VStack> VStack::padding(const EdgeInsets& padding) {
    padding_ = padding;
    return std::static_pointer_cast<VStack>(shared_from_this());
}

std::shared_ptr<VStack> VStack::alignment(Alignment alignment) {
    alignment_ = alignment;
    return std::static_pointer_cast<VStack>(shared_from_this());
}

std::shared_ptr<VStack> VStack::add_child(const std::shared_ptr<View>& child) {
    children_.push_back(child);
    return std::static_pointer_cast<VStack>(shared_from_this());
}

float VStack::spacing() const { return spacing_; }
const EdgeInsets& VStack::padding() const { return padding_; }
Alignment VStack::alignment() const { return alignment_; }
const std::vector<std::shared_ptr<View>>& VStack::children() const { return children_; }

// HStack implementation
std::shared_ptr<HStack> HStack::create() {
    return std::shared_ptr<HStack>(new HStack());
}

HStack::HStack() = default;

std::shared_ptr<HStack> HStack::spacing(float spacing) {
    spacing_ = spacing;
    return std::static_pointer_cast<HStack>(shared_from_this());
}

std::shared_ptr<HStack> HStack::padding(float padding) {
    padding_ = EdgeInsets::all(padding);
    return std::static_pointer_cast<HStack>(shared_from_this());
}

std::shared_ptr<HStack> HStack::padding(const EdgeInsets& padding) {
    padding_ = padding;
    return std::static_pointer_cast<HStack>(shared_from_this());
}

std::shared_ptr<HStack> HStack::alignment(Alignment alignment) {
    alignment_ = alignment;
    return std::static_pointer_cast<HStack>(shared_from_this());
}

std::shared_ptr<HStack> HStack::add_child(const std::shared_ptr<View>& child) {
    children_.push_back(child);
    return std::static_pointer_cast<HStack>(shared_from_this());
}

float HStack::spacing() const { return spacing_; }
const EdgeInsets& HStack::padding() const { return padding_; }
Alignment HStack::alignment() const { return alignment_; }
const std::vector<std::shared_ptr<View>>& HStack::children() const { return children_; }

} // namespace omnia
