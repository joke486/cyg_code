//机械2101 陈宇光 
//任务二  21.9.26

#include<bits/stdc++.h>
using namespace std;
void cp(double a[]){
	double temp;									//记录当前操作的项 
	int i,j;									
	for (i=2;i<=10;i++){						//开始是默认第一个数自成一个有序段 
		temp=a[i];				
		for(j=i-1;j>=1;j--) if(a[j]<a[i])break;	//逆向找出比当前操作值小的第一个数 
		if(j<=i-1){								//如果j确实发生移动，即当前操作数不比前面有序段中的数都大
			for(int k=i;k>=j+1;k--) a[k]=a[k-1];//则将大的数逆向后移 
		}
		a[j+1]=temp;							//插入 
		for(int x=1;x<=10;x++) cout<<a[x]<<" ";	//输出每次的结果 
		cout<<endl;
	}
}
int main(){
	srand((int)time(NULL));						//时间 函数重置种子 
	double sj[15];								//数组多放了一些
	for (int i=1;i<=10;i++){
		sj[i]=rand()/double(RAND_MAX);			//数组赋值 
	}
	for (int i=1;i<=10;i++) cout<<sj[i]<<" ";	//输出原序列
	cout<<endl;
	cp(sj);										//插排
	for (int i=1;i<=10;i++) cout<<sj[i]<<" ";	//输出结果 
	cout<<endl;
	system("pause");
	return 0;
}
