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
    virtual std::shared_ptr<View> build() { return shared_from_this(); }

protected:
    /**
     * Get a shared pointer to this view.
     */
    std::shared_ptr<View> shared_from_this() {
        return std::static_pointer_cast<View>(std::shared_from_this());
    }
};

} // namespace omnia
