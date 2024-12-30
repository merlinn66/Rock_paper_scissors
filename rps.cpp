#include <iostream>
#include <string>
#include <ctime>

void intro();
int three_seed(int seed);
int playGame(int& score_player, int& score_computer, int botMove, int playerChoice);
int getBot(int seed);
int getPlayer();
void username(std::string &name);

using namespace std;

int main() {
    intro();

    string user_id;
    username(user_id);

    int score_player = 0;
    int score_computer = 0;
    const int max_round = 3;

    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < max_round; i++) {
        int playerChoice = getPlayer(); // Get player's choice
        int botMove = getBot(rand()); // Get bot's choice
        playGame(score_player, score_computer, botMove, playerChoice);
    }

    cout << user_id << " " << score_player << " - " << score_computer << " Computer" << endl;

    if (score_player > score_computer){
        cout << "CONGRADULATIONS YOU WIN!" << endl;
    }
    else if(score_player < score_computer){
        cout << "YOU LOST :(" <<  endl;
    }
    else {
        cout << "IT'S A DRAW :/" << endl;
    }

    return 0;
}

void intro() {
    cout << "Welcome to this rock paper scissors game. " << endl;
    cout << "+---------RULES--------+" << endl;
    cout << "+ For ROCK type 1      +" << endl;
    cout << "+ For Paper type 2     +" << endl;
    cout << "+ For SCISSORS type 3  +" << endl;
    cout << "+----------------------+" << endl;
}

int three_seed(int seed) {
    srand(seed); // Seed the random number generator
    const int number_of_hands = 3; // Total number of options
    return rand() % number_of_hands + 1; // Generate number between 1 and 3
}

int getPlayer() {
    string playerMove;
    cout << "Rock. Paper. Scissors. shoot: ";
    cin >> playerMove;

    // Input validation with a loop to ensure valid choice
    while (true) {
        if (playerMove == "Rock" || playerMove == "rock") {
            return 1;
        } else if (playerMove == "Paper" || playerMove == "paper") {
            return 2;
        } else if (playerMove == "Scissors" || playerMove == "scissors") {
            return 3;
        } else {
            cout << "Invalid Input! Please choose Rock, Paper, or Scissors: ";
            cin >> playerMove; // Prompt again for valid input
        }
    }
}

int getBot(int seed) {
    // 1 = rock, 2 = paper, 3 = scissor   
    return three_seed(seed);
}

int playGame(int& score_player, int& score_computer, int botMove, int playerChoice) {
    if (playerChoice == botMove) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == 1 && botMove == 3) || // Rock beats Scissors
               (playerChoice == 2 && botMove == 1) || // Paper beats Rock
               (playerChoice == 3 && botMove == 2)) { // Scissors beats Paper
        cout << "You win this round!" << endl;
        score_player++;
    } else {
        cout << "Bot wins this round!" << endl;
        score_computer++;
    }
    return 0;
}

void username(string& name) {
    cout << "Enter player Name: ";
    cin >> name;
}
