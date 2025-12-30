#include "Utils.hpp"

void darkenColor(SDL_Color* color, double factor)
{
    color->r = static_cast<Uint8>(color->r * factor);
    color->g = static_cast<Uint8>(color->g * factor);
    color->b = static_cast<Uint8>(color->b * factor);
}