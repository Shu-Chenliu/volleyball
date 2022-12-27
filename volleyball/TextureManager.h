#pragma once
#include "volleyball.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
class TextureManager
{
private:
public:
    static SDL_Texture* loadTexture(const std::string& fileName);
    static SDL_Texture* loadFont(const std::string& text);
    static SDL_Texture* loadFont(const std::string& text, SDL_Color& textColor);
};