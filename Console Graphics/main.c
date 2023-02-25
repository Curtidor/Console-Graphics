#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "console.h"
#include "graphics.h"
#include "helper.h"


void drawTestScene(Console* console)
{
    writeRect(console, 0, 69, 269, 6, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY); //dirt
    writeRect(console, 0, 65, 269, 4, FOREGROUND_GREEN | BACKGROUND_INTENSITY); // grass
    writeRect(console, 0, 0, 20, 10, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); // sun
}


int main()
{
    Console* console = createConsole(269, 75, 8,10);
    fillConsoleBuffer(console->consoleBuffer, FOREGROUND_BLUE, FOREGROUND_INTENSITY);

    clock_t start, end;
    double cpu_time_used = 0;
    double fps = 0;
    int frame_count = 0;

    while (1) {

        // Start timing the code
        start = clock();

        // Run the code that you want to time
        /*
        for (int i = 0; i < 10; i++) {
            int x = rand() % console->consoleBuffer->bufferSize.X;
            int y = rand() % console->consoleBuffer->bufferSize.Y;
            int width = rand() % (console->consoleBuffer->bufferSize.X - x);
            int height = rand() % (console->consoleBuffer->bufferSize.Y - y + 2);
            writeRect(console, x, y, width, height, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY);
        }
        */

        drawTestScene(console);
        drawFrame(console);


        // End timing the code
        end = clock();

        // Calculate the time elapsed and print the result
        cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
        fps = 1.0 / cpu_time_used;

        // Print the frame rate every second
        frame_count++;
        if (cpu_time_used >= 1.0) {
            printf("FPS: %d\n", frame_count);
            frame_count = 0;
            cpu_time_used = 0;
        }
    }

    return 0;
}
