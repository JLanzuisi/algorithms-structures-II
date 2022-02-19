#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

class Brackets {
    public:
        explicit Brackets(string inputBracketList = "");
        char type(int i) const;
        void write(const string & s);
    private:
        string bracketList;
};

int main() {
    stack<char> openingBrackets;
    Brackets brackets;
    string inputString;
    int replaces;

    cin >> inputString;

    brackets.write(inputString);

    for (size_t i = 0; i<inputString.length(); i++) {
        if (inputString[i] == '[' || inputString[i] == '{' || inputString[i] == '(' || inputString[i] == '<') {
            openingBrackets.push(inputString[i]);
        } else if (i == 0) {
            cout << "Impossible";
            exit(0);
        } else if (openingBrackets.empty()) {
            cout << "Impossible";
            exit(0);
        } else {
            if (openingBrackets.top() != brackets.type(i)) {
                replaces++;
            }
            openingBrackets.pop();
        }
    }

    if (openingBrackets.empty()) {
        cout << replaces;
    } else {
        cout << "Impossible";
    }

    return 0;
}

Brackets::Brackets(string inputBracketList) : bracketList{inputBracketList} {}

void Brackets::write(const string & s) {
    bracketList = s;
}

char Brackets::type(int i) const {
    if (bracketList[i] == '[' || bracketList[i] == ']') {
        return '[';
    } else if (bracketList[i] == '(' || bracketList[i] == ')') {
        return '(';
    } else if (bracketList[i] == '{' || bracketList[i] == '}') {
        return '{';
    } else if (bracketList[i] == '<' || bracketList[i] == '>') {
        return '<';
    } else {
        exit(1);
    }
}