//��е2101 �����
//������   2021.10.3
#include <bits/stdc++.h>
#include "task3.h"

using namespace std;

int main()
{
    int temp=0,x1,x2,y1,y2;                                     //���м�ֵ�����������������
    Matr *a,*b,*c;                                              //����������
    a = new Matr();
    b = new Matr();
    c = new Matr();
    Matr_Calc m_c;
    cout<<"�������1��������"<<endl;                             //������ʾ
    cin>>x1>>y1; 
    cout<<"�������2��������"<<endl;                                              
    cin>>x2>>y2;                                                //���뷶Χ
    a->init(x1,y1);                                             //��ʼ��
    b->init(x2,y2);
    c->init(x1,y1);  
    a->x=x1;   a->y=y1;
    b->x=x2;   b->y=y2;
    c->x=x1;   c->y=y1;                                                            
    cout<<"�������1"<<endl;
    for(int i=0;i<x1;i++)
    {
        for(int j=0;j<y1;j++)
        {
            cin>>temp;                                          //�����м�ֵ
            a->write(i,j,temp);                                 //���м�ֵд�������
        }
    }
    cout<<"�������2"<<endl;
    for(int i=0;i<x2;i++)
    {
        for(int j=0;j<y2;j++)
        {
            cin>>temp;                                          
            b->write(i,j,temp);                                 
        }
    }
    system("pause");
    m_c.add(a,b,c);                                             //�ӷ�
    m_c.mul(a,b,c);                                             //�˷�
    m_c.inverse(a,c);                                           //����
    m_c.transpos(a);                                            //ת��       
    system("pause");    
    return 0;
}