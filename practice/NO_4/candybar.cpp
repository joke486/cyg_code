#include<bits/stdc++.h>
using namespace std;

struct candybar
{
    string band;
    double weight;
    int kll;
};

int main()
{
    printf("�����\n c++ primer plus ��������ϰ8\n");
    candybar *a[3];
    for(int i=0;i<=2;i++)                                                   //����Ҫһ��һ�������ڴ�
    {
        a[i] = new candybar;
    }
    for(int i=0;i<=2;i++)
    {
        cin>>a[i]->band;
        cin>>a[i]->weight;
        cin>>a[i]->kll;
    }
    for(int i=0;i<=2;i++)
    {
        cout << a[i] -> band << endl;
        cout << a[i] -> weight << endl; 
        cout << a[i] -> kll << endl;
    }
    system("pause");
    return 0;
}
