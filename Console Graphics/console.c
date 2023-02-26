#include <stdlib.h>
#include "console.h"

Console* createConsole(int width, int height, int fontSizeX, int fontSizeY)
{
    Console* console = createConsoleXY(0, 0, width, height, fontSizeX, fontSizeY);
    return console;
}

Console* createConsoleXY(int x, int y, int width, int height, int fontSizeX, int fontSizeY)
{
    Console* console = malloc(sizeof(Console));
    if (!console) return NULL;

    console->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (console->hConsole == INVALID_HANDLE_VALUE) return NULL;
   
    if (fontSizeX <= 0 || fontSizeY <= 0) {
        //sets the font size to the default sizes if a invalid font size is used
        fontSizeX = 8;
        fontSizeY = 16;
    }
    setConsoleFontSize(console, fontSizeX, fontSizeY);
   

    console->writeRegion.Left = x;
    console->writeRegion.Top = y;
    console->writeRegion.Right = x + width - 1;
    console->writeRegion.Bottom = y + height - 1;

    console->consoleBuffer = malloc(sizeof(ConsoleBuffer));
    if (!console->consoleBuffer) return NULL;

    console->consoleBuffer->buffer = malloc(sizeof(CHAR_INFO) * width * height);

    console->consoleBuffer->bufferSize.X = width;
    console->consoleBuffer->bufferSize.Y = height;

    console->consoleBuffer->bufferCoord.X = x;
    console->consoleBuffer->bufferCoord.Y = y;

    COORD totalBufferSize = { width * fontSizeX, height * fontSizeY }; // acounts for the width as well as the fontSize

    SetConsoleScreenBufferSize(console->hConsole, totalBufferSize);
    setConsoleWindowSize(console, totalBufferSize.X, totalBufferSize.Y);

    return console;
}

void fillConsoleBuffer(ConsoleBuffer* consoleBuffer, int colorFlag, int intensityFlag)
{
    for (int i = 0; i < consoleBuffer->bufferSize.X * consoleBuffer->bufferSize.Y; i++) {
        consoleBuffer->buffer[i].Char.UnicodeChar = L'█';
        consoleBuffer->buffer[i].Attributes = colorFlag | intensityFlag;
    }
}


int drawFrame(Console* console)
{
    COORD temp = { 0,0 };
    SetConsoleCursorPosition(console->hConsole, temp);
    if (!WriteConsoleOutput
    (
        console->hConsole,
        console->consoleBuffer->buffer,
        console->consoleBuffer->bufferSize,
        console->consoleBuffer->bufferCoord,
        &console->writeRegion
    )) {
        return -1;
    }

    return 0;
}


int setConsoleFontSize(Console* console, short width, short height)
{
    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
    GetCurrentConsoleFontEx(console->hConsole, FALSE, &font);

    font.dwFontSize.X = width;
    font.dwFontSize.Y = height;
    if (!SetCurrentConsoleFontEx(console->hConsole, FALSE, &font)) {
        return -1;
    }

    return 0;
}

void setConsoleWindowSize(Console* console, int width, int height)
{
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
    SetConsoleWindowInfo(console->hConsole, TRUE, &rect);
}

int randomConsoleColor()
{
    int color[] = { FOREGROUND_RED, FOREGROUND_GREEN, FOREGROUND_BLUE, FOREGROUND_INTENSITY };
    return color[rand() % 4];
}
