//��е2101 �����
//����һ��1�� 21.9.28

#include <bits/stdc++.h>
using namespace std;

struct fushu                        //����ṹ��
{
    float mo;                       //������ģ
    float fs[5];                    //���鴢��ʵ�����鲿���Է���һ�࿪��һЩ
};

void sm(fushu n)                    //���㸴����ģ
{
    float temp;                     //���м�ֵ
    temp= pow(n.fs[1],2) + pow(n.fs[2],2);  //ʵ���鲿�ֱ�ƽ��
    n.mo=sqrt(temp);                //����
}

void pl(fushu n,fushu m)            //�����ļӷ�
{
    float tx,ty;                    //�м�ֵ
    tx = n.fs[1] + m.fs[1];
    ty = n.fs[2] + m.fs[2];
    printf("plus: %f,%f i\n",tx,ty);    //ֱ��������
}
void multi(fushu n,fushu m)         //�˷�ͬ��
{
    float tx,ty;
    tx = (n.fs[1] * m.fs[1]) - (n.fs[2] * m.fs[2]);
    ty = (n.fs[1] * m.fs[2]) + (n.fs[2] * m.fs[1]);
    printf("multi: %f,%f i\n",tx,ty);
}

void ge(fushu n)                    //������򵥣����鲿�ķ���
{
    float tx,ty;
    tx = n.fs[1];                   //���Լ������һ�𣬵�û��
    ty = 0-n.fs[2];
    printf("gong'e: %f,%f i\n",tx,ty);
}
int main()
{
    struct fushu x,y;
    scanf("%f%f",&x.fs[1],&x.fs[2]);    //ֱ������ʵ�����鲿��û��Ҫ����ϡ�i��
    scanf("%f%f",&y.fs[1],&y.fs[2]);
    sm(x);sm(y);
    pl(x,y);
    multi(x,y);
    ge(x);ge(y);
    system("pause");                    //��ͣ�����
    return 0;
}