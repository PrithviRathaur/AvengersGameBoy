#include "gba.h"
#include "logic.h"
#include "draw.h"
#include "images/StartScreen.h"
#include "images/Grassy.h"
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

#include <stdio.h>
#include <stdlib.h>

// AppState enum definition
typedef enum {
    START,
    START_NODRAW,
    APP_INIT,
    APP,
    APP_EXIT,
    APP_EXIT_NODRAW,
} GBAState;

int main(void) {
    REG_DISPCNT = MODE3 | BG2_ENABLE;

    GBAState state = START;
    // We store the "previous" and "current" states.
    AppState currentAppState, nextAppState;

    // We store the current and previous values of the button input.
    u32 previousButtons = BUTTONS;
    u32 currentButtons = BUTTONS;

    while (1) {
        // Load the current state of the buttons
        currentButtons = BUTTONS;

        // Manipulate the state machine below as needed.
        switch(state) {
            case START:
                // Wait for VBlank
                waitForVBlank();
                drawFullScreenImageDMA(StartScreen);
                state = START_NODRAW;
                break;
            case START_NODRAW:
                if (KEY_JUST_PRESSED(BUTTON_START, currentButtons, previousButtons)) {
                    state = APP_INIT;
                }
                if (KEY_JUST_PRESSED(BUTTON_SELECT, currentButtons, previousButtons)) {
                    state = START;
                }
                break;
            case APP_INIT:
                // Initialize the app. Switch to the APP state.
                initializeAppState(&currentAppState);
                // Draw the initial state of the app
                fullDrawAppState(&currentAppState);

                state = APP;
                if (KEY_JUST_PRESSED(BUTTON_SELECT, currentButtons, previousButtons)) {
                    state = START;
                }
                break;
            case APP:
                // Process the app for one frame, store the next state
                nextAppState = processAppState(&currentAppState, previousButtons, currentButtons);

                // Wait for VBlank before we do any drawing.
                waitForVBlank();

                // Undraw the previous state
                undrawAppState(&currentAppState);

                // Draw the current state
                drawAppState(&nextAppState);

                // Now set the current state as the next state for the next iter.
                currentAppState = nextAppState;

                // Check if the app is exiting. If it is, then go to the exit state.
                if (nextAppState.gameOver) {
                    state = APP_EXIT;
                }
                if (KEY_JUST_PRESSED(BUTTON_SELECT, currentButtons, previousButtons)) {
                    state = START;
                }

                break;
            case APP_EXIT:
                // Wait for VBlank
                waitForVBlank();
                if (currentAppState.win) {
                    drawWin(&currentAppState);
                } else {
                    drawLose(&currentAppState);
                }
                // Draw the exit / gameover screen
                state = APP_EXIT_NODRAW;
                break;
            case APP_EXIT_NODRAW:
                if (KEY_JUST_PRESSED(BUTTON_SELECT, currentButtons, previousButtons)) {
                    state = START;
                }
                if (KEY_JUST_PRESSED(BUTTON_START, currentButtons, previousButtons)) { 
                    state = APP_INIT;
                }
                break;
        }

        // Store the current state of the buttons
        previousButtons = currentButtons;
    }

    return 0;
}
