#ifndef MATRIX_H_
#define MATRIX_H_

#include <bits/stdc++.h>
using namespace std;

class Matr
{  
public:
    int x,y;
    float **jz;
    void init(int n,int m);                                 //初始化
    void del(int m);                                        //释放
    float read(int n,int m);                                //读取
    void write(int n,int m,float temp);                       //写入
};

class Matr_Calc
{
public:
    bool pd_ni(Matr *a);                                    //判断是否可逆
    void add(Matr *a,Matr *b,Matr *c);                      //加法
    void mul(Matr *a,Matr *b,Matr *c);                      //乘法
    float det(Matr *a,int i,int j);                                     //求行列式
    void transpos(Matr *a);                                 //转置                                 
    void print(Matr *a);
    void inverse(Matr *a,Matr *b);//求逆
};

#endif

void Matr:: init(int n,int m)
{
    jz = new float *[n];
    for(int i=0;i<m;i++) 
    {
        jz[i] = new float[m];
    }
}

void Matr::del(int m)
{
    for(int i=0;i<m;i++) delete []jz[i];                    //释放内存
    
    delete []*jz;                                           //'*'不能忘
}

float Matr::read(int n,int m)                               //读取对应的值
{
    if(n<=x && m<=y)                                //判断读取是否合法
    {
        return *(*(jz+n)+m);  
    }           
    printf("错误：坐标不在矩阵中\n");
    return -31415;
}

void Matr::write(int n,int m,float temp)                //temp的类型一定要是float，我查了半天
{
    if(n<=x && m<=y)                                    //判断写入是否合法
    {
        *(*(jz+n)+m) = temp;
        return;
    }
    printf("错误：写入坐标不在矩阵中\n");
    return;
}
//矩阵的数值读取与写入
bool Matr_Calc::pd_ni(Matr *a)                              //判断是否可逆
{
    if(a->x!=a->y) return false;
    if(det(a,1,1) == 0) return false;
    else return true;
}

void Matr_Calc::add(Matr *a,Matr *b,Matr *c)
{
    if(a->x != b->x || a->y != b->y)                //判断是否能相加
    {
        printf("两个矩阵不可相加\n");
        return;
    } 
    for (int i=0;i < c->x;i++)
    {
        for (int j=0;j < c->y;j++)
        {
            c -> write(i,j,a->read(i,j) + b->read(i,j));    //读取a，b的值，相加并写入c
        }
    }
    print(c);printf("加法\n");
}

void Matr_Calc::mul(Matr *a,Matr *b,Matr *c)
{
    if(a->y != b->x)
    {
        printf("两矩阵不能相乘\n");
        return;
    }
    float temp=0;                                      //设两个中间值，一个存矩阵相等的行列
    for(int i=0;i<c->x;i++)
    {
        for(int j=0;j<c->y;j++)
        {
            temp = 0;                                   //重置temp  
            for(int k=0;k<a->y;k++)
            {
                temp +=a->read(i,k) * b->read(k,j);         //另一个累加
            }
            c->write(i,j,temp);                             //最后更新c矩阵的值 
        }
    }
    print(c);printf("乘法\n");
}

float Matr_Calc::det(Matr *a,int i,int j)                               //求行列式
{   
    float value;                                                        //摆烂了，n阶实在是写不出来，直接暴力
    if (a->x == 2)
	{
		value = a->read(0,0) * a->read(1,1) - a->read(0,1) * a->read(1,0);
	}
	else
	{
		value = a->read(0,0) * a->read(1,1) * a->read(2,2) + \
				a->read(0,1) * a->read(1,2) * a->read(2,0) + \
				a->read(0,2) * a->read(1,0) * a->read(2,1) - \
				a->read(0,0) * a->read(1,2) * a->read(2,1) - \
				a->read(0,1) * a->read(1,0) * a->read(2,2) - \
				a->read(0,2) * a->read(1,1) * a->read(2,0);
	}
    if((i+j)%2==0)return value;                                         //用于代数余子式的符号
    else return value*(-1);
	
} 

void Matr_Calc:: print(Matr *a)                               //打印矩阵
{
    for(int i=0;i<a->x;i++)
    {
        for(int j=0;j<a->y;j++)
        {
            cout << a->read(i,j)<<" ";
        }
        cout<<endl;
    }
    return;
}

void Matr_Calc::transpos(Matr *a)                               //矩阵转置 
{   
    Matr *temp;
    temp = new Matr();
    temp->x=a->y;
    temp->y=a->x;
    temp->init(temp->x,temp->y);
    for(int i=0;i < a->x;i++)
        for(int j=0;j < a->y;j++)
            temp->write(i,j,a->read(j,i));
    print(temp); 
    printf("转置\n");                                            //打印结果
    temp->del(temp->y);
}           
void Matr_Calc::inverse(Matr *a,Matr *b)
{
    float bs=det(a,1,1);                                                //求a的行列式
    for(int j=0;j<a->y;j++)
    {
        for(int i=0;i<a->x;i++)                                         //代数余子式的计算
        {
            Matr *temp;                                                 //设中间矩阵
            temp = new Matr();
            temp->x=a->x-1;
            temp->y=a->y-1;
            temp->init(temp->x,temp->y);                                //初始化
            int xx=0,yy=0;
            for(int k=0;k<a->x;k++)
            {
                if(k!=i)                                                
                {
                    for(int g=0;g<a->y;g++)
                    {
                        if(g!=j)
                        {
                            temp->write(xx,yy,a->read(k,g));
                            yy++;
                        }
                    }
                    xx++;yy=0;
                }
            }
            float t1=0;                                                 //中间值过渡
            t1=det(temp,i,j)/bs;
            b->write(j,i,t1);
            temp->del(temp->y);                                         //释放内存
        }
    }
    print(b);                                                           //打印结果
    printf("求逆\n");
}