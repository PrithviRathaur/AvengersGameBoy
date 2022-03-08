#include "logic.h"
#include "gba.h"
#include "draw.h"
void initializeAppState(AppState* appState) {
    appState->thanosObject.row = 72; 
    appState->thanosObject.col = 10;
    appState->thanosObject.move = 0;

    appState->gauntletObject.row = 72;
    appState->gauntletObject.col = 214;

    appState->ironmanObject.row = 25;
    appState->ironmanObject.col = 36;
    appState->ironmanObject.move = 4;

    appState->hulkObject.row = 123;
    appState->hulkObject.col = 57;
    appState->hulkObject.move = 3;

    appState->thorObject.row = 25;
    appState->thorObject.col = 81;
    appState->thorObject.move = 4;

    appState->captainAmericaObject.row = 123;
    appState->captainAmericaObject.col = 102;
    appState->captainAmericaObject.move = 3;

    appState->blackWidowObject.row = 25;
    appState->blackWidowObject.col = 122;
    appState->blackWidowObject.move = 4;

    appState->spidermanObject.row = 123;
    appState->spidermanObject.col = 143;
    appState->spidermanObject.move = 3;


    appState->drStrangeObject.row = 25;
    appState->drStrangeObject.col = 164;
    appState->drStrangeObject.move = 4;

    appState->blackPantherObject.row = 123;
    appState->blackPantherObject.col = 185;
    appState->blackPantherObject.move = 3;

    appState->gameOver = 0;
    appState->win = 0;
    char* string = "Thanos got the Gauntlet!";
    appState->winString = string;
    string = "There goes 1/2 your friends and family!";
    appState->winString2 = string;
    string = "The Avengers defeated Thanos!";
    appState->loseString = string;
    string = "Press START to Restart";
    appState->replayString = string;
}

// This function processes your current app state and returns the new (i.e. next)
// state of your application.
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow) {
    AppState nextAppState = *currentAppState;
    nextAppState.thanosObject.move = 0;
    if KEY_DOWN(BUTTON_RIGHT, keysPressedNow) {
    	if (checkBoundary(currentAppState, 0, 1, 1)) {
    		nextAppState.thanosObject.col++;
    		currentAppState->thanosObject.move = 1;
    	}
    } else if KEY_DOWN(BUTTON_LEFT, keysPressedNow) {
        if (checkBoundary(currentAppState, 0, -1, 2)) {
    		nextAppState.thanosObject.col--;
    		currentAppState->thanosObject.move = 2;
    	}
    } else if KEY_DOWN(BUTTON_UP, keysPressedNow) {
    	if (checkBoundary(currentAppState, -1, 0, 3)) {
    		nextAppState.thanosObject.row--;
    		currentAppState->thanosObject.move = 3;
    	}
    } else if KEY_DOWN(BUTTON_DOWN, keysPressedNow) {
    	if (checkBoundary(currentAppState, 1, 0, 4)) {
    		nextAppState.thanosObject.row++;
    		currentAppState->thanosObject.move = 4;
    	}
    }
    if (currentAppState->ironmanObject.move == 4) {
    	if (videoBuffer[OFFSET(currentAppState->ironmanObject.row + IRONMAN_HEIGHT, currentAppState->ironmanObject.col, WIDTH)] == WHITE) {
    		nextAppState.ironmanObject.move = 3;
    	} else {
    		nextAppState.ironmanObject.row++;
    	}
    } else {
    	if (videoBuffer[OFFSET(currentAppState->ironmanObject.row - 1, currentAppState->ironmanObject.col, WIDTH)] == WHITE) {
    		nextAppState.ironmanObject.move = 4;
    	} else {
    		nextAppState.ironmanObject.row--;
    	}
    }

    if (currentAppState->hulkObject.move == 4) {
    	if (videoBuffer[OFFSET(currentAppState->hulkObject.row + HULK_HEIGHT, currentAppState->hulkObject.col, WIDTH)] == WHITE) {
    		nextAppState.hulkObject.move = 3;
    	} else {
    		nextAppState.hulkObject.row++;
    	}
    } else {
    	if (videoBuffer[OFFSET(currentAppState->hulkObject.row - 1, currentAppState->hulkObject.col, WIDTH)] == WHITE) {
    		nextAppState.hulkObject.move = 4;
    	} else {
    		nextAppState.hulkObject.row--;
    	}
    }
    if (currentAppState->thorObject.move == 4) {
    	if (videoBuffer[OFFSET(currentAppState->thorObject.row + THOR_HEIGHT, currentAppState->thorObject.col, WIDTH)] == WHITE) {
    		nextAppState.thorObject.move = 3;
    	} else {
    		nextAppState.thorObject.row++;
    	}
    } else {
    	if (videoBuffer[OFFSET(currentAppState->thorObject.row - 1, currentAppState->thorObject.col, WIDTH)] == WHITE) {
    		nextAppState.thorObject.move = 4;
    	} else {
    		nextAppState.thorObject.row--;
    	}
    }
    if (currentAppState->captainAmericaObject.move == 4) {
    	if (videoBuffer[OFFSET(currentAppState->captainAmericaObject.row + CAPTAINAMERICA_HEIGHT, currentAppState->captainAmericaObject.col, WIDTH)] == WHITE) {
    		nextAppState.captainAmericaObject.move = 3;
    	} else {
    		nextAppState.captainAmericaObject.row++;
    	}
    } else {
    	if (videoBuffer[OFFSET(currentAppState->captainAmericaObject.row - 1, currentAppState->captainAmericaObject.col, WIDTH)] == WHITE) {
    		nextAppState.captainAmericaObject.move = 4;
    	} else {
    		nextAppState.captainAmericaObject.row--;
    	}
    }
    if (currentAppState->blackWidowObject.move == 4) {
    	if (videoBuffer[OFFSET(currentAppState->blackWidowObject.row + BLACKWIDOW_HEIGHT, currentAppState->blackWidowObject.col, WIDTH)] == WHITE) {
    		nextAppState.blackWidowObject.move = 3;
    	} else {
    		nextAppState.blackWidowObject.row++;
    	}
    } else {
    	if (videoBuffer[OFFSET(currentAppState->blackWidowObject.row - 1, currentAppState->blackWidowObject.col, WIDTH)] == WHITE) {
    		nextAppState.blackWidowObject.move = 4;
    	} else {
    		nextAppState.blackWidowObject.row--;
    	}
    }
    if (currentAppState->spidermanObject.move == 4) {
    	if (videoBuffer[OFFSET(currentAppState->spidermanObject.row + SPIDERMAN_HEIGHT, currentAppState->spidermanObject.col, WIDTH)] == WHITE) {
    		nextAppState.spidermanObject.move = 3;
    	} else {
    		nextAppState.spidermanObject.row++;
    	}
    } else {
    	if (videoBuffer[OFFSET(currentAppState->spidermanObject.row - 1, currentAppState->spidermanObject.col, WIDTH)] == WHITE) {
    		nextAppState.spidermanObject.move = 4;
    	} else {
    		nextAppState.spidermanObject.row--;
    	}
    }
    if (currentAppState->drStrangeObject.move == 4) {
    	if (videoBuffer[OFFSET(currentAppState->drStrangeObject.row + DRSTRANGE_HEIGHT, currentAppState->drStrangeObject.col, WIDTH)] == WHITE) {
    		nextAppState.drStrangeObject.move = 3;
    	} else {
    		nextAppState.drStrangeObject.row++;
    	}
    } else {
    	if (videoBuffer[OFFSET(currentAppState->drStrangeObject.row - 1, currentAppState->drStrangeObject.col, WIDTH)] == WHITE) {
    		nextAppState.drStrangeObject.move = 4;
    	} else {
    		nextAppState.drStrangeObject.row--;
    	}
    }
    if (currentAppState->blackPantherObject.move == 4) {
    	if (videoBuffer[OFFSET(currentAppState->blackPantherObject.row + BLACKPANTHER_HEIGHT, currentAppState->blackPantherObject.col, WIDTH)] == WHITE) {
    		nextAppState.blackPantherObject.move = 3;
    	} else {
    		nextAppState.blackPantherObject.row++;
    	}
    } else {
    	if (videoBuffer[OFFSET(currentAppState->blackPantherObject.row - 1, currentAppState->blackPantherObject.col, WIDTH)] == WHITE) {
    		nextAppState.blackPantherObject.move = 4;
    	} else {
    		nextAppState.blackPantherObject.row--;
    	}
    }

    int row1 = nextAppState.thanosObject.row;
    int col1 = nextAppState.thanosObject.col;

    int row2 = row1 + THANOS_HEIGHT - 1;
    int col2 = col1 + THANOS_WIDTH - 1;
    if (col2 > 214) {
	    if ((row1 > nextAppState.gauntletObject.row) & (row1 < (nextAppState.gauntletObject.row + INFINITYGAUNTLET_HEIGHT))) {
	    	if ((col1 > nextAppState.gauntletObject.col) & (col1 < (nextAppState.gauntletObject.col + INFINITYGAUNTLET_WIDTH))) {
	    		nextAppState.gameOver = 1;
	    		nextAppState.win = 1;
	    	} else if ((col2 > nextAppState.gauntletObject.col) & (col2 < (nextAppState.gauntletObject.col + INFINITYGAUNTLET_WIDTH))) {
	    		nextAppState.gameOver = 1;
	    		nextAppState.win = 1;
	    	}
	    } else if ((row2 > nextAppState.gauntletObject.row) & (row2 < (nextAppState.gauntletObject.row + INFINITYGAUNTLET_HEIGHT))) {
	    	if ((col1 > nextAppState.gauntletObject.col) & (col1 < (nextAppState.gauntletObject.col + INFINITYGAUNTLET_WIDTH))) {
	    		nextAppState.gameOver = 1;
	    		nextAppState.win = 1;
	    	} else if ((col2 > nextAppState.gauntletObject.col) & (col2 < (nextAppState.gauntletObject.col + INFINITYGAUNTLET_WIDTH))) {
	    		nextAppState.gameOver = 1;
	    		nextAppState.win = 1;
	    	}
	    }
	} else if ((col2 > 35) & (col2 < 57)) {
		if ((row1 > nextAppState.ironmanObject.row) & (row1 < (nextAppState.ironmanObject.row + IRONMAN_HEIGHT))) {
			if ((col1 > nextAppState.ironmanObject.col) & (col1 < (nextAppState.ironmanObject.col + IRONMAN_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.ironmanObject.col) & (col2 < (nextAppState.ironmanObject.col + IRONMAN_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		} else if ((row2 > nextAppState.ironmanObject.row) & (row2 < (nextAppState.ironmanObject.row + IRONMAN_HEIGHT))) {
			if ((col1 > nextAppState.ironmanObject.col) & (col1 < (nextAppState.ironmanObject.col + IRONMAN_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.ironmanObject.col) & (col2 < (nextAppState.ironmanObject.col + IRONMAN_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		}
	} else if ((col2 > 57) & (col2 < 81)) {
		if ((row1 > nextAppState.hulkObject.row) & (row1 < (nextAppState.hulkObject.row + HULK_HEIGHT))) {
			if ((col1 > nextAppState.hulkObject.col) & (col1 < (nextAppState.hulkObject.col + HULK_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.hulkObject.col) & (col2 < (nextAppState.hulkObject.col + HULK_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		} else if ((row2 > nextAppState.hulkObject.row) & (row2 < (nextAppState.hulkObject.row + HULK_HEIGHT))) {
			if ((col1 > nextAppState.hulkObject.col) & (col1 < (nextAppState.hulkObject.col + HULK_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.hulkObject.col) & (col2 < (nextAppState.hulkObject.col + HULK_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		}
	} else if ((col2 > 80) & (col2 < 102)) {
		if ((row1 > nextAppState.thorObject.row) & (row1 < (nextAppState.thorObject.row + THOR_HEIGHT))) {
			if ((col1 > nextAppState.thorObject.col) & (col1 < (nextAppState.thorObject.col + THOR_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.thorObject.col) & (col2 < (nextAppState.thorObject.col + THOR_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		} else if ((row2 > nextAppState.thorObject.row) & (row2 < (nextAppState.thorObject.row + THOR_HEIGHT))) {
			if ((col1 > nextAppState.thorObject.col) & (col1 < (nextAppState.thorObject.col + THOR_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.thorObject.col) & (col2 < (nextAppState.thorObject.col + THOR_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		}
	} else if ((col2 > 101) & (col2 < 122)) {
		if ((row1 > nextAppState.captainAmericaObject.row) & (row1 < (nextAppState.captainAmericaObject.row + CAPTAINAMERICA_HEIGHT))) {
			if ((col1 > nextAppState.captainAmericaObject.col) & (col1 < (nextAppState.captainAmericaObject.col + CAPTAINAMERICA_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.captainAmericaObject.col) & (col2 < (nextAppState.captainAmericaObject.col + CAPTAINAMERICA_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		} else if ((row2 > nextAppState.captainAmericaObject.row) & (row2 < (nextAppState.captainAmericaObject.row + CAPTAINAMERICA_HEIGHT))) {
			if ((col1 > nextAppState.captainAmericaObject.col) & (col1 < (nextAppState.captainAmericaObject.col + CAPTAINAMERICA_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.captainAmericaObject.col) & (col2 < (nextAppState.captainAmericaObject.col + CAPTAINAMERICA_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		}
	} else if ((col2 > 121) & (col2 < 143)) {
		if ((row1 > nextAppState.blackWidowObject.row) & (row1 < (nextAppState.blackWidowObject.row + BLACKWIDOW_HEIGHT))) {
			if ((col1 > nextAppState.blackWidowObject.col) & (col1 < (nextAppState.blackWidowObject.col + BLACKWIDOW_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.blackWidowObject.col) & (col2 < (nextAppState.blackWidowObject.col + BLACKWIDOW_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		} else if ((row2 > nextAppState.blackWidowObject.row) & (row2 < (nextAppState.blackWidowObject.row + BLACKWIDOW_HEIGHT))) {
			if ((col1 > nextAppState.blackWidowObject.col) & (col1 < (nextAppState.blackWidowObject.col + BLACKWIDOW_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.blackWidowObject.col) & (col2 < (nextAppState.blackWidowObject.col + BLACKWIDOW_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		}
	} else if ((col2 > 142) & (col2 < 164)) {
		if ((row1 > nextAppState.spidermanObject.row) & (row1 < (nextAppState.spidermanObject.row + SPIDERMAN_HEIGHT))) {
			if ((col1 > nextAppState.spidermanObject.col) & (col1 < (nextAppState.spidermanObject.col + SPIDERMAN_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.spidermanObject.col) & (col2 < (nextAppState.spidermanObject.col + SPIDERMAN_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		} else if ((row2 > nextAppState.spidermanObject.row) & (row2 < (nextAppState.spidermanObject.row + SPIDERMAN_HEIGHT))) {
			if ((col1 > nextAppState.spidermanObject.col) & (col1 < (nextAppState.spidermanObject.col + SPIDERMAN_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.spidermanObject.col) & (col2 < (nextAppState.spidermanObject.col + SPIDERMAN_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		}
	} else if ((col2 > 163) & (col2 < 185)) {
		if ((row1 > nextAppState.drStrangeObject.row) & (row1 < (nextAppState.drStrangeObject.row + DRSTRANGE_HEIGHT))) {
			if ((col1 > nextAppState.drStrangeObject.col) & (col1 < (nextAppState.drStrangeObject.col + DRSTRANGE_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.drStrangeObject.col) & (col2 < (nextAppState.drStrangeObject.col + DRSTRANGE_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		} else if ((row2 > nextAppState.drStrangeObject.row) & (row2 < (nextAppState.drStrangeObject.row + DRSTRANGE_HEIGHT))) {
			if ((col1 > nextAppState.drStrangeObject.col) & (col1 < (nextAppState.drStrangeObject.col + DRSTRANGE_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.drStrangeObject.col) & (col2 < (nextAppState.drStrangeObject.col + DRSTRANGE_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		}
	} else if ((col2 > 184) & (col2 < nextAppState.gauntletObject.col)) {
		if ((row1 > nextAppState.blackPantherObject.row) & (row1 < (nextAppState.blackPantherObject.row + BLACKPANTHER_HEIGHT))) {
			if ((col1 > nextAppState.blackPantherObject.col) & (col1 < (nextAppState.blackPantherObject.col + BLACKPANTHER_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.blackPantherObject.col) & (col2 < (nextAppState.blackPantherObject.col + BLACKPANTHER_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		} else if ((row2 > nextAppState.blackPantherObject.row) & (row2 < (nextAppState.blackPantherObject.row + BLACKPANTHER_HEIGHT))) {
			if ((col1 > nextAppState.blackPantherObject.col) & (col1 < (nextAppState.blackPantherObject.col + BLACKPANTHER_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			} else if ((col2 > nextAppState.blackPantherObject.col) & (col2 < (nextAppState.blackPantherObject.col + BLACKPANTHER_WIDTH))) {
				nextAppState.gameOver = 1;
				nextAppState.win = 0;
			}
		}
	}
    UNUSED(keysPressedBefore);
    return nextAppState;
}


int checkBoundary(AppState* currentAppState, int rowChange, int colChange, int direction) {
	int newRow = currentAppState->thanosObject.row + rowChange;
	int newCol = currentAppState->thanosObject.col + colChange;
	if (direction == 1) {
		for (int i = 0; i < THANOS_HEIGHT; i++) {
			if (videoBuffer[OFFSET(newRow + i, newCol + THANOS_WIDTH - 1, WIDTH)] == WHITE) {
				return 0;
			}
		}	
		return 1;	
	} else if (direction == 2) {
		for (int i = 0; i < THANOS_HEIGHT; i++) {
			if (videoBuffer[OFFSET(newRow + i, newCol, WIDTH)] == WHITE) {
				return 0;
			}
		}
		return 1;
	} else if (direction == 3) {
		for (int i = 0; i < THANOS_WIDTH; i++) {
			if (videoBuffer[OFFSET(newRow, newCol + i, WIDTH)] == WHITE) {
				return 0;
			}
		}
		return 1;
	} else if (direction == 4) {
		for (int i = 0; i < THANOS_WIDTH; i++) {
			if (videoBuffer[OFFSET(newRow + THANOS_HEIGHT - 1, newCol + i, WIDTH)] == WHITE) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
