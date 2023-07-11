#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//A simple functions to print instructions
void print_instructions()
	{
		printf("The rules are simple and as follows:\n");
		printf("1.There is a Magic Number that you have to guess.\n");
		printf("2.Magic Number will be in the range of 1 to 100.\n");
		printf("3.You will have 5 tries to guess it.\n");
		printf("4.Your first guess will be random.\n");
		printf("5.With each guess, you will be given some hint which will lead you to the answer.\n");
		printf("6.If you guess correctly in 5 tries or under, you win.\n\n");
	}

int main()
{
	//Declaring variables
	unsigned int magicno, guess, comparision;
	char ans, ans2, instructions_want;
	int loopcontrol, win, play = 0, need = 1; //win, play and need will be used as a boolean variables.
	
	//Preparing the random number generator
	srand((unsigned)time(NULL));

	//Introduction 
	printf("WELCOME TO THE MAGIC NUMBER GAME\n\n");
	printf("In this game you will have to guess a hidden number.\n\n");
	
	//Asking if the user would like to play
	printf("Would you like to play? <y/n> : ");
	scanf_s("%c", &ans);

	if (ans == 'n')
	{
		printf("Have a nice day\n");
		return 0;
	}

	replay:
		//Preparing the hidden number
		magicno = rand() % 100;

		printf("\n"); //TO BE REPLACED BY NEXT LINE CHARACTER 

		//Now lets give the rules
		if (need)
		print_instructions();

		if (play) //For asking the player if the want to view the rules again or not
		{
			printf("Would you like to view the instructions again? <y/n> ");
			scanf_s(" %c", &instructions_want);
			if (instructions_want == 'y')
				print_instructions();
		}

		printf("\n");
		printf("MAY THE NUMBERS BE WITH YOU...\n\n");

		//Now lets start the actual game 

		for (loopcontrol = 1; loopcontrol <= 5; loopcontrol++) //Execution of five attempts
		{
			win = 0;

			if (loopcontrol == 5)
				printf("Careful! This is your final guess.\n\n"); //For final guess only

			//A little extra help if the player doesnot reach the answer in 3 guesses
			if (loopcontrol == 4)
			{
				printf("Pssst....having some trouble? Here is some help:\n\n");
				printf("-Almost there   --> difference of 1 to 5 between guess and magic number.\n");
				printf("-Ver close      --> difference of 6 to 10 between guess and magic number.\n");
				printf("-Close          --> difference of 11 to 15 between guess and magic number.\n");
				printf("-Not quite near --> difference of 16 to 20 between guess and magic number.\n");
				printf("-A little far   --> difference of 21 to 25 between guess and magic number.\n");
				printf("-Quite far      --> difference of 25 or more between guess and magic number.\n\n");
			}

			//Taking the guess
			printf("Enter your guess no.%d: ", loopcontrol);
			scanf_s("%d", &guess);
			printf("\n");

			//Checking the guess
			if (guess == magicno) //Win or no win?
			{
				win = 1;
				break;
			}
			else if (guess <= magicno) //Is guess greater or lesser
			{
				printf("Your guess is lower than the Magic Number.\n\n");
				comparision = magicno - guess;
			}

			else
			{
				printf("Your guess is higher than the Magic Number.\n\n");
				comparision = guess - magicno;
			}

			//These series will give a second hint in the form of a number range
			if (comparision >= 1 && comparision <= 5)
				printf("You are almost on the Magic Number.\n\n");
			else if (comparision >= 6 && comparision <= 10)
				printf("You are very close to the Magic Number.\n\n");
			else if (comparision >= 11 && comparision <= 15)
				printf("You are close to the Magic Number.\n\n");
			else if (comparision >= 16 && comparision <= 20)
				printf("You are not quite near the Magic Number.\n\n");
			else if (comparision >= 21 && comparision <= 25)
				printf("You are a little far from the Magic Number.\n\n");
			else
				printf("You are quite far from the Magic Number.\n\n");
		} //End of the turn loop

		play = 1;
		need = 0;

		if (win == 1) //Checking for win or loss
		{
			printf("Congratulations you guessed correctly.\n");
			printf("The Magic Number was %d\n\n", guess);
		}
		else
		{
			printf("Sorry, you were unable to guess the Magic Number.\n");
			printf("The Magic Number was : %d\n\n", magicno);
		}

		printf("Would you like to play again? <y/n> : ");
		scanf_s(" %c", &ans2);
	
		if (ans2 == 'y')
			goto replay;
		else
			printf("\nThank you for playing.\n\n");

		return 0;
}