#include "pong.h"
#include <math.h>

void Pong_Plane_Collide(const Pong_Plane *plane, Pong_Ball *ball)
{
    float dot = Vector_DotProduct(&plane->normal, &ball->position);

    if(dot + plane->offset < PONG_BALL_RADIUS)
    {
        ball->velocity = Vector_Reflect(&ball->velocity, &plane->normal);
        ball->velocity = Vector_MultiplyScalar(&ball->velocity, PONG_BALL_SPEED);
    }
}

void Pong_Ball_Initialise(Pong_Ball *ball)
{
    ball->position.x = 300.0f;
    ball->position.y = 300.0f;

    ball->velocity.x = 0.0f;
    ball->velocity.y = PONG_BALL_SPEED;
}

void Pong_Ball_TimeStep(Pong_Ball *ball)
{
    ball->position = Vector_Add(
        &ball->position,
        &ball->velocity
    );
}

void Pong_Ball_Draw(const Pong_Ball *ball)
{
    glPushMatrix();

    glTranslatef(
        ball->position.x,
        ball->position.y,
        0.0f
    );

    glScalef(PONG_BALL_RADIUS, PONG_BALL_RADIUS, 1.0f);
    glBegin(GL_TRIANGLE_FAN);

    for(float i = 0; i < M_PI * 2; i += 0.3f)
    {
        glVertex2f(
            cosf(i),
            sinf(i)
        );
    }

    glEnd();
    glPopMatrix();
}

void Pong_Paddle_Initialise(Pong_Paddle *paddle, float x, float y)
{
    paddle->state = Pong_PaddleState_Still;
    paddle->position.x = x;
    paddle->position.y = y;
}

void Pong_Paddle_Collide(const Pong_Paddle *paddle, Pong_Ball *ball)
{
    const float x_min = paddle->position.x - (PONG_PADDLE_W / 2.0f);
    const float x_max = paddle->position.x + (PONG_PADDLE_W / 2.0f);
    const float y_min = paddle->position.y - (PONG_PADDLE_H / 2.0f);
    const float y_max = paddle->position.y + (PONG_PADDLE_H / 2.0f);

    const Vector closest_point = {
        ball->position.x < x_min ? x_min : ball->position.x > x_max ? x_max : ball->position.x,
        ball->position.y < y_min ? y_min : ball->position.y > y_max ? y_max : ball->position.y
    };

    Vector direction;
   
    direction = Vector_Subtract(&ball->position, &closest_point);
    const float distance = Vector_Magnitude(&direction);

    if(distance <= 0.0f)
    {
        return;
    }

    if(distance < PONG_BALL_RADIUS)
    {
        direction.y /= 25.0f;
        direction = Vector_Normalise(&direction);

	const Vector push_back = Vector_MultiplyScalar(
            &direction,
            (PONG_BALL_RADIUS - distance)
        );

        ball->velocity = Vector_Subtract(
	    &ball->position,
	    &paddle->position
	);

	ball->velocity = Vector_Normalise(&ball->velocity);
	ball->velocity = Vector_MultiplyScalar(&ball->velocity, PONG_BALL_SPEED);
        ball->position = Vector_Add(&ball->position, &push_back);
    }
}

void Pong_Paddle_TimeStep(Pong_Paddle *paddle)
{
    if(paddle->state == Pong_PaddleState_Left)
    {
        if(paddle->position.x - PONG_PADDLE_SPEED > (PONG_PADDLE_W / 2.0f))
	{
            paddle->position.x -= PONG_PADDLE_SPEED;
	}
	else
	{
            paddle->position.x = (PONG_PADDLE_W / 2.0f);
	}
    }
    else if(paddle->state == Pong_PaddleState_Right)
    {
        if(paddle->position.x + PONG_PADDLE_SPEED + (PONG_PADDLE_W / 2.0f) < PONG_COURT_W)
	{
            paddle->position.x += PONG_PADDLE_SPEED;
	}
	else
	{
            paddle->position.x = PONG_COURT_W - (PONG_PADDLE_W / 2.0f);
	}
    }
}

void Pong_Paddle_Draw(const Pong_Paddle *paddle)
{
    glPushMatrix();

    glTranslatef(
        paddle->position.x - (PONG_PADDLE_W / 2.0f),
        paddle->position.y - (PONG_PADDLE_H / 2.0f), 0.0f
    );

    glBegin(GL_TRIANGLE_STRIP);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(PONG_PADDLE_W, 0.0f);
    glVertex2f(0.0f, PONG_PADDLE_H);
    glVertex2f(PONG_PADDLE_W, PONG_PADDLE_H);

    glEnd();
    glPopMatrix();
}

void Pong_DrawPaddle(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
    glPushMatrix();
    glTranslatef(x - w / 2.0f, y - h / 2.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(w, 0.0f);
    glVertex2f(w, h);
    glVertex2f(0.0f, h);
    glEnd();
    glPopMatrix();
}
