/*
Given a string of characters, design an algorithm and implement it 
using a program to print all possible permutations of the string in 
lexicographic order.
*/



#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void printPermutations(string str) {
    // Step 1: Sort the string
    sort(str.begin(), str.end());

    cout << "All lexicographic permutations:\n";
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    printPermutations(input);

    return 0;
}
