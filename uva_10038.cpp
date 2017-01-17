#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
int n,k;
char c;
bool flag=0;
using namespace std;
int main() {
    vector<int> v;
    vector<int> v1;
    while (cin >> n) {
        for (int j = 0; j < n; ++j) {
            cin >> k;
            v.push_back(k);
        }

        for (int i = 0; i < n-1; ++i) {
            v1.push_back(abs(v[i] - v[i + 1]));
        }
        sort(v1.begin(), v1.end());
        for (int i = 0; i < v1.size() - 1; ++i) {
            if (v1[i] == v1[i + 1]) {
                flag = 1;
                break;
            } else
                continue;
        }
        if (flag == 1) {
            cout << "Not jolly" << endl;
        } else
            cout << "Jolly" << endl;

        flag=0;
        v.clear();
        v1.clear();
    }
}
