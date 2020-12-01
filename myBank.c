#include <stdio.h>
#include "myBank.h"
#define MAX 50
#define START 901
#define MAX_ACCOUNT 950

static int cnt = 901;
static float ACCOUNTS [MAX][2] = {{0}};

void open(float initDepos){
    
    if(initDepos > 0){
	    if(cnt <= MAX_ACCOUNT){
		for(int i = 901; i<MAX_ACCOUNT; i++){
			if(ACCOUNTS[i-START][0] == 0){
				ACCOUNTS[cnt-START][0] = (float)cnt;
				ACCOUNTS[cnt-START][1] = initDepos;
				printf("Your new account number is: %.0f and your balance is: %.2f\n" ,ACCOUNTS[cnt-START][0], ACCOUNTS[cnt-START][1]);
				cnt++;
				break;
			}
		}
	    }
	    else{
		printf("Sorry, but there is maximum number of accounts.\n");
	    }
    }
    else{
    	printf("Invalid Amount.\n");
    }
}

void balance(int accountNum){
    if(ACCOUNTS[accountNum-START][0] != 0){
        printf("Your balance is: %.2f\n", ACCOUNTS[accountNum-START][1]);
    }
    else{
        printf("This account is closed\n");
    }
}

void deposit(int accountNum, float amount){
    if((accountNum < 901 || accountNum > 950)){
	    if(amount > 0){
		if(ACCOUNTS[accountNum-START][0] != 0){
			ACCOUNTS[accountNum-START][1] += amount;
			printf("Your new balance is: %.2f\n", ACCOUNTS[accountNum-START][1]);
		}
		else{
			printf("This account is closed\n");
		}
	    }
	    else{
	    	printf("Cant deposit a negative number\n");
	    }
	    printf("Invalid account number\n");
    }
}

void withdraw (int accountNum, float amount){
    if((accountNum < 901 || accountNum > 950)){
	    if(amount > 0){
		if(ACCOUNTS[accountNum-START][0] == 0){
			printf("This account is closed\n");
		}
		if(ACCOUNTS[accountNum-START][1]-amount >= 0)
		{
			ACCOUNTS[accountNum-START][1] -= amount;
			printf("Your new balance is: %.2f\n", ACCOUNTS[accountNum-START][1]);
		}
	    	else{
			printf("Cannot withdraw more than the balance.\n");
	    	}
	    }
	    else{
	    	printf("Cant Withdraw a negative number\n");
	    }
	    printf("Invalid account number\n");
    }
}

void close(int accountNum){
    if(ACCOUNTS[accountNum-START][0] != 0){
        ACCOUNTS[accountNum-START][0] = 0;
        cnt--;
    }
    else{
        printf("This account is not exist.\n");
    }
}

void addInt(int interestRate){
    float IR = (float)(interestRate/(double)100.00);
    for(int i=START; i<MAX_ACCOUNT; i++){
        if(ACCOUNTS[i-START][0] != 0){
            ACCOUNTS[i-START][1] += ACCOUNTS[i-START][1]*IR;
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

