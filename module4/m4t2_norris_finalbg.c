/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    // Alternate both color tiles (rectangles) 
    // they're some fraction of the screen width and height
    const int screenWidth = 800;
    const int screenHeight = 600;
    int tile_width = 80;
    int tile_height = 60;
    Color color1 = LIME;
    Color color2 = DARKGREEN;
   
    InitWindow(screenWidth, screenHeight, "M4T2 - Lawn Texture");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKGREEN);
            // Test: Draw one tile 
            //DrawRectangle(0, 0, tile_width, tile_height, color1);
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            // Loop through one line, alternating colors
            
            int line_num = 0;
            Color first, second;
            for (int y=0; y < screenHeight; y += tile_height) {
                // alternate odd and even lines
                if (line_num % 2 == 0) {
                    first = color1;
                    second = color2;
                } 
                else {
                    first = color2;
                    second = color1;
                } 
                // draw the row
                for (int x=0; x < screenWidth; x += 2*tile_width) {
                    DrawRectangle(x, y, tile_width, tile_height, first);               // first color
                    DrawRectangle(x+tile_width, y, tile_width, tile_height, second);     // second goes in between
                } // end row
                line_num++; 
            } // end of screen

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}