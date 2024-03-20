// 10872: 팩토리얼
#include <iostream>
using namespace std;
int N;

int factorial(int n) {
    if(n == 1 || n == 0) return 1;
    else return n * factorial(n - 1);
}

int main() {
    cin >> N;

    cout << factorial(N) << endl;

    return 0;
}