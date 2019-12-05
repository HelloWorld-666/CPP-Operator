#include "iostream"
#include <windows.h>

using namespace std;

struct node
{
    int m;
    int n;
};

class Complex
{
public:
    //方式一：
    //带有一个参数的构造函数
    Complex()
    {
        real = 0;
        vir  = 0;
    }

    //带有两个参数的构造函数
    Complex(int _real/* = 0*/, int _vir/* = 0*/)    //不能带有注释中的缺省参数，否则相当于定义了两个一样的不需传递参数的默认构造函数(定义对象都不需要传递参数)，造成重定义
    {
        real = _real;
        vir  = _vir;
    }

    //方式二：利用初始化列表
  /*  Complex(int _real = 2, int _vir = 4) : real(_real), vir(_vir)         
    {

    }*/

    ~Complex()
    {

    }
    
    Complex operator+(Complex &_c)
    {
        Complex c3;                                 //需要用到默认构造函数Complex()
        c3.real = this->real + _c.real;
        c3.vir  = this->vir  + _c.vir;
        return c3;
    }

    //负号 (不是减号)
    void operator-()
    {
        //Complex c;
        real = -real;
        vir = -vir;
        //return c;
    }

    //非运算符
    void operator!()        //这里不需要返回值，并且不是c.real，而是real或者this->real！！ 
    {
        if (real != 0)
        {
            real = 0;
        }
        else if (real == 0)
        {
            real = 1;
        }

        if (vir != 0)
        {
            vir = 0;
        }
        else if (vir == 0)
        {
            vir = 1;
        }
    }

    //二元： >
    bool operator>(Complex &_c)
    {
        if (this->real > _c.real)
        {
            return true;
        }
        else if (this->real == _c.real && this->vir > _c.vir)
        {
            return true;
        }
        return false;
    }

    //输出运算符重载
    friend ostream& operator<<(ostream &output, Complex &_c)        //友元:如果是重载双目操作符（即为类的成员函数），就只要设置一个参数作为右侧运算量，而左侧运算量就是对象本身 而 >> 或 << 左侧运算量是 cin或cout 而不是对象本身，所以不满足后面一点，就只能申明为友元函数了
    {
    output << "real = " << _c.real << '\t' << "vir = " << _c.vir << endl;
    return output;
    }

    //测试1：<<重载为什么需要是友元:
    /* ostream& operator<<(ostream& output)
     {
     output << "real = " << this->real << '\t' << "vir = " << this->vir << endl;
     return output;
     }*/

    //测试2：<<重载为什么需要是友元：
    int operator<<(Complex &_c)
    {
        return _c.vir;
    }

    //输入运算符重载
    friend istream& operator>>(istream &input, Complex &_c)         //友元
    {
        input >> _c.real >> _c.vir;
        return input;
    }

    //前置++
    Complex operator++()
    {
        return Complex(real++, vir++);  //返回一个匿名对象，并为匿名对象++
    }

    //后置++
    Complex& operator++(int)    //返回引用？
    {
        Complex c(real, vir);
        //c.real = this->real;
        //c.vir = this->vir;
        this->real++;
        this->vir++;

        return c;                       //返回自加前的值
    }

    //赋值运算符：
    void operator=(Complex &_c)
    {
        this->real = _c.real;
        this->vir  = _c.vir;
    }

    //()运算符
    Complex operator()(int a, int b, int n)
    {
        Complex c;
        c.real = a + n;
        c.vir  = b + n;
        return c;
    }

    Complex operator[](int n)
    {
        real = n;
        vir = n + 10;
        return *this;
    }

    //->指针符号
    node* operator->()       //this->real this->vir
    {
        node* c = new node();
        c->m = 12;
        c->n = 24;
        return c;
    }

    void Display()
    {
        cout << real << "+" << vir << "i" << endl;
    }

private:
    int real;
    int vir;
};

int main()
{
    //Complex c1, c2;
    Complex c1(0, 3), c2(2,7);
    Complex a = c1 + c2;
    a.Display();

    Complex c3(-5, 11);
    -c3;                //负号    相当于    operator-(c3)
    c3.Display();

    Complex c4(-7, 0);
    !c4;                //非
    c4.Display();

    if (c1 > c2)        //大于
    {
        cout << "c1 > c2" << endl;
    }
    else
    {
        cout << "c1 < c2" << endl;
    }
    
    //Complex c5;
    //cin >> c5;              // >> 输入运算符重载 (针对Complpex类型输入)
    //cout << c5 << endl;     // << 输出运算符重载 (针对Complpex类型输出)
    //c1 << cout;             // 错误：习惯上人们是使用 cin>> 和 cout<< 的(使用友元函数来重载运算符)，但如果使用成员函数来重载会出现 d1<<cout; 这种不自然的代码（对应函数定义：ostream& operator<<(ostream& output)）。         
    
    //test：
    printf("---%d\n", c4 << c3);    // 对应上面的测试二 (<<左边为Complex任意对象：c1、c2......都可以，右边负责输出具体数据)

    Complex c6(15, 2018);
    cout << &c6 << endl;
    c6++;
    //++c6;
    c6.Display();

    Complex c7 = c6;        //赋值 =
    c7.Display();

    Complex c8 = c7(5, 7, 9);   //() 运算符
    c8.Display();

    cout << "===" << endl;
    Complex c9;
    cout << c9[15] << endl;     //下标 []

    cout << "m:" << c9->m << '\t' << "n:" << c9->n << endl;  //->指针符号

    getchar();
    Sleep(5000);
    return 0;
}

/*
    后置++？？？？？？？？？？？？？？？？？？？？？？？？

    A(int a = 0, int b)     //这种编译器报错，不给通过。默认的参数，必须从最后一个参数开始，如果前1个是默认的参数，后面必须全默认才行。
    A(int a, int b = 0)     //不是默认构造
*/