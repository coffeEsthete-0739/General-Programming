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
    vector<Item> items = {{60,10},{100,20},{120,30}};
    int W=50;
    cout << "Max Value: " << fractionalKnapsack(items,W);
}
