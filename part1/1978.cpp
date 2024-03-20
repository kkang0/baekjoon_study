// 1978: 소수 찾기
#include <iostream>
using namespace std;
int N;

int main() {
    cin >> N;

    int num;
    int res = 0;
    for(int i = 0; i < N; i++) {
        cin >> num;

        int count = 0;
        for(int j = 1; j <= num; j++) {
            if(num % j == 0) count++;
        }
        
        if(count == 2) res++;
    }

    cout << res << endl;

    return 0;
}