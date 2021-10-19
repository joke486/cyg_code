#ifndef FUSHU00_H_                       //如果没有定义头文件
#define FUSHU00_H_                       //定义头文件

#include <bits/stdc++.h>                //万金油头文件

class fushul                            //类的定义
{
private:
    float fs[5];                        //私人部分就只有复数的实部和虚部
public:
    void acquire(float n,float m);      //赋值
    void pl(fushul n,fushul m);         //加法
    void multi(fushul n,fushul m);      //乘法
    void ge();                          //共轭
};

#endif                                  //这个不能忘
                                        //类的函数实现必须和定义在一个文件里，否则报错！！！！
void fushul::acquire(float n,float m)
{
    fs[1] = n;
    fs[2] = m;
}
void fushul::pl(fushul n,fushul m)      //有一说一，括号里还是类是不是套娃了？
{
    float tx,ty;
    tx = n.fs[1] + m.fs[1];
    ty = n.fs[2] + m.fs[2];
    printf("plus: %f,%f i\n",tx,ty);    //输出结果
}
void fushul::multi(fushul n,fushul m)
{
    float tx,ty;
    tx = (n.fs[1] * m.fs[1]) - (n.fs[2] * m.fs[2]);
    ty = (n.fs[1] * m.fs[2]) + (n.fs[2] * m.fs[1]);
    printf("multi: %f,%f i\n",tx,ty);
}

void fushul::ge()                       //由于共轭只针对一个复数，括号就留空了
{
    float tx,ty;
    tx = fs[1];
    ty = 0-fs[2];
    printf("gong'e: %f,%f i\n",tx,ty);
}