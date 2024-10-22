#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 100

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

// Function prototypes
void addExpense(Expense expenses[], int *count);
void viewExpenses(Expense expenses[], int count);
void deleteExpense(Expense expenses[], int *count);
void viewTotalExpenses(Expense expenses[], int count);

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. View Total Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                deleteExpense(expenses, &count);
                break;
            case 4:
                viewTotalExpenses(expenses, count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }
    printf("Enter description: ");
    fgets(expenses[*count].description, DESCRIPTION_LENGTH, stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0; // Remove newline

    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);
    getchar(); // to consume the newline character

    (*count)++;
    printf("Expense added!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses available.\n");
        return;
    }
    printf("\nExpenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    int index;
    printf("Enter expense number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid expense number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--;
    printf("Expense deleted!\n");
}

void viewTotalExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses available to calculate total.\n");
        return;
    }
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}
