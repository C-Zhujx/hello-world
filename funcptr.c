#include <stdio.h>
#define EVENT_ENABLE( curVal, lastVal, mask )  ( ( lastVal^curVal ) & mask )
#define GET_MAX 1
#define GET_MIN 2

typedef unsigned long UINT32;
typedef unsigned int UINT16;

typedef void (*funcptr)(void);
typedef int (*func)(int, int);

int get_max(int i, int j); 
int get_min(int i, int j);
int get(int i, int j, int flag);

int get_max2(int i, int j, int x, func p);
func get_max3(int a);
void hello(void);
void bye(void);
void ok(void);
void speak(int id);
int count_bits(int x);
void pri();


int main()
{
	
	int a = 10, b = 5, c = 100;
	
	int result = get(a, b, GET_MIN);
	printf("%d\n",result);
	
	int result2 = get(a, b, GET_MAX);
	printf("%d\n",result2);
	
	int result3 = get_max2(a, b, c, get_max);
	printf("%d\n", result3);
	
	func m = get_max3(100);
	int result4 = (*m)(a, b);
	printf("%d\n", result4);
	
#if 0	
	pri();

	UINT32 vcg_mask = 1;
	UINT16 vcg = 3;
	printf("%x\n",(~(vcg_mask << (vcg-1))));
	
	speak(0);
	speak(1);
	speak(2);
	char a = 4;
	
	printf("!4=%d ~4=%d\n",!a,~a);
#endif
	return 0;
}


int get_max(int i, int j)
{
	return (i>j ? i : j);
}
int get_min(int i, int j)
{
	return (i<j ? i : j);
}
func get_max3(int a)
{
	printf("the number is %d\n",a);
	return get_max;
}

int get(int i, int j, int flag)
{
	func p = NULL;
	if(flag == GET_MAX)
	{
		p = get_max;
	}
	else if(flag == GET_MIN)
	{
		p = get_min;
	}
	
	return (*p)(i,j);
}

int get_max2(int i, int j, int x, func p)
{
	int res = (*p)(i, j);
	int max = (*p)(res, x);
	
	return max;
}

void hello(void) {
	printf("你好!\n");
}

void bye(void){
	printf("再见!\n");
}

void ok(void)
{
	printf("好的!\n");
}

void speak(int id)
{
	funcptr word[3] = {&hello, &bye, &ok};
	funcptr fun = word[id];
	(*fun)();
}

int count_bits(int x)
{
  register int xx=x;
  xx=xx-((xx>>1) & 0x55555555);
  xx=(xx&0x33333333)+((xx>>2)&0x33333333);
  xx=(xx+(xx>>4))&0x0f0f0f0f;
  xx=xx+(xx>>8);
  return (xx+(xx>>16)) & 0xff;
}


void pri()
{
	UINT32 a = 0x00400000;
	UINT32 b = 0x00000000;
	UINT32 c = 0x0FBFFDFF;
	UINT32 d = 0x0BE00DFF;
	 
	printf("%x\n", EVENT_ENABLE(a,b,d));
	
}
