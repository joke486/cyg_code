//��е2101 ����� 
//����һ��2�� 21.9.28

#include <bits/stdc++.h>
#include "task1_2.h"

using namespace std;

int main()
{
    fushul f1,f2;                       //��������������
    float x1,x2,y1,y2;                  //ȡ�м�ֵ
    cin >> x1 >> y1;                    //����ʵ�鲿
    cin >> x2 >> y2;
    f1.acquire(x1,y1);                  //��ֵ
    f2.acquire(x2,y2);
    f1.pl(f1,f2);                       //�ӷ�
    f1.multi(f1,f2);                    //�˷�
    f1.ge();                            //����
    f2.ge();
    system("pause");
    return 0;
}
//���︴��������ʵ�鲿�ķ���Ȩ�޶���˽�ˣ�Ӧ��ֻ����д���ú�����ֵ(�о��е㷳)
//��ʵ�鲿����ɹ��ã��ͽṹû����������