#ifndef MATRIX_H_
#define MATRIX_H_

#include <bits/stdc++.h>
using namespace std;

class Matr
{  
public:
    int x,y;
    float **jz;
    void init(int n,int m);                                 //��ʼ��
    void del(int m);                                        //�ͷ�
    float read(int n,int m);                                //��ȡ
    void write(int n,int m,float temp);                       //д��
};

class Matr_Calc
{
public:
    bool pd_ni(Matr *a);                                    //�ж��Ƿ����
    void add(Matr *a,Matr *b,Matr *c);                      //�ӷ�
    void mul(Matr *a,Matr *b,Matr *c);                      //�˷�
    float det(Matr *a,int i,int j);                                     //������ʽ
    void transpos(Matr *a);                                 //ת��                                 
    void print(Matr *a);
    void inverse(Matr *a,Matr *b);//����
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
    for(int i=0;i<m;i++) delete []jz[i];                    //�ͷ��ڴ�
    
    delete []*jz;                                           //'*'������
}

float Matr::read(int n,int m)                               //��ȡ��Ӧ��ֵ
{
    if(n<=x && m<=y)                                //�ж϶�ȡ�Ƿ�Ϸ�
    {
        return *(*(jz+n)+m);  
    }           
    printf("�������겻�ھ�����\n");
    return -31415;
}

void Matr::write(int n,int m,float temp)                //temp������һ��Ҫ��float���Ҳ��˰���
{
    if(n<=x && m<=y)                                    //�ж�д���Ƿ�Ϸ�
    {
        *(*(jz+n)+m) = temp;
        return;
    }
    printf("����д�����겻�ھ�����\n");
    return;
}
//�������ֵ��ȡ��д��
bool Matr_Calc::pd_ni(Matr *a)                              //�ж��Ƿ����
{
    if(a->x!=a->y) return false;
    if(det(a,1,1) == 0) return false;
    else return true;
}

void Matr_Calc::add(Matr *a,Matr *b,Matr *c)
{
    if(a->x != b->x || a->y != b->y)                //�ж��Ƿ������
    {
        printf("�������󲻿����\n");
        return;
    } 
    for (int i=0;i < c->x;i++)
    {
        for (int j=0;j < c->y;j++)
        {
            c -> write(i,j,a->read(i,j) + b->read(i,j));    //��ȡa��b��ֵ����Ӳ�д��c
        }
    }
    print(c);printf("�ӷ�\n");
}

void Matr_Calc::mul(Matr *a,Matr *b,Matr *c)
{
    if(a->y != b->x)
    {
        printf("�����������\n");
        return;
    }
    float temp=0;                                      //�������м�ֵ��һ���������ȵ�����
    for(int i=0;i<c->x;i++)
    {
        for(int j=0;j<c->y;j++)
        {
            temp = 0;                                   //����temp  
            for(int k=0;k<a->y;k++)
            {
                temp +=a->read(i,k) * b->read(k,j);         //��һ���ۼ�
            }
            c->write(i,j,temp);                             //������c�����ֵ 
        }
    }
    print(c);printf("�˷�\n");
}

float Matr_Calc::det(Matr *a,int i,int j)                               //������ʽ
{   
    float value;                                                        //�����ˣ�n��ʵ����д��������ֱ�ӱ���
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
    if((i+j)%2==0)return value;                                         //���ڴ�������ʽ�ķ���
    else return value*(-1);
	
} 

void Matr_Calc:: print(Matr *a)                               //��ӡ����
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

void Matr_Calc::transpos(Matr *a)                               //����ת�� 
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
    printf("ת��\n");                                            //��ӡ���
    temp->del(temp->y);
}           
void Matr_Calc::inverse(Matr *a,Matr *b)
{
    float bs=det(a,1,1);                                                //��a������ʽ
    for(int j=0;j<a->y;j++)
    {
        for(int i=0;i<a->x;i++)                                         //��������ʽ�ļ���
        {
            Matr *temp;                                                 //���м����
            temp = new Matr();
            temp->x=a->x-1;
            temp->y=a->y-1;
            temp->init(temp->x,temp->y);                                //��ʼ��
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
            float t1=0;                                                 //�м�ֵ����
            t1=det(temp,i,j)/bs;
            b->write(j,i,t1);
            temp->del(temp->y);                                         //�ͷ��ڴ�
        }
    }
    print(b);                                                           //��ӡ���
    printf("����\n");
}