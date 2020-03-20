#include<iostream>
#include<math.h>
using namespace std;
#define prime_num1 47	//���ܵĴ�����p
#define prime_num2 53	//���ܵĴ�����q

int is_prime_num(int i, int j)//�ж��������Ƿ�Ϊ����
{
	int big, small, remainder=0;
	if (i > j)
	{
		big = i;
		small = j;
	}
	else
	{
		big = j;
		small = i;
	}
	do
	{
		remainder = big % small;
		big = small;
		small = remainder;
	} while (remainder);
	if (big == 0)
	{
		return 0;
	}
	else if (big == 1)
	{
		return 1;
	}
}
int get_pub_key()//���㹫Կ
{
	int count = 0;
	int pub_key = 0;
	int n = prime_num1 * prime_num2;
	int euler = (prime_num1 - 1) * (prime_num2 - 1);	//ŷ������ֵ
	for (pub_key = 2; pub_key < euler; pub_key++)
	{
		if (is_prime_num(pub_key, euler))
		{
			return pub_key;//Ĭ�Ϸ��ص�һ��������Ĺ�Կ
			break;
		}
		else
		{

		}
	}
}
int get_pri_key()//����˽Կ
{
	int pri_key = 0;
	int pub_key = get_pub_key();
	int euler = (prime_num1 - 1) * (prime_num2 - 1);
	for (pri_key = 1; pri_key < euler; pri_key++)
	{
		if ((pri_key * pub_key) % euler == 1)
		{
			return pri_key;//Ĭ�Ϸ��ص�һ���������˽Կ
			break;
		}
	}
}
int fun_operation(int a, int b, int c)//���ڼ�������ܵ��㷨,���Ϊ(a^b)%c
{
	int sum = 1;
	int T = a % c;
	while (b != 0)
	{
		if (b & 1)
		{
			sum = (sum * T) % c;
		}
		b >>= 1;
		T = (T * T) % c;
	}
	return sum;
}
int main()
{
	int* p,*q;
	int n = prime_num1 * prime_num2;
	int clear_num, cipher_num;
	int euler = (prime_num1 - 1) * (prime_num2 - 1);
	int pub_key_arr[2] = { 0 }, pri_key_arr[2] = { 0 };
	p = pub_key_arr;
	q = pri_key_arr;
	*p = get_pub_key();
	*(p + 1) = n;
	*q = get_pri_key();
	*(q + 1) = n;

	for (int i = 0; i < 2; i++)
	{
		cout << "��Կ��Ϊ:";
		cout << *(p + i);
		cout << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		cout << "˽Կ��Ϊ:";
		cout << *(q + i);
		cout << endl;
	}
	
	cout << "����������:" << endl;
	cin >> clear_num;
	cout << endl;
	if ((clear_num <= -(n)) || (clear_num >= n))
	{
		cout << "����Խ��" << endl;
	}
	else
	{
		cipher_num = fun_operation(clear_num, *p, n);
		cout << "���ܺ������:";
		cout << cipher_num << endl;
		cout << "���ܺ������:";
		cout << fun_operation(cipher_num, *q, n) << endl;
	}
	return 0;
}
