#include <iostream>
#include <cassert>

using namespace std;

int main() {
    string amount_of_sushi;
    string input_str;
    int prev_length;
    int current_length = 0;
    int answer;

    getline(cin, amount_of_sushi);
    getline(cin, input_str);

    prev_length = stoi(amount_of_sushi)+1;

    input_str.push_back(' ');
    input_str.push_back('3');

    for (size_t i = 0; i < input_str.length(); i++) {
        if (i == 0) {
            current_length++;
        } else if (i % 2 == 0) {
            if (input_str[i] == input_str[i-2]) {
                current_length++;
            } else {
                if (current_length >= prev_length) {
                    answer = 2 * prev_length;
                } else {
                    answer = 2 * current_length;
                }
                prev_length = current_length;
                current_length = 1;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
