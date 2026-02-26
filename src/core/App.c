#include "App.h"
#include "Draw.h"
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <conio.h>

int sol_run()
{
    int sel = 0; /* 0 = Yes, 1 = No */
    int chosen = -1;
    system("cls");
    sol_draw(sel);

    for (;;)
    {
        int c = _getch();

        if (c == 'q' || c == 'Q' || c == 27)
        {
            break;
        }
        else if (c == '1')
        {
            PlaySound("Test1.wav", NULL, SND_FILENAME | SND_ASYNC);
        }

        if (c == '\r' || c == 32)
        {
            chosen = sel;
        }
        if (c == 97)
        {
            sel = 0;
        }
        else if (c == 100)
        {
            sel = 1;
        }

        if (c == 0 || c == 224)
        {
            int key = _getch();
            if (key == 75)
                sel = 0;
            else if (key == 77)
                sel = 1;
        }
        switch (chosen)
        {
        case 0:
            PlaySound("assets/Test1.wav", NULL, SND_FILENAME | SND_ASYNC);
            break;
        case 1:
            PlaySound("assets/Test2.wav", NULL, SND_FILENAME | SND_ASYNC);
            break;
        }
        chosen = -1;
        sol_draw(sel);
    }
    system("cls");

    return 0;
}