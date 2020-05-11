#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> compute_prefix(string p){
    vector<int> v(p.size());
    v[0]=0;
    int k=0;
    //注意此处v代表的是前缀长度并且从下标0开始，因此k=v[k-1]，如果是从下标1开始是v[k]
    //其实只是k=两个p[m]!=p[n]之后的v[m-1],这是由于p[m]和p[n]不等
    for(int i=1;i<p.size();++i){
        while(k>0&&p[k]!=p[i]){
            k=v[k-1];
        }
        //k=0的情况直接比较
        if(p[k]==p[i])k=k+1;
        v[i]=k;
    }
    return v;
}

//如果有匹配字符串返回开始下标，否则返回-1
int kmp_match(string p, string t) {
    int len = t.length();
    int p_len = p.length();
    int s;
    vector<int> v = compute_prefix(p);
    int q = 0;
    //逻辑上，如果有不相等的，就将q回退，从回退位置继续比较，
    for (int i = 0; i < len ; ++i) {
        while (q > 0 && p[q] != t[i]) {
            q = v[q - 1];
        }
        if (p[q] == t[i])++q;
        if (q == p_len)
            return i-q+1;
    }
    return -1;
}
