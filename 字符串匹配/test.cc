#include"kmp.h"

int main(){
    string t = "BBCABCDABABCDABCDABDE";
    string p = "ABCDABD";
    int x=kmp_match(p,t);
    cout<<x;
    return 0;
}