#pragma once

#include <memory>

namespace omnia {

/**
 * Base class for all UI components/views.
 */
class View {
public:
    View() = default;
    virtual ~View() = default;

    /**
     * Build the view. Subclasses should override this method.
     * Returns a view that can be displayed.
     */
    virtual std::shared_ptr<View> build() { return std::shared_ptr<View>(this); }

protected:
    /**
     * Get a shared pointer to this view (for subclasses that properly manage lifetime).
     * This is a helper for subclasses that inherit from enable_shared_from_this.
     */
    virtual std::shared_ptr<View> shared_from_this() {
        return std::shared_ptr<View>(this);
    }
};

} // namespace omnia
