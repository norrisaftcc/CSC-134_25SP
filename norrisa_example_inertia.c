/*******************************************************************************************
*
*   raylib [core] examples - basic screen manager
*
*   NOTE: This example illustrates a very simple screen manager based on a states machines
*
*   Example originally created with raylib 4.0, last time updated with raylib 4.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2021-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    GameScreen currentScreen = LOGO;

    // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0;          // Useful to count frames
    int speedUp = 0;                // speed up every x seconds
    SetTargetFPS(60);               // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------
    // All our variables
    int player_x = 0;
    int player_y = 0;
    int speed_x  = 3;
    int speed_y  = 3;
    
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 120)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = ENDING;
                }
            } break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            switch(currentScreen)
            {
                case LOGO:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                    DrawText("Loading Snake, please wait...", 290, 220, 20, GRAY);

                } break;
                case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText("SNAKE TITLE SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or click to start", 120, 220, 20, MAROON);

                } break;
                case GAMEPLAY:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, DARKGREEN);
                    DrawText("SNAKE GAMEPLAY SCREEN", 20, 20, 40, SKYBLUE);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, SKYBLUE);
                    
                    DrawRectangle(200, 200, 50, 50, SKYBLUE);
                    // Draw player here
                    // reminder
                    /*
                    int player_x = 0;
                    int player_y = 0;
                    int speed_x  = 1;
                    int speed_y  = 1;
                    */
                    // update position
                    //player_x = player_x + speed_x;
                    //player_y = player_y + speed_y;
                    // speed up forever
                    /*speedUp ++;
                    if (speedUp > 60 ) { // 5 seconds is 5 * 60
                        speedUp = 0;
                        speed_x ++;
                        speed_y ++;
                    }
                    */
                    // speed cap
                    if (speed_x > 10) {
                        speed_x = 10;
                    }
                    if (speed_x < -10) {
                        speed_x = -10;
                    }
                    if (speed_y > 10) {
                        speed_y = 10;
                    }
                    if (speed_y < -10) {
                        speed_y = -10;
                    }
                    
                    if (IsKeyPressed(KEY_LEFT)) {
                        speed_x--;
                    }
                    if (IsKeyPressed(KEY_RIGHT)) {
                        speed_x++;
                    }
                    if (IsKeyPressed(KEY_UP)) {
                        speed_y--;
                    }
                    if (IsKeyPressed(KEY_DOWN)) {
                        speed_y++;
                    }
                    // This should use inertia...
                    player_x = player_x + speed_x;
                    player_y = player_y + speed_y;
                    
                    // Wrap around
                    if (player_x > screenWidth ) {
                        player_x = 0;
                    }
                    if (player_x < 0) {
                        player_x = screenWidth;
                    }
                    if (player_y > screenHeight) {
                        player_y = 0;
                    }
                    
                    if (player_y < 0) {
                        player_y = screenHeight;
                    }
                    
                    // draw player
                    DrawRectangle(player_x, player_y, 50, 50, DARKPURPLE);
                    

                } break;
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}