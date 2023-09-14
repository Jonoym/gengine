#include <utils/Vector2D.h>

namespace Gengine
{
    Vector2D::Vector2D()
        : x(0.0f), y(0.0f)
    {
    }

    Vector2D::Vector2D(float xCoord, float yCoord)
        : x(xCoord), y(yCoord)
    {
    }

    Vector2D::Vector2D(const Vector2D &vector)
        : x(vector.x), y(vector.y)
    {
    }

    Vector2D &Vector2D::operator=(const Vector2D &other)
    {
        if (this != &other)
        {
            this->x = other.x;
            this->y = other.y;
        }

        return *this;
    }

    bool Vector2D::operator==(const Vector2D &other)
    {
        return (x == other.x) && (y == other.y);
    }

    Vector2D Vector2D::operator+(const Vector2D &other)
    {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D Vector2D::operator-(const Vector2D &other)
    {
        return Vector2D(x - other.x, y - other.y);
    }
}