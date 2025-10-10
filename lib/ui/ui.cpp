#include "ui.hpp"
#include "util.cpp"
#include "raylib.h"

namespace arlogix::ui{    

    void run() {
        int screenWidth = 400;
        int screenHeight = 600;

        SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        InitWindow(screenWidth, screenHeight, "Calculadora Arlogix");
        SetWindowMinSize(400, 600);
        SetTargetFPS(60);
        // Font fonte = LoadFont("path/to/your/font.ttf"); 

        Rectangle visor = {screenWidth*0.05f, screenHeight-(screenHeight*0.99f), screenWidth-(screenWidth*0.10f), screenHeight-(screenHeight*0.90f)};



        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();

            //Visor da calculadora
            DrawRectangleRec(visor, BLUE);
            // Texto do visor
            DrawTextBoxed(GetFontDefault(), "0+3-4*(4/8)+(-5)+100000", visor, 20, 1, true, BLACK);
            
            //UnloadFont(fonte);

            EndDrawing();
        }

        CloseWindow();
    }
}