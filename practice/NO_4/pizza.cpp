#include<bits/stdc++.h>
using namespace std;

struct pizza
{
    string name;
    double l,weight;
};

int main()
{
    printf("�����\n c++ primer plus ��������ϰ7\n");
    pizza *a;
    a = new pizza;
    cin>>a->l;
    cin>>a->name;
    cin>>a->weight;
    cout << a -> l << endl << a -> name << endl << a -> weight << endl;
    system("pause");
    return 0;
}