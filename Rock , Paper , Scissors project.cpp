#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

void displayMenu();
int getPlayerChoice();
int getComputerChoice();
string choiceToString(int choice);
int determineRoundWinner(int player, int computer);
void displayRoundResult(int player, int computer, int result);
void displayFinalResults(int playerWins, int computerWins, int ties);

int main()   //Play Rock Paper Scissors
{
    srand(time(0));

    int playerChoice;
    int computerChoice;

    int playerWins = 0;
    int computerWins = 0;
    int ties = 0;

    do
    {
        displayMenu();

        playerChoice = getPlayerChoice();

        if (playerChoice != QUIT)
        {
            computerChoice = getComputerChoice();

            int result = determineRoundWinner(playerChoice, computerChoice);

            if (result == 1)
            {
                playerWins++;
            }
            else if (result == 2)
            {
                computerWins++;
            }
            else
            {
                ties++;
            }

            displayRoundResult(playerChoice, computerChoice, result);
        }

    } while (playerChoice != QUIT);

    displayFinalResults(playerWins, computerWins, ties);

    return 0;
}


void displayMenu()
{
    cout << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "4. Quit" << endl;
}


int getPlayerChoice()
{
    int choice;

    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 4)
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
    }

    return choice;
}


int getComputerChoice()
{
    return rand() % 3 + 1;
}


string choiceToString(int choice)
{
    if (choice == ROCK)
    {
        return "Rock";
    }
    else if (choice == PAPER)
    {
        return "Paper";
    }
    else
    {
        return "Scissors";
    }
}


int determineRoundWinner(int player, int computer)
{
    if (player == computer)
    {
        return 3;
    }

    if ((player == ROCK && computer == SCISSORS) ||
        (player == PAPER && computer == ROCK) ||
        (player == SCISSORS && computer == PAPER))
    {
        return 1;
    }

    return 2;
}


void displayRoundResult(int player, int computer, int result)
{
    cout << "You chose: "
        << choiceToString(player) << endl;

    cout << "Computer chose: "
        << choiceToString(computer) << endl;

    if (result == 1)
    {
        cout << "You win!" << endl;
    }
    else if (result == 2)
    {
        cout << "Computer wins!" << endl;
    }
    else
    {
        cout << "Tie!" << endl;
    }
}


void displayFinalResults(int playerWins, int computerWins, int ties)
{
    cout << endl;
    cout << "Final Results" << endl;

    cout << "Player wins: "
        << playerWins << endl;

    cout << "Computer wins: "
        << computerWins << endl;

    cout << "Ties: "
        << ties << endl;

    if (playerWins > computerWins)
    {
        cout << "You won the tournament!" << endl;
    }
    else if (computerWins > playerWins)
    {
        cout << "Computer won the tournament!" << endl;
    }
    else
    {
        cout << "The tournament is a draw." << endl;
    }
}