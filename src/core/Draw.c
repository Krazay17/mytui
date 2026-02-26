#include "Draw.h"
#include <stdio.h>
#include <windows.h>

void sol_draw(int sel)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    /* build frame in memory */
    char buf[256];
    int len = sprintf(buf,
                      "  Make your choice:\n\n"
                      "  %s[ Chicken and Corn ]%s"
                      "   "
                      "%s[ Whip ]%s"
                      "\n\n  q: quit\n",
                      sel == 0 ? "\033[42m" : "", sel == 0 ? "\033[0m" : "",
                      sel == 1 ? "\033[7m" : "", sel == 1 ? "\033[0m" : "");

    /* move cursor home, then overwrite in one call — no clearing */
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
    DWORD written;
    WriteConsoleA(h, buf, len, &written, NULL);
}