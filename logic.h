#ifndef LOGIC_H
#define LOGIC_H

#include "gba.h"
#include "images/infinityGauntlet.h"
#include "images/thanos.h"
#include "images/ironman.h"
#include "images/hulk.h"
#include "images/thor.h"
#include "images/captainamerica.h"
#include "images/blackwidow.h"
#include "images/spiderman.h"
#include "images/blackpanther.h"
#include "images/drStrange.h"
#include "images/winScreen.h"
#include "images/loseScreen.h"

typedef struct {
    int row;
    int col;
    int move;
} Thanos;

typedef struct {
    int row;
    int col;
} Gauntlet;

typedef struct {
    int row;
    int col;
    int move;
} Ironman;

typedef struct {
    int row;
    int col;
    int move;
} Hulk;

typedef struct {
    int row;
    int col;
    int move;
} Thor;

typedef struct {
    int row;
    int col;
    int move;
} CaptainAmerica;

typedef struct {
    int row;
    int col;
    int move;
} BlackWidow;

typedef struct {
    int row;
    int col;
    int move;
} Spiderman;

typedef struct {
    int row;
    int col;
    int move;
} DrStrange;

typedef struct {
    int row;
    int col;
    int move;
} BlackPanther;

typedef struct {
    // Store whether or not the game is over in this member:
    int gameOver;
    int win;
    char* winString;
    char* winString2;
    char* loseString;
    char* replayString;
    Thanos thanosObject;
    Gauntlet gauntletObject;
    Ironman ironmanObject;
    Hulk hulkObject;
    Thor thorObject;
    CaptainAmerica captainAmericaObject;
    BlackPanther blackPantherObject;
    BlackWidow blackWidowObject;
    DrStrange drStrangeObject;
    Spiderman spidermanObject;



    /*
    * TA-TODO: Add any logical elements you need to keep track of in your app.
    *
    * For example, for a Snake game, those could be:
    *
    * Snake snake;
    * Food foods[10];
    * int points;
    *
    */

} AppState;

/*
* TA-TODO: Add any additional structs that you need for your app.
*
* For example, for a Snake game, one could be:
*
* typedef struct {
*   int heading;
*   int length;
*   int x;
*   int y;
* } Snake;
*
*/

// This function can initialize an unused AppState struct.
void initializeAppState(AppState *appState);

// This function will be used to process app frames.
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow);

int checkBoundary(AppState* currentAppState, int rowChange, int colChange, int direction);

// If you have anything else you need accessible from outside the logic.c
// file, you can add them here. You likely won't.

#endif
