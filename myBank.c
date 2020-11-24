#include <stdio.h>
#include "myBank.h"
#define MAX 50
#define START 901
#define MAX_ACCOUNT 950

static int cnt = 901;
static float ACCOUNTS [MAX][2] = {{0}};

void open(float initDepos){
    if(cnt <= MAX_ACCOUNT){
        ACCOUNTS[cnt-START][0] = (float)cnt;
        ACCOUNTS[cnt-START][1] = initDepos;
        printf("Your new account number is: %.0f and your balance is: %.2f\n" ,ACCOUNTS[cnt-START][0], ACCOUNTS[cnt-START][1]);
        cnt++;
    }
    else{
        printf("Sorry, but there is maximum number of accounts.\n");
    }
}

void balance(int accountNum){
    if(ACCOUNTS[accountNum-START][0] != 0){
        printf("Your balance is: %.2f\n", ACCOUNTS[accountNum-START][1]);
    }
    else{
        printf("This account is not exist.\n");
    }
}

void deposit(int accountNum, float amount){
    if(ACCOUNTS[accountNum-START][0] != 0){
        ACCOUNTS[accountNum-START][1] += amount;
        printf("Your new balance is: %.2f\n", ACCOUNTS[accountNum-START][1]);
    }
    else{
        printf("This account is not exist.\n");
    }
}

void withdraw (int accountNum, float amount){
    if(ACCOUNTS[accountNum-START][0] != 0 && ACCOUNTS[accountNum-START][1]-amount >= 0){
        ACCOUNTS[accountNum-START][1] -= amount;
        printf("Your new balance is: %.2f\n", ACCOUNTS[accountNum-START][1]);
    }
    else{
        printf("This account is not exist.\n");
    }
}

void close(int accountNum){
    if(ACCOUNTS[accountNum-START][0] != 0){
        ACCOUNTS[accountNum-START][0] = 0;
    }
    else{
        printf("This account is not exist.\n");
    }
}

void addInt(float interestRate){
    for(int i=START; i<MAX_ACCOUNT; i++){
        if(ACCOUNTS[i-START][0] != 0){
            ACCOUNTS[i-START][1] += ACCOUNTS[i-START][1]*interestRate;
        }
    }
}

void toString (){
    for(int i=0; i<MAX; i++){
        if(ACCOUNTS[i][0] != 0){
        printf("Account number: %.0f --> Balance: %.2f\n", ACCOUNTS[i][0], ACCOUNTS[i][1]);
        }
    }
}

void end (){
    for(int i=0; i<MAX; i++){
       ACCOUNTS[i][0] = 0;
       ACCOUNTS[i][1] = 0;
    }
}

