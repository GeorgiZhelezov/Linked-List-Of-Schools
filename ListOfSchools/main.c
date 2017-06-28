#include"func.h"

int isSorted = 0, firstZero = 0, isDeleted = 0;

int main() {
	/*===========================================================================

	TODO:
	-optimize code !!!;
	-fix editing when 2 schools with the same ID exist in the list !!;
	-figure out how to sort the list with an array !;
	-figure out if it's possible to sort the list with the qsort() function;

	=============================================================================*/
	char command[16], enter = 0;
	int warningCheck = 0;

	School_Data *start = NULL;
	School_Data *newest = NULL;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (1) {

		system("cls");

		printf("Type the command after the arrow (->):\n1.To add a school -> add\n");
		printf("2.To sort the list -> sort\n");
		printf("3.To print the list -> print\n");
		printf("4.To print the schools with an area greater than the set one -> area\n");
		printf("5.To edit a school -> edit\n");
		printf("6.To save the list to a .bin file -> save\n");
		printf("7.To quit -> quit\n");

		printf("Command: ");
		scanf("%s%c", command, &enter);

		if (strcmp(command, "quit") == 0) {
			printf("Qutting\n");
			system("pause");
			break;
		}
		else if (strcmp(command, "print") == 0) {
			printList(start);
			printf("\n\n");
			system("pause");
		}
		else if (strcmp(command, "add") == 0) {
			if (start == NULL) {
				start = AddSchool(NULL, NULL);
				newest = start;
			}
			else {
				newest = AddSchool(newest, start);
			}
			newest = checkID(start);
		}
		else if (strcmp(command, "area") == 0) {
			Area(start);
		}
		else if (strcmp(command, "sort") == 0) {
			if (start == NULL) {
				printf("Empty list !\n");
				system("pause");
			}
			else {
				start = Sort(start);
				newest = ResetNewest(start);
			}
		}
		else if (strcmp(command, "edit") == 0) {
			if (start == NULL) {
				printf("Empty list !\n");
				system("pause");
			}
			else {
				int status = 0;
				School_Data *temp = start->next;
				do {
					status = EditSchool(start);
				} while (status != 1);
				if (isSorted == 1 && firstZero == 1) {
					start = temp;
				}
				else if (firstZero == 1) {
					start = temp;
				}
				warningCheck = Warning(start);
			}
		}
		else if (strcmp(command, "save") == 0) {
			if ((warningCheck = Warning(start)) == 1) {
				printf("\nCan not save !\n");
				system("pause");
			}
			else {
				WriteToFile(start);
			}
		}
		else if (strcmp(command, "read") == 0) {
			cleanUp(start);
			start = NULL;
			start = Read(start);
		}
		else if (strcmp(command, "qsort") == 0) {
			//start = qSort(start);
		}
		else if (strcmp(command, "arrsort") == 0) {
			//start = ArrSort(start);
		}
	}
	cleanUp(start);
	return 0;
}