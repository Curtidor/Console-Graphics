#include <math.h>
#include "shapes.h" 


static Pixel pixel = { L'█', FOREGROUND_RED | FOREGROUND_INTENSITY };

void writeRect(ConsoleBuffer* consoleBuffer, int x, int y, int width, int height, int color)
{

    pixel.char_info.Attributes = color;

    for (int i = y; i < y + height; i++) {
        if (i >= consoleBuffer->bufferSize.Y) continue;

        for (int j = x; j < x + width; j++) {
            if (j >= consoleBuffer->bufferSize.X) continue;

            consoleBuffer->buffer[i * consoleBuffer->bufferSize.X + j] = pixel.char_info;
        }
    }
}

void writeCircle(ConsoleBuffer* consoleBuffer, int radius, int centerX, int centerY, int color)
{
    int x, y;
    double angle, radians;

    const double PI = 3.14159265359;

    pixel.char_info.Attributes = color;


    for (y = 0; y < consoleBuffer->bufferSize.Y; y++)
    {
        for (x = 0; x < consoleBuffer->bufferSize.X; x++)
        {
            double distance = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));

            if (distance <= radius)
            {
                consoleBuffer->buffer[x + y * consoleBuffer->bufferSize.X] = pixel.char_info;
            }
        }
    }
}





