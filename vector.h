#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    float x;
    float y;
}Vector;

Vector Vector_Add(const Vector *left, const Vector *right);

Vector Vector_Subtract(const Vector *left, const Vector *right);

Vector Vector_Multiply(const Vector *left, const Vector *right);

Vector Vector_Divide(const Vector *left, const Vector *right);

Vector Vector_AddScalar(const Vector *left, float right);

Vector Vector_SubtractScalar(const Vector *left, float right);

Vector Vector_MultiplyScalar(const Vector *left, float right);

Vector Vector_DivideScalar(const Vector *left, float right);

Vector Vector_Reflect(const Vector *vector, const Vector *normal);

Vector Vector_Normalise(const Vector *vector);

Vector Vector_Normal(const Vector *vector);

float Vector_DotProduct(const Vector *left, const Vector *right);

float Vector_Magnitude(const Vector *vector);

#endif
