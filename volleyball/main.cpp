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
    //���Xwindow����
    game->init("Pikachu Volleyball", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAME_WIDTH, GAME_HEIGHT, false);
    
    while (game->selectingMode())//��ܳ�H���H�٦�option
    {
        game->displayStartScreen();//��ܳ�H���Hoption�������A����H�����Hissingle��ismulti�ܦ�true
        while (game->optionMode())//���option
            game->displayOptionScreen();//���targetscore
    }
    while (game->running())//�O���O�b����
    {
        frameStart = SDL_GetTicks();

        if (game->singleMode())
        {
            game->handleEvents();//�B�z�H������
            game->update();//���H�βy����m �åB�P�_�H���S������y �άO�y���S�����a �����a�Nreset �y�|�bĹ�y�����@�䱼�U��
            game->render();//�B�z�n��ܦb�ù��W���F��
            game->checkGameSet();//�P�_���S���H��Ftargetscore
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