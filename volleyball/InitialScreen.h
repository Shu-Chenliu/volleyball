#pragma once
#include "Screen.h"
#include "SDL.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
class StartScreen : public Screen
{
public:
    explicit StartScreen(SDL_Renderer* _renderer);
    ~StartScreen();
    virtual void handleEvents(const Uint8*& keystate, bool& isSelecting, bool& isSingle, bool& isMulti, bool& isOption);
    virtual void update() override;
    virtual void render() override;
};