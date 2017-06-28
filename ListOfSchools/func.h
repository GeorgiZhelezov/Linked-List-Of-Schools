#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

typedef struct struct_school {

	char school_name[50];
	int ID; 
	double area;
	int num_students;
	char principal_name[50];
	struct struct_school *next;

}School_Data;

School_Data *AddSchool(School_Data *newest, School_Data *start);
School_Data *Sort(School_Data *start);
School_Data *ResetNewest(School_Data *start);
School_Data *DeleteZero(School_Data *start);
School_Data *Read(School_Data *start);
School_Data *checkID(School_Data *start);
School_Data *qSort(School_Data *start);

//School_Data *ArrSort(School_Data *start);
//int qSortCompare(const void * a, const void * b);

int BubbleCheck(School_Data *newStart, int school_counter);
int EditSchool(School_Data *start);
int WriteToFile(School_Data *start);
int Area(School_Data *start);
int Warning(School_Data *start);

void printList(School_Data *start);
void cleanUp(School_Data *start);

