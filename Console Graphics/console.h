#pragma once
#include <Windows.h>

typedef struct ConsoleBuffer
{
    CHAR_INFO* buffer;
    COORD bufferSize;
    COORD screenBufferSize;
    COORD bufferCoord;
} ConsoleBuffer;


typedef struct Console
{
    SMALL_RECT writeRegion;
    HANDLE hConsole;
    ConsoleBuffer* consoleBuffer;

} Console;

Console* createConsole(short width, short height, float fontSizeX, float fontSizeY);
Console* createConsoleXY(short x, short y, short width, short height, float fontSizeX, float fontSizeY);

HANDLE getStandardHandle();
WORD createColor(int r, int g, int b);

void writeToConsoleBuffer(ConsoleBuffer* consoleBuffer, int colorFlag, int intensityFlag);
int writeToConsole(Console* console);
int setConsoleFontSize(Console* console, float width, float height);
void setConsoleWindowSize(Console* console, int width, int height);
