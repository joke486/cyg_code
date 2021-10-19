#ifndef FUSHU00_H_                       //���û�ж���ͷ�ļ�
#define FUSHU00_H_                       //����ͷ�ļ�

#include <bits/stdc++.h>                //�����ͷ�ļ�

class fushul                            //��Ķ���
{
private:
    float fs[5];                        //˽�˲��־�ֻ�и�����ʵ�����鲿
public:
    void acquire(float n,float m);      //��ֵ
    void pl(fushul n,fushul m);         //�ӷ�
    void multi(fushul n,fushul m);      //�˷�
    void ge();                          //����
};

#endif                                  //���������
                                        //��ĺ���ʵ�ֱ���Ͷ�����һ���ļ�����򱨴�������
void fushul::acquire(float n,float m)
{
    fs[1] = n;
    fs[2] = m;
}
void fushul::pl(fushul n,fushul m)      //��һ˵һ�������ﻹ�����ǲ��������ˣ�
{
    float tx,ty;
    tx = n.fs[1] + m.fs[1];
    ty = n.fs[2] + m.fs[2];
    printf("plus: %f,%f i\n",tx,ty);    //������
}
void fushul::multi(fushul n,fushul m)
{
    float tx,ty;
    tx = (n.fs[1] * m.fs[1]) - (n.fs[2] * m.fs[2]);
    ty = (n.fs[1] * m.fs[2]) + (n.fs[2] * m.fs[1]);
    printf("multi: %f,%f i\n",tx,ty);
}

void fushul::ge()                       //���ڹ���ֻ���һ�����������ž�������
{
    float tx,ty;
    tx = fs[1];
    ty = 0-fs[2];
    printf("gong'e: %f,%f i\n",tx,ty);
}