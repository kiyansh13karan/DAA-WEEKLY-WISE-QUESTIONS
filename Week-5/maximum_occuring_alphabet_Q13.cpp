/*
 Given an unsorted array of alphabets containing duplicate
 elements. Design an algorithm and implement it using a program to find
 which alphabet has maximum number of occurrences and
*/



#include <iostream>
using namespace std;

char findMaxOccurringAlphabet(const char arr[], int n) {
    int count[26] = {0}; // Array to store count of each alphabet
    
    // Count occurrences of each alphabet
    for (int i = 0; i < n; i++) {
        count[arr[i] - 'a']++;
    }
    
    // Find the alphabet with maximum occurrences
    int maxCount = 0;
    char maxChar = 'a';
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxChar = 'a' + i;
        }
    }
    
    return maxChar;
}

int main() {
    char arr[] = {'b', 'c', 'a', 'b', 'a', 'c', 'a', 'a', 'a'};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    char maxAlphabet = findMaxOccurringAlphabet(arr, n);
    cout << "The alphabet with the maximum occurrences is: " << maxAlphabet << endl;
    
    return 0;
}
