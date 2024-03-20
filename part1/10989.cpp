// 10989: 수 정렬하기 3
#include <iostream>
using namespace std;
int N;
int arr[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        arr[num] += 1;
    }

    for(int i = 0; i < 10001; i++) {
        for(int j = 0; j < arr[i]; j++) {
            cout << i << '\n';
        }
    }

    return 0;
}