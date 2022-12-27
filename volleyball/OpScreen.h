#pragma once
#include "Screen.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
class OptionScreen : public Screen
{
private:
    std::string score;
    bool isInitial = true;
    bool isValid = true;
public:
    explicit OptionScreen(SDL_Renderer* renderer, int& targetScore);
    ~OptionScreen();
    void handleEvents(const Uint8* keystate, bool& isOption, int& targetScore);
    virtual void update() override;
    virtual void render() override;
    bool checkValid();
};