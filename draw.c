#include "draw.h"
#include "gba.h"
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



// This function will be used to draw everything about the app
// including the background and whatnot.
void fullDrawAppState(AppState *state) {
    drawFullScreenImageDMA(Grassy);
    drawImageDMA(state->gauntletObject.row, state->gauntletObject.col, INFINITYGAUNTLET_WIDTH, INFINITYGAUNTLET_HEIGHT, infinityGauntlet);
    drawImageDMA(state->thanosObject.row, state->thanosObject.col, THANOS_WIDTH, THANOS_HEIGHT, thanos);
    drawImageDMA(state->ironmanObject.row, state->ironmanObject.col, IRONMAN_WIDTH, IRONMAN_HEIGHT, ironman);
    drawImageDMA(state->hulkObject.row, state->hulkObject.col, HULK_WIDTH, HULK_HEIGHT, hulk);
    drawImageDMA(state->thorObject.row, state->thorObject.col, THOR_WIDTH, THOR_HEIGHT, thor);
    drawImageDMA(state->captainAmericaObject.row, state->captainAmericaObject.col, CAPTAINAMERICA_WIDTH, CAPTAINAMERICA_HEIGHT, captainamerica);
    drawImageDMA(state->blackWidowObject.row, state->blackWidowObject.col, BLACKWIDOW_WIDTH, BLACKWIDOW_HEIGHT, blackwidow);
    drawImageDMA(state->spidermanObject.row, state->spidermanObject.col, SPIDERMAN_WIDTH, SPIDERMAN_HEIGHT, spiderman);
    drawImageDMA(state->drStrangeObject.row, state->drStrangeObject.col, DRSTRANGE_WIDTH, DRSTRANGE_HEIGHT, drStrange);
    drawImageDMA(state->blackPantherObject.row, state->blackPantherObject.col, BLACKPANTHER_WIDTH, BLACKPANTHER_HEIGHT, blackpanther);
    drawBorder(state);
}

void drawBorder(AppState* state) {
	drawRectDMA(state->thanosObject.row - 20, state->thanosObject.col - 7, THANOS_WIDTH + 14, 1, WHITE);
    drawRectDMA(state->thanosObject.row + THANOS_HEIGHT + 20, state->thanosObject.col - 7, THANOS_WIDTH + 14, 1, WHITE);
    drawRectDMA(state->thanosObject.row - 20, state->thanosObject.col - 7, 1, THANOS_HEIGHT + 40, WHITE);
    drawRectDMA(state->thanosObject.row - 50, state->thanosObject.col + THANOS_WIDTH + 6, 1, 30, WHITE);
    drawRectDMA(state->thanosObject.row + THANOS_HEIGHT + 20, state->thanosObject.col + THANOS_WIDTH + 6, 1, 30, WHITE);

	drawRectDMA(state->thanosObject.row - 20, state->gauntletObject.col - 7, INFINITYGAUNTLET_WIDTH + 13, 1, WHITE);
	drawRectDMA(state->thanosObject.row + THANOS_HEIGHT + 20, state->gauntletObject.col - 7, INFINITYGAUNTLET_WIDTH + 13, 1, WHITE);
	drawRectDMA(state->thanosObject.row - 20, state->gauntletObject.col + INFINITYGAUNTLET_WIDTH + 6, 1, THANOS_HEIGHT + 41, WHITE);
	drawRectDMA(state->thanosObject.row - 50, state->gauntletObject.col - 7, 1, 30, WHITE);
	drawRectDMA(state->thanosObject.row + THANOS_HEIGHT + 20, state->gauntletObject.col - 7, 1, 30, WHITE);

	drawRectDMA(state->thanosObject.row - 50, state->thanosObject.col + THANOS_WIDTH + 6, ((state->gauntletObject.col - 7) - (state->thanosObject.col + THANOS_WIDTH + 6)), 1, WHITE);
	drawRectDMA(state->thanosObject.row + THANOS_HEIGHT + 50, state->thanosObject.col + THANOS_WIDTH + 6, ((state->gauntletObject.col - 7) - (state->thanosObject.col + THANOS_WIDTH + 6)) + 1, 1, WHITE);
}

// This function will be used to undraw (i.e. erase) things that might
// move in a frame. 
void undrawAppState(AppState *state) {
	int move = state->thanosObject.move;
	if (move == 1) {
		getRidOfTrail(state->thanosObject.row, state->thanosObject.col, 1, THANOS_HEIGHT, Grassy);
	} else if (move == 2) {
		getRidOfTrail(state->thanosObject.row, state->thanosObject.col + THANOS_WIDTH - 1, 1, THANOS_HEIGHT, Grassy);
	} else if (move == 3) {
		getRidOfTrail(state->thanosObject.row + THANOS_HEIGHT - 1, state->thanosObject.col, THANOS_WIDTH, 1, Grassy);
	} else if (move == 4) {
		getRidOfTrail(state->thanosObject.row, state->thanosObject.col, THANOS_WIDTH, 1, Grassy);
	}
	move = state->ironmanObject.move;
	if (move == 3) {
		getRidOfTrail(state->ironmanObject.row + IRONMAN_HEIGHT - 1, state->ironmanObject.col, IRONMAN_WIDTH, 1, Grassy);
	} else if (move == 4) {
		getRidOfTrail(state->ironmanObject.row, state->ironmanObject.col, IRONMAN_WIDTH, 1, Grassy);
	}
	move = state->hulkObject.move;
	if (move == 3) {
		getRidOfTrail(state->hulkObject.row + HULK_HEIGHT - 1, state->hulkObject.col, HULK_WIDTH, 1, Grassy);
	} else if (move == 4) {
		getRidOfTrail(state->hulkObject.row, state->hulkObject.col, HULK_WIDTH, 1, Grassy);
	}
	move = state->thorObject.move;
	if (move == 3) {
		getRidOfTrail(state->thorObject.row + THOR_HEIGHT - 1, state->thorObject.col, THOR_WIDTH, 1, Grassy);
	} else if (move == 4) {
		getRidOfTrail(state->thorObject.row, state->thorObject.col, THOR_WIDTH, 1, Grassy);
	}
	move = state->captainAmericaObject.move;
	if (move == 3) {
		getRidOfTrail(state->captainAmericaObject.row + CAPTAINAMERICA_HEIGHT - 1, state->captainAmericaObject.col, CAPTAINAMERICA_WIDTH, 1, Grassy);
	} else if (move == 4) {
		getRidOfTrail(state->captainAmericaObject.row, state->captainAmericaObject.col, CAPTAINAMERICA_WIDTH, 1, Grassy);
	}
	move = state->blackWidowObject.move;
	if (move == 3) {
		getRidOfTrail(state->blackWidowObject.row + BLACKWIDOW_HEIGHT - 1, state->blackWidowObject.col, BLACKWIDOW_WIDTH, 1, Grassy);
	} else if (move == 4) {
		getRidOfTrail(state->blackWidowObject.row, state->blackWidowObject.col, BLACKWIDOW_WIDTH, 1, Grassy);
	}
	move = state->spidermanObject.move;
	if (move == 3) {
		getRidOfTrail(state->spidermanObject.row + SPIDERMAN_HEIGHT - 1, state->spidermanObject.col, SPIDERMAN_WIDTH, 1, Grassy);
	} else if (move == 4) {
		getRidOfTrail(state->spidermanObject.row, state->spidermanObject.col, SPIDERMAN_WIDTH, 1, Grassy);
	}
	move = state->drStrangeObject.move;
	if (move == 3) {
		getRidOfTrail(state->drStrangeObject.row + DRSTRANGE_HEIGHT - 1, state->drStrangeObject.col, DRSTRANGE_WIDTH, 1, Grassy);
	} else if (move == 4) {
		getRidOfTrail(state->drStrangeObject.row, state->drStrangeObject.col, DRSTRANGE_WIDTH, 1, Grassy);
	}
	move = state->blackPantherObject.move;
	if (move == 3) {
		getRidOfTrail(state->blackPantherObject.row + BLACKPANTHER_HEIGHT - 1, state->blackPantherObject.col, BLACKPANTHER_WIDTH, 1, Grassy);
	} else if (move == 4) {
		getRidOfTrail(state->blackPantherObject.row, state->blackPantherObject.col, BLACKPANTHER_WIDTH, 1, Grassy);
	}

}

void drawWin(AppState* state) {
	drawFullScreenImageDMA(winScreen);
	drawCenteredString(0,50, WIDTH, HEIGHT, state->winString, WHITE);
	drawCenteredString(0,60, WIDTH, HEIGHT, state->winString2, WHITE);
	drawCenteredString(0,70, WIDTH, HEIGHT, state->replayString, WHITE);
}

void drawLose(AppState* state) {
	drawFullScreenImageDMA(loseScreen);
	drawCenteredString(0,60, WIDTH, HEIGHT, state->loseString, WHITE);
	drawCenteredString(0,70, WIDTH, HEIGHT, state->replayString, WHITE);
}


// This function will be used to draw things that might have moved in a frame.
void drawAppState(AppState *state) {
	drawImageDMA(state->thanosObject.row, state->thanosObject.col, THANOS_WIDTH, THANOS_HEIGHT, thanos);
	drawImageDMA(state->ironmanObject.row, state->ironmanObject.col, IRONMAN_WIDTH, IRONMAN_HEIGHT, ironman);
	drawImageDMA(state->hulkObject.row, state->hulkObject.col, HULK_WIDTH, HULK_HEIGHT, hulk);
	drawImageDMA(state->thorObject.row, state->thorObject.col, THOR_WIDTH, THOR_HEIGHT, thor);
    drawImageDMA(state->captainAmericaObject.row, state->captainAmericaObject.col, CAPTAINAMERICA_WIDTH, CAPTAINAMERICA_HEIGHT, captainamerica);
    drawImageDMA(state->blackWidowObject.row, state->blackWidowObject.col, BLACKWIDOW_WIDTH, BLACKWIDOW_HEIGHT, blackwidow);
    drawImageDMA(state->spidermanObject.row, state->spidermanObject.col, SPIDERMAN_WIDTH, SPIDERMAN_HEIGHT, spiderman);
    drawImageDMA(state->drStrangeObject.row, state->drStrangeObject.col, DRSTRANGE_WIDTH, DRSTRANGE_HEIGHT, drStrange);
    drawImageDMA(state->blackPantherObject.row, state->blackPantherObject.col, BLACKPANTHER_WIDTH, BLACKPANTHER_HEIGHT, blackpanther);
}
