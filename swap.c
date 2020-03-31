
//交换数据的函数
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}



void swap2(int a, int b)
{
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}
