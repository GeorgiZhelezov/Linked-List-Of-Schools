# Linked-list-of-schools
My second semester assignment in my C programming class

General description of the program:

Create, edit and save a singularly linked list of schools with a name, ID, area, number of students and principle name. At first a menu will be printed to the console and the user has to input the command he wishes to run. The names of the commands are written after the arrow (->).
If a newly added school's ID matches an existing ID in the list, the newly added one will be deleted. In the "edit" function, if the user changes the number of students in a school to 0, the school will be deleted.

- „add” – add a school to the list 
- „sort“ – sort the list via Bubble sort
- „print“ – print the list
- „area“ – print the schools who have an area higher than a value entered by the user  
- „edit“ – edit a school
- „save“ – save the list to a .bin  file

Used functions:
- School_Data *AddSchool(School_Data *addingSchool, School_Data *start);
    adds a new school to the list and returns a pointer to it

- School_Data *Sort(School_Data *start);
    sorts the list via Bubble sort and returns a pointer to the first element of the list

- School_Data *ResetNewest(School_Data *start);
    resets the pointer newest so that it points to the last element of the list after it is sorted

- School_Data *DeleteZero(School_Data *start);
    if, after edditing, we have deleted the element that start points to, this function will point start to the next element

- int BubbleCheck(School_Data *newStart, int school_counter);
    checks if the list is sorted
    returns 0 if sorted or 1 if not sorted

- int EditSchool(School_Data *start);
    edit the individual data types of a school (it's name, ID, number of students or principal name) 
    returns 1 when successful

- int WriteToFile(School_Data *start);
    saves the list to a .bin file
    returns 0 when successful or 1 if the list is empty

- int Area(School_Data *start);
    prints those schools who have an area greater than an entered value
    returns 0 if successful or 1 if the list is empty

- void checkID(School_Data *start);
    checks if the ID of the newly added school does not match the ID of an existing school in the list
    if it matches one, the newly added school will be deleted

- void printList(School_Data *start);
    prints the list to the console

- void cleanUp(School_Data *start);
    cleans up the used memmory when exiting the program
