#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

// Comparator function for sorting items based on value/weight ratio
bool comp(pair<int, int> a, pair<int, int> b) {
    double r1 = (double)a.first / (double)a.second;
    double r2 = (double)b.first / (double)b.second;
    return r1 > r2;
}

// Function to calculate the maximum value of items in the fractional knapsack
double fractionalKnapsack(int W, vector<pair<int, int>> &items, int n) {
    sort(items.begin(), items.end(), comp);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].second <= W) {
            curWeight += items[i].second;
            finalValue += items[i].first;
        } else {
            int remain = W - curWeight;
            finalValue += (items[i].first / (double)items[i].second) * (double)remain;
            break;  // ************************
        }
    }

    return finalValue;
}

int main() {
    int n, W;

    // Input number of items and maximum weight
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    vector<pair<int, int>> items(n);  // ************************

    // Input the values and weights of the items
    cout << "Enter the value and weight of each item (value weight):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second; // First is value, second is weight
    }

    // Calculate the maximum value
    double maxValue = fractionalKnapsack(W, items, n);
    cout << "The maximum value is "  << maxValue << endl;

    return 0;
}
