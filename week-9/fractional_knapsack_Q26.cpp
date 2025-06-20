/*
Givenaknapsackofmaximumcapacityw.Nitemsareprovided,
 eachhavingitsownvalueandweight.YouhavetoDesignanalgorithm
 andimplement itusingaprogramtofindthelistof theselecteditems
 such that the final selectedcontent hasweightwandhasmaximum
 value.Youcantakefractionsof items,i.e. theitemscanbebrokeninto
 smaller pieces so that you have to carry
 only a fraction xi of item i, where 0 ≤xi≤ 1
*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

// Comparator to sort by value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

void fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    vector<pair<int, double>> selected; // item index and fraction taken

    for (int i = 0; i < items.size(); i++) {
        if (W == 0)
            break;

        if (items[i].weight <= W) {
            // Take full item
            W -= items[i].weight;
            totalValue += items[i].value;
            selected.push_back({i, 1.0});
        } else {
            // Take fraction of item
            double fraction = (double)W / items[i].weight;
            totalValue += items[i].value * fraction;
            selected.push_back({i, fraction});
            W = 0;
        }
    }

    cout << "Selected items (index : fraction taken):\n";
    for (auto p : selected) {
        cout << "Item " << p.first << " : " << p.second << endl;
    }

    cout << "Maximum value in knapsack = " << totalValue << endl;
}

int main() {
    int N, W;
    cout << "Enter number of items: ";
    cin >> N;

    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    vector<Item> items(N);
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < N; i++) {
        cout << "Item " << i << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    fractionalKnapsack(W, items);

    return 0;
}
