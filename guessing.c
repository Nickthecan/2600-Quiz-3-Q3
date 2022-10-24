//Author: Nicholas Amancio
//CS2600 | Quiz 3 | 102322

/*Question 3 : Number guessing game 
Create an interactive program that allows a user to guess a number between 1-10. You 
should create a menu that will have options (this should be displayed on the screen):
Press 1 to play a game
Press 2 to change the max number
Press 3 to quit
If option 1 is selected the program should prompt the user to enter a number. 
If the user is correct tell them they won then the program should go back to the menu. 
Otherwise tell them if they were too low or high in there guess and allow them to guess 
again. This should continue until they win. If they enter q instead of a number when 
prompted the game should end(NOT the program) and return to the menu.
If option 2 is chosen, then tell them the max value they can set the number. Make sure 
they do not enter a negative number or go above the max value.
If option 3 is chosen thank the user for playing and end the game.
Now create a new branch – call it save_user_max_number
Can you save the users request for the max number where the program is able to 
remember it the next time it starts?
*/

/* Outline
Create a switch case to display the 3 options
When option 1 is selected, we will use the scan function in order to allow the user to enter a number
Then we will throw the number in a if else statement to determine whether the number is greater than or lesser than the given number
This will go into a do while loop so the user can keep guessing until they can guess the number correctly
When the user enters q, then it should jump out of the while loop and go back to the main menu
When option 2 is selected, the user can set the max number, the set number will change to that new number
We will checkIntegrity and checkMaximum in order to see if the number is valid
When option 3 is chosen, the game will quit
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//global variables
const int MIN = 0;
const int MAX = 100;
int max = 10;

//implemented methods
void printMenu();
int changeMax(int max, const int MAX);
void game();

int main() {
    //variables for when playing the game
    int guess;
    int guesses = 0;
    int answer;

    //input for menu
    int userInput;

    //print out menu
    printMenu();

    //user input
    scanf("%d", &userInput);

    //switch case to list the different options
    switch (userInput) {
        //case 1 is the game
        case 1:
            //game method
            game();
            break;
        //case 2 changes the max value
        case 2:

            //changes the max value using the method
            max = changeMax(max, MAX);

            //returns to the main function
            main();
            break;
        
        //case 3 terminates the program
        case 3:
            printf("Goodbye!\n");
            break;
        
        //default case if user does not inputs the given numbers
        default:
            printf("\nInvalid Input! Please input another number.\n");

            //returns to the main function
            main();
    }
    return 0;
} //end main 

//prints the menu
void printMenu() {
    printf("Guessing Game\n");
    printf("-----------------------\n");
    printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
} //end printMenu

//changes the max value
int changeMax(int max, const int MAX) {

    //variable for changing the max
    int newMax;

    //allows the user to input a new max value
    printf("Change the MAX number that you desire: ");
    scanf("%d", &newMax);

    //if-else to check the integrity of the number to see if it is in bounds of min and max
    if (newMax < 0) {
        printf("The number inputted is below 0. Please enter a new number: ");
        scanf("%d", &newMax);
    }
    else if (newMax > MAX) {
        printf("The number inputted is too high. Please enter a new number: ");
        scanf("%d", &newMax);
    }
    else {
        //assigns the new max value
        max = newMax;
    }
    return max;            
} //end changeMax

//game
void game() {
     //variables for when playing the game
    int guess;
    int guesses = 0;
    int answer;
    char quit[2];

    //seed
    srand(time(0));
            
    //generate a random number between min and max
    answer = rand() % max + MIN;
            
    //do while loop to determine whether the guess is correct or not
    do {

        printf("Enter a guess: ");
        scanf("%s", &quit);

        if (quit[0] == 'q') {
            break;
        }
        else {
            guess = atoi(quit);
            
            if (guess > answer && guess > max)
                printf("number above max\n");
            else if (guess < answer && guess < MIN)
                printf("number below min\n");
            else if (guess > answer)
                printf("Too high!\n");
            else if (guess < answer)
                printf("Too low!\n");
            else if (guess == 'q')
                return;
            else   
                printf("Correct\n");
            guesses++;
        }
    }while(guess != answer);

    //prints out the answer and the number of guesses
    printf("answer: %d\n", answer);
    printf("guesses: %d\n\n", guesses);
            
    //returns to the main function
    main();
} //end game