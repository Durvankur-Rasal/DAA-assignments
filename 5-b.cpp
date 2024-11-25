#include <iostream>
#include <vector>
using namespace std;

// Global variable to track the maximum profit
int maxProfit = 0;

// Function to solve the knapsack problem using backtracking
void knapsackBacktracking(int index, int currentWeight, int currentProfit, int maxWeight, vector<int> &weights, vector<int> &profits) {
    // Base case: if all items have been considered
    if (index == weights.size()) {
        // Update the maximum profit
        maxProfit = max(maxProfit, currentProfit);
        return;
    }

    // If the current item can be included in the knapsack
    if (currentWeight + weights[index] <= maxWeight) {
        // Include the item and move to the next item
        knapsackBacktracking(index + 1, currentWeight + weights[index], currentProfit + profits[index], maxWeight, weights, profits);
    }

    // Exclude the current item and move to the next item
    knapsackBacktracking(index + 1, currentWeight, currentProfit, maxWeight, weights, profits);
}

int main() {
    int n, W;

    // Input the number of items and maximum weight
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    vector<int> weights(n), profits(n);

    // Input the weights and profits of the items
    for (int i = 0; i < n; i++) {
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> weights[i];
        cout << "Enter profit of item " << i + 1 << ": ";
        cin >> profits[i];
    }

    // Solve the problem using backtracking
    knapsackBacktracking(0, 0, 0, W, weights, profits);

    // Output the maximum profit
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
