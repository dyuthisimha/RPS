#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

/*
 Convert numeric move values to readable text:
 0 -> Rock, 1 -> Paper, 2 -> Scissors
 */
const char *move_name(int move) 
{
    if (move == 0) return "Rock";
    if (move == 1) return "Paper";
    if (move == 2) return "Scissors";
    return "Unknown Move"; 
}

/*
 Decide the winner for one round.
 Returns: 0 for draw, 1 if player wins, -1 if computer wins
 */
int decide_winner(int player, int computer) 
{
    if (player == computer) return 0;
    
    if ((player - computer + 3) % 3 == 1) 
        return 1; // Player wins
        
    return -1; // Computer wins
}

// Generate an unbiased random move in range [0, 2] using rejection sampling.
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
    int player_move;
    int computer_move;
    int result;

    /* Seed random number generator once per program run. */
    srand((unsigned int)time(NULL));

    printf("Rock Paper Scissors (single round)\n");
    printf("Type Rock(r), Paper(p), or Scissors(s)\n");
    printf("Enter choice: ");

    if (scanf("%19s", choice) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 0; choice[i] != '\0'; i++)
        choice[i] = tolower((unsigned char)choice[i]);

    if (strcmp(choice, "rock") == 0 || strcmp(choice, "r") == 0)
        player_move = 0;

    else if (strcmp(choice, "paper") == 0 || strcmp(choice, "p") == 0)
        player_move = 1;

    else if (strcmp(choice, "scissors") == 0 || strcmp(choice, "s") == 0)
        player_move = 2;

    else
    {
        printf("Invalid choice. Type Rock, Paper, or Scissors.\n");
        return 1;
    }

    /* Computer picks a random move from 0 to 2. */
    computer_move = random_move();

    printf("\nYou chose: %s\n", move_name(player_move));
    printf("Computer chose: %s\n", move_name(computer_move));

    result = decide_winner(player_move, computer_move);

    if (result == 0) 
        printf("Result: It's a draw!\n");
    else if (result == 1) 
        printf("Result: You win!\n");
    else 
        printf("Result: Computer wins!\n");
    
    return 0;
}
