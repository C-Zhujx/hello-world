#include <iostream>


using namespace std;



class Egg
{
private:
	static Egg e;
	int i;
	Egg(int ii) :i(ii) {}
	Egg(const Egg &);	
public:
	static Egg* instance()
	{
		return &e;
	}
	int val() const
	{
		return i;
	}
};

Egg Egg::e(47); //这个类只有这一个对象，这就是单例模式

int main()
{


	Egg *e = Egg::instance();
	Egg *e2 = Egg::instance();//这两行都是对同一个对象做的操作，即class中的static Egg e

	cout << e->val() << endl;
	cout << e2->val() << endl;
	cout << Egg::instance()->val() << endl;

//	Egg e3 = *Egg::instance(); //这两行还是可以创建对象。这里是调用拷贝构造函数。
//	Egg e4(*Egg::instance());//将拷贝构造函数做成私有的，这两行就不能进行赋值了

	system("pause");
	return 0;
}
