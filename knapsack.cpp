#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int profit;
    int id;
    float pByW;
};

/* bool compare(Item a, Item b) {
    return a.pByW > b.pByW;
}

void knapsack(vector<Item> items, int sac) {
    float maxProfit = 0;

    for (int i = 0; i < items.size(); i++) {
        items[i].pByW = (float)items[i].profit / items[i].weight;
    }

    sort(items.begin(), items.end(), compare);

    for (int i = 0; i < items.size(); i++) {
        if (sac >= items[i].weight) {
            sac -= items[i].weight;
            maxProfit += items[i].profit;
            cout << "Item fully selected id " << items[i].id << endl;
        } else if (sac > 0) {
            maxProfit += sac * items[i].pByW;
            cout << "Item partially selected id " << items[i].id << endl;
            sac = 0;
        }

        if (sac == 0) break;
    }

    cout << "Max Profit: " << maxProfit << endl;
}
 */

bool compare(Item a, Item b)
{
    return a.pByW > b.pByW;
}
void knapsack(vector<Item> items)
{
    float maxProfit = 0;
    int sac = 100;
    int n = items.size();
    for (int i  = 0; i<n; i++)
    {
        items[i].pByW = (float)items[i].profit / items[i].weight;
    }
    sort(items.begin(), items.end(), compare);

    for (int i = 0; i < n; i++)
    {
        if (sac >= items[i].weight)
        {
            maxProfit+=items[i].profit;
            sac-=items[i].weight;
            cout<<"id: "<<items[i].id<< " fully selected"<<endl;
        }
        else if (sac > 0)
        {
            maxProfit+=(float)sac*items[i].pByW;
            sac = 0;
            cout<<"id: "<<items[i].id<< " partially selected"<<endl;
        }
        if (sac == 0)
        {
            break;
        }
    }
    cout<<"maxProfit: "<<maxProfit<<endl;
}

int main()
{
    vector<Item> items = {
        {10, 60, 1},
        {40, 100, 2},
        {20, 120, 3},
        {30, 90, 4},
        {25, 75, 5},
        {15, 45, 6},
        {50, 150, 7},
        {5, 20, 8},
        {35, 105, 9},
        {45, 135, 10}};

    knapsack(items);
    return 0;
}
