#include <stdlib.h>
#include "console.h"

Console* createConsole(short width, short height, float fontSizeX, float fontSizeY)
{
    Console* console = createConsoleXY(0, 0, width, height, fontSizeX, fontSizeY);
    setConsoleFontSize(console, fontSizeX, fontSizeY);
    return console;
}

Console* createConsoleXY(short x, short y, short width, short height, float fontSizeX, float fontSizeY)
{

    Console* console = malloc(sizeof(Console));

    if (!console) return NULL;

    console->hConsole = getStandardHandle();
    setConsoleFontSize(console, fontSizeX, fontSizeY);

    console->writeRegion.Left = x;
    console->writeRegion.Top = y;
    console->writeRegion.Right = y + width - 1;
    console->writeRegion.Bottom = x + height - 1;

    console->consoleBuffer = malloc(sizeof(ConsoleBuffer));

    if (!console->consoleBuffer) return NULL;

    console->consoleBuffer->buffer = malloc(sizeof(CHAR_INFO) * width * height);


    console->consoleBuffer->bufferSize.X = width;
    console->consoleBuffer->bufferSize.Y = height;

    console->consoleBuffer->screenBufferSize.X = width * fontSizeX;
    console->consoleBuffer->screenBufferSize.X = height * fontSizeY;


    SetConsoleScreenBufferSize(console, console->consoleBuffer->screenBufferSize);
    setConsoleWindowSize(console, width * fontSizeX, height * fontSizeY);

    console->consoleBuffer->bufferCoord.X = x;
    console->consoleBuffer->bufferCoord.Y = y;

    return console;
}

HANDLE getStandardHandle()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        return NULL;
    }
    return hConsole;
}

void writeToConsoleBuffer(ConsoleBuffer* consoleBuffer, int colorFlag, int intensityFlag)
{
    for (int i = 0; i < consoleBuffer->bufferSize.X * consoleBuffer->bufferSize.Y; i++) {
        consoleBuffer->buffer[i].Char.UnicodeChar = L'█';
        consoleBuffer->buffer[i].Attributes = randomConsoleColor() | intensityFlag;

    }
}



int writeToConsole(Console* console)
{
    COORD cursorPos = { 0, 0 };  // Set cursor position to (0,0)
    SetConsoleCursorPosition(console->hConsole, cursorPos);
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

WORD createColor(int r, int g, int b)
{
    WORD attributes = (r << 8 | g << 3 | b >> 3);
    return attributes;

}

int randomConsoleColor()
{
    int color[] = { FOREGROUND_RED, FOREGROUND_GREEN, FOREGROUND_BLUE, FOREGROUND_INTENSITY };
    return color[rand() % 4];
}

int setConsoleFontSize(Console* console, float width, float height)
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

void drawCircle(int x, int y, int radius)
{

}
