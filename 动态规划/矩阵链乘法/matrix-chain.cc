//矩阵链乘法
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int matrix_chain_mul(int* arr, int len, int s[6][6]) {
    int v[6][6];//六个矩阵
    for (int i = 0; i < len; i++) {
        v[i][i] = 0;
    }
    int j;
    int tmp;
    for (int l = 2; l <= len; l++) {//长度
        for (int i = 0; i < len - l + 1; i++) {
            j = i + l - 1;
            v[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                tmp = v[i][k] + v[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                if (v[i][j] > tmp) {
                    v[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
    return v[1][4];
}

void printMatrix(int i, int j, int s[6][6]) {
    if (i == j) {
        cout << "A" << i;
    }
    else {
        cout << "(";
        printMatrix(i, s[i][j], s);
        printMatrix(s[i][j] + 1, j, s);
        cout << ")";
    }
}

int main() {
    int  arr[7] = { 30,35,15,5,10,20,25 };
    int s[6][6];
    int x = matrix_chain_mul(arr, 6, s);
    cout << x << endl;
    printMatrix(0, 5, s);
}

