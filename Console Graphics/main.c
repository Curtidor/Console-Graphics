#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "console.h"

int main()
{
    Console* console = createConsole(132, 34, 8, 8);
    writeToConsoleBuffer(console->consoleBuffer, FOREGROUND_BLUE, FOREGROUND_INTENSITY);


    clock_t start, end;
    double cpu_time_used = 0;
    double fps = 0;
    int frame_count = 0;

    while (1) {

        // Start timing the code
        start = clock();

        // Run the code that you want to time
        writeToConsoleBuffer(console->consoleBuffer, FOREGROUND_BLUE, FOREGROUND_INTENSITY);
        writeToConsole(console);

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