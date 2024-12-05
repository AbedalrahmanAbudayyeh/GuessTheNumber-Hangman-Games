#include<stdio.h> //enter to stdio.h library that tells to the compiler what is the meaning of printf,sacnf..
#include<stdlib.h> //enter to stdlib.h library 
#include<time.h>	//enter to time.h library 
#include"foc_fa22.h" //enter to foc_fa22.h library that tells to the compiler what is the meaning of showArray
#include<string.h>	//enter to string .h library that tells to the compiler what is the meaning of strlen
#define MAXNUMWORDS 100 //maximum number of words that the user is going to to read from the file 
#define MAXLENGTHWORDS 60 // maximum length of the words 
void startGuessTheNumberGame(); //declare void function for guess the number game 
void startHangmanGame(); //declare void function for hangman game 
int main() //function where the exeution begins
{	 
	int game; //declare game as what the user wants to play 
	printf("please enter your name\n"); //printing please enter your name 
	char name[50]; //declare name[50] as the that the user's name 
	scanf("%s",name); //read name from the user 
	printf("Welcome %s!! \n",name); //printing a welcome massege 
	int x=1; //declare x and intialize 1 in it to put it inside the loop 
	while (x) //starting a while loop  
	{ 
		printf("choose the number of game that you wish to play, or Exit\n"); //printing choose the number of game that you wish to play, or Exit 
		printf("1.Guess The Numeber Game\n2.Hangman Game\n3.Exit\n"); //printing the games and Exit 
		scanf("%d",&game); // read game from the user	 
		if(game == 1) // if the user puts 1 
		{	 
			int snum; //declare snum as the secret number   
			printf("Enter a secert number between 1 and 10000: "); //printing Enter a secert number between 1 and 10000: 
			scanf("%d",&snum); //read snum from the user 
			if (snum <= 10000 && snum >= 1) //if statement to be the limit from 1-10000 
			{ 
				startGuessTheNumberGame(); //call the the function 
			} 
			else // if the snum is out of the limit 
			{
				printf("Invalid Choice\n"); //printing Invalid Choice 
			}	
		} 
		else if(game == 2) //if the user puts 2 
		{ 
			startHangmanGame(); //call the the function 
		}	 
		else if(game == 3) //if the user puts 3 
		{ 
			x=0; // let x=0 to get out of the loop 
		} 
		else //if the user puts any other number 
		{ 
			printf("Invalid Choice "); //printing Invalid Choice  
		} 
	} 
} 
void startGuessTheNumberGame() //define guess the number game function 
{ 
	printf("Guess The Number Has Started\n"); //printing Guess The Number Has Started 
	int option,guessnum; //declare option as the options and declare guessnum as the guess number 
	int highest=10000; // declare highest as the highest guess and intialize 10000 
	int lowest=1; //	declare lowest as the lowest guess and intialize 1 
	int counter=1; //declare counter as the tries and intialize 1 in it 
	int arr[150][150]; // declare arr[150][150] as the 2d array for the image 
	while(lowest<highest) //starting while loop 
		{  
			guessnum= (highest+lowest) /2; //calculate (highest+lowest) /2 inside guessnum as the binary search 
			printf("my guess: %d",guessnum); // print the users guess 
			printf(" choose one of these 3 options\n"); //printing choose one of these 3 options 
			printf("1.You found the secert number\n2.The secert number is smaller than %d\n3.The secert number is bigger than %d\n",guessnum,guessnum); //printing the options 
			scanf("%d",&option); //read option from the user 
			if(option == 1) //if the user puts 1 
			{ 
				printf("  My guess is correct \n You tried %d time/s \n",counter); //printing that his guess is correct and how many tries  
				for(int i=0;i<150;i++) //starting a for loop for the highet 
				{ 
					for(int j=0;j<150;j++) // starting a for loop for the width 
					{ 
						arr[i][j]=255; //let arr[i][j]=255 to be the image colored white 
						if ((j>65 && j<85) && i > (150-counter*10)) //if statement for the black column 
						arr[i][j]=0; //let arr[i][j]=0 to be the image colored black  
					} 
				} 
				showArray(150,150,arr); //showArray toshow the image 
				lowest=highest; //let lowest=highest to get out of the loop 
			} 
			else if(option == 2) //if the user puts 2 
			{ 
				counter++; //calculate counter++ to inrease the tries 
				highest=guessnum -1; //calculate highest=guessnum -1 to be the limit from 1 to the guess number 
			} 
			else if(option == 3) //if the user puts 3 
			{ 
				counter++; //calculate counter++ to inrease the tries 
				lowest=guessnum +1; //calculate lowest=guessnum +1 to be the limit from the guess number to 1 
			} 
			else //if the user puts any other number 
			{ 
				counter++; //calculate counter++ to inrease the tries 
				printf("Invalid Choice "); //printing Invalid Choice  
			}	 
		} 
} 
void startHangmanGame() //define hangman game function
{
			printf("Hangman Has Started\n"); //printing Hangman Has Started
			int x=1; //declare x and initiailize 1 in it to use it in while loop 
			int option; //declare option as the category that the user wants to choose
			FILE *F; // import the file called F by pointer that takes the address of the file
			srand(time(NULL)); // srand included to not get the same random words each time i run the game
			char guesswords[MAXNUMWORDS][MAXLENGTHWORDS]; //declared 2 dimensional array of MAXNUMWORDS of 100 to use in my hangman game
			int wordsreadin=0; //number of words that the user is reading from the file
			int z=0; //declare z as the number of the word in the file and intialize 0 in it
			while(x) //starting a while loop 
		      	{
				printf("Choose a category:\n"); //printing Choose a category:
				printf("1. Food\n2. Objects\n3. Names\n4. Colors\n"); //printing the categories
				scanf("%d",&option); // read option from the user
				if(option == 1) // if the user enters 1 
				{
						F=fopen("food.txt","r"); // opening the file, entering the name of it and the status of it is reading "r"
						while(z != -1) // starting a while loop and z != -1 to make sure that the words dont reapeat
						{
							z=fscanf(F,"%s",guesswords[wordsreadin]); //fscanf to read the string from the file
							wordsreadin++; //increment words read in 
						}
						int randomindex = rand() % wordsreadin;  //decalre randomindex and intialize the rand() function in order to select one of the words in guesswords char randomly that used to built in function in stdlib library
						int numoflives=5; //declared this int to specify the user lives
						int numcorrect=0; // declered this counter to keep track of how many correct letters has the user had
						int oldcorrect=0; //declared this int to be the amount of the previous correct letters
						int lengthwords=strlen(guesswords[randomindex]); //the length of the word  selected because when we start playing the game and when the user enters a character they've guessed we need to loop through the length and print it
						int letterguessed[10]={0,0,0,0,0,0,0,0,0,0}; // the [10] is the maximum length of the random word and so we type 10 zeros (as the max length of my word)  this int is for comparison and each 0 means a position on an index , so each time the user has guessed a word it changes the 0 to 1 and we need the 0 - 1 numbers for comparison purposes			
						int loopindex=0; // declared simple int counter for looping
						char guess[0]; // declared this string that the user makes because we're going to need to take some input
						char letterenterd; // declared this char to store the letters that the user guessed
						while(numcorrect < lengthwords) // (starting a while loop) while the number of correct letters guessed is less than the length of the word.. keep looping
						{
							printf("The word so far is: "); //printing The word so far is:
							for(loopindex=0;loopindex<lengthwords;loopindex++) //starting a for loop to loop through each letter in the random word
							{
								if(letterguessed[loopindex]==1) // if the user already guessed the letter and it equaled 1
								{
									printf("%c",guesswords[randomindex][loopindex]); // print that letter
								}
								else //else (if letterguessed[loopindex==0])
								{
									printf("_"); //print "_" insted
								}
							}
							printf("\n"); //printing new line
							printf("you have %d lives\n",numoflives); // printing how many lives does the user has 
							printf("Enter a guess letter: \n"); //printing Enter a guess letter:
							scanf("%s",guess); //read the first letter/number from string guess from the user 
							letterenterd = guess[0]; // storing the letter that the user guessed inside of the guess array we're going to need to take some output
							oldcorrect=numcorrect; //store the current num correct value in old correct so when the user puts the same correct guessed letter again numcorrect doesnt increase
							for(loopindex=0;loopindex<lengthwords;loopindex++) //starting a for loop to loop through each letter in the random word
							{
							 	  if(letterguessed[loopindex]==1) // if the user already guessed the letter 
							  	  {
							  		continue; //continue to dont increase the numcorrect
							  	  }
							  	  if(letterenterd == guesswords[randomindex][loopindex]) //if the letter enterd by the user = the array of characters which contains all the letters in the random word that inside the file
							  	  {
									letterguessed[loopindex]=1; // replace that letter with 1 insted of 0
									numcorrect++; //increase the correct letter guessed counter
								  }
							}
							if(oldcorrect == numcorrect)  // if the oldcorrect == numcorrect to make sure that the correct letter that enterd doesnt increase the numcorrect if it enterd again
							{
								numoflives--; //decrease one of the lives
								printf("Wrong Guess\n"); // printing Wrong guess
								if(numoflives == 0) // if lives equaled 0, we should stop looping 
								{
									break; //break to go out of the loop
								}
							}
							else //if oldcorrect != numcorrect
							{
								printf("Correct Guess\n"); // printing Correct guess
							}
						}
							
			 			if(numoflives == 0) //if numoflives = 0 
						{
							printf("Hardluck the word was %s \n",guesswords[randomindex]); // printing a hardluck massege 
								break; // break to get out of the game and go back to the main menu
						}
						else //else (if the user got the hangman word)
						{
							printf("congratulations you found the word %s \n",guesswords[randomindex]); // printing a congratulations message
								break; // break to get out of the game and go back to the main menu
						}
					}
					 else if(option == 2) //if the user enters 2
					 {
						F=fopen("objects.txt","r"); // opening the file, entering the name of it and the status of it is reading "r"
						while(z != -1)  // starting a while loop and z != -1 to make sure that the words dont reapeat
						{    
							z=fscanf(F,"%s",guesswords[wordsreadin]);//fscanf to read the string from the file
							wordsreadin++; //increment words read in 
						}
						int randomindex = rand() % wordsreadin;  //decalre randomindex and intialize the rand() function in order to select one of the words in guesswords char randomly that used to built in function in stdlib library
						int numoflives=5; //declared this int to specify the user lives
						int numcorrect=0; // declered this counter to keep track of how many correct letters has the user had
						int oldcorrect=0; //declared this int to be the amount of the previous correct letters
						int lengthwords=strlen(guesswords[randomindex]); //the length of the word  selected because when we start playing the game and when the user enters a character they've guessed we need to loop through the length and print it
						int letterguessed[10]={0,0,0,0,0,0,0,0,0,0}; // the [10] is the maximum length of the random word and so we type 10 zeros (as the max length of my word)  this int is for comparison and each 0 means a position on an index , so each time the user has guessed a word it changes the 0 to 1 and we need the 0 - 1 numbers for comparison purposes			
						int loopindex=0; // declared simple int counter for looping
						char guess[0]; // declared this string that the user makes because we're going to need to take some input
						char letterenterd; // declared this char to store the letters that the user guessed
						while(numcorrect < lengthwords) // (starting a while loop) while the number of correct letters guessed is less than the length of the word.. keep looping
						{
							printf("The word so far is: "); //printing The word so far is:
							for(loopindex=0;loopindex<lengthwords;loopindex++) //starting a for loop to loop through each letter in the random word
							{
								if(letterguessed[loopindex]==1) // if the user already guessed the letter and it equaled 1
								{
									printf("%c",guesswords[randomindex][loopindex]); // print that letter
								}
								else //else (if letterguessed[loopindex==0])
								{
									printf("_"); //print "_" insted
								}
							}
							printf("\n"); //printing new line
							printf("you have %d lives\n",numoflives); // printing how many lives does the user has 
							printf("Enter a guess letter: \n"); //printing Enter a guess letter:
							scanf("%s",guess); //read the first letter/number from string guess from the user 
							letterenterd = guess[0]; // storing the letter that the user guessed inside of the guess array we're going to need to take some output
							oldcorrect=numcorrect; //store the current num correct value in old correct so when the user puts the same correct guessed letter again numcorrect doesnt increase
							for(loopindex=0;loopindex<lengthwords;loopindex++) //starting a for loop to loop through each letter in the random word
							{
							 	  if(letterguessed[loopindex]==1) // if the user already guessed the letter 
							  	  {
							  		continue; //continue to dont increase the numcorrect
							  	  }
							  	  if(letterenterd == guesswords[randomindex][loopindex]) //if the letter enterd by the user = the array of characters which contains all the letters in the random word that inside the file
							  	  {
									letterguessed[loopindex]=1; // replace that letter with 1 insted of 0
									numcorrect++; //increase the correct letter guessed counter
								  }
							}
							if(oldcorrect == numcorrect)  // if the oldcorrect == numcorrect to make sure that the correct letter that enterd doesnt increase the numcorrect if it enterd again
							{
								numoflives--; //decrease one of the lives
								printf("Wrong Guess\n"); // printing Wrong guess
								if(numoflives == 0) // if lives equaled 0, we should stop looping 
								{
									break; //break to go out of the loop
								}
							}
							else //if oldcorrect != numcorrect
							{
								printf("Correct Guess\n"); // printing Correct guess
							}
						}
							
			 			if(numoflives == 0) //if numoflives = 0 
						{
							printf("Hardluck the word was %s \n",guesswords[randomindex]); // printing a hardluck massege 
								break; // break to get out of the game and go back to the main menu
						}
						else //else (if the user got the hangman word)
						{
							printf("congratulations you found the word %s \n",guesswords[randomindex]); // printing a congratulations message
								break; // break to get out of the game and go back to the main menu
						}
					}
					else if(option == 3) //if the user enters 3
					{
						F=fopen("names.txt","r"); // opening the file, entering the name of it and the status of it is reading "r"
						while(z != -1) // starting a while loop and z != -1 to make sure that the words dont reapeat
						{
							z=fscanf(F,"%s",guesswords[wordsreadin]); //fscanf to read the random string from the file
							wordsreadin++; //increment words read in 
						}
						int randomindex = rand() % wordsreadin;  //decalre randomindex and intialize the rand() function in order to select one of the words in guesswords char randomly that used to built in function in stdlib library
						int numoflives=5; //declared this int to specify the user lives
						int numcorrect=0; // declered this counter to keep track of how many correct letters has the user had
						int oldcorrect=0; //declared this int to be the amount of the previous correct letters
						int lengthwords=strlen(guesswords[randomindex]); //the length of the word  selected because when we start playing the game and when the user enters a character they've guessed we need to loop through the length and print it
						int letterguessed[10]={0,0,0,0,0,0,0,0,0,0}; // the [10] is the maximum length of the random word and so we type 10 zeros (as the max length of my word)  this int is for comparison and each 0 means a position on an index , so each time the user has guessed a word it changes the 0 to 1 and we need the 0 - 1 numbers for comparison purposes			
						int loopindex=0; // declared simple int counter for looping
						char guess[0]; // declared this string that the user makes because we're going to need to take some input
						char letterenterd; // declared this char to store the letters that the user guessed
						while(numcorrect < lengthwords) // (starting a while loop) while the number of correct letters guessed is less than the length of the word.. keep looping
						{
							printf("The word so far is: "); //printing The word so far is:
							for(loopindex=0;loopindex<lengthwords;loopindex++) //starting a for loop to loop through each letter in the random word
							{
								if(letterguessed[loopindex]==1) // if the user already guessed the letter and it equaled 1
								{
									printf("%c",guesswords[randomindex][loopindex]); // print that letter
								}
								else //else (if letterguessed[loopindex==0])
								{
									printf("_"); //print "_" insted
								}
							}
							printf("\n"); //printing new line
							printf("you have %d lives\n",numoflives); // printing how many lives does the user has 
							printf("Enter a guess letter: \n"); //printing Enter a guess letter:
							scanf("%s",guess); //read the first letter/number from string guess from the user 
							letterenterd = guess[0]; // storing the letter that the user guessed inside of the guess array we're going to need to take some output
							oldcorrect=numcorrect; //store the current num correct value in old correct so when the user puts the same correct guessed letter again numcorrect doesnt increase
							for(loopindex=0;loopindex<lengthwords;loopindex++) //starting a for loop to loop through each letter in the random word
							{
							 	  if(letterguessed[loopindex]==1) // if the user already guessed the letter 
							  	  {
							  		continue; //continue to dont increase the numcorrect
							  	  }
							  	  if(letterenterd == guesswords[randomindex][loopindex]) //if the letter enterd by the user = the array of characters which contains all the letters in the random word that inside the file
							  	  {
									letterguessed[loopindex]=1; // replace that letter with 1 insted of 0
									numcorrect++; //increase the correct letter guessed counter
								  }
							}
							if(oldcorrect == numcorrect)  // if the oldcorrect == numcorrect to make sure that the correct letter that enterd doesnt increase the numcorrect if it enterd again
							{
								numoflives--; //decrease one of the lives
								printf("Wrong guess\n"); // printing Wrong guess
								if(numoflives == 0) // if lives equaled 0, we should stop looping 
								{
									break; //break to go out of the loop
								}
							}
							else //if oldcorrect != numcorrect
							{
								printf("Correct guess\n"); // printing Correct guess
							}
						}
							
			 			if(numoflives == 0) //if numoflives = 0 
						{
							printf("Hardluck the word was %s \n",guesswords[randomindex]); // printing a hardluck massege 
								break; // break to get out of the game and go back to the main menu
						}
						else //else (if the user got the hangman word)
						{
							printf("congratulations you found the word %s \n",guesswords[randomindex]); // printing a congratulations message
								break; // break to get out of the game and go back to the main menu
						}
					}
					else if(option == 4) //if the user enters 4
					{
						F=fopen("colors.txt","r"); // opening the file, entering the name of it and the status of it is reading "r"
						while(z != -1)  // starting a while loop and z != -1 to make sure that the words dont reapeat
						{       
							z=fscanf(F,"%s",guesswords[wordsreadin]); //fscanf to read the string from the file
							wordsreadin++; //increment words read in 
						}
						int randomindex = rand() % wordsreadin;  //decalre randomindex and intialize the rand() function in order to select one of the words in guesswords char randomly that used to built in function in stdlib library
						int numoflives=5; //declared this int to specify the user lives
						int numcorrect=0; // declered this counter to keep track of how many correct letters has the user had
						int oldcorrect=0; //declared this int to be the amount of the previous correct letters
						int lengthwords=strlen(guesswords[randomindex]); //the length of the word  selected because when we start playing the game and when the user enters a character they've guessed we need to loop through the length and print it
						int letterguessed[10]={0,0,0,0,0,0,0,0,0,0}; // the [10] is the maximum length of the random word and so we type 10 zeros (as the max length of my word)  this int is for comparison and each 0 means a position on an index , so each time the user has guessed a word it changes the 0 to 1 and we need the 0 - 1 numbers for comparison purposes			
						int loopindex=0; // declared simple int counter for looping
						char guess[0]; // declared this string that the user makes because we're going to need to take some input
						char letterenterd; // declared this char to store the letters that the user guessed
						while(numcorrect < lengthwords) // (starting a while loop) while the number of correct letters guessed is less than the length of the word.. keep looping
						{
							printf("The word so far is: "); //printing The word so far is:
							for(loopindex=0;loopindex<lengthwords;loopindex++) //starting a for loop to loop through each letter in the random word
							{
								if(letterguessed[loopindex]==1) // if the user already guessed the letter and it equaled 1
								{
									printf("%c",guesswords[randomindex][loopindex]); // print that letter
								}
								else //else (if letterguessed[loopindex==0])
								{
									printf("_"); //print "_" insted
								}
							}
							printf("\n"); //printing new line
							printf("you have %d lives\n",numoflives); // printing how many lives does the user has 
							printf("Enter a guess letter: \n"); //printing Enter a guess letter:
							scanf("%s",guess); //read the first letter/number from string guess from the user 
							letterenterd = guess[0]; // storing the letter that the user guessed inside of the guess array we're going to need to take some output
							oldcorrect=numcorrect; //store the current num correct value in old correct so when the user puts the same correct guessed letter again numcorrect doesnt increase
							for(loopindex=0;loopindex<lengthwords;loopindex++) //starting a for loop to loop through each letter in the random word
							{
							 	  if(letterguessed[loopindex]==1) // if the user already guessed the letter 
							  	  {
							  		continue; //continue to dont increase the numcorrect
							  	  }
							  	  if(letterenterd == guesswords[randomindex][loopindex]) //if the letter enterd by the user = the array of characters which contains all the letters in the random word that inside the file
							  	  {
									letterguessed[loopindex]=1; // replace that letter with 1 insted of 0
									numcorrect++; //increase the correct letter guessed counter
								  }
							}
							if(oldcorrect == numcorrect) // if the oldcorrect == numcorrect to make sure that the correct letter that enterd doesnt increase the numcorrect if it enterd again
							{
								numoflives--; //decrease one of the lives
								printf("Wrong Guess\n"); // printing Wrong guess
								if(numoflives == 0) // if lives equaled 0, we should stop looping 
								{
									break; //break to go out of the loop
								}
							}
							else //if oldcorrect != numcorrect
							{
								printf("Correct Guess\n"); // printing Correct guess
							}
						}	
			 			if(numoflives == 0) //if numoflives = 0 
						{
							printf("Hardluck the word was %s \n",guesswords[randomindex]); // printing a hardluck massege 
								break; // break to get out of the game and go back to the main menu
						}
						else //else (if the user got the hangman word)
						{
							printf("congratulations you found the word %s \n",guesswords[randomindex]); // printing a congratulations message
								break; // break to get out of the game and go back to the main menu
						}
					}
					else // if the user entered any other number 
					{
						printf("Invalid Choice\n"); // printing Invalid Choice
					}
   			} 	
}
