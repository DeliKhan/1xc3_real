#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*This function takes a string input and checks it for any input errors
if flag is true, that means there is an error in input
if flag is false, then there is no error in input*/
void check_input(bool *flag, char *amount, long double *balance)
{
    int counter = 0; // counter will count the number of decimal points (to catch multiple decimal point error)
    /*Check to see if there is any unusual characters or multiple decimal points*/
    for (int i = 0; amount[i] != '\0'; i++) // loop until end of string
    {
        // ASCII code for numbers 0-9 is 48-57, and a period ()'.') is 46
        if ((int)amount[i] >= 48 && (int)amount[i] <= 57) // check if number
        {
            *flag += false; // no error
        }
        else if ((int)amount[i] == 46) // check if its a decimal point
        {
            if (++counter > 1) // add this decimal point and if we have more than one decimal point, its an error
            {
                *flag += true;
                printf("Error: multiple decimal points. Try again\n");
            }
        }
        else // if its some other random character
        {
            *flag += true;
            printf("Error: invalid character found: %c. Try again\n", amount[i]);
        }
    }
    *balance = atof(amount); // convert to long double
    /* Check to see if balance has only 2 decimal places only if it passed the first test & has a decimal point*/
    if (*flag == false && counter != 0)
    {
        char copy_balance[100]; // strtok modifies string, so create a copy
        strcpy(copy_balance, amount);
        char *parts;                       // token which will hold the split string
        parts = strtok(copy_balance, "."); // split string at decimal point and take first value
        printf("%s\n", parts);
        parts = strtok(NULL, "."); // take second value (part after decimal point) and split string at decimal point
        printf("%s\n", parts);
        if (strlen(parts) > 2) // if value after decimal point is more than 2 characters, it has too many decimal places
        {
            *flag += true;
            printf("Error: you put too many numbers after the decimal point. Try again\n");
        }
    }
}

int main()
{
    bool flag = false;                // flag that will be raised for input errors
    char balance_input[100] = {'\0'}; // where the initial balance input will be stored as a string
    long double balance = 0.0;        // where the initial balance input will be stored as a number
    do                                // continuously ask for initial balance til they give one of proper format
    {
        flag = false;
        printf("What is your initial balance? Write in the format Dollars.cents");
        scanf("%s", &balance_input[0]); // the warning can be solved with &balance_input[0]
        // balance = atof(balance_input);
        check_input(&flag, balance_input, &balance);
    } while (flag);
    int choice = 0; // user input on what operation they want to do
    printf("Select an operation: \n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("0. exit\n");
    printf("Input the corresponding number:");
    scanf("%d", &choice);
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
        {
            char deposit_input[100] = {'\0'}; // where input of deposit amount is stored as string
            long double deposit = 0.0;        // deposit input amount stored as number
            do                                // continuously ask for deposit amount til its the right format
            {
                flag = false;
                printf("Enter amount to deposit  ");
                scanf("%s", &deposit_input[0]);
                check_input(&flag, deposit_input, &deposit);
            } while (flag);
            balance += deposit;
            snprintf(balance_input, 100, "%Lf", balance); // update string input of balance with new balance
            break;
        }
        case 2:
        {
            char withdraw_input[100] = {'\0'}; // where input of withdraw amount is stored as a string
            long double withdraw = 0.0;        // withdraw input amount stored as number
            do                                 // continuously ask for withdraw amount til its the right format
            {
                flag = false;
                printf("Enter amount to withdraw  ");
                scanf("%s", &withdraw_input[0]);
                check_input(&flag, withdraw_input, &withdraw);
            } while (flag);
            balance -= withdraw;
            snprintf(balance_input, 100, "%Lf", balance); // update string input of balancce with new balance
            break;
        }
        case 3:
        {
            printf("Your current balance is: $%.2Lf\n", balance);
            break;
        }
        default:
        {
            printf("Invalid option. Try again\n");
            break;
        }
        }
        printf("Select an operation: \n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("0. exit\n");
        printf("Input the corresponding number: ");
        scanf("%d", &choice);
    }
}