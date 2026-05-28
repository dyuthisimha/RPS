#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Convert numeric move values to readable text: 0 -> Rock, 1 -> Paper, 2 -> Scissors
const char *move_name(int move)
{
    if (move == 0) return "Rock";
    if (move == 1) return "Paper";
    if (move == 2) return "Scissors";
    return "Unknown Move";
}

// Decide winner: 0  = draw; 1  = player wins; -1  = computer wins
int decide_winner(int player, int computer)
{
    if (player == computer) return 0;
    if ((player - computer + 3) % 3 == 1) return 1;
    return -1;
}

//Generate unbiased random move
int random_move(void)
{
    int limit = RAND_MAX - (RAND_MAX % 3);
    int value;

    do {
        value = rand();
    } while (value >= limit);

    return value % 3;
}

int main(void)
{
    char choice[20];
    char play_again = 'y';

    int player_move;
    int computer_move;
    int result;

    int player_score = 0;
    int computer_score = 0;
    int draws = 0;

    srand((unsigned int)time(NULL));

    printf("=== Rock Paper Scissors ===\n");

    while (play_again == 'y')
    {
        printf("\nType Rock(r), Paper(p), or Scissors(s)\n");
        printf("Enter choice: ");

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
            printf("Invalid choice.\n");
            continue;
        }

        computer_move = random_move();

        printf("\nYou chose: %s\n", move_name(player_move));
        printf("Computer chose: %s\n", move_name(computer_move));

        result = decide_winner(player_move, computer_move);

        if (result == 0)
        {
            printf("Result: It's a draw!\n");
            draws++;
        }
        else if (result == 1)
        {
            printf("Result: You win!\n");
            player_score++;
        }
        else
        {
            printf("Result: Computer wins!\n");
            computer_score++;
        }

        // Print scores
        printf("\n--- Scoreboard ---\n");
        printf("You: %d\n", player_score);
        printf("Computer: %d\n", computer_score);
        printf("Draws: %d\n", draws);

        // Ask to play again
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &play_again);

        play_again = tolower((unsigned char)play_again);
    }

    printf("\n=== Final Scores ===\n");
    printf("You: %d\n", player_score);
    printf("Computer: %d\n", computer_score);
    printf("Draws: %d\n", draws);

    printf("\nThanks for playing!\n");

    return 0;
}
