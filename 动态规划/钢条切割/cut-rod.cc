//钢条切割
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int len = 11;

int cut_rod(map<int, int> m, int n) {
    int p[len];
    for (auto& t : p) {
        t = 0;
    }
    for (int i = 1; i < len; i++) {
        int tmp = INT_MIN;
        for (int j = 1; j <= i; j++) {
            tmp = max(tmp, m[j] + p[i - j]);
        }
        p[i] = tmp;
    }
    return p[n];
}

int main() {
    map<int, int> cut_map;
    cut_map[0] = 0;
    cut_map[1] = 1;
    cut_map[2] = 5;
    cut_map[3] = 8;
    cut_map[4] = 9;
    cut_map[5] = 10;
    cut_map[6] = 17;
    cut_map[7] = 17;
    cut_map[8] = 20;
    cut_map[9] = 24;
    cut_map[10] = 30;

    int n = cut_rod(cut_map, 4);
    cout << n << endl;
    return 0;
}