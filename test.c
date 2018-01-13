#include <stdio.h>
//修改代码，王愿杰

#define N 10

//交换函数
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

//1.冒泡
void order1(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

//2.选择
void order2(int arr[],int n)
{
	int i,j,m;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[m]<arr[j])
			{
				m=j;
			}
		}
		if(m!=i)
		{
			swap(&arr[m],&arr[i]);
		}
	}
}
//3.插入
void order3(int arr[],int n)
{
	int i,j,m;
	for(i=1;i<n;i++)
	{
		m=arr[i];
		for(j=i-1;j>=0&&m<arr[j];j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=m;
	}
}
//两侧排序
int order4(int arr[],int n)
{
	int i,j,m;
	for(i=0;i<n/2;i++)
	{
		//先取出最大，放到前面
		m=i;
		for(j=i+1;j<n-i;j++)
		{
			if(arr[m]<arr[j])
			{
				m=j;
			}
		}
		if(m!=i)
		{
			swap(&arr[m],&arr[i]);
		}
		//再去出除最前一个，最大，放最后。
		m=N-i-1;
		for(j=i+1;j<n-i-1;j++)
		{
			if(arr[m]<arr[j])
			{
				m=j;
			}
		}
		if(m!=n-i-1)
		{
			swap(&arr[m],&arr[n-i-1]);
		}
	}
}

//输出
void printArr(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[N]={4,8,2,6,0,7,9,1,3,5};
	//排序
	order4(arr,N);
	printArr(arr,N);
	return 0;
}
