#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bankAccount {
    char name[100];
    int accountNumber;
    float balance;
} newAccount;

newAccount set_bankAccount(char name[100], int accountNumber, float balance){
    newAccount Account;
    strcpy(Account.name, name);
    Account.accountNumber = accountNumber;
    Account.balance = balance;
    return Account;
    
}

void get_bankAccount(newAccount Account){
    printf("%s\n", Account.name);
    printf("%i\n", Account.accountNumber);
    printf("%f\n", Account.balance);
    printf("Account data returned");
}

void check_bankAccount(newAccount Account){
    float b = Account.balance;
    
    if(b < 0){
        printf("Bank account is overdrawn\n");
    }
}

int main(){
    
    newAccount *pAccounts = (newAccount *)calloc(5, sizeof(newAccount));
    
    pAccounts[1] = set_bankAccount("Richard Rich", 12345, -5000);
    
    get_bankAccount(pAccounts[1]);
    
    check_bankAccount(pAccounts[1]);
    
    return 0;
}
