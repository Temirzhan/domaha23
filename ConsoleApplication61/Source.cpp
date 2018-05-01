#include <stdio.h>
#include <string.h>
#include<locale.h>
#include "Header.h"
#include<stdlib.h>
#include<time.h>
#include"Re.h"

FILE *pt;
void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int N;
	printf("Введите задание\n");
	scanf("%d",&N);
	switch (N)
	{
	case 1:
	{
		Job newJob;
		if ((pt = fopen("text", "wb")) != NULL)
		{
			printf("Наименование работы:");
			scanf("%s", newJob.Work);
			printf("Колличесвтов выделенного времени в часах:");
			scanf("%d", &newJob.time);
			printf("Колличесвтов затраченного времени в часах:");
			scanf("%d", &newJob.timeR);
			printf("Стоимость работы:");
			scanf("%d", &newJob.HowMuch);
			fwrite(&newJob, sizeof(Job), 1, pt);
			fclose(pt);
		}
		if ((pt = fopen("text", "rb+")) != NULL)
		{
			fread(&newJob, sizeof(Job), 1, pt);
			printf("%s\n", newJob.Work);
			printf("Колл выделенного времени %d\n", newJob.time);
			printf("Колл реального времени %d\n", newJob.timeR);
			printf("Стоимость работы %d \n", newJob.HowMuch);
			fclose(pt);
		}
		if ((pt = fopen("text", "wb+")) != NULL)
		{
			if ((newJob.time - newJob.timeR) >= 2)
				newJob.HowMuch *= 0.8;
			fwrite(&newJob, sizeof(Job), 1, pt);
			fclose(pt);
		}

	}
		break;
	case 2:
	{
		HP New;
		if ((pt = fopen("text2", "wb")) != NULL)
		{
			printf("Название :");
			scanf("%s", New.Name);
			printf("Срок хранения d.m.y:");
			scanf("%d.%d.%d", &New.srok.day, &New.srok.month,&New.srok.year);
			printf("Дата начало проdaжи d.m.y:");
			scanf("%d.%d.%d", &New.start.day, &New.start.month, &New.start.year);
			printf("Стоимость :");
			scanf("%d", &New.price);
			fwrite(&New, sizeof(HP), 1, pt);
			fclose(pt);
		}
		if ((pt = fopen("text2", "rb+")) != NULL)
		{
			fread(&New, sizeof(HP), 1, pt);
			printf("Название:%s\n", New.Name);
			printf("До %d.%d.%d \n", New.srok.day, New.srok.month, New.srok.year);
			printf("Дата начало проdaжи %d.%d.%d:\n", New.start.day, New.start.month, New.start.year);
			printf("Стоимость %d\n",New.price);
		}
		if ((pt = fopen("text2", "wb+")) != NULL)
		{
			float t1 = ((New.srok.day + New.srok.month * 30 ) / 365)+New.srok.year;
			float t2 = ((New.start.day + New.start.month * 30) / 365) + New.start.year;
			if ((t1-t2)>3)
				New.price *= 0.8;
			fwrite(&New, sizeof(HP), 1, pt);
			fclose(pt);
		}
	}
	break;
	case 3:
	{
		BooK *book=NULL;
		book = (BooK*)calloc(100, sizeof(BooK));
		if ((pt = fopen("text3", "wb")) != NULL)
		{
			for (int i = 0; i < 100; i++)
			{
				NameA((book+i)->AvName);
				NAME_book((book + i)->BoName);
				(book + i)->count = 1 - rand() % 100;
				(book + i) ->price= 1 - rand() % 100;
				(book + i)->date.day = 1 + rand() % 30;
				(book + i)->date.month = 1 + rand() % 12;
				(book + i)->date.year = 2018;
			}

			fwrite(book, sizeof(BooK), 100, pt);

			fclose(pt);
		}
		if ((pt = fopen("text3", "rb+")) != NULL)
		{
			fread(book, sizeof(BooK), 100, pt);
			for (int i = 0; i < 100; i++)
			{
				char NameU[50];
				strcpy(NameU, (book + i)->BoName);
				int k = 0;
				int flag =0;
				for (int f = 0; f < 100; f++)
				{
					if ((book + i)->BoName[f] == '\0')
					{
						flag = 2;
					}
					if ((book + i)->BoName[f] ==' '||flag==2)
					{
						NameU[f] = '\0';
						if (strcmp(NameU + k, "убийство") == 0)
						{
							flag = 1;
							break;
						}
							
							k = f + 1;
					}
					if (flag == 2)
					{
						break;
					}
				}
					if (flag == 1)
					{
						printf("%s\n", (book + i)->AvName);
						printf("название книги %s\n", (book + i)->BoName);
						printf("Колличество эк. %d\n", (book + i)->count);
						printf("цена . %d\n", (book + i)->price);
						printf("%d.%d.%d\n", (book + i)->date.day, (book + i)->date.month, (book + i)->date.year);
					}
			}
		}
		free(book);
	}
	break;
	case 4:
	{
		Avto *New=NULL;
		New = (Avto*)calloc(100, sizeof(Avto));
		if ((pt = fopen("text3", "wb")) != NULL)
		{
			for (int i = 0; i < 100; i++)
			{
				(New + i)->date = 1900 + rand() % 118;
				NameA((New + i)->Dvigatel);
				NameA((New + i)->MAdein);
				NameA((New + i)->Name);
				(New + i)->Probek = 0 + rand() % 100000;
				(New + i)->price = 10000 + rand() % 1000000;
			}

			fwrite(New, sizeof(Avto), 100, pt);

			fclose(pt);
		}
		if ((pt = fopen("text3", "rb+")) != NULL)
		{
			fread(New, sizeof(Avto), 100, pt);
			for (int i = 0; i < 100; i++)
			{
				if ((New + i)->Probek > 100 && (New + i)->price > 200000)
				{
					printf("%s\n", (New + i)->Name);
					printf("%s\n", (New + i)->MAdein);
					printf("Двигатель %s\n", (New + i)->Dvigatel);
					printf("год %d\n", (New + i)->date);
					printf(" цена %d\n", (New + i)->price);
					printf("%s\n", (New + i)->Name);
					printf("Пробег %d\n", (New + i)->Probek);
				}
			}
		}
		free(New);
	}
	break;
	case 5:
	{
		student *newStudent;
		newStudent = (student*)calloc(100, sizeof(student));
		if ((pt = fopen("text3", "wb")) != NULL)
		{
			for (int i = 0; i < 100; i++)
			{
				NameA((newStudent + i)->Name.Fname);
				NameA((newStudent + i)->Name.Lname);
				NameA((newStudent + i)->Name.sName);
				(newStudent + i)->bablo = 0 + rand() % 45000;
				(newStudent + i)->nomer = 1 + rand() % 5;
				(newStudent + i)->study.fiz = 0 + rand() % 100;
				(newStudent + i)->study.inform = 0 + rand() % 100;
				(newStudent + i)->study.mat = 0 + rand() % 100;
			}

			fwrite(newStudent, sizeof(student), 100, pt);

			fclose(pt);
		}
		if ((pt = fopen("text3", "rb+")) != NULL)
		{
			fread(newStudent, sizeof(student), 100, pt);
			for (int i = 0; i < 100; i++)
			{
				if ((newStudent + i)->study.fiz < 50|| (newStudent + i) ->study.inform<50|| (newStudent + i) ->study.mat<50)
				{
					(newStudent + i)->bablo *= 0.8;
				}
			}
		}
		if ((pt = fopen("text3", "wb")) != NULL)
		{
			fwrite(newStudent, sizeof(student), 100, pt);
			fclose(pt);
		}
		free(newStudent);
	}
	break;
	}
}