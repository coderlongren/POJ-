/*
为增大反腐力度，某地警方专门支队，对若干银行账户展开调查。 如果两个账户间发生过转账，则认为有关联。如果a,b间有关联, 
b,c间有关联，则认为a,c间也有关联。 对于调查范围内的n个账户（编号0到n-1），警方已知道m条因转账引起的直接关联。 
现在希望知道任意给定的两个账户，求出它们间是否有关联。有关联的输出1，没有关联输出0 小明给出了如下的解决方案：
*/
#include <stdio.h>
#define N 100
int connection(int* m, int p, int q)
{
	if (m[p] == m[q])
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 

void link(int* m, int p,int q)
{
	int i;
	if (connection(m,p,q))
	{
		return;
	}
	int p_id = m[p];
	int q_id = m[q];
	for (i = 0; i < N; i++)
	{
		if (connection(m,p_id,i))//把两个数建立连接 example link(m,2,6) 就是让6 向 2看齐
		{
			m[i] = q_id;
		}
	}



}

int main()
{
	int m[N];
	for (int i = 0; i < N; i++)
	{
		m[i] = i;
	}
	link(m,1,2);
	link(m,2,5);
	link(m,5,9);
	int j = connection(m,1,5); //输出 两个数字是否有关系
	printf("%d",j);

    return 0;
}
