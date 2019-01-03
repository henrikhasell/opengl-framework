#ifndef PONG_H
#define PONG_H

#include <GL/gl.h>
#include "vector.h"

#define PONG_COURT_W 600
#define PONG_COURT_H 1000
#define PONG_PADDLE_W 180
#define PONG_PADDLE_H 20
#define PONG_PADDLE_SPEED 10.0f

#define PONG_BALL_RADIUS 17.0f
#define PONG_BALL_SPEED 7.0f

typedef enum Pong_PaddleState {
    Pong_PaddleState_Still,
    Pong_PaddleState_Left,
    Pong_PaddleState_Right
}Pong_PaddleState;

typedef struct Pong_Paddle {
    Vector position;
    Pong_PaddleState state;
}Pong_Paddle;

typedef struct Pong_Ball {
    Vector position;
    Vector velocity;
    float angle;
}Pong_Ball;

typedef struct Pong_Plane {
    Vector normal;
    float offset;
}Pong_Plane;

void Pong_Plane_Collide(const Pong_Plane *plane, Pong_Ball *ball);

void Pong_Ball_Initialise(Pong_Ball *ball);

void Pong_Ball_TimeStep(Pong_Ball *ball);

void Pong_Ball_Draw(const Pong_Ball *ball);

void Pong_Paddle_Initialise(Pong_Paddle *paddle, float x, float y);

void Pong_Paddle_Collide(const Pong_Paddle *paddle, Pong_Ball *ball);

void Pong_Paddle_TimeStep(Pong_Paddle *paddle);

void Pong_Paddle_Draw(const Pong_Paddle *paddle);

void Pong_DrawPaddle(GLfloat x, GLfloat y, GLfloat w, GLfloat h);

#endif
