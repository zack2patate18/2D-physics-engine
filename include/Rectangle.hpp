#include <SDL2/SDL.h>
#include <cstring>
#include "Utils.hpp"

class Rectangle
{
public:
    double x;
    double y;
    double width;
    double height;
    int r;
    int g;
    int b;
    int br;
    int bg;
    int bb;
    char name[64];
    bool shown;
    bool enabled;

    const char type[5] = "Rect";

    SDL_Renderer *renderer;

    Rectangle(double x_, double y_, float width_, float height_, SDL_Color color_, char name_[64], double gravity_, SDL_Renderer *renderer_, bool shown_ = true, bool enabled_ = true, SDL_Color backgroundColor_ = {0, 0, 0, 255}, double airResistance_ = 0);

    void display();
};