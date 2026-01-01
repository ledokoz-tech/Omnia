#pragma once

#include <memory>

namespace omnia {

/**
 * Base class for all UI components/views.
 */
class View : public std::enable_shared_from_this<View> {
public:
    View() = default;
    virtual ~View() = default;

    /**
     * Build the view. Subclasses should override this method.
     * Returns a view that can be displayed.
     */
    virtual std::shared_ptr<View> build() { return shared_from_this(); }

protected:
    using std::enable_shared_from_this<View>::shared_from_this;
};

} // namespace omnia
