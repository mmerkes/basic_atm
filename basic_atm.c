/*
Assignment purpose: User defined functions, pointers, Menu driven program

You have been hired to write the software for MYBANK’s ATM network. Customers are interested in making deposits, withdrawals, transferring money between accounts and checking their account balances. MYBANK customers will have a Checking, Savings and/or Credit Card accounts.	
	 
You must have at least 6 user defined functions:

Additional Requirements:
•	Create a typed algorithm that outlines the steps your program will follow in English/pseudocode. This is worth 10 points of the grade for this assignment.
•	Use function prototypes.
•	Write comments for each function that will appear in the file before each prototype and again before each function definition.
•	Be sure to comment your code adequately.
•	Be sure to indent properly. Check your textbook and lecture code examples to see how it should be done.
•	Use meaningful variable names.
•	Your starting bank balalnces should be as follows:
o	Checking - $850.00
o	Savings - $2500.00
o	Credit - $-1850.00
•	Electronically submit only your source code, mybank.c through the Assignment Manager in Blackboard by 12pm on Monday, March 18th.
•	Turn in a printed copy of your source code, a sample output demonstrating your program, and a copy of your algorithm in class on Monday, March 18th
•	Late Submission: No program will be accepted for grading after 5pm on Friday, March 22nd. Late penalties apply.




Sample Output


Please choose from the following menu:
DEPOSIT .......... 1
WITHDRAWAL ....... 2
ACCOUNT BALANCE... 3
TRANSFER ......... 4
Your selection: 2

Type of account
Choose C for Checking
Choose S for Savings
Choose R for Credit
r

Please enter the amount of your withdrawal: 400.56
Please take your cash and receipt

Do you wish to make another selection? (y or n): y

Please choose from the following menu:
DEPOSIT .......... 1
WITHDRAWAL ....... 2
ACCOUNT BALANCE... 3
TRANSFER ......... 4
Your selection: 1

Type of account
Choose C for Checking
Choose S for Savings
Choose R for Credit
c

Please enter the amount of your deposit: 400.56

Don't forget your receipt!

Do you wish to make another selection? (y or n): y

Please choose from the following menu:
DEPOSIT .......... 1
WITHDRAWAL ....... 2
ACCOUNT BALANCE... 3
TRANSFER ......... 4
Your selection: 2

Type of account
Choose C for Checking
Choose S for Savings
Choose R for Credit
s
Please enter the amount of your withdrawal: 50.00
Please take your cash and receipt

Do you wish to make another selection? (y or n): y

Please choose from the following menu:
DEPOSIT .......... 1
WITHDRAWAL ....... 2
ACCOUNT BALANCE... 3
TRANSFER ......... 4
Your selection: 3

Type of account
Choose C for Checking
Choose S for Savings
Choose R for Credit
s
You have 950.00 in your account

Do you wish to make another selection? (y or n): n
Press any key to continue . . . */

#include <stdio.h>
#include <stdbool.h>

bool cont = true;
char again, currentAccount;
int selection;

void newLine(void) {
	printf("\n");
}

char makeCapital (char c) {
	if (c > 90)
		c -= 32;
	return c;
}

// Displays the list of options available
//prompts for the user’s selection and sets the value of the selection
void mainMenu(int *option) {
	bool isValid = false;

	while (!isValid) {
		printf("Please choose from the following menu:\n");
		printf("DEPOSIT .......... 1\n");
		printf("WITHDRAWAL ....... 2\n");
		printf("ACCOUNT BALANCE... 3\n");
		printf("TRANSFER ......... 4\n");
		printf("Your selection: ");
		scanf("%i", option);
		getchar();

		if (*option >= 1 && *option <= 4)
			isValid = true;
		else
			printf("Invalid entry. Choose again.\n");

		newLine();
	}
}

//Asks the user if they want another transaction
void Keepgoing(char *goagain) {
	printf("Do you wish to make another selection? (y or n): ");
	scanf("%c", goagain);
	getchar();
}

//Asks the user which type of account they would like to access and sets the 
//value of the selection
void AccountMenu( char *acctType) {
	bool isValid = false;
	char c;

	while(!isValid) {
		printf("Type of account\n");
		printf("Choose C for Checking\n");
		printf("Choose S for Savings\n");
		printf("Choose R for Credit\n");
		scanf("%c", &c);
		getchar();

		c = makeCapital(c);

		if (c == 'C' || c == 'S' || c == 'R') {
			isValid = true;
			*acctType = c;
		} else
			printf("Invalid selection. Please choose again.\n");

		newLine();
	}
}

//Prompts the user for the amount of deposit and updates the selected account 
void MakeDeposit( double *balance);

//Prompts the user for the amount of the withdrawal, determines if there are 
//sufficient funds and updates the selected account if funds are dispensed 
void MakeWithdrawal( double *balance, char acctType);

//Displays the user’s current account balance for the selected account
void GetBalance( double balance);

int main(void) {

	printf("Welcome to MyBank\n\n");

	while (cont) {

		mainMenu(&selection);
		AccountMenu(&currentAccount);
		switch (selection) {
			case 1: //Deposit

				break;
			case 2: //withdrawal

				break;
			case 3: //Account balance

				break;
			case 4: //Transfer

				break;
		}

		Keepgoing(&again);
		if (again == 'n') {
			cont = false;
		}
		newLine();
	}
/*
 To transfer money, first withdraw from the specified account
Then deposit that money into the receiving account
*/

}







