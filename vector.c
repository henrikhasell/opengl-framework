#include "vector.h"
#include <math.h>

Vector Vector_Add(const Vector *left, const Vector *right)
{
    Vector result = {
        left->x + right->x,
        left->y + right->y
    };
    return result;
}

Vector Vector_Subtract(const Vector *left, const Vector *right)
{
    Vector result = {
        left->x - right->x,
        left->y - right->y
    };
    return result;
}

Vector Vector_Multiply(const Vector *left, const Vector *right)
{
    Vector result = {
        left->x * right->x,
        left->y * right->y
    };
    return result;
}

Vector Vector_Divide(const Vector *left, const Vector *right)
{
    Vector result = {
        left->x / right->x,
        left->y / right->y
    };
    return result;
}

Vector Vector_AddScalar(const Vector *left, float right)
{
    Vector result = {
        left->x + right,
        left->y + right
    };
    return result;
}

Vector Vector_SubtractScalar(const Vector *left, float right)
{
    Vector result = {
        left->x - right,
        left->y - right
    };
    return result;
}

Vector Vector_MultiplyScalar(const Vector *left, float right)
{
    Vector result = {
        left->x * right,
        left->y * right
    };
    return result;
}

Vector Vector_DivideScalar(const Vector *left, float right)
{
    Vector result = {
        left->x / right,
        left->y / right
    };
    return result;
}

Vector Vector_Reflect(const Vector *vector, const Vector *normal)
{
    Vector a;
    Vector b;

    a = Vector_Normalise(vector);
    b = Vector_MultiplyScalar(normal, 2);
    b = Vector_Add(&a, &b);
    b = Vector_Normalise(&b);

    return b;
    
}

Vector Vector_Normalise(const Vector *vector)
{
    float magnitude = Vector_Magnitude(vector);
    return Vector_DivideScalar(vector, magnitude);
}

Vector Vector_Normal(const Vector *vector)
{
    Vector result = {
        -vector->y,
	+vector->x
    };
    return result;
}

float Vector_DotProduct(const Vector *left, const Vector *right)
{
    return left->x * right->x + left->y * right->y; 
}

float Vector_Magnitude(const Vector *vector)
{
    return sqrtf(vector->x * vector->x + vector->y * vector->y);
}

