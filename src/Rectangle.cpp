#include "Rectangle.hpp"
#include <cstring>

Rectangle::Rectangle(double x_, double y_, float width_, float height_, SDL_Color color_, char name_[64], double gravity_, SDL_Renderer *renderer_, bool shown_, bool enabled_, SDL_Color backgroundColor_, double airResistance_)
{
  x = x_;
  y = y_;
  width = width_;
  height = height_;
  r = color_.r;
  g = color_.g;
  b = color_.b;
  br = backgroundColor_.r;
  bg = backgroundColor_.g;
  bb = backgroundColor_.b;
  strcpy(name, name_);
  shown = shown_;
  enabled = enabled_;

  renderer = renderer_;
}

void Rectangle::display()
{
  /* if (enabled && shown) {
    SDL_Color shadowColor = {br, bg, bb, 255};
    darkenColor(&shadowColor, 0.6);
    SDL_SetRenderDrawColor(renderer, shadowColor.r, shadowColor.g, shadowColor.b, 255);
    SDL_RenderFillCircle(renderer, x + 3, y + 3, radius);
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillCircle(renderer, x, y, radius);
  } */

  if (enabled && shown) {
    SDL_Color shadowColor = {br, bg, bb, 255};
    darkenColor(&shadowColor, 0.6);
    SDL_SetRenderDrawColor(renderer, shadowColor.r, shadowColor.g, shadowColor.b, 255);
    SDL_Rect shadowRect = {static_cast<int>(x) + 3, static_cast<int>(y) + 3, static_cast<int>(width), static_cast<int>(height)};
    SDL_RenderFillRect(renderer, &shadowRect);
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect rect = {static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height)};
    SDL_RenderFillRect(renderer, &rect);
  }
}