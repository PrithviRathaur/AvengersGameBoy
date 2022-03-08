#ifndef DRAW_H
#define DRAW_H

#include "logic.h"

// This function will be used to draw everything about the state of your app
// including the background and whatnot.
void fullDrawAppState(AppState *state);

// This function will be used to undraw (i.e. erase) things that might
void undrawAppState(AppState *state);

// This function will be used to draw things that might have moved in a frame.
void drawAppState(AppState *state);

void drawBorder(AppState* state);
void drawWin(AppState* state);
void drawLose(AppState* state);

#endif
