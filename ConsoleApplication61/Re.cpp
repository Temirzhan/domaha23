#include <stdio.h>
#include <string.h>
#include<locale.h>
#include "Header.h"
#include<stdlib.h>
#include<time.h>

void NameA(char* name)
{
	for (int i=0; i < 20; i++)	
	{
		*(name+i) = (char)65 + rand() % 50;
	}
}

void NAME_book(char *name)
{
	int one = 0 + rand() % 9;
	int two = 0 + rand() % 9;
	char Name[10][50] = { "������� ","������� ","������ ","���������� ","����� ","������� ","����������� ","�������� ","������� ","������������ " };
	char Name2[10][50] = { "��������","�����������","��������","�������","���������������","���������","�����������","���������","����������","�������" };
	sprintf(name, "%s %s", Name[one], Name2[two]);
}