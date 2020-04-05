#include <stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

int MAX(int n,int *a)
{
	int  m, max1=0,sub=0;
	for (m = 0; m < n; m++)
	{
		sub += a[m];
		if(sub<a[m])
		{
			sub = a[m];
		}
		if (max1 < sub)
		{
			max1 = sub;
		}
	}
	return max1;
}

int main()
{
	int i=0,max=0,n=0,flag=0;
	int* a = new int[n+1];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > 0)
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		max = 0;
	}
	else
	{
		max = MAX(n,a);
	}
	cout << max << endl;
	system("pause");
	return 0;
}
