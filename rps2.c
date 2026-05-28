#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Convert numeric move values to readable text
const char *move_name(int move)
{
    if (move == 0) return "Rock";
    if (move == 1) return "Paper";
    if (move == 2) return "Scissors";

    return "Unknown";
}

// Decide winner: 0 = draw; 1 = player wins; -1 = computer wins
int decide_winner(int player, int computer)
{
    if (player == computer)
        return 0;

    if ((player - computer + 3) % 3 == 1)
        return 1;

    return -1;
}

// Generate unbiased random move
int random_move(void)
{
    int limit = RAND_MAX - (RAND_MAX % 3);
    int value;

    do  {
    value = rand();
    } while (value >= limit);

    return value % 3;
}

int main(void)
{
    char choice[20];

    int player_move;
    int computer_move;
    int result;

    int player_score = 0;
    int computer_score = 0;
    int draws = 0;
    int rounds;

    srand((unsigned int)time(NULL));

    printf("=====================================\n");
    printf("        ROCK PAPER SCISSORS\n");
    printf("=====================================\n");

    // Ask number of rounds
    printf("Enter number of rounds: ");

    if (scanf("%d", &rounds) != 1 || rounds <= 0)
    {
        printf("Invalid number of rounds.\n");
        return 1;
    }

    // Play fixed number of rounds
    for (int round = 1; round <= rounds; round++)
    {
        printf("\n---------- Round %d ----------\n", round);

        printf("\nChoose your move:\n");
        printf("Rock (r)\n");
        printf("Paper (p)\n");
        printf("Scissors (s)\n");
        printf("\nEnter choice: ");

        if (scanf("%19s", choice) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        // Convert input to lowercase
        for (int i = 0; choice[i] != '\0'; i++)
            choice[i] = tolower((unsigned char)choice[i]);

        // Convert text input to move number
        if (strcmp(choice, "rock") == 0 || strcmp(choice, "r") == 0)
            player_move = 0;

        else if (strcmp(choice, "paper") == 0 || strcmp(choice, "p") == 0)
            player_move = 1;

        else if (strcmp(choice, "scissors") == 0 || strcmp(choice, "s") == 0)
            player_move = 2;

        else
        {
            printf("Invalid choice. Try again.\n");
            round--; // repeat same round
            continue;
        }

        computer_move = random_move();

        // Print moves
        printf("\n--------------------------------------\n");
        printf("You chose: %s\n",
               move_name(player_move));
        printf("Computer chose: %s\n",
               move_name(computer_move));
        printf("--------------------------------------\n");

        // Decide winner
        result = decide_winner(player_move, computer_move);

        if (result == 0)
        {
            printf("\nResult: It's a draw!\n");
            draws++;
        }
        else if (result == 1)
        {
            printf("\nResult: You win!\n");
            player_score++;
        }
        else
        {
            printf("\nResult: Computer wins!\n");
            computer_score++;
        }

        // Scoreboard
        printf("\n========== SCOREBOARD ==========\n");
        printf("You      : %d\n", player_score);
        printf("Computer : %d\n", computer_score);
        printf("Draws    : %d\n", draws);
    }

    // Final scores
    printf("\n========== Final Scores ==========\n");

    printf("You: %d\n", player_score);
    printf("Computer: %d\n", computer_score);
    printf("Draws: %d\n", draws);

    // Overall winner
    if (player_score > computer_score)
        printf("\nOverall Winner: You!\n");
    else if (computer_score > player_score)
        printf("\nOverall Winner: Computer!\n");
    else
        printf("\nOverall Result: It's a Tie!\n");

    printf("\nThanks for playing!\n");
    return 0;
}
