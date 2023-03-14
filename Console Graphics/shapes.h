#include "console.h"

typedef struct Pixel 
{
	CHAR_INFO char_info;
}Pixel ;


void writeRect(ConsoleBuffer* consoleBuffer, int x, int y, int width, int height, int color);
void writeCircle(ConsoleBuffer* consoleBuffer, int radius, int centerX, int centerY, int color);
