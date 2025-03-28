// CIrcular Array Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 10
#pragma warning(disable: 4996)


void initializeArray(int array[]); //Setting all initial indices to NULL
void addElement(int *index, int element, int array[]);  //Adding
int identifyElement(int index, int array[]);    //Accessing
void deleteElement(int index, int array[]);    //Deleting
void findHighest(int index, int array[]);   //Traversing
void displayAll(int index, int array[]);
double getNum(void); 

void main(void)
{
    int choice;
    int add;
    int index = 0;
    int circularArray[ARRAY_SIZE];
    int indexToDelete;
    int show;
    bool exit = false;
    initializeArray(circularArray);
    
    while (!exit)
    {
        printf("\nPress a button:\n 1) Add\n 2) Display Index\n 3) Delete Index\n 4)Find highest index\n 5) Display All\n 6) Exit");
        choice = (int)getNum();
        switch (choice)
        {
        case 1:
            printf("What element would you like to add?");
            add = (int)getNum();
            addElement(&index, add, circularArray);
        break;
        case 2:
            printf("What index would you like to show?");
            show = (int)getNum();
            if (show >= 0 && show <= 9)
            {
                printf("value at index %d is %d\n", show, circularArray[show]);
                printf("that index was added %d additions ago", index);
            }
            else
            {
                printf("invalid index request");
            }
            break;
        case 3:
            printf("How many 'elements ago' would you like to delete. Select 0 for most recent element");
            indexToDelete = (int)getNum();
            if (indexToDelete >= 0 && indexToDelete <= 9)
            {
                deleteElement(indexToDelete, circularArray);
            }
            else
            {
                printf("invalid index\n");
            }
            break;
        case 4:
            findHighest(index-1, circularArray);
            break;
        case 5:
            displayAll(index-1, circularArray);
            break;
        case 6:
            exit = true;
        default:
            printf("Not a valid choice. Try again\n");
            break;
        }
    }
    return;
}

void initializeArray(int array[]) //Setting all initial indices to NULL
{
    int arraySize = ARRAY_SIZE - 1;
    for (int i = 0;i <= arraySize; i++)
    {
        array[i] = NULL;
    }
    return;
}

void addElement(int* index, int element, int array[])  //Adding
{
    array[*index] = element;
    if (*index == ARRAY_SIZE - 1)
    {
        *index = 0;
        return;
    }
    (*index)++;
    return;
}

int identifyElement(int index, int array[])   //Accessing
{
    return array[index];
}

void deleteElement(int index, int array[])    //Deleting
{
    if (array[index] != NULL)
    {
        array[index] = NULL;
        return;
    }
    else
    {
        printf("Array index is already unoccupied");
    }
}

void findHighest(int index, int array[])   //Traversing
{
    int i = 0;
    int highestValue = 0;
    int valueIndex = 0;
    while (i < ARRAY_SIZE)
    {
        if (array[index] != NULL && array[index] >= highestValue)
        {
            highestValue = array[index];
            valueIndex = i; 
        }
        index--;
        if (index < 0)
        {
            index += ARRAY_SIZE;
        }
        i++;
    }
    
    printf("The highest (most recent) value in the array is %d\n", highestValue);
    printf("That value was added %d additions ago", valueIndex);
    return;
}

void displayAll(int index, int array[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (array[index] == NULL)
        {
            printf("Index added %d ago:  Empty\n", i);
        }
        else
        {
            printf("Index added %d ago: %d\n", i, array[index]);
        }
        index--;
        if (index < 0)
        {
            index += ARRAY_SIZE;
        }
    }
}
double getNum(void) {
    char record[121] = { 0 }; // Buffer to store input string
    double number = 0.0; // Variable to store the converted number

    // Prompt the user for input and read the input string
    fgets(record, 121, stdin);

    // Attempt to convert the string to a double
    if (sscanf(record, "%lf", &number) != 1.0) {

        // If conversion fails, set the number to -1
        number = -1.0;
    }

    return number; // Return the double (or -1 if conversion failed)
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
