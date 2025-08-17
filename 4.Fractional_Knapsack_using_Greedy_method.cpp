#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item { int value, weight; };

bool cmp(Item a, Item b) {
    return (double)a.value/a.weight > (double)b.value/b.weight;
}

double fractionalKnapsack(vector<Item> items, int W) {
    sort(items.begin(), items.end(), cmp);
    double total = 0;
    for(auto &it : items){
        if(W >= it.weight){
            W -= it.weight;
            total += it.value;
        } else {
            total += (double)it.value * W / it.weight;
            break;
        }
    }
    return total;
}

int main(){
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter value and weight for each item:\n";
    for(int i=0;i<n;i++) cin >> items[i].value >> items[i].weight;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    cout << "Max Value: " << fractionalKnapsack(items,W);
}
