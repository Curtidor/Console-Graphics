#include "graphics.h" 
#include "helper.h"

void writeRect(Console* console, int x, int y, int width, int height, int color)
{
    CHAR_INFO charInfo;
    charInfo.Attributes = color;
    charInfo.Char.UnicodeChar = L'█';

    for (int i = y; i < y + height; i++) {
        if (i >= console->consoleBuffer->bufferSize.Y) continue;

        for (int j = x; j < x + width; j++) {
            if (j >= console->consoleBuffer->bufferSize.X) continue;

            console->consoleBuffer->buffer[i * console->consoleBuffer->bufferSize.X + j] = charInfo;
        }
    }
}



void drawCircle(int x, int y, int radius)
{

}
