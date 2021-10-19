//机械2101 陈宇光
//任务三   2021.10.3
#include <bits/stdc++.h>
#include "task3.h"

using namespace std;

int main()
{
    int temp=0,x1,x2,y1,y2;                                     //设中间值，两个矩阵的行与列
    Matr *a,*b,*c;                                              //设三个矩阵
    a = new Matr();
    b = new Matr();
    c = new Matr();
    Matr_Calc m_c;
    cout<<"输入矩阵1的行与列"<<endl;                             //文字提示
    cin>>x1>>y1; 
    cout<<"输入矩阵2的行与列"<<endl;                                              
    cin>>x2>>y2;                                                //输入范围
    a->init(x1,y1);                                             //初始化
    b->init(x2,y2);
    c->init(x1,y1);  
    a->x=x1;   a->y=y1;
    b->x=x2;   b->y=y2;
    c->x=x1;   c->y=y1;                                                            
    cout<<"输入矩阵1"<<endl;
    for(int i=0;i<x1;i++)
    {
        for(int j=0;j<y1;j++)
        {
            cin>>temp;                                          //输入中间值
            a->write(i,j,temp);                                 //将中间值写入矩阵中
        }
    }
    cout<<"输入矩阵2"<<endl;
    for(int i=0;i<x2;i++)
    {
        for(int j=0;j<y2;j++)
        {
            cin>>temp;                                          
            b->write(i,j,temp);                                 
        }
    }
    system("pause");
    m_c.add(a,b,c);                                             //加法
    m_c.mul(a,b,c);                                             //乘法
    m_c.inverse(a,c);                                           //求逆
    m_c.transpos(a);                                            //转置       
    system("pause");    
    return 0;
}