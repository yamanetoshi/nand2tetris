#include <string.h>

unsigned short dest(char *str)
{
	if (str == NULL)
		return 0;

	if (0 == strcmp(str, "M"))
	{
		return 1;
	}
	else if (0 == strcmp(str, "D"))
	{
		return 2;
	}
	else if (0 == strcmp(str, "MD"))
	{
		return 3;
	}
	else if (0 == strcmp(str, "A"))
	{
		return 4;
	}
	else if (0 == strcmp(str, "AM"))
	{
		return 5;
	}
	else if (0 == strcmp(str, "AD"))
	{
		return 6;
	}
	else if (0 == strcmp(str, "AMD"))
	{
		return 7;
	}
	return 0;
}

unsigned short comp(char *str)
{
	const unsigned short a = 64;

	const unsigned short c1 = 32;
	const unsigned short c2 = 16;
	const unsigned short c3 = 8;
	const unsigned short c4 = 4;
	const unsigned short c5 = 2;
	const unsigned short c6 = 1;

	if (0 == strcmp(str, "0"))
	{
		return c1 + c3 + c5;
	}
	else if (0 == strcmp(str, "1"))
	{
		return c1 + c2 + c3 + c4 + c5 + c6;
	}
	else if (0 == strcmp(str, "-1"))
	{
		return c1 + c2 + c3 + c5;
	}
	else if (0 == strcmp(str, "D"))
	{
		return c3 + c4;
	}
	else if (0 == strcmp(str, "A"))
	{
		return c1 + c2;
	}
	else if (0 == strcmp(str, "!D"))
	{
		return c3 + c4 + c6;
	}
	else if (0 == strcmp(str, "!A"))
	{
		return c1 + c2 + c6;
	}
	else if (0 == strcmp(str, "D+1"))
	{
		return c2 + c3 + c4 + c5 + c6;
	}
	else if (0 == strcmp(str, "A+1"))
	{
		return c1 + c2 + c4 + c5 + c6;
	}
	else if (0 == strcmp(str, "D-1"))
	{
		return c3 + c4 + c5;
	}
	else if (0 == strcmp(str, "A-1"))
	{
		return c1 + c2 + c5;
	}
	else if (0 == strcmp(str, "D+A"))
	{
		return c5;
	}
	else if (0 == strcmp(str, "D-A"))
	{
		return c2 + c5 + c6;
	}
	else if (0 == strcmp(str, "A-D"))
	{
		return c4 + c5 + c6;
	}
	else if (0 == strcmp(str, "D&A"))
	{
		return 0;
	}
	else if (0 == strcmp(str, "D|A"))
	{
		return c2 + c4 + c6;
	}
	else if (0 == strcmp(str, "M"))
	{
		return a + c1 + c2;
	}
	else if (0 == strcmp(str, "!M"))
	{
		return a + c1 + c2 + c6;
	}
	else if (0 == strcmp(str, "-M"))
	{
		return a + c1 + c2 + c5 + c6;
	}
	else if (0 == strcmp(str, "M+1"))
	{
		return a + c1 + c2 + c4 + c5 + c6;
	}
	else if (0 == strcmp(str, "M-1"))
	{
		return a + c1 + c2 + c5;
	}
	else if (0 == strcmp(str, "D+M"))
	{
		return a + c5;
	}
	else if (0 == strcmp(str, "D-M"))
	{
		return a + c2 + c5 + c6;
	}
	else if (0 == strcmp(str, "M-D"))
	{
		return a + c4 + c5 + c6;
	}
	else if (0 == strcmp(str, "D&M"))
	{
		return a;
	}
	else if (0 == strcmp(str, "D|M"))
	{
		return a + c2 + c4 + c6;
	}

	return 0;
}

unsigned short jump(char *str)
{
	if (NULL == str)
	{
		return 0;
	}
	else if (0 == strcmp(str, "JGT"))
	{
		return 1;
	}
	else if (0 == strcmp(str, "JEQ"))
	{
		return 2;
	}
	else if (0 == strcmp(str, "JGE"))
	{
		return 3;
	}
	else if (0 == strcmp(str, "JLT"))
	{
		return 4;
	}
	else if (0 == strcmp(str, "JNE"))
	{
		return 5;
	}
	else if (0 == strcmp(str, "JLE"))
	{
		return 6;
	}
	else if (0 == strcmp(str, "JMP"))
	{
		return 7;
	}

	return 0;
}
