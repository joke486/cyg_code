//机械2101班 陈宇光 2021.10.15
//三角函数半角的正弦值
#include<bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
{
    float a,temp,y;
    cin>>a;
    temp=a*pi/360;                                        //将a转化成半角弧度
    y=fabs(sin(temp));                                    //求sin，取绝对值
    cout<<"y="<<y<<endl;
    //system("pause");
    return 0;
}