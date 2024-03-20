// 10819: 차이를 최대로
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, num;
    vector<int> v;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num); 
    }

    sort(v.begin(), v.end());

    int result = 0;
    do {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            if(i == N - 1) continue;
            sum += abs(v[i] - v[i + 1]);
        }
        result = max(sum, result);
    } while (next_permutation(v.begin(), v.end()));
    
    cout << result << endl;

    return 0;
}