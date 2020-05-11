#include "head.h"

//面试题 08.12. 八皇后
class Solution
{
public:
    bool checkIfRight(int i, int row, vector<int> vec_aux)
    {
        for (int k = 0; k < row; ++k)
        {
            if (vec_aux[k] == i)
                return false;
            if (abs(i - vec_aux[k]) == row - k)
                return false;
        }
        return true;
    }
    void backTracking(int n, int row, vector<vector<int>> &vec, vector<int> &vec_aux)
    {
        if (row == n)
        {
            vec.push_back(vec_aux);
            return;
        }
        for (int i = 0; i < n; ++i)
        { //从第0个位置到第n-1个位置
            if (checkIfRight(i, row, vec_aux))
            {
                vec_aux.push_back(i);
                backTracking(n, row + 1, vec, vec_aux);
                vec_aux.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<int>> vec;
        vector<int> vec_aux;
        backTracking(n, 0, vec, vec_aux);
        vector<vector<string>> s;
        for (int i = 0; i < vec.size(); ++i)
        {
            vector<string> svec;
            for (int j = 0; j < vec[i].size(); ++j)
            {
                string stmp;
                for (int k = 0; k < n; ++k)
                {
                    if (vec[i][j] == k)
                        stmp.push_back('Q');
                    else
                        stmp.push_back('.');
                }
                svec.push_back(stmp);
            }
            s.push_back(svec);
        }
        return s;
    }
};