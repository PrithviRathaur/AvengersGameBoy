# Thanos GameBoy Game

This project contains the files used to create a gameboy game in C. The game's main character is Thanos, and the objective of the game is to dodge all the Avengers and obtain the infinity gauntlet. The gameplay mimics the gameplay in Level 2 of the Worlds Hardest Game, which can be found online. 

## Project Description

This project was done in C to gain in understanding of C and implement object oriented programming in C. The gameboy game was run on a docker container that contained a gameboy emulator. Another goal of the project was to write efficient code, as the gameboy is not a computationally powerful device. The game was programmed as a finite state machine, with numerous states corresponding to situations in the game. 

[![Gameplay of a Loss](https://img.youtube.com/vi/8KhIv_sltKI/0.jpg)](https://www.youtube.com/watch?v=8KhIv_sltKI)

## File Description

- **draw.c**: Given a game state, this file contains all the code necessary for drawing a scene on the gameboy screen. 
- **logic.c**: This file contains the game logic for the avengers game. This file updates the positions of the various characters in the games, reads in user inputs, and updates the app's state correspondingly.
- **main.c**: This file runs the gameboy game as a finite state machine, switching between the states until the game is shut off by the user. 
