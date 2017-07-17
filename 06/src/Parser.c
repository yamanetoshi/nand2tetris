#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Parser.h"
#include "Code.h"

FILE *fpr = NULL;
#define BUFSIZE 255

char buffer[BUFSIZE];
char abuffer[BUFSIZE];
char destbuffer[BUFSIZE];
char jmpbuffer[BUFSIZE];
char compbuffer[BUFSIZE];

char *parseDest(char *);
char *parseComp(char *);
char *parseJump(char *);

#define BitSize 16

void strrev(char s[]){
    char temp = '\0';
    char *first = s;
    char *last = s;

    // 長さ0の文字列なら操作せず返す
    if(*first == '\0'){ return; }

    // 文字列の最後の文字のポインタを取得する
    while( *(last+1) != '\0'){ last++; }

    // 外側から逆にする
    while(first < last){
        temp = *first;
        *first = *last;
        *last = temp;

        // 一つずつ範囲を小さくする
        first++;
        last--;
    }
    return;
}

void us2binstr(char *str, unsigned short us)
{
	int bit = 1, i;
//	char c[BitSize];
 
	for (i = 0; i < BitSize; i++) {
		if (us & bit)
			str[i] = '1';
		else
			str[i] = '0';
		bit <<= 1;
	}
}

/**
 * 文字列の先頭と末尾にある空白を削除する
 * @param[in] s  対象文字列
 * @return 削除した空白の数を返す
 */
int trim(char *s) {
	int i;
	int count = 0;

	/* 空ポインタか? */
	if ( s == NULL ) { /* yes */
		return -1;
	}

	/* 文字列長を取得する */
	i = strlen(s);

	/* 末尾から順に空白でない位置を探す */
	while ( --i >= 0 && s[i] == ' ' ) count++;

	/* 終端ナル文字を付加する */
	s[i+1] = '\0';

	/* 先頭から順に空白でない位置を探す */
	i = 0;
	while ( s[i] != '\0' && s[i] == ' ' ) i++;
	strcpy(s, &s[i]);

	return i + count;
}

void lntrim(char *str) {  
	char *p;  

	p = strchr(str, '\n');  
	if(p != NULL) {  
		*p = '\0';  
	}  

	p = strchr(str, '\r');  
	if(p != NULL) {  
		*p = '\0';  
	}  
}  

void ParserInit(char *filename)
{
	if ((fpr=fopen(filename,"r"))==NULL)
	{
		fprintf(stderr, "cannot open file : %s\n", filename);
		exit(1);
	}
}

void advance()
{
	while(1)
	{
		if (NULL == fgets(buffer, BUFSIZE , fpr))
			break;

		lntrim(buffer);
		trim(buffer);

		if (buffer[0] == '\0')
			continue;
		if (buffer[0] == '/' && buffer[1] == '/')
			continue;
		
		if (A_COMMAND == commandType(buffer))
		{
			printf("%s\n", symbol(buffer));
			
		} else if (C_COMMAND == commandType(buffer))
		{
//			printf("\n");

			unsigned short tmp = 7;
			tmp = tmp << 13;

			char compstr[BUFSIZE];
			memset(compstr, '\0', sizeof(compstr));
			unsigned short compint = comp(parseComp(buffer));
			us2binstr(compstr, compint);
			strrev(compstr);
//			printf("%s\n", compstr);

			tmp |= compint << 6;

			char deststr[BUFSIZE];
			memset(deststr, '\0', sizeof(deststr));
			unsigned short destint = dest(parseDest(buffer));
			us2binstr(deststr, destint);
			strrev(deststr);
//			printf("%s\n", deststr);
//			printf("%016d\n", destint);

			tmp |= destint << 3;

			char jmpstr[BUFSIZE];
			memset(jmpstr, '\0', sizeof(jmpstr));
			unsigned short jmpint = jump(parseJump(buffer));
			us2binstr(jmpstr, jmpint);
			strrev(jmpstr);
//			printf("%s\n", jmpstr);

			tmp |= jmpint;
			char outstr[BUFSIZE];
			memset(outstr, '\0', sizeof(outstr));
			us2binstr(outstr, tmp);
			strrev(outstr);
//			printf("\n");
			printf("%s\n", outstr);

//			printf("\n");
		}
	}

	fclose(fpr);
	fpr = NULL;
}

enum cmdType commandType(char *str)
{
	if (str[0] == '@')
	{
		return A_COMMAND;
	} else
	{
		return C_COMMAND;
	}
}

char *symbol(char *str)
{
	str[0] = '0';
//	unsigned short symint = (unsigned short)(0xefff & atoi(str));
	unsigned short symint = (unsigned short)atoi(str);
	us2binstr(abuffer, symint);
	strrev(abuffer);
	abuffer[0] = '0';

	return abuffer;
}

char *parseDest(char *str)
{
	char *deststr = NULL;

	strcpy(destbuffer, str);
	deststr = strchr(destbuffer, '=');

	if (deststr == NULL)
	{
		return NULL;
	}
	else
	{
		*deststr = '\0';
		return destbuffer;
	}
}

char *parseComp(char *str)
{
	char *deststr = NULL;
	char *compstr = NULL;
	char *jumpstr = NULL;

	strcpy(compbuffer, str);
	deststr = strchr(compbuffer, '=');
	jumpstr = strchr(compbuffer, ';');

	if (jumpstr != NULL)
		*jumpstr = '\0';

	if (deststr == NULL)
	{
		compstr = compbuffer;
	}
	else
	{
		compstr = deststr + 1;
	}

	return compstr;
}

char *parseJump(char *str)
{
	strcpy(jmpbuffer, str);
	char *jmpstr = NULL;

	jmpstr = strchr(jmpbuffer, ';');

	if (jmpstr == NULL)
	{
		return NULL;
	}
	else
	{
		return jmpstr + 1;
	}

	return NULL;
}
