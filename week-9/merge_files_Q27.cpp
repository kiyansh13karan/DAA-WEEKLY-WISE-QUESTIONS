/*
 Givenanarrayofelements.Assumearr[i] representsthesizeof
 filei.Writeanalgorithmandaprogramtomergeallthesefilesintosingle
 filewithminimumcomputation.ForgiventwofilesAandBwithsizesm
 andn,computationcostofmergingthemisO(m+n). (Hint:usegreedy
 approach)
*/



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minMergeCost(vector<int>& files) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int size : files) {
        minHeap.push(size);
    }

    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int cost = first + second;
        totalCost += cost;

        minHeap.push(cost); // Push merged file size back
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    vector<int> files(n);
    cout << "Enter size of each file:\n";
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    int result = minMergeCost(files);
    cout << "Minimum total computation cost to merge all files: " << result << endl;

    return 0;
}
