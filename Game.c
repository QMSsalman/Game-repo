#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, computer;
    int userScore = 0, computerScore = 0, ties = 0;
    char *choices[] = {"Stone", "Paper", "Scissors"};
    char playAgain;

    srand(time(0));

    do {
        printf("Enter choice: 1-Stone, 2-Paper, 3-Scissors\n");
        scanf("%d", &user);

        if (user < 1 || user > 3) {
            printf("Invalid choice! Try again.\n\n");
            continue;
        }

        computer = (rand() % 3)+1;

        printf("You chose: %s\n", choices[user-1]);
        printf("Computer chose: %s\n", choices[computer-1]);

        if (user == computer) {
            printf("It's a tie!\n");
            ties++;
        }
        else if ((user == 1 && computer == 3) ||
                 (user == 2 && computer == 1) ||
                 (user == 3 && computer == 2)) {
            printf("You win!\n");
            userScore++;
        }
        else {
            printf("Computer wins!\n");
            computerScore++;
        }

        printf("Score -> You: %d | Computer: %d | Ties: %d\n", userScore, computerScore, ties);

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
        printf("\n");

    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}