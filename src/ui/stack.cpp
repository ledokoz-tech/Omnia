#include <omnia/ui/stack.hpp>

namespace omnia {

// VStack implementation
std::shared_ptr<VStack> VStack::create() {
    return std::shared_ptr<VStack>(new VStack());
}

VStack::VStack() = default;

VStack& VStack::spacing(float spacing) {
    spacing_ = spacing;
    return *this;
}

VStack& VStack::padding(float padding) {
    padding_ = EdgeInsets::all(padding);
    return *this;
}

VStack& VStack::padding(const EdgeInsets& padding) {
    padding_ = padding;
    return *this;
}

VStack& VStack::alignment(Alignment alignment) {
    alignment_ = alignment;
    return *this;
}

VStack& VStack::add_child(const std::shared_ptr<View>& child) {
    children_.push_back(child);
    return *this;
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

HStack& HStack::spacing(float spacing) {
    spacing_ = spacing;
    return *this;
}

HStack& HStack::padding(float padding) {
    padding_ = EdgeInsets::all(padding);
    return *this;
}

HStack& HStack::padding(const EdgeInsets& padding) {
    padding_ = padding;
    return *this;
}

HStack& HStack::alignment(Alignment alignment) {
    alignment_ = alignment;
    return *this;
}

HStack& HStack::add_child(const std::shared_ptr<View>& child) {
    children_.push_back(child);
    return *this;
}

float HStack::spacing() const { return spacing_; }
const EdgeInsets& HStack::padding() const { return padding_; }
Alignment HStack::alignment() const { return alignment_; }
const std::vector<std::shared_ptr<View>>& HStack::children() const { return children_; }

} // namespace omnia
