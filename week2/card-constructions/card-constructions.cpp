// The amount of cards in a pyramid of heigth h is:
//              3/2 h^2 + 1/2 h.

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

double amount_of_cards (int heigth) {
    return ((1.5)*heigth*heigth) + ((0.5)*heigth);
}

int main() {
    const int max_height = 25820; // Height of pyramid with 10^9 cards

    int amount_of_tests, current_test;

    int left, right, mid, temp;

    vector<int> tests;

    cin >> amount_of_tests;

    for (int i = 0; i < amount_of_tests; i++){
        cin >> temp;
        tests.push_back(temp);
    }

    for (int i = 0; i < amount_of_tests; i++) {

        int answer = 0;

        while (tests[i] > 1) { // Keep going only if we have enough to build pyramid
            answer++;
            left = 0;
            right = max_height;
            while (left <= right) {
                mid = (left + right) / 2;

                if (double(tests[i]) < amount_of_cards(mid)) {
                    right = mid - 1;
                } else if (double(tests[i]) > amount_of_cards(mid)) {
                    left = mid + 1;
                } else {
                    break;
                }
            }
            tests[i] = tests[i] - amount_of_cards(right);
        }
        cout << answer << endl;
    }

    return 0;
}
