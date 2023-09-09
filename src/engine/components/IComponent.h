#pragma once

class IComponent {

public:
    virtual ~IComponent() {}
    virtual void update() {}
    virtual void dispose() {}

    virtual bool operator==(const IComponent& other) {
        // Default implementation can be provided here or left empty
        // Derived classes can override this function.
        return this == &other;
    }
};