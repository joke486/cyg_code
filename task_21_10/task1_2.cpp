//机械2101 陈宇光 
//任务一（2） 21.9.28

#include <bits/stdc++.h>
#include "task1_2.h"

using namespace std;

int main()
{
    fushul f1,f2;                       //声明两个复数类
    float x1,x2,y1,y2;                  //取中间值
    cin >> x1 >> y1;                    //输入实虚部
    cin >> x2 >> y2;
    f1.acquire(x1,y1);                  //赋值
    f2.acquire(x2,y2);
    f1.pl(f1,f2);                       //加法
    f1.multi(f1,f2);                    //乘法
    f1.ge();                            //共轭
    f2.ge();
    system("pause");
    return 0;
}
//这里复数的类中实虚部的访问权限都是私人，应该只能另写公用函数赋值(感觉有点烦)
//但实虚部都设成公用，和结构没多少区别了