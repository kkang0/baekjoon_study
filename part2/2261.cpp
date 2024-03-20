// 2261: 가장 가까운 두 점
#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
using namespace std;
const int INF = (int)2e9;

int dist(int x1, int y1, int x2, int y2) {
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int main() {
    int n, x, y;
    vector<pair<int, int>> p;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }

    int min_dist = INF;
    for(int i = 0; i < n; i++) {
        int x1 = p[i].first;
        int y1 = p[i].second;
        for(int j = i + 1; j < n; j++) {
            int x2 = p[j].first;
            int y2 = p[j].second;

            int distance = dist(x1, y1, x2, y2);
            min_dist = min(distance, min_dist);
        }
    }

    cout << min_dist << endl;

    return 0;
}