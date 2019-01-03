#include "application.h"
#include "pong.h"
#include <GL/gl.h>

const Uint8 *keyboard_state;

Pong_Paddle paddle_1, paddle_2;
Pong_Plane plane[4];
Pong_Ball ball;

void Application_Initialise()
{
    keyboard_state = SDL_GetKeyboardState(NULL);

    Pong_Paddle_Initialise(&paddle_1, 300, 100);
    Pong_Paddle_Initialise(&paddle_2, 300, 900);

    plane[0].normal.x = 0.0f;
    plane[0].normal.y = -1.0f;
    plane[0].offset = 1000.0f;


    plane[1].normal.x = 0.0f;
    plane[1].normal.y = 1.0f;
    plane[1].offset = 0.0f;

    plane[2].normal.x = -1.0f;
    plane[2].normal.y = 0.0f;
    plane[2].offset = 600.0f;

    plane[3].normal.x = 1.0f;
    plane[3].normal.y = 0.0f;
    plane[3].offset = 0.0f;

    Pong_Ball_Initialise(&ball);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, WINDOW_W, WINDOW_H, 0.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Application_Cleanup()
{

}

void Application_TimeStep()
{
    if(keyboard_state[SDL_SCANCODE_LEFT])
        paddle_1.state = Pong_PaddleState_Left;
    else if(keyboard_state[SDL_SCANCODE_RIGHT])
        paddle_1.state = Pong_PaddleState_Right;
    else
        paddle_1.state = Pong_PaddleState_Still;

    if(keyboard_state[SDL_SCANCODE_A])
        paddle_2.state = Pong_PaddleState_Left;
    else if(keyboard_state[SDL_SCANCODE_D])
        paddle_2.state = Pong_PaddleState_Right;
    else
        paddle_2.state = Pong_PaddleState_Still;

    Pong_Paddle_TimeStep(&paddle_1);
    Pong_Paddle_TimeStep(&paddle_2);

    Pong_Ball_TimeStep(&ball);

    for(size_t i = 0; i < 4; i++)
    {
        Pong_Plane_Collide(plane + i, &ball);
    }

    Pong_Paddle_Collide(&paddle_1, &ball);
    Pong_Paddle_Collide(&paddle_2, &ball);
}

void Application_DrawFrame()
{
    Pong_Paddle_Draw(&paddle_1);
    Pong_Paddle_Draw(&paddle_2);
    Pong_Ball_Draw(&ball);
}

void Application_HandleKeyPress(const SDL_KeyboardEvent *event)
{

}

void Application_HandleKeyRelease(const SDL_KeyboardEvent *event)
{

}
