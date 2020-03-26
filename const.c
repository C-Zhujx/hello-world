const int *p = NULL; //指向const变量的指针  等同于 int const *p = NULL; 两种写法不同，意义相同。
//指向const变量的指针最常用于函数的形参，目的是在保护形参指针所指向的变量在函数执行过程中不被修改。


const指针
int a = 100;
int * const p = &a; //p指针变量是const类型，不能被修改。奥利给。 p被称为指针常量。

指向const变量的const指针
const int * const p = &a;
