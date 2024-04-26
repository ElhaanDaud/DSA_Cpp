#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to solve 0/1 knapsack problem
int knapsack(int capacity, const vector<Item>& items) {
    int n = items.size();
    // Create a 2D table to store the maximum value that can be obtained
    // for each weight with different number of items
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // If the weight of the current item is more than the capacity, it cannot be included
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                // Otherwise, consider either including the current item or excluding it
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }

    // Return the maximum value that can be obtained with the given capacity
    return dp[n][capacity];
}

int main() {
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    int maxValue = knapsack(capacity, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl; //10 50 5 40 6 36 4 36 122

    return 0;
}
