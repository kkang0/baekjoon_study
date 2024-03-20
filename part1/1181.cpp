// 1181: 단어 정렬
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N;

int cmp(string a, string b) {
    if(a.length() == b.length()) {
        return a < b;
    }
    else {
        return a.length() < b.length();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string s;
    vector<string> arr;
    for(int i = 0; i < N; i++) {
        cin >> s;
        arr.push_back(s);
    }

    sort(arr.begin(), arr.end(), cmp);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}