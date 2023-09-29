#include <utils/Vector2D.h>

#include <core/Logger.h>

namespace Gengine
{
    const Vector2D Vector2D::ZERO(0.0f, 0.0f);
    const Vector2D Vector2D::LEFT(-1.0f, 0.0f);
    const Vector2D Vector2D::RIGHT(1.0f, 0.0f);
    const Vector2D Vector2D::UP(0.0f, -1.0f);
    const Vector2D Vector2D::DOWN(0.0f, 1.0f);

    Vector2D::Vector2D()
        : mX(0.0f), mY(0.0f)
    {
    }

    Vector2D::Vector2D(int32 xCoord, int32 yCoord)
        : mX(static_cast<float32>(xCoord)), mY(static_cast<float32>(yCoord))
    {
    }

    Vector2D::Vector2D(float32 xCoord, float32 yCoord)
        : mX(xCoord), mY(yCoord)
    {
    }

    Vector2D::Vector2D(const Vector2D &vector)
        : mX(vector.mX), mY(vector.mY)
    {
    }

    Vector2D& Vector2D::operator+=(const Vector2D &other)
    {
        this->mX += other.mX;
        this->mY += other.mY;

        return *this;
    }

    Vector2D& Vector2D::operator-=(const Vector2D &other)
    {
        this->mX -= other.mX;
        this->mY -= other.mY;

        return *this;
    }

    Vector2D &Vector2D::operator=(const Vector2D &other)
    {
        if (this != &other)
        {
            this->mX = other.mX;
            this->mY = other.mY;
        }

        return *this;
    }

    bool Vector2D::operator==(const Vector2D &other) const
    {
        return (mX == other.mX) && (mY == other.mY);
    }

    Vector2D Vector2D::operator+(const Vector2D &other) const
    {
        return Vector2D(mX + other.mX, mY + other.mY);
    }

    Vector2D Vector2D::operator*(const Vector2D &other) const
    {
        return Vector2D(mX * other.mX, mY * other.mY);
    }

    Vector2D Vector2D::operator*(float32 scalar) const 
    {
        return Vector2D(mX * scalar, mY * scalar);
    }

    Vector2D Vector2D::operator/(float32 scalar) const
    {
        return Vector2D(mX / scalar, mY / scalar);
    }

    Vector2D Vector2D::operator-(const Vector2D &other) const
    {
        return Vector2D(mX - other.mX, mY - other.mY);
    }

    const float32 Vector2D::Length() const
    {
        return std::sqrt(mX * mX + mY * mY);
    }

    const Vector2D Vector2D::Normalise() const
    {
        return Vector2D(mX / Length(), mY / Length());
    }

}