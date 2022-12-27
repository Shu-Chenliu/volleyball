#include <cstdlib>
#include <ctime>
#include "volleyball.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
using namespace std;
const int GAME_WIDTH = 800, GAME_HEIGHT = 600;
// FPS
const int FPS = 60;
const int frameDelay = 1000 / FPS;
Uint32 frameStart;
int frameTime;

int main()
{
    // random setting for AI
    //srand((unsigned int)time(NULL));

    Game* game = new Game();
    //跳出window視窗
    game->init("Pikachu Volleyball", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAME_WIDTH, GAME_HEIGHT, false);
    
    while (game->selectingMode())//選擇單人雙人還有option
    {
        game->displayStartScreen();//選擇單人雙人option的頁面，選到單人或雙人issingle或ismulti變成true
        while (game->optionMode())//選到option
            game->displayOptionScreen();//選擇targetscore
    }
    while (game->running())//是不是在執行
    {
        frameStart = SDL_GetTicks();

        if (game->singleMode())
        {
            game->handleEvents();//處理人的移動
            game->update();//更改人及球的位置 並且判斷人有沒有打到球 或是球有沒有落地 有落地就reset 球會在贏球的那一邊掉下來
            game->render();//處理要顯示在螢幕上的東西
            game->checkGameSet();//判斷有沒有人到達targetscore
        }
        if (game->multiMode())
        {
            while (game->settingMultiplay())
            {
                game->displayMultiplaySettingScreen();
            }
            game->handleEvents();
            game->update();
            game->render();
            game->checkGameSet();
        }

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    game->clean();
    return 0;
}