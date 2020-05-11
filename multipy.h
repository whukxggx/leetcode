#include"head.h"

//43. 字符串相乘
class Solution {
public:
    int mult(char a, char b) {
        return (static_cast<int>(a) - static_cast<int>('0')) *
            (static_cast<int>(b) - static_cast<int>('0'));
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int size1 = num1.size();
        int size2 = num2.size();
        vector<int> vec(size1 + size2 , 0);
        for (int i = size1 - 1; i >= 0; --i) {//必须从后往前乘
            for (int j = size2 - 1; j >= 0; --j) {
                int bitMult = mult(num1[i], num2[j]);
                bitMult += vec[i + j + 1];//查看低位是否有进位
                vec[i + j + 1] = bitMult % 10;
                vec[i + j] += bitMult / 10;
            }
        }
        string mul;
        int i = 0;
        while (i < vec.size() - 1 && vec[i] == 0)
            i++;
        for (; i < vec.size(); ++i) {
            mul.append(to_string(vec[i]));
        }
        return mul;
}
};