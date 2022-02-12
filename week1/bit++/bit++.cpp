// Implements the bit++ language. First it recieves
// the amount of instructions (as an int) and then
// one instruction (strings of length 3) per line.
// Submit 2
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    int X = 0;
    string amount_of_instructions;
    string instruction;

    getline(cin, amount_of_instructions);

    assert(amount_of_instructions.length() == 1);

    for (int i = 0; i < stoi(amount_of_instructions); i++) {
        getline(cin, instruction);

        assert(instruction.length() == 3);

        if(instruction.substr(0, 2) == "++" || instruction.substr(1, 2) == "++") {
            X++;
        } else {
            X--;
        }
    }

    cout << X;
    
    return 0;
}