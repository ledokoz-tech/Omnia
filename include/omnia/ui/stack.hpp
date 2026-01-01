#pragma once

#include <omnia/view.hpp>
#include <omnia/utils/geometry.hpp>
#include <vector>
#include <memory>

namespace omnia {

enum class Alignment {
    Start,
    Center,
    End,
    Fill
};

/**
 * Vertical stack layout.
 */
class VStack : public View {
public:
    /**
     * Create a new vertical stack.
     */
    static std::shared_ptr<VStack> create();

    /**
     * Set the spacing between children.
     */
    std::shared_ptr<VStack> spacing(float spacing);

    /**
     * Set the padding around the stack.
     */
    std::shared_ptr<VStack> padding(float padding);

    /**
     * Set the padding with EdgeInsets.
     */
    std::shared_ptr<VStack> padding(const EdgeInsets& padding);

    /**
     * Set the alignment of children.
     */
    std::shared_ptr<VStack> alignment(Alignment alignment);

    /**
     * Add a child view.
     */
    std::shared_ptr<VStack> add_child(const std::shared_ptr<View>& child);

    // Getters
    float spacing() const;
    const EdgeInsets& padding() const;
    Alignment alignment() const;
    const std::vector<std::shared_ptr<View>>& children() const;

private:
    VStack();

    float spacing_ = 0.0f;
    EdgeInsets padding_;
    Alignment alignment_ = Alignment::Start;
    std::vector<std::shared_ptr<View>> children_;
};

/**
 * Horizontal stack layout.
 */
class HStack : public View {
public:
    /**
     * Create a new horizontal stack.
     */
    static std::shared_ptr<HStack> create();

    /**
     * Set the spacing between children.
     */
    std::shared_ptr<HStack> spacing(float spacing);

    /**
     * Set the padding around the stack.
     */
    std::shared_ptr<HStack> padding(float padding);

    /**
     * Set the padding with EdgeInsets.
     */
    std::shared_ptr<HStack> padding(const EdgeInsets& padding);

    /**
     * Set the alignment of children.
     */
    std::shared_ptr<HStack> alignment(Alignment alignment);

    /**
     * Add a child view.
     */
    std::shared_ptr<HStack> add_child(const std::shared_ptr<View>& child);

    // Getters
    float spacing() const;
    const EdgeInsets& padding() const;
    Alignment alignment() const;
    const std::vector<std::shared_ptr<View>>& children() const;

private:
    HStack();

    float spacing_ = 0.0f;
    EdgeInsets padding_;
    Alignment alignment_ = Alignment::Start;
    std::vector<std::shared_ptr<View>> children_;
};

} // namespace omnia
