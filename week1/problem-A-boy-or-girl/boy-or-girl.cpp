// Takes a string 'username', does some sanity checks,
// then removes all repeated characters from 'username'
// and then uses the hero method:
//      if the number of distinct characters in one's user name is odd,
//      then he is a male, otherwise she is a female. 
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int main() {
    string username;

    getline(cin, username);

    assert(!username.empty()); // String not empty
    assert(username.find(" ") == string::npos); // String without spaces
    assert(all_of(username.begin(), username.end(), &::islower)); // All lowercase

    // Delete all repeated chars
    for (size_t i = 0; i < username.length(); i++) {
        if (username.find(username[i], i+1) != string::npos) {
            username.erase(i, 1);
            i--;
        }
    }

    if (username.length() % 2 == 0) {
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }


    return 0;
}