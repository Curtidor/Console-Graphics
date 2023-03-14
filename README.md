# Console-Graphics
This is a simple project that provides an easy and quick way to use the console in Windows. It consists of two header files, console.h and shapes.h, that define structs and functions for creating a console window, drawing shapes.

## Features
* Easy creation of a console window with a specified size and font size.
* Drawing of rectangles and circles with a specified color.

# Usage
To create a new console, call the createConsole() function with the desired width and height of the console, as well as the desired font size. Alternatively, you can call the createConsoleXY() function to specify both the position and the size of the console.

```c
Console* console = createConsole(80, 25, 8, 16);
```
## Drawing shapes

The library provides two functions for drawing shapes: writeRect() and writeCircle(). These functions write to the console buffer, so you'll need to call drawFrame() to display the changes on the screen.
```c
writeRect(console->consoleBuffer, 10, 10, 20, 10, randomConsoleColor());
writeCircle(console->consoleBuffer, 10, 40, 10, randomConsoleColor());
drawFrame(console);
```

## Changing the console font size
You can change the font size of the console by calling setConsoleFontSize(). Note that changing the font size may affect the size of the console window.
```c
setConsoleFontSize(console, 12, 24);
```

## Filling the buffer
Allows you to set every pixel in buffer to one color
```c
 fillConsoleBuffer(console->consoleBuffer, 0, 0);
 ```


# Example
```c
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
```
This example creates a console window with a size of 80x50 and a font size of 8x8. It then fills the console buffer with black characters. It generates random colors for the rectangle and circle and draws them in the buffer. Finally, it calls drawFrame to display the buffer in the console window.
