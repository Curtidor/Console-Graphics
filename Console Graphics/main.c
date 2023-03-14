#include <stdio.h>
#include "console.h"
#include "shapes.h"

int main()
{
    Console* console = createConsole(80, 50, 8, 8);

    fillConsoleBuffer(console->consoleBuffer, 0, 0);

    writeRect(console->consoleBuffer, 10, 10, 20, 10, rand() % 16);
    writeCircle(console->consoleBuffer, 5, 30, 30, rand() % 16);

    drawFrame(console);

    return 0;
}