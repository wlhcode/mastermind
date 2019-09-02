#include<iostream>

#include<random>

#include<ctime>

using namespace std;
char code[5];
char gues[5];
int main() {
    srand(time(NULL));
    for (int i = 0; i < 4; i++) code[i] = rand() % 7 + '0';

    cout << "Welcome to Mastermind!" << endl;
    cout << "I have a 4-digit code using numbers 0 to 6." << endl;
    cout << "For each guess there is a verdict:" << endl;
    cout << "\t+ for correct color and position;" << endl;
    cout << "\t- for correct color but incorrect position." << endl;
    cout << "Can you break the code in 12 guesses?" << endl << endl;

    for (int i = 1; i <= 12; i++) {
        cout << "Guess " << i << ": ";
        cin >> gues;
        int exact = 0, color = 0;
        bool used[5];
        for (int j = 0; j < 4; j++) used[j] = 0;
        for (int g = 0; g < 4; g++) {
            for (int c = 0; c < 4; c++) {
                if (used[c] == 1) continue;
                if (gues[g] == code[c]) {
                    used[c] = 1;
                    if (g == c) exact++;
                    else color++;
                    break;
                }
            }
        }
        if (exact == 4) {
            cout << "Congratulations! You have broken the code in " << i << " guesses." << endl;
            return 0;
        } else {
            for (int k = 0; k < exact; k++) cout << "+";
            for (int k = 0; k < color; k++) cout << "-";
            cout << endl;
        }
    }
    cout << "Incorrect! You have failed to break the code. The code is " << code << "." << endl;
    return 0;
}
