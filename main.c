#include <stdio.h>
#include "myBank.h"
#include "myBank.c"

int main (){
	char in;


	while(in != 'E'){
	   printf("Please choose a transaction type:\n O-Open Account\n B-Balance inquiry\n D-Deposit\n W-Withdrawal\n C-Close account\n I-Interest\n P-Print\n E-Exit  ");
	   scanf(" %c", &in);
	   switch(in)
	   {
		   case 'O' :
		   {
		       float amount;
		       printf("Amount?");
		       if(scanf("%f", &amount)==0){
		       	printf("Invalid Amount\n");
		       	break;
		       }
    		   open(amount);
    		   break;		       
		   }
		   case 'B':
		   {
		       int num;
		       printf("Account number?");
		       if(scanf("%d", &num) == 0){
		       	printf("Failed to read accout\n");
		       	break;
		       }
		       balance(num);
		       break;
		   }
		   case 'D':
		   {
		       float amount;
		       int num;
		       printf("Account number?");
		       if(scanf("%d", &num) == 0){
		       	printf("Failed to read accout\n");
		       	break;
		       }
		       else{
			       printf("Amount?");
			       if(scanf("%f", &amount) == 0){
			       	printf("Invalid Amount\n");
			       	
		       }
		       deposit(num, amount);
		       break;
		       }
		   }
		   case 'W':
		   {
		       float amount;
		       int num;
		       printf("Account number?");
		       if(scanf("%d", &num) == 0){
		       	printf("Failed to read accout\n");
		       	break;
		       }
		       else{
			       printf("Amount?");
			       if(scanf("%f", &amount) == 0){
			       	printf("Invalid Amount\n");
			       	
		       }
		       withdraw(num, amount);
		       break;
		       }
		   }
		   case 'C':
		   {
		       int num;
		       printf("Account number?");
		       if(scanf("%d", &num) == 0){
		       	printf("Failed to read accout\n");
		       	break;
		       }
		       close(num);
		       break;
		   }
		   case 'I':
		   {	       
		       int num;
		       printf("Please enter interest rate:");
		       if(scanf("%d", &num) == 0){
		       	printf("Failed to read accout\n");
		       	break;
		       }
		       addInt(num);
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
                printf("Invalid transaction type\n");
            }
	   }
	}
return 0;
}


