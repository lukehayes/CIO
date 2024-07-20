
#include <stdio.h>
#include "io.h"


int main(int argc, char *argv[])
{
	const char* f = ReadFile("../main.c");

	printf("%s \n", f);


	free(f);
}
