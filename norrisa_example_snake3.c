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
#include <stdlib.h>

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
    int speed_x  = 0;
    int speed_y  = 3;
    
    int fruit_x;
    int fruit_y;
    
    
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
                if (framesCounter > 60)
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
                    
                    DrawCircle(screenWidth / 2, screenHeight / 2, 250, MAROON);
                    DrawText("Loading Snake, please wait...", 290, 220, 20, GRAY);

                } break;
                case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                    DrawText("SNAKE TITLE SCREEN", 20, 20, 40, MAROON);
                    DrawCircleGradient(screenWidth / 2, screenHeight / 2, 250, PINK, MAROON);
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
                    int base_speed = 3;
                    
                    if (IsKeyPressed(KEY_LEFT)) {
                        speed_x = -base_speed;
                        speed_y = 0;
                    }
                    if (IsKeyPressed(KEY_RIGHT)) {
                        speed_x = base_speed;
                        speed_y = 0;
                    }
                    if (IsKeyPressed(KEY_UP)) {
                        speed_y = -base_speed;
                        speed_x = 0;
                    }
                    if (IsKeyPressed(KEY_DOWN)) {
                        speed_y = base_speed;
                        speed_x = 0;
                    }
                    // This should use inertia?
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
                    
                    // draw the fruit
                    fruit_x = 300;
                    fruit_y = 300;
                    DrawCircleGradient(fruit_x, fruit_y, 20, PINK, MAROON);
                    DrawCircle(fruit_x-10, fruit_y-10, 6, GREEN);
                    DrawCircle(fruit_x-10, fruit_y-10, 2,  DARKGREEN);
                    
                    // draw player
                    // Easiest if we assume player_x and player_y are in the CENTER of the sprite
                    DrawCircleGradient(player_x, player_y, 25, VIOLET, DARKPURPLE);
                    DrawCircle(player_x - 10, player_y, 2, RAYWHITE);
                    DrawCircle(player_x + 10, player_y, 2, RAYWHITE);
                    DrawRectangle(player_x - 10, player_y + 10, 20, 2, RAYWHITE);
                    
                    // Did we get the fruit? within 10 pixels
                    // requires #include <stdlib.h>
                    if ( abs(player_x - fruit_x) < 10) {
                        if ( abs(player_y - fruit_y) < 10) {
                            player_x = 10;
                            player_y = 10;
                            currentScreen = ENDING;
                        }
                    }
                                        

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