#pragma once
#include <Windows.h>

typedef struct ConsoleBuffer
{
    CHAR_INFO* buffer;
    COORD bufferSize;
    COORD bufferCoord;

} ConsoleBuffer;


typedef struct Console
{
    SMALL_RECT writeRegion;
    HANDLE hConsole;
    ConsoleBuffer* consoleBuffer;

} Console;

Console* createConsole(int width, int height, int fontSizeX, int fontSizeY);
Console* createConsoleXY(int x, int y, int width, int height, int fontSizeX, int fontSizeY);

void fillConsoleBuffer(ConsoleBuffer* consoleBuffer, int colorFlag, int intensityFlag);
void setConsoleWindowSize(Console* console, int width, int height);

int drawFrame(Console* console);
int setConsoleFontSize(Console* console, short width, short height);
int randomConsoleColor();
