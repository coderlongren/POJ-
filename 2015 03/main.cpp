/*
Ϊ���󷴸����ȣ�ĳ�ؾ���ר��֧�ӣ������������˻�չ�����顣 ��������˻��䷢����ת�ˣ�����Ϊ�й��������a,b���й���, 
b,c���й���������Ϊa,c��Ҳ�й����� ���ڵ��鷶Χ�ڵ�n���˻������0��n-1����������֪��m����ת�������ֱ�ӹ����� 
����ϣ��֪����������������˻���������Ǽ��Ƿ��й������й��������1��û�й������0 С�����������µĽ��������
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
		if (connection(m,p_id,i))//���������������� example link(m,2,6) ������6 �� 2����
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
	int j = connection(m,1,5); //��� ���������Ƿ��й�ϵ
	printf("%d",j);

    return 0;
}
