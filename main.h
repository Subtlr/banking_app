#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ACC_NAME_LEN 48

struct Account
{
    int account_id;
    char account_name[MAX_ACC_NAME_LEN];
    float balance;
};

void display_account(struct Account acc){
    for (size_t i = 0; i < 20; i++)
    {
        printf("-");
    }
    
    printf("\nAccount ID: %d\n", acc.account_id);
    printf("Account Name: %s", acc.account_name);
    printf("Balance: $%.2f\n", acc.balance);

    for (size_t i = 0; i < 20; i++)
    {
        printf("-");
    }
    printf("\n");
}

struct Account create_account(){
    char acc_name[MAX_ACC_NAME_LEN];
    while (1){
        char *name_buffer = malloc(10000);
        if (!name_buffer) {
            printf("Memory allocation failed. \n");
        }

        printf("\nEnter the name of your account: ");
        if (fgets(name_buffer, 10000, stdin) == NULL)
        {
            fprintf(stderr, "Something went wrong, please try again. \n");
            free(name_buffer);
        }

        size_t length = strlen(name_buffer);
        printf("\nLength of the buffer %d\n", length);
        if (length > MAX_ACC_NAME_LEN)
        {
            fprintf(stderr, "Error: Account name too long. Max %d characters allowed.\n", MAX_ACC_NAME_LEN);
            free(name_buffer);
        }
        
        if (length < MAX_ACC_NAME_LEN)
        {
            printf("Name chosen: %s\n", name_buffer);
            strcpy(acc_name, name_buffer);
            break;
        }
        
    }
    
    struct Account acc;
    acc.account_id = 1;
    strcpy(acc.account_name, acc_name);
    acc.balance = 0;
    return acc;
}

void deposit(struct Account *acc){
    float money_deposited = 0.0;
    while (1)
    {
        float deposit_buffer;
        printf("\nHow much would you like to deposit?: ");
        scanf("%f", &deposit_buffer);
        if (deposit_buffer < 0)
        {
            printf("You can't deposit negative money, please use the withdrawal function. \n");
        } else if (deposit_buffer > 99999) {
            printf("You are trying to deposit too much money! \n");
        } else {
            printf("$%.2f successfully deposited into the account. \n", deposit_buffer);
            money_deposited = deposit_buffer;
            break;
        }
    }
    acc->balance += money_deposited;
    printf("You now have $%f.\n", acc->balance);
}

void withdraw(struct Account *acc){
    float money_withdrawed = 0.0;
    
    if (acc->balance <= 0)
    {
        printf("You do not have any money.\n");
        return;
    }
    
    
    while (1)
    {
        float withdraw_buffer = 0;
        printf("\nHow much would you like to withdraw?: ");
        scanf("%f", &withdraw_buffer);
        if (!withdraw_buffer)
        {
            printf("\nSomething went wrong, please try again. \n");
        } else if (withdraw_buffer < 0) {
            printf("\nYou cannot withdraw negative money, please use the deposit function. \n");
            break;
        } else if (withdraw_buffer > acc->balance) {
            printf("You do not have enough money to withdraw $%f\n", withdraw_buffer);
        } else {
            money_withdrawed = withdraw_buffer;
            printf("\nSuccesfully withdrawed $%f \n", money_withdrawed);
            acc->balance -= money_withdrawed;
            break;
        }
    }
}

void program_loop(){
    printf("Welcome to fiuk bank! Please create an account.\n");
    struct Account acc = create_account();
    while (1)
    {
        printf("Current account: %s\n", acc.account_name);
        printf("What would you like to do? \n1) Check account; \n2) Withdraw; \n3) Deposit. \nType in the number of the action you want to do: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_account(acc);
            break;
        case 2:
            withdraw(&acc);
            break;
        case 3:
        deposit(&acc);
        break;
        }   
    }   
}