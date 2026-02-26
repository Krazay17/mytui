#include <windows.h>

typedef struct {
    int up;
    int down;
    int left;
    int right;
    int confirm;
    int quit;
} Input;

Input sol_input_poll(void) {
    Input input = {0};
    input.up      = (GetAsyncKeyState('W')      & 0x8000) || (GetAsyncKeyState(VK_UP)    & 0x8000);
    input.down    = (GetAsyncKeyState('S')      & 0x8000) || (GetAsyncKeyState(VK_DOWN)  & 0x8000);
    input.left    = (GetAsyncKeyState('A')      & 0x8000) || (GetAsyncKeyState(VK_LEFT)  & 0x8000);
    input.right   = (GetAsyncKeyState('D')      & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8000);
    input.confirm = (GetAsyncKeyState(VK_RETURN) & 0x8000) || (GetAsyncKeyState(VK_SPACE) & 0x8000);
    input.quit    = (GetAsyncKeyState('Q')      & 0x8000) || (GetAsyncKeyState(VK_ESCAPE) & 0x8000);
    return input;
}