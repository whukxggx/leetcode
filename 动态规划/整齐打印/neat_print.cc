//整齐打印
//暂时有点问题
#include<iostream>
using namespace std;
const int len=40;
const int M=10;
//以下从下标1开始


int calMinBlankN(int minBlank[len+1][len+1]){
    int c[len+1];//保存最少空格数立方和
    c[0]=0;
    for(int j=1;j<=len;++j){
        c[j]=minBlank[1][j];
        for(int k=1;k<=j;k++){//找寻第1个到j之间最小的空格立方和
            int tmp=c[k-1]+minBlank[k][j];
            if(tmp<c[j]){
                c[j]=tmp;
            }
        }
    }
    return c[len];
}
//计算单行空格数
int cal_blank(int i,int j,int M,int *l){
    int tmp=0;
    for(int t=i;t<=j;++t){
        tmp+=l[t];
    }
    return (M-j+i-tmp);
}

void cal_minBlank(int *l,int minBlank[len+1][len+1]){
    for(int i=1;i<len;i++){
        for(int j=i;j<len;j++){
            int tmp=cal_blank(i,j,M,l);
            if(tmp<0){
                minBlank[i][j]=INT_MAX;
            }else if(tmp>=0&&j==len){
                minBlank[i][j]=0;
            }else{
                minBlank[i][j]=tmp*tmp*tmp;
            }
        }
    }
}
int main(){
    int l[len+1];
    int minBlank[len+1][len+1];
    for(int i=0;i<=len;++i){
        l[i]=rand()%5;
    }
    cal_minBlank(l,minBlank);
    int x=calMinBlankN(minBlank);
    cout<<x<<endl;
    return 0;
}

