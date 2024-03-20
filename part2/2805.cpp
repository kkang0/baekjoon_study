// 2805: 나무 자르기
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000000];

int main() {
    long long N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    long long low = 0;
    long long high = arr[N - 1];
    long long max = 0;

    while(low <= high) {
        long long sum = 0;
        long long mid = (low + high) / 2;

        for(int i = 0; i < N; i++) {
            if(arr[i] - mid > 0) {
                sum += arr[i] - mid;
            }
        }

        if(sum >= M) {
            max = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

   cout << max << '\n';

    return 0;
}