#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

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
        parts = strtok(NULL, ".");         // take second value (part after decimal point) and split string at decimal point
        if (strlen(parts) > 2)             // if value after decimal point is more than 2 characters, it has too many decimal places
        {
            *flag += true;
            printf("Error: you put too many numbers after the decimal point. Try again\n");
        }
    }
}

/* A version of the above function, but doesn't flag error if more than 2 decimal places*/
void check_interest_input(bool *flag, char *percentage_input, long double *percentage)
{
    /*Check to see if there is any unusual characters or multiple decimal points*/
    int counter = 0;
    for (int i = 0; percentage_input[i] != '\0'; i++)
    {
        // ASCII code for numbers 0-9 is 48-57, and a period ()'.') is 46
        if ((int)percentage_input[i] >= 48 && (int)percentage_input[i] <= 57)
        {
            *flag += false;
        }
        else if ((int)percentage_input[i] == 46)
        {
            counter++;
            if (counter > 1)
            {
                *flag += true;
                printf("Error: multiple decimal points. Try again\n");
            }
        }
        else
        {
            *flag += true;
            printf("Error: invalid character found: %c. Try again\n", percentage_input[i]);
        }
    }
    *percentage = atof(percentage_input);
}

// Only checks for invalid characters and converts to integer
void mini_check_characters(bool *flag, char *input, int *result)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        // ASCII code for numbers 0-9 is 48-57, and a period ()'.') is 46
        if ((int)input[i] >= 48 && (int)input[i] <= 57)
        {
            *flag += false;
        }
        else
        {
            *flag += true;
            printf("Error: invalid character found: %c. Try again\n", input[i]);
        }
    }
    *result = atoi(input);
}

int main()
{
    bool flag = false;                      // flag that will be raised for input errors
    char interest_rate_input[100] = {'\0'}; // where the interest rate input will be stored as string
    long double interest_rate = 0.0;        // where the interest rate input will be stored as a number
    do                                      // continuously ask input til given in proper format
    {
        flag = false;
        printf("What is the current interest rate? Write as a percentage without percentage sign    ");
        scanf("%s", &interest_rate_input[0]);
        check_interest_input(&flag, interest_rate_input, &interest_rate);
    } while (flag);
    /*                                   Get accounts                                             */
    char number_of_accounts_input[3] = {'\0'}; // string input of number of accounts
    int number_of_accounts = 10;               // initialized as maximum number of accounts
    long double accounts[10] = {0.0};          // array that holds all accounts, set to max number of accounts
    do                                         // continuously loop til proper format given (a number)
    {
        flag = false;
        printf("Please type the number of accounts you'd like to have   ");
        scanf("%s", &number_of_accounts_input[0]);
        mini_check_characters(&flag, number_of_accounts_input, &number_of_accounts);
        if (number_of_accounts == 0 || number_of_accounts > 10) // check to make sure the number of accounts isn't 0 or more than the maximum (10)
        {
            flag += true;
            printf("Invalid number of accounts. Try again\n");
        }
    } while (flag);
    char balance_input[100] = {'\0'};            // where the initial balance input will be stored as a string
    long double balance = 0.0;                   // where the initial balance input will be stored as a number
    for (int t = 0; t < number_of_accounts; t++) // loop to get initial balance for each account
    {
        do
        {
            flag = false;
            printf("What is your initial balance for account %d? Write in the format Dollars.Cents    ", t + 1);
            scanf("%s", &balance_input[0]);
            check_input(&flag, balance_input, &balance);
        } while (flag);
        accounts[t] = balance;
    }
    int current_account = 0;                              // will store the account number currently in use
    int choice = 0;                                       // user input on what operation they want to do
    printf("Current Account: %d\n", current_account + 1); // remember, user thinks account starts from 1, not 0, so add one
    printf("Select an operation: \n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Future Balance Using Interest Rate\n");
    printf("5. Switch Account\n");
    printf("6. Display All Balances\n");
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
            accounts[current_account] += deposit; // add to balance of the specific account
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
                if (withdraw > accounts[current_account]) // check if the person is withdrawing more than they have in current account
                {
                    flag += true;
                    printf("Error: Withdraw amount is more than amount in balance. Try again\n");
                }
            } while (flag);
            accounts[current_account] -= withdraw; // subtract from balance of the specific account
            break;
        }
        case 3:
        {
            // remember, current_account starts with 0, so when presenting to user, change to starting with 1
            printf("Your current balance of account %d is: $%.2Lf\n", current_account + 1, accounts[current_account]);
            break;
        }
        case 4:
        {
            char years_input[100] = {'\0'};   // where the number of years will be stored as a string
            int years = 0;                    // where the number of years will be stored as a number
            long double future_balance = 0.0; // the new balance after x years on y interest rate
            do                                // continuously loop til proper format is inputted
            {
                flag = false;
                printf("Input the number of years  ");
                scanf("%s", &years_input[0]);
                mini_check_characters(&flag, years_input, &years);
            } while (flag);
            future_balance = balance * powl(1 + interest_rate / 100, years); // powl(a,b) returns a^b as a long double
            // The below is an aesthetic, it will singularize or pluralize the word based on number of years
            if (years == 1)
            {
                printf("The future balance in %s year will be $%.2Lf for account %d\n", years_input, future_balance, current_account + 1);
            }
            else
            {
                printf("The future balance in %s years will be $%.2Lf for account %d\n", years_input, future_balance, current_account + 1);
            }
            break;
        }
        case 5:
        {
            char current_account_input[4] = {'\0'}; // this stores the new account number we want to swap to
            do                                      // continuously loop til proper format given (a number)
            {
                flag = false;
                printf("Which account would you like to switch to? ");
                scanf("%s", &current_account_input[0]);
                mini_check_characters(&flag, current_account_input, &current_account);
            } while (flag);
            current_account--; // remember, the value the user gives is based on 1 being the start, we want it to start from 0, so minus 1
            break;
        }
        case 6:
        {
            for (int i = 0; i < number_of_accounts; i++) // loop through each element and print its value
            {
                printf("Balance in account %d: $%.2Lf\n", i + 1, accounts[i]);
            }
            break;
        }
        default:
        {
            printf("Invalid option. Try again\n");
            break;
        }
        }
        printf("Current Account: %d\n", current_account + 1);
        printf("Select an operation: \n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Future Balance Using Interest Rate\n");
        printf("5. Switch Account\n");
        printf("6. Display All Balances\n");
        printf("0. exit\n");
        printf("Input the corresponding number:");
        scanf("%d", &choice);
    }
}