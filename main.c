#include <stdio.h>
#include "myBank.h"
#include "myBank.c"

int main (){
	char in;


	while(in != 'E'){
	   printf("Welcome! Please choose an action: (Note: our system is case sensitive. Use only capital.)\nOpen account - press O.\nCheck balance- press B.\nDeposit- press D.\nWithdraw- press W.\nClose account- press C.\nAdd an interest- press I.\nSee all accounts- press P.\nTerminate- press E.\n");
	   scanf(" %c", &in);
	   switch(in)
	   {
		   case 'O' :
		   {
		       float amount;
		       printf("Amount?");
		       scanf("%f", &amount);
		       open(amount);
		       break;
		   }
		   case 'B':
		   {
		       int num;
		       printf("Account number?");
		       scanf("%d", &num);
		       balance(num);
		       break;
		   }
		   case 'D':
		   {
		       float amount;
		       int num;
		       printf("Account number?");
		       scanf("%d", &num);

		       printf("Amount?");
		       scanf("%f", &amount);
		       deposit(num, amount);
		       break;
		   }
		   case 'W':
		   {
		       float amount;
		       int num;
		       printf("Account number?");
		       scanf("%d", &num);

		       printf("Amount?");
		       scanf("%f", &amount);
		       withdraw(num, amount);
		       break;
		   }
		   case 'C':
		   {
		       int num;
		       printf("Account number?");
		       scanf("%d", &num);
		       close(num);
		       break;
		   }
		   case 'I':
		   {
		       float IR;
		       printf("Interest rate?");
		       scanf("%f", &IR);
		       addInt(IR);
		       break;
		   }
		   case 'P':
		   {
		       toString();
		       break;
		   }
		   case 'E':
		   {
		       end();
		       break;
		   }
		   default:
            {
                printf("Invalid input! please try again.\nRemember, only capital letters!\n");
            }
	   }
	}
return 0;
}


