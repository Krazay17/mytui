#include "App.h"
#include "Draw.h"
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

MenuItem items[] = {
    {"Corn", "assets/ChickenCorn.mp3"},
    {"BigWay", "assets/BigWay.mp3"},
    {"Applause", "assets/Applause.mp3"},

    {"FlashFlashAway", "assets/FlashFlashAway.mp3"},
    {"SoMuchToDo", "assets/SoMuchToDo.mp3"},
    {"IWasHiding", "assets/Twitchwashiding.mp3"},
};

Menu menu = {items, 2, 3};

int increment_limit(int x, int limit)
{
    x++;
    if (x > limit)
        return limit;
    return x;
}

int decrement_limit(int x, int limit)
{
    x--;
    if (x < limit)
        return limit;
    return x;
}

int increment_wrap(int x, int size)
{
    x++;
    if (x > size)
        return 0;
    return x;
}

int decrement_wrap(int x, int size)
{
    x--;
    if (x < 0)
        return size;
    return x;
}

void play_mp3(const char* path) {
    char command[256];
    
    // 1. Close any previous file using this alias to prevent overlaps
    mciSendStringA("close mp3_alias", NULL, 0, NULL);
    
    // 2. Open the new file
    // Note: We use "type mpegvideo" even for audio; it's just how the old driver works
    sprintf(command, "open \"%s\" type mpegvideo alias mp3_alias", path);
    mciSendStringA(command, NULL, 0, NULL);
    
    // 3. Play it
    mciSendStringA("play mp3_alias", NULL, 0, NULL);
}

int sol_run()
{
    int selX = 0;
    int selY = 0;
    int sizeX = menu.cols - 1;
    int sizeY = menu.rows - 1;

    system("cls");
    printf("---- Soundboard: q to quit ----");
    sol_draw(&menu, selX, selY);

    for (;;)
    {
        int c = _getch();

        if (c == 'q' || c == 'Q' || c == 27)
        {
            break;
        }

        if (c == '\r' || c == 32)
        {
            int index = (selY * menu.cols) + selX;
            MenuItem selected = menu.items[index];

            if (selected.soundPath != NULL)
            {
                play_mp3(selected.soundPath);
                //PlaySoundA(selected.soundPath, NULL, SND_FILENAME | SND_ASYNC);
            }
        }

        if (c == 'd')
            selX = increment_wrap(selX, sizeX);
        else if (c == 'a')
            selX = decrement_wrap(selX, sizeX);
        else if (c == 's')
            selY = increment_wrap(selY, sizeY);
        else if (c == 'w')
            selY = decrement_wrap(selY, sizeY);

        if (c == 0 || c == 224)
        {
            int key = _getch();

            if (key == 77)
                selX = increment_wrap(selX, sizeX);
            else if (key == 75)
                selX = decrement_wrap(selX, sizeX);
            else if (key == 80)
                selY = increment_wrap(selY, sizeY);
            else if (key == 72)
                selY = decrement_wrap(selY, sizeY);
        }

        sol_draw(&menu, selX, selY);
    }

    mciSendStringA("close all", NULL, 0, NULL);

    return 0;
}