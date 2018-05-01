#pragma once
struct Job
{
	char Work[100];
	int time;
	int timeR;
	int HowMuch;
};

struct Date
{
	int day;
	int month;
	int year;
};
struct  HP
{
	char Name[100];
	Date srok;
	Date start;
	int price;
};
struct BooK
{
	char AvName[100];
	char BoName[100];
	int count;
	int price;
	Date date;

};

struct Avto
{
	char Name[100];
	char MAdein[100];
	int date;
	char Dvigatel[100];
	int Probek;
	int price;
};
struct namestud
{
	char Fname[100];
	char Lname[100];
	char sName[100];
};
struct Study
{
	int mat; 
	int fiz;
	int inform;
};
struct student
{
	namestud Name;
	int nomer;
	Study study;
	int bablo;
};