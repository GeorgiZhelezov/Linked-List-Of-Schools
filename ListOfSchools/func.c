#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
#include <float.h>
#include <ctype.h>

extern int isSorted, firstZero, isDeleted;

//===============================================================================================

School_Data *AddSchool(School_Data *newest, School_Data *start) {

	School_Data *newSchool, *mostRecent = newest;
	newSchool = malloc(sizeof(School_Data));
	char read[5120] = { 0 };
	const int zeroTest = 0; 

	system("cls");


	while (1) {
	inputSchoolName:printf("Input school name: ");
		fgets(read, sizeof(read), stdin);

		if (read[0] == '\n') {
			printf("Error\n");
			goto inputSchoolName;
		}
		if (strlen(read) > 50) {
			printf("Array out of bounds !\n");
		}
		else {
			strcpy(newSchool->school_name, read);
			break;
		}
	}


inputID:printf("\nInput ID: ");
	fgets(read, sizeof(read), stdin);

	if (atoi(read) >= INT_MAX || atoi(read) <= INT_MIN) {
		printf("Error in input number !");
		goto inputID;
	}

	for (int i = 0; i < sizeof(read); i++)
	{
		if (i == 0 && (read[i] == '\n' || read[i] == '0')) {
			printf("Error");
			goto inputID;
		}
		if (i != 0 && read[i] == '\n') {
			break;
		}
		if (isalpha(read[i]) != 0 || isalnum(read[i]) == 0) {
			printf("Error ! ");
			goto inputID;
		}
	}
	newSchool->ID = atoi(read);


inputArea:printf("\nInput area: ");
	fgets(read, sizeof(read), stdin);

	if (atof(read) >= DBL_MAX || atof(read) <= DBL_MIN || atof(read) <= 0) {
		printf("Error in input number !");
		goto inputArea;
	}

	for (int i = 0; i < sizeof(read); i++)
	{
		if (read[i] == '\n') {
			break;
		}
		if (isalpha(read[i]) != 0 || isalnum(read[i]) == 0) {
			printf("Error !");
			goto inputArea;
		}
	}
	newSchool->area = atof(read);



inputNumStudents:printf("\nInput number of students: ");
	fgets(read, sizeof(read), stdin);

	if (atoi(read) >= INT_MAX || atoi(read) < 0) {
		printf("Error in input number !");
		goto inputNumStudents;
	}

	for (int i = 0; i < sizeof(read); i++)
	{
		if (read[i] == '\n') {
			break;
		}
		if (isalpha(read[i]) != 0 || isalnum(read[i]) == 0) {
			printf("Error !");
			goto inputNumStudents;
		}
	}
	newSchool->num_students = atoi(read);


	while (1) {
	inputPrincipalName:printf("\nInput principal name: ");
		fgets(read, sizeof(read), stdin);

		if (read[0] == '\n') {
			printf("Error\n");
			goto inputPrincipalName;
		}

		if (strlen(read) > 50) {
			printf("Array out of bounds !\n");
		}
		else {
			strcpy(newSchool->principal_name, read);
			break;
		}
	}

	if (!mostRecent) {
		mostRecent = newSchool;
		mostRecent->next = NULL;
	}
	else {

		mostRecent->next = newSchool;
		mostRecent->next->next = NULL;
		mostRecent = newSchool;
	}
	return newSchool;
}

//===============================================================================================

School_Data *checkID(School_Data *start) {

	School_Data *currentSchool1 = start, *temp = start;
	School_Data *currentSchool2 = NULL;
	School_Data *SchoolToDelete = NULL;

	if (currentSchool1->next != NULL) {

		while (currentSchool1 != NULL) {
			currentSchool2 = currentSchool1->next;
			if (currentSchool1->next == NULL) {
				temp = currentSchool1;
			}
			while (currentSchool2 != NULL) {
				if (currentSchool1->ID == currentSchool2->ID) {
					SchoolToDelete = currentSchool2;
					break;
				}
				currentSchool2 = currentSchool2->next;
			}
			currentSchool1 = currentSchool1->next;
		}
		if (SchoolToDelete != NULL) {

			currentSchool1 = start;

			while (currentSchool1 != NULL) {

				if (currentSchool1->next == SchoolToDelete) {
					printf("This school will be deleted becaue a school with the same ID already exists in the list\nName:%s \nID:%d \nArea:%f Number of students:%d \nPrincipal name:%s\n",
						SchoolToDelete->school_name,
						SchoolToDelete->ID,
						SchoolToDelete->area,
						SchoolToDelete->num_students,
						SchoolToDelete->principal_name);

					currentSchool1->next = SchoolToDelete->next;
					free(SchoolToDelete);

					system("pause");
					return currentSchool1;
				}
				currentSchool1 = currentSchool1->next;
			}
		}
	}
	return temp;
}

//===============================================================================================

void printList(School_Data *start) {
	int count = 0;
	School_Data *currentSchool = start;
	if (!currentSchool) {
		printf("Empty list !\n");
	}
	else {
		printf("\n");
		while (currentSchool) {
			count++;
			printf("%d. Name:%sID:%d \nArea:%.2f\nNumber of students:%d \nPrincipal name:%s\n",
				count,
				currentSchool->school_name,
				currentSchool->ID,
				currentSchool->area,
				currentSchool->num_students,
				currentSchool->principal_name);
			printf("\n");
			currentSchool = currentSchool->next;
		}
	}
}

//===============================================================================================

void cleanUp(School_Data *start) {

	School_Data *freeData = start;
	School_Data *holdData = NULL;

	while (freeData != NULL) {
		holdData = freeData->next;
		free(freeData);
		freeData = holdData;
	}
}

//===============================================================================================

int Area(School_Data *start) {

	School_Data *currentSchool = start;
	double customArea = 0;
	int count = 0;
	char read[256] = { 0 };

	if (start == NULL) {
		printf("Empty list !\n");
		system("pause");
		return 1;
	}

customAreaLoop:printf("\nInput area: ");

	fgets(read, sizeof(read), stdin);

	if (atof(read) >= DBL_MAX || atof(read) <= DBL_MIN || atof(read) <= 0) {
		printf("Error in input number !");
		goto customAreaLoop;
	}

	for (int i = 0; i < sizeof(read); i++)
	{
		if (read[i] == '\n') {
			break;
		}
		if (isalpha(read[i]) != 0 || isalnum(read[i]) == 0) {
			printf("Error !");
			goto customAreaLoop;
		}
	}
	customArea = atof(read);

	while (currentSchool != NULL) {
		if (currentSchool->area > customArea) {
			count++;
			printf("%d. Name:%s \nID:%d \nArea:%.2f\nNumber of students:%d \nPrincipal name:%s\n",
				count,
				currentSchool->school_name,
				currentSchool->ID,
				currentSchool->area,
				currentSchool->num_students,
				currentSchool->principal_name);
		}
		currentSchool = currentSchool->next;
	}
	if (count == 0) {
		printf("Nothing found\n");
	}
	system("pause");
	return 0;
}

//===============================================================================================

School_Data *Sort(School_Data *start) {

	School_Data *currentSchool = start,
		*nextSchool = currentSchool->next,
		*maxValue = start,
		*temp = NULL,
		*newStart = start,
		*previous = NULL;

	int firstSwap = 0, swap = 0, run = 1, school_counter = 1;

	if (currentSchool->next == NULL) {
		printf("\nNothing to sort\n");
		system("pause");
		return start;
	}
	while (currentSchool->next != NULL) {
		school_counter++;
		if (currentSchool->next->num_students > currentSchool->num_students &&
			maxValue->num_students < currentSchool->next->num_students) {

			maxValue = currentSchool->next;
		}
		currentSchool = currentSchool->next;
	}
	currentSchool = start;

	while (BubbleCheck(newStart, school_counter) != 0) {

		if (currentSchool->num_students < nextSchool->num_students) {

			temp = currentSchool;
			currentSchool = nextSchool;
			nextSchool = temp;
			if (previous != NULL) {
				previous->next = currentSchool;
			}
			swap = 1;
			if (firstSwap == 0) {
				firstSwap = 1;
				newStart = currentSchool;
			}

			nextSchool->next = currentSchool->next;
			currentSchool->next = nextSchool->next;

			previous = currentSchool;
			currentSchool = nextSchool;
			nextSchool = nextSchool->next;

		}
		else {

			swap = 0;
			if (firstSwap == 0) {
				firstSwap = 1;
				newStart = currentSchool;
			}

			if (previous != NULL && swap == 0) {
				previous->next = currentSchool;
			}
			previous = currentSchool;
			currentSchool = nextSchool;
			nextSchool = nextSchool->next;
		}

		if (currentSchool->next == NULL) {
			previous->next = currentSchool;
			currentSchool = newStart;
			nextSchool = currentSchool->next;
			firstSwap = 0;
			previous = NULL;
		}
	}
	isSorted = 1;
	return maxValue;
}

//===============================================================================================

School_Data *ResetNewest(School_Data *start) {

	School_Data *current_school = start;

	while (current_school->next != NULL) {
		if (current_school->next == NULL) {
			return current_school;
		}
		current_school = current_school->next;
	}
}

//===============================================================================================

int BubbleCheck(School_Data *newStart, int school_counter) {

	School_Data *SCcurrent = newStart, *SCnext = newStart->next;
	int temp = school_counter;

	SCcurrent = newStart;

	while (SCnext != NULL) {

		if (SCnext != NULL && SCcurrent->num_students < SCnext->num_students) {
			return 1;
		}
		temp--;
		SCcurrent = SCcurrent->next;
		SCnext = SCnext->next;

	}
	if (temp != 1) {
		return 1;
	}
	return 0;
}

//===============================================================================================

int EditSchool(School_Data *start) {

	School_Data *current_school = start;
	int choice = 0, IDfinder = 0;
	system("cls");
	char enter = 0, read[5120] = { 0 };

	printList(start);

inputSearchID:printf("\nType the ID of the school you want to edit: ");
	fgets(read, sizeof(read), stdin);

	if (strcmp(read, "quit\n") == 0) {
		return 1;
	}

	if (atoi(read) >= INT_MAX || atoi(read) <= INT_MIN) {
		printf("Error in input number !");
		goto inputSearchID;
	}

	for (int i = 0; i < sizeof(read); i++)
	{
		if (read[0] == '\n') {
			printf("Error");
			goto inputSearchID;
		}
		if (read[i] == '\n' && i != 0) {
			break;
		}
		if (isalpha(read[i]) != 0 || isalnum(read[i]) == 0) {
			printf("Error ! ");
			goto inputSearchID;
		}
	}
	IDfinder = atoi(read);

	while (current_school != NULL) {

		if (current_school->ID == IDfinder) {

		choice_loop:do {
			printf("\nChoose what to edit:\n1.Name\n2.ID\n3.Area\n4.Number of students\n5.Principal name\n6.Exit\nEnter a number:");
			scanf("%d%c", &choice, &enter);
		} while (choice < 1 || choice>6);

		while (1) {

			switch (choice)
			{
			case 1:
				while (1) {
				editSchoolName:printf("\nEnter a new name: ");
					fgets(read, sizeof(read), stdin);

					if (read[0] == '\n') {
						printf("Error\n");
						goto editSchoolName;
					}
					if (strlen(read) > 50) {
						printf("Array out of bounds !\n");
					}
					else {
						strcpy(current_school->school_name, read);
						break;
					}
				}
				break;
			case 2:
			editID:printf("\nEnter new ID:");
				fgets(read, sizeof(read), stdin);

				if (atoi(read) >= INT_MAX || atoi(read) <= INT_MIN) {
					printf("Error in input number !");
					goto editID;
				}

				for (int i = 0; i < sizeof(read); i++)
				{
					if (i == 0 && (read[i] == '\n' || read[i] == '0')) {
						printf("Error");
						goto editID;
					}
					if (read[i] == '\n') {
						break;
					}
					if (isalpha(read[i]) != 0 || isalnum(read[i]) == 0) {
						printf("Error ! ");
						goto editID;
					}
				}
				current_school->ID = atoi(read);
				break;
			case 3:
			editArea:printf("\nInput area: ");
				fgets(read, sizeof(read), stdin);

				if (atof(read) >= DBL_MAX || atof(read) <= DBL_MIN || atof(read) == 0) {
					printf("Error in input number !");
					goto editArea;
				}

				for (int i = 0; i < sizeof(read); i++)
				{
					if (read[i] == '\n') {
						break;
					}
					if (isalpha(read[i]) != 0 || isalnum(read[i]) == 0) {
						printf("Error !");
						goto editArea;
					}
				}
				current_school->area = atof(read);
				break;
			case 4:
			editNumStudents:printf("\nEnter the number of students:");
				fgets(read, sizeof(read), stdin);

				if (atoi(read) >= INT_MAX || atoi(read) < 0) {
					printf("Error in input number !");
					goto editNumStudents;
				}

				for (int i = 0; i < sizeof(read); i++)
				{
					if (read[0] == '\n' || (read[0] == '0' && read[1] != '\n')) {
						printf("Error");
						goto editNumStudents;
					}
					if (read[i] == '\n' && i != 0) {
						break;
					}
					if (isalpha(read[i]) != 0 || isalnum(read[i]) == 0) {
						printf("Error ! ");
						goto editNumStudents;
					}
				}
				current_school->num_students = atoi(read);
				start = DeleteZero(start);
				break;
			case 5:
				while (1) {
				editPrincipalName:printf("\nEnter a new principal name:");
					fgets(read, sizeof(read), stdin);

					if (read[0] == '\n') {
						printf("Error\n");
						goto editPrincipalName;
					}

					if (strlen(read) > 50) {
						printf("Array out of bounds !\n");
					}
					else {
						strcpy(current_school->principal_name, read);
						break;
					}
				}
				break;
			case 6:
				printf("\nExiting\n");
				return 1;
			default: return 1;
			}

			while (1) {
				if (isDeleted != 1) {
					printf("\nDo you want to continue editing ? (yes/no): ");
					char command[16];
					scanf("%s%c", &command, &enter);

					if (strcmp(command, "no") == 0) {
						return 1;
					}
					else if (strcmp(command, "yes") == 0) {
						goto  choice_loop;
					}
				}
				else {
					isDeleted = 0;
					return 1;
				}
			}
		}
		}
		else if (current_school->next == NULL) {
			printf("\nSchool not found\n");
			system("pause");
			return 0;
		}
		current_school = current_school->next;
	}
	return 1;
}

//===============================================================================================

School_Data *DeleteZero(School_Data *start) {

	School_Data *current_school = start, *previous = start, *temp = NULL;
	int confirm = 0;

	while (current_school != NULL) {

		if (current_school->num_students == 0 && current_school == start) {
			firstZero = 1;
		}

		if (current_school->num_students == 0) {
			confirm = 1;
			printf("This school will be deleted because it has 0 students:\n%s %d %f %d %s\n",
				current_school->school_name,
				current_school->ID,
				current_school->area,
				current_school->num_students,
				current_school->principal_name);

			temp = current_school;
			previous->next = current_school->next;
			current_school = current_school->next;
			free(temp);
			isDeleted = 1;
		}

		if (confirm != 1) {
			previous = current_school;
			current_school = current_school->next;
		}
		confirm = 0;
	}
	return start;
}

//===============================================================================================

int WriteToFile(School_Data *start) {

	School_Data *current_school = start, *previous = NULL, *next_school = NULL;
	FILE *fp;
	char filename[50] = { 0 };

	if (start == NULL) {
		printf("Empty list ! Nothing to save\n");
		system("pause");
		return 1;
	}

fileNameLoop:printf("\nEnter a file name:");
	fgets(filename, sizeof(filename), stdin);
	for (int i = 0; i < sizeof(filename); i++)
	{
		if (filename[i] == '\n') {
			break;
		}

		if (i != 0 && isalnum(filename[i]) != 0 &&
			filename[i + 1] == '.' &&
			filename[i + 2] == 'b' &&
			filename[i + 3] == 'i' &&
			filename[i + 4] == 'n' &&
			filename[i + 5] == '\n') {

			filename[i + 5] = '\0';
			break;
		}

		if (isalnum(filename[i]) == 0) {
			printf("Error in input file name\n");
			goto fileNameLoop;
		}
	}

	fp = fopen(filename, "wb");

	if (fp == NULL) {
		printf("\nError while opening: %s Check if it ends with .bin", filename);
		goto fileNameLoop;
	}
	else {
		printf("\nSuccessfully opened\n");
	}
	while (current_school != NULL) {

		next_school = current_school->next;
		current_school->next = NULL;

		if (fwrite(current_school, sizeof(School_Data), 1, fp) != 1) {
			printf("Error while saving");
		}

		current_school->next = next_school;
		current_school = next_school;
	}
	fclose(fp);
	return 0;
}

//===============================================================================================
int Warning(School_Data *start) {

	if (start == NULL) {
		printf("Empty list !\n");
		return 1;
	}

	School_Data *temp1 = start, *temp2 = start->next;
	while (temp1 != NULL) {
		while (temp2 != NULL)
		{
			if (temp1->ID == temp2->ID) {

				printf("\nWARNING!!! There are schools in the list with the same ID !\n\n");

				printf("School 1:\n");
				printf("Name:%sID:%d \nArea:%.2f\nNumber of students:%d \nPrincipal name:%s\n",
					temp1->school_name,
					temp1->ID,
					temp1->area,
					temp1->num_students,
					temp1->principal_name);

				printf("School 2:\n");
				printf("Name:%sID:%d \nArea:%.2f\nNumber of students:%d \nPrincipal name:%s\n",
					temp2->school_name,
					temp2->ID,
					temp2->area,
					temp2->num_students,
					temp2->principal_name);

				system("pause");
				return 1;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
		if (temp1 == NULL) {
			break;
		}
		else {
			temp2 = temp1->next;
		}
	}
	return 0;
}
//===============================================================================================

School_Data *Read(School_Data *start) {

	FILE *fp;
	char filename[16] = { 0 };

	scanf("%s", filename);

	if ((fp = fopen(filename, "rb")) == NULL) {
		printf("\nError while opening file\n");
		system("pause");
	}
	else {
		rewind(fp);
		int k = 1;

		while (k == 1) {

			if (start == NULL) {
				start = malloc(sizeof(School_Data));

				if ((k = fread(start, sizeof(School_Data), 1, fp)) == 1) {
					start->next = NULL;
				}
				else {
					printf("\nError while reading from file\n");
					system("pause");
				}

			}
			else {

				School_Data *newSchool = malloc(sizeof(School_Data));
				School_Data *current = start;

				while (current->next != NULL) {
					current = current->next;
				}

				if ((k = fread(newSchool, sizeof(School_Data), 1, fp)) == 1) {
					current->next = newSchool;
					newSchool->next = NULL;
				}
				else {
					printf("\nError while reading from file or the program has reached the end of the file\n");
					system("pause");
				}
			}
		}
	}
	fclose(fp);
	return start;
}

School_Data *qSort(School_Data *start) {

	School_Data *current_school = start;
	int counter = 0;
	School_Data *adress[] = { 0 };

	while (current_school != NULL) {
		counter++;
		current_school = current_school->next;
	}

	const int countertest = counter;
	current_school = start;

	for (int i = 0; current_school != NULL; i++)
	{
		adress[i] = malloc(sizeof(School_Data));
		adress[i] = current_school;
		current_school = current_school->next;
	}

	for (int i = 0; i<countertest; i++)
	{

		if (adress[i + 1] != NULL && adress[i]->num_students < adress[i + 1]->num_students) {
			School_Data *temp = adress[i];
			adress[i] = adress[i + 1];
			adress[i + 1] = temp;

			adress[i + 1]->next = adress[i + 2];
			adress[i]->next = adress[i + 1];

		}
	}

	return adress[0];
}

//School_Data *ArrSort(School_Data *start) {
//	
//	if (start == NULL) {
//		printf("Empty list");
//	}
//	else {
//
//		School_Data *current_school = start;
//		int counter = 0;
//		
//		while (current_school != NULL) {
//			counter++;
//			current_school = current_school->next;
//		}
//		current_school = start;
//
//		School_Data *arr[] = malloc(counter * sizeof(School_Data));
//
//		for (int i = 0; current_school != NULL; current_school = current_school->next, i++)
//		{
//			arr[i] = current_school;
//		}
//
//
//		for (int i = 0; arr[i+1]!=NULL; i++)
//		{	
//			if (arr[i]->num_students < arr[i + 1]->num_students) {
//				School_Data *temp = arr[i+1];
//				arr[i + 1] = arr[i];
//				arr[i] = temp;
//			}
//		}
//
//
//	}
//}