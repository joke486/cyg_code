//机械2101班 陈宇光 2021.10.15
//拆分整数并计算
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    int x,y;
    double tx,ty,quo;
    cin>>n;
    x=10*(n[0]-'0')+(n[1]-'0');
    y=10*(n[2]-'0')+(n[3]-'0');
    cout<<x<<"   "<<y<<endl;
    tx=sqrt(x);ty=sqrt(y);
    quo=tx/ty;
    printf("%.2lf\n",quo);
    cout<<x%y<<endl;
    //system("pause");
    return 0;
}