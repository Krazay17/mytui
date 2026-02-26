#include "Draw.h"
#include "App.h"
#include <stdio.h>
#include <windows.h>

void sol_draw(Menu *menu, int selX, int selY)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, (COORD){0, 2});

    for (int y = 0; y < menu->rows; y++)
    {
        printf("  ");
        for (int x = 0; x < menu->cols; x++)
        {
            int index = (y * menu->cols) + x;
            MenuItem item = menu->items[index];

            if (x == selX && y == selY)
            {
                // Highlighted
                printf("\033[42m[ %-8s ]\033[0m  ", item.label);
            }
            else
            {
                printf("[ %-8s ]  ", item.label);
            }
        }
        printf("\n\n");
    }
}