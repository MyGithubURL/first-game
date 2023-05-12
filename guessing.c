#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HRED "\e[0;91m"
#define reset "\e[0m"

int main()
{
    int attempts, option, try;

    srand(time(NULL));
    int randomNumber = rand()%50;

    printf(HGRN "\n1 - Easy: 15 attempts\n");
    printf(HYEL "2 - Medium: 10 attempts\n");
    printf(HRED "3 - Hard: 5 attempts\n" reset);
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
            printf("\nThe random number is " HRED "SMALLER\n" reset);
        }
        if(try < randomNumber) {
            printf("\nThe random number is " HGRN "BIGGER\n" reset);
        }

        if(try == randomNumber) {
            printf(HYEL "\n\n\tCONGRATULATIONS !!! YOU WIN\n\n" reset);
            break;
        }
        attempts--;
    } while (try =! randomNumber || attempts > 0);
    if(attempts == 0) {
        printf(HRED "Game Over -- No more attempts" reset);
    }
}
