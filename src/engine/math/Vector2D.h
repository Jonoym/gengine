#pragma once

#include <string>

class Vector2D {

public:

    float x;
    float y;

    Vector2D();
    ~Vector2D();

    Vector2D(float xCoord, float yCoord);
    Vector2D(const Vector2D& vector);
    Vector2D& operator= (const Vector2D& other);

    bool operator== (const Vector2D& other);
    Vector2D operator+ (const Vector2D& other);
    Vector2D operator- (const Vector2D& other);

    std::string toString();
};