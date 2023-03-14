#include <stdlib.h>
#include "console.h"
#include "shapes.h"



int main()
{

    Console* console = createConsole(270, 60, 10, 8);
    fillConsoleBuffer(console->consoleBuffer, FOREGROUND_BLUE, FOREGROUND_INTENSITY);


    while (1) {

        // Start timing the code
        int x = rand() % console->consoleBuffer->bufferSize.X;
        int y = rand() % console->consoleBuffer->bufferSize.Y;

        writeCircle(console->consoleBuffer, rand() % 10 + 1, x, y, rand() % 16);

        //drawTestScene(console);
        drawFrame(console);
    }

    return 0;
}
