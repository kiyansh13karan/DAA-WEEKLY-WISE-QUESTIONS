/*
.Given an array of characters, you have to find distinct characters from 
this array. Design an algorithm and implement it using a program to 
solve this problem using hashing. (Time Complexity = O(n))
*/



#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void findDistinctCharacters(const vector<char>& arr) {
    unordered_set<char> hashSet;

    for (char ch : arr) {
        hashSet.insert(ch);
    }

    cout << "Distinct characters: ";
    for (char ch : hashSet) {
        cout << ch << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> arr(n);
    cout << "Enter the characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findDistinctCharacters(arr);

    return 0;
}
