#pragma once
#include "volleyball.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
class GameObject
{
protected:
    int width;
    int height;
    float xpos;
    float ypos;
    float radius=50;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;

public:
    GameObject(const std::string textureSheet, int w, int h, int x, int y); // for general
    GameObject(int score, int w, int h, int x, int y); // for scores
    GameObject(const char* text, int w, int h, int x, int y); // for texts (red)
    GameObject(const std::string text, int w, int h, int x, int y, SDL_Color& textColor); // for texts (other color)
    GameObject(const char* textureSheet, int w, int h, int x, int y, const std::string& _flag); // for imgs
    virtual ~GameObject();

    // getters
    float getXpos();
    float getYpos();
    // setters
    void setXpos(float x);
    void setYpos(float y);
    void setText(const std::string& text, SDL_Color& textColor);

    virtual void update();
    void update(int score);
    void render();
};