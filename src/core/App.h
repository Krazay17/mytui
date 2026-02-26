#ifndef APP_H
#define APP_H

typedef struct {
    const char* label;
    const char* soundPath;
} MenuItem;

typedef struct {
    MenuItem* items; // Flat array of items
    int rows;
    int cols;
} Menu;

int sol_run();
void play_mp3(const char* path);

#endif