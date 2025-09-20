#include <stdio.h>
#include "main.h"
#include <string.h>

int main(){
    printf("Welcome to fiuk bank! Please create an account. \n");
    struct Account acc1 = create_account();
    display_account(acc1);

    deposit(&acc1);
    withdraw(&acc1);

    display_account(acc1);
    return 0;
}