// 4344: 평균은 넘곘지
#include <iostream>
#include <cmath>
using namespace std;
int C;
int student[1001];

int main() {
    int count;
    cin >> C;
    for(int i = 0; i < C; i++) {
        int sum = 0;
        int avg = 0;

        cin >> count;
        for(int j = 0; j < count; j++) {
            cin >> student[j];
            sum += student[j];
        }

        avg = sum / count;

        int num = 0;
        for(int k = 0; k < count; k++) {
            if(student[k] > avg) {
                num++;
            }
        }

        double result = (double)num / count * 100;

        cout << fixed;
        cout.precision(3);
        cout << result << "%" << endl;
    }

    return 0;
}