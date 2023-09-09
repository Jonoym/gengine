#include <vector>

#include "../entities/Entity.h"

class IArea {

    public:

        IArea() {};
        ~IArea() {};

        void addEntity();

    private:

        std::vector<Entity> vector;
};