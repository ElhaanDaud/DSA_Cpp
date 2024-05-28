//Write a program to show the working of fractional knapsack problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    double totalValue = 0.0;

    // Calculate the ratio of value to weight for each item
    for (int i = 0; i < items.size(); ++i) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items based on their value-to-weight ratio in non-increasing order
    sort(items.begin(), items.end(), compare);

    // Loop through the items and add them to the knapsack
    for (int i = 0; i < items.size(); ++i) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            totalValue += (double)capacity / items[i].weight * items[i].value;
            break; // No more capacity left
        }
    }

    return totalValue;
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

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
