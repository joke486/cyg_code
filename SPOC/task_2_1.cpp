//��е2101�� ����� 2021.10.15
//���Ǻ�����ǵ�����ֵ
#include<bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
{
    float a,temp,y;
    cin>>a;
    temp=a*pi/360;                                        //��aת���ɰ�ǻ���
    y=fabs(sin(temp));                                    //��sin��ȡ����ֵ
    cout<<"y="<<y<<endl;
    //system("pause");
    return 0;
}