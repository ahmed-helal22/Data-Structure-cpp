#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
//b)airbort in codeforce
//ميزتها انها اسرع من sort array لو هتستعملها كتير 
using namespace std;

int main() {
    int n, m;cin >> n >> m;
    vector<int>planes(m);
    for (int i = 0;i < m;i++)
    {
        cin >> planes[i];
    }

    int max_price = 0;
    priority_queue<int>max_pq(planes.begin(), planes.end());
    for (int i = 0;i < n;i++)
    {
        int current_seat = max_pq.top();
        max_price += current_seat;
        max_pq.pop();
        if (current_seat - 1 > 0)
        {
            max_pq.push(current_seat - 1);
        }
    }

    int min_price = 0;
    priority_queue<int, vector<int>, greater<int>>min_pq(planes.begin(), planes.end());
    for (int i = 0;i < n;i++)
    {
        int current_seat = min_pq.top();
        min_price += current_seat;
        min_pq.pop();
        if (current_seat - 1 > 0)
        {
            min_pq.push(current_seat - 1);
        }

    }
    cout << max_price << " " << min_price;
    return 0;
}