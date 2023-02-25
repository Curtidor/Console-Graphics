#include <stdlib.h>
#include "helper.h"

int random_int(int min, int max)
{
	return min + rand() % (max + 1 - min);
}
