// Program: 100 Game, in this game : Two players start from 0 and alternatively add a number from 1 to 10 to the sum. The player who reaches 100 wins.
// Author:  Eyad Yossri Sayed - no section yet - 20230078
// Version: 2.0
// Date:    1/3/2024

#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "\n* 100 Game *\n* Two players start from 0 and alternatively add a number from 1 to 10 to the sum. *\n* The player who reaches 100 wins. *\n";

    int sum = 0;
    int current_player = 1;

    // Main Game loop
    while (sum < 100) {
        // Determine current player
        string player_name = (current_player == 1) ? "Player 1" : "Player 2";

        // Ask the current player to input a number within the valid range
        int num = 0;
        while (true) {
            cout << player_name << ": Please enter a number from 1 to " << min(10, 100 - sum) << ": ";

            // Check if the input is a valid integer
            if (!(cin >> num)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number.\n";
            } else if (num < 1 || num > min(10, 100 - sum)) {
                cout << "Invalid input. Please enter a number within the valid range.\n";
            } else {
                break;
            }
        }

        // If the input is valid, add the input number to the sum and display the current sum
        sum += num;
        cout << "\n---------> Current Sum = " << sum << endl;

        // Check if the current player wins
        if (sum == 100) {
            cout << "The Winner is " << player_name << endl;
            break;
        }

        // Switch player (alternates between 1 and 2)
        current_player = 3 - current_player;
    }

    cout << "Game Over" << endl;

    return 0;
}
