// 2750: 수 정렬하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;

int main() {
    cin >> N;

    int num;
    vector<int> arr;
    for(int i = 0; i < N; i++) {
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}