#include <SDL2/SDL.h>
#include <cstring>
#include "Utils.hpp"

class Ball
{
public:
    double x;
    double y;
    float radius;
    int r;
    int g;
    int b;
    int br;
    int bg;
    int bb;
    char name[64];
    double gravity;
    bool shown;
    bool enabled;
    double airResistance;

    double ySpeed = 0;
    double xSpeed = 0;
    double xVelocity = 0;
    double yVelocity = 0;
    double restitution = 0.68; // 0.68
    bool touching = false;

    const char type[5] = "Ball";

    SDL_Renderer *renderer;

    Ball(double x_, double y_, float radius_, SDL_Color color_, char name_[64], double gravity_, SDL_Renderer *renderer_, bool shown_ = true, bool enabled_ = true, SDL_Color backgroundColor_ = {0, 0, 0, 255}, double airResistance_ = 0);

    void display();

    void update(double deltaTime);

    void applyXvelocity(int intensity);

    void applyYvelocity(int intensity);
};