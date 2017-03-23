#include <iostream>
using namespace std;
class Base
{
  public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
};

int main()
{
    typedef void (*Fun)(void);

    Base b;

    Fun pFun = NULL;
    Fun pFun1 = NULL;

    cout << "虚函数表地址：" << &b << endl;
    cout << "虚函数表 — 第一个函数地址：" << (long *)*(long *)(&b) << endl;

    ((Fun)(*((long *)(*(long *)(&b)) + 0)))(); //call f()
    ((Fun)(*((long *)(*(long *)(&b)) + 1)))(); //call g()
    ((Fun)(*((long *)(*(long *)(&b)) + 2)))(); //call h()
}
