#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate computer choice
char generateChoice() {
    int num = rand() % 3;

    if (num == 0) return 's'; // Snake
    if (num == 1) return 'w'; // Water
    return 'g';               // Gun
}

// Function to decide winner
int gameResult(char user, char comp) {
    if (user == comp)
        return 0;

    if ((user == 's' && comp == 'w') ||
        (user == 'w' && comp == 'g') ||
        (user == 'g' && comp == 's'))
        return 1;

    return -1;
}

int main() {
    char user, comp;
    int result;

    srand(time(0)); // Seed random

    printf("🐍 Snake 🆚 💧 Water 🆚 🔫 Gun Game\n");
    printf("Enter 's' for Snake, 'w' for Water, 'g' for Gun: ");
    scanf(" %c", &user);

    comp = generateChoice();

    printf("\nYou chose: %c", user);
    printf("\nComputer chose: %c\n", comp);

    result = gameResult(user, comp);

    if (result == 0)
        printf("Result: It's a Draw!\n");
    else if (result == 1)
        printf("Result: You Win! 🎉\n");
    else
        printf("Result: You Lose! 😢\n");

    return 0;
}