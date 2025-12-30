#include "circle.hpp"
#include "Ball.hpp"
#include <cstring>

Ball::Ball(double x_, double y_, float radius_, SDL_Color color_, char name_[64], double gravity_, SDL_Renderer *renderer_, bool shown_, bool enabled_, SDL_Color backgroundColor_, double airResistance_)
{
  x = x_;
  y = y_;
  radius = radius_;
  r = color_.r;
  g = color_.g;
  b = color_.b;
  br = backgroundColor_.r;
  bg = backgroundColor_.g;
  bb = backgroundColor_.b;
  strcpy(name, name_);
  gravity = gravity_;
  shown = shown_;
  enabled = enabled_;
  airResistance = airResistance_;

  renderer = renderer_;
}

void Ball::display()
{
  if (enabled && shown) {
    SDL_Color shadowColor = {br, bg, bb, 255};
    darkenColor(&shadowColor, 0.6);
    SDL_SetRenderDrawColor(renderer, shadowColor.r, shadowColor.g, shadowColor.b, 255);
    SDL_RenderFillCircle(renderer, x + 3, y + 3, radius);
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillCircle(renderer, x, y, radius);
  }
}

void Ball::update(double deltaTime)
{
  yVelocity += gravity;

  if (y + radius >= 600)
  {
    y = 600 - radius;
    yVelocity = -yVelocity * restitution;
  }

  if (y - radius <= 0)
  {
    y = 0 + radius;
    yVelocity = -yVelocity * restitution;
  }

  if (x + radius >= 800)
  {
    x = 800 - radius;
    xVelocity = -xVelocity * restitution;
  }

  if (x - radius <= 0)
  {
    x = 0 + radius;
    xVelocity = -xVelocity * restitution;
  }

  x += (xVelocity * deltaTime * airResistance);
  y += (yVelocity * deltaTime * airResistance);
}

void Ball::applyXvelocity(int intensity)
{
  xVelocity += intensity;
}

void Ball::applyYvelocity(int intensity)
{
  yVelocity += intensity;
}