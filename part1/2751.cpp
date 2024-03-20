// 2751: 수 정렬하기2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;

int main() {
    ios::sync_with_stdio(false);
    
    cin >> N;

    int num;
    vector<int> arr;
    for(int i = 0; i < N; i++) {
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}