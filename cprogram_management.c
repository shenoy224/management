/*
---------------------------------------------------------
/*
------------------------------------------------------------
Title       : Expense Tracking System
Language    : C
Approach    : Modular Programming
------------------------------------------------------------
AIM:
To develop a menu-driven expense tracking system using
modular programming concepts in C.

DESCRIPTION:
This program allows a user to:
1. Login using username and password
2. Add daily expenses
3. View total expenses during a session

MODULAR DESIGN:
main.c     : Contains main() function
expense.c  : Contains function definitions
expense.h  : Contains structure and function declarations

AUTHOR     : <Your Name>
DATE       : <Date>
------------------------------------------------------------
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*-------------------------------------------------------
Structure Definition
Purpose:
    To store details of a single expense
-------------------------------------------------------*/
struct Expense {
    char item_description[50];  // Description of expense
    float amount;               // Expense amount
};

/*-------------------------------------------------------
Global Variables
Purpose:
    To store expense data during program execution
-------------------------------------------------------*/
struct Expense expense_list[100]; // Array to store expenses
int expense_count = 0;            // Number of expenses

/*-------------------------------------------------------
Function Prototypes
-------------------------------------------------------*/
int login();
void mainMenu();
void addExpense();
void viewTotalExpenses();

/*-------------------------------------------------------
Main Function
Purpose:
    Program execution starts here
-------------------------------------------------------*/
int main() {
    if (login()) {
        printf("\nLogin successful. Welcome!\n");
        mainMenu();
    } else {
        printf("\nAccess Denied. Exiting program.\n");
    }
    return 0;
}

/*-------------------------------------------------------
Function Name : login
Purpose       : Authenticates user credentials
Return Type   : int
Return Value  : 1 if login successful, 0 otherwise
-------------------------------------------------------*/
int login() {
    char input_user[20];
    char input_pass[20];

    // Stored login credentials
    char correct_user[] = "user";
    char correct_pass[] = "pass";

    printf("--- Login ---\n");
    printf("Enter username: ");
    scanf("%s", input_user);

    printf("Enter password: ");
    scanf("%s", input_pass);

    // Compare input credentials with stored values
    if (strcmp(input_user, correct_user) == 0 &&
        strcmp(input_pass, correct_pass) == 0) {
        return 1;   // Login successful
    } else {
        return 0;   // Login failed
    }
}

/*-------------------------------------------------------
Function Name : mainMenu
Purpose       : Displays menu and handles user choices
-------------------------------------------------------*/
void mainMenu() {
    int choice;

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Add a new expense\n");
        printf("2. View total expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewTotalExpenses();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

/*-------------------------------------------------------
Function Name : addExpense
Purpose       : Adds a new expense to the list
-------------------------------------------------------*/
void addExpense() {
    if (expense_count >= 100) {
        printf("Expense list is full!\n");
        re
