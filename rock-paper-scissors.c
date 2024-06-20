#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Prototypes
string get_user_choice(string possible_choices[]);
string get_computer_choice(string possible_choices[]);
int compare(string user_choice, string computer_choice);

int main(void) {

    string possible_choices[] = {"rock", "paper", "scissors"};
    string user_choice = get_user_choice(possible_choices);
    string computer_choice = get_computer_choice(possible_choices);

    int results = compare(user_choice, computer_choice);

    if (results == 0) {
        printf("USER WINS!\nUSER CHOSE: %s\nCOMPUTER CHOSE: %s\n", user_choice, computer_choice);
    }

    else if (results == 1) {
        printf("USER LOSES!\nUSER CHOSE: %s\nCOMPUTER CHOSE: %s\n", user_choice, computer_choice);
    }

    else {
        printf("DRAW!\nUSER CHOSE: %s\nCOMPUTER CHOSE: %s\n", user_choice, computer_choice);
    }
}

string get_user_choice(string possible_choices[]) {
    bool validated_choice = false;
    string user_choice;

    do {
        user_choice = get_string("Enter a choice between rock, paper or scissors\n> ");

        for (int i = 0; i <= 2; i++) {
            if (strcmp(possible_choices[i], user_choice) == 0) {
                validated_choice = true;
                break;
            }
        }

        if (validated_choice) {
            break;
        }

        printf("Invalid choice: %s\n", user_choice);

    } while (!validated_choice);

    return user_choice;

}

string get_computer_choice(string possible_choices[]) {
    srand(time(NULL));

    int random_num = rand() % 3;
    string computer_choice = possible_choices[random_num];

    return computer_choice;
}

int compare(string user_choice, string computer_choice) {

    //0: user wins, 1: user loses, 2: draw

    if ((strcmp(user_choice, "rock") == 0 && strcmp(computer_choice, "scissors") == 0) ||
            (strcmp(user_choice, "paper") == 0 && strcmp(computer_choice, "rock") == 0) ||
            (strcmp(user_choice, "scissors") == 0 && strcmp(computer_choice, "paper") == 0)) {
            return 0; // user wins
    }

    else if (user_choice == computer_choice) {
        return 2;
    }

    else {
        return 1;
    }

}
