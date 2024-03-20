// 8958: OX퀴즈
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int N;  // 테스트 케이스의 개수

int main() {
    string s;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s;

        int add = 0;
        int sum = 0;
        for(int j = 0; j < s.length(); j++) {
            if(s[j] == 'O') {
                add++;
                sum += add;
            }
            else if (s[j] == 'X') {
                add = 0;
            }
        }

        cout << sum << endl;
    }

    return 0;
}