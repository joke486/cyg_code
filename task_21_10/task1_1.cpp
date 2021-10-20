//机械2101 陈宇光
//任务一（1） 21.9.28

#include <bits/stdc++.h>
using namespace std;

struct fushu                        //定义结构体
{
    float mo;                       //复数的模
    float fs[5];                    //数组储存实部和虚部，以防万一多开了一些
};

void sm(fushu n)                    //计算复数的模
{
    float temp;                     //设中间值
    temp= pow(n.fs[1],2) + pow(n.fs[2],2);  //实部虚部分别平方
    n.mo=sqrt(temp);                //开根
}

void pl(fushu n,fushu m)            //复数的加法
{
    float tx,ty;                    //中间值
    tx = n.fs[1] + m.fs[1];
    ty = n.fs[2] + m.fs[2];
    printf("plus: %f,%f i\n",tx,ty);    //直接输出结果
}
void multi(fushu n,fushu m)         //乘法同上
{
    float tx,ty;
    tx = (n.fs[1] * m.fs[1]) - (n.fs[2] * m.fs[2]);
    ty = (n.fs[1] * m.fs[2]) + (n.fs[2] * m.fs[1]);
    printf("multi: %f,%f i\n",tx,ty);
}

void ge(fushu n)                    //共轭更简单，改虚部的符号
{
    float tx,ty;
    tx = n.fs[1];                   //可以计算输出一起，但没用
    ty = 0-n.fs[2];
    printf("gong'e: %f,%f i\n",tx,ty);
}
int main()
{
    struct fushu x,y;
    scanf("%f%f",&x.fs[1],&x.fs[2]);    //直接输入实部和虚部，没有要求加上‘i’
    scanf("%f%f",&y.fs[1],&y.fs[2]);
    sm(x);sm(y);
    pl(x,y);
    multi(x,y);
    ge(x);ge(y);
    system("pause");                    //暂停看结果
    return 0;
}