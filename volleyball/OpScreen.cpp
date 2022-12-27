#include "OpScreen.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
#include<string>
const int MODE_WIDTH = 150;
const int MODE_HEIGHT = 50;

GameObject* setScore;
GameObject* setScoreDigit;
GameObject* backButton;
GameObject* warning;

OptionScreen::OptionScreen(SDL_Renderer* renderer, int& targetScore) : Screen(renderer)
{
    std::cout << "OptionScreen constructor()!" << std::endl;
    score = std::to_string(targetScore);

    setScore = new GameObject("Set Score", 100, MODE_HEIGHT, 100, 200, white);
    setScoreDigit = new GameObject(score, 50, MODE_HEIGHT, 300, 200, black);
    backButton = new GameObject("Back", 100, MODE_HEIGHT, 350, 500, white);
    warning = new GameObject("Please set scores..", 400, 100, 30, 30, white);
}

OptionScreen::~OptionScreen()
{
    std::cout << "OptionScreen deconstructor()!" << std::endl;

    delete setScore;
    delete setScoreDigit;
    delete backButton;
    delete warning;
}

void OptionScreen::handleEvents(const Uint8* keystate, bool& isOption, int& targetScore)
{
    SDL_Event event;
    SDL_WaitEvent(&event);

    switch (event.type) {
    case SDL_KEYDOWN:
        if (arrow->getYpos() == 210 && keystate[SDL_SCANCODE_BACKSPACE] && score.length() > 0)//使用者輸入要刪掉的時候
        {
            score = score.substr(0, score.length() - 1);
            setScoreDigit->setText(score, black);//setscoredigit秀出score的值然後黑色
        }
        if (arrow->getYpos() == 210 && keystate[SDL_SCANCODE_DOWN])
            arrow->setYpos(510);
        if (arrow->getYpos() == 510 && keystate[SDL_SCANCODE_UP])
            arrow->setYpos(210);
        if (arrow->getYpos() == 510 && keystate[SDL_SCANCODE_RETURN])//使用者選擇back回到上一頁
        {
            if (checkValid())
            {
                targetScore = std::stoi(score);
                isOption = false;
            }
        }
        break;

    case SDL_TEXTINPUT:
        SDL_StartTextInput();
        if (arrow->getYpos() == 210 && score.length() < 3)
        {
            score += event.text.text;
            setScoreDigit->setText(score, black);
        }
        break;
    default:
        break;
    }
}

void OptionScreen::update()
{
    if (isInitial)
    {
        arrow->setYpos(210);
        isInitial = false;
    }
    if (!isValid)
        warning->update();

    screen->update();
    arrow->update();
    setScore->update();
    setScoreDigit->update();
    backButton->update();
}

void OptionScreen::render()
{
    SDL_RenderClear(renderer);

    // this is where we put things to render
    screen->render();
    setScore->render();
    setScoreDigit->render();
    backButton->render();
    arrow->render();

    if (!isValid)
        warning->render();

    SDL_RenderPresent(renderer);
}

bool OptionScreen::checkValid()
{
    if (score == "")
    {
        isValid = false;
        return false;
    }
    else
    {
        isValid = true;
        return true;
    }
}