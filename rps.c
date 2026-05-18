#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Convert numeric move values to readable text:
 * 0 -> Rock, 1 -> Paper, 2 -> Scissors
 */
const char *move_name(int move) {
    if (move == 0) return "Rock";
    if (move == 1) return "Paper";
    return "Scissors";
}

/*
 * Decide winner for one round.
 * Returns:
 *  0 for draw
 *  1 if player wins
 * -1 if computer wins
 */
int decide_winner(int player, int computer) {
    if (player == computer) return 0;

    if ((player == 0 && computer == 2) ||
        (player == 1 && computer == 0) ||
        (player == 2 && computer == 1)) {
        return 1;
    }

    return -1;
}

int main(void) {
    int player_move;
    int computer_move;
    int result;

    /* Seed random number generator once per program run. */
    srand((unsigned int)time(NULL));

    printf("Rock Paper Scissors (single round)\n");
    printf("Choose your move:\n");
    printf("0 - Rock\n1 - Paper\n2 - Scissors\n");
    printf("Enter choice: ");

    if (scanf("%d", &player_move) != 1) {
        printf("Invalid input. Please enter 0, 1, or 2.\n");
        return 1;
    }

    if (player_move < 0 || player_move > 2) {
        printf("Choice out of range. Please enter 0, 1, or 2.\n");
        return 1;
    }

    /* Computer picks a random move from 0 to 2. */
    computer_move = rand() % 3;

    printf("\nYou chose: %s\n", move_name(player_move));
    printf("Computer chose: %s\n", move_name(computer_move));

    result = decide_winner(player_move, computer_move);

    if (result == 0) {
        printf("Result: It's a draw!\n");
    } else if (result == 1) {
        printf("Result: You win!\n");
    } else {
        printf("Result: Computer wins!\n");
    }

    return 0;
}
