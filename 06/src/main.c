#include <stdio.h>
#include "Parser.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "invalid arguments\n");
		return 1;
	}

	ParserInit(argv[argc - 1]);
	advance();

	return 0;
}
