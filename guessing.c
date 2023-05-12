#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int attempts, option, try;

    srand(time(NULL));
    int randomNumber = rand()%50;

    printf("\n1 - Easy: 15 attempts\n");
    printf("2 - Medium: 10 attempts\n");
    printf("3 - Hard: 5 attempts\n");
    printf("Choose the difficult (1/2/3): ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        attempts = 15;
        break;
    case 2:
        attempts = 10;
        break;
    case 3:
        attempts = 5;
        break;
    }

    do
    {
        printf("Attemps left: %d\n", attempts);
        printf("Guess a number between 1 - 50: ");
        scanf("%d", &try);

        if(try > 50 || try < 0) {
            printf("Please, insert a number in the valid range (0 - 50)\n");
            attempts++;
        }

        if(try > randomNumber) {
            printf("\nThe random number is SMALLER\n");
        }
        if(try < randomNumber) {
            printf("\nThe random number is BIGGER\n");
        }

        if(try == randomNumber) {
            printf("\n\n\tCONGRATULATIONS !!! YOU WIN\n\n");
            break;
        }
        attempts--;
    } while (try =! randomNumber || attempts > 0);
    if(attempts == 0) {
        printf("Game Over -- No more attempts");
    }
}
