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
    //��ʽһ��
    //����һ�������Ĺ��캯��
    Complex()
    {
        real = 0;
        vir  = 0;
    }

    //�������������Ĺ��캯��
    Complex(int _real/* = 0*/, int _vir/* = 0*/)    //���ܴ���ע���е�ȱʡ�����������൱�ڶ���������һ���Ĳ��贫�ݲ�����Ĭ�Ϲ��캯��(������󶼲���Ҫ���ݲ���)������ض���
    {
        real = _real;
        vir  = _vir;
    }

    //��ʽ�������ó�ʼ���б�
  /*  Complex(int _real = 2, int _vir = 4) : real(_real), vir(_vir)         
    {

    }*/

    ~Complex()
    {

    }
    
    Complex operator+(Complex &_c)
    {
        Complex c3;                                 //��Ҫ�õ�Ĭ�Ϲ��캯��Complex()
        c3.real = this->real + _c.real;
        c3.vir  = this->vir  + _c.vir;
        return c3;
    }

    //���� (���Ǽ���)
    void operator-()
    {
        //Complex c;
        real = -real;
        vir = -vir;
        //return c;
    }

    //�������
    void operator!()        //���ﲻ��Ҫ����ֵ�����Ҳ���c.real������real����this->real���� 
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

    //��Ԫ�� >
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

    //������������
    friend ostream& operator<<(ostream &output, Complex &_c)        //��Ԫ:���������˫Ŀ����������Ϊ��ĳ�Ա����������ֻҪ����һ��������Ϊ�Ҳ�����������������������Ƕ����� �� >> �� << ����������� cin��cout �����Ƕ��������Բ��������һ�㣬��ֻ������Ϊ��Ԫ������
    {
    output << "real = " << _c.real << '\t' << "vir = " << _c.vir << endl;
    return output;
    }

    //����1��<<����Ϊʲô��Ҫ����Ԫ:
    /* ostream& operator<<(ostream& output)
     {
     output << "real = " << this->real << '\t' << "vir = " << this->vir << endl;
     return output;
     }*/

    //����2��<<����Ϊʲô��Ҫ����Ԫ��
    int operator<<(Complex &_c)
    {
        return _c.vir;
    }

    //�������������
    friend istream& operator>>(istream &input, Complex &_c)         //��Ԫ
    {
        input >> _c.real >> _c.vir;
        return input;
    }

    //ǰ��++
    Complex operator++()
    {
        return Complex(real++, vir++);  //����һ���������󣬲�Ϊ��������++
    }

    //����++
    Complex& operator++(int)    //�������ã�
    {
        Complex c(real, vir);
        //c.real = this->real;
        //c.vir = this->vir;
        this->real++;
        this->vir++;

        return c;                       //�����Լ�ǰ��ֵ
    }

    //��ֵ�������
    void operator=(Complex &_c)
    {
        this->real = _c.real;
        this->vir  = _c.vir;
    }

    //()�����
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

    //->ָ�����
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
    -c3;                //����    �൱��    operator-(c3)
    c3.Display();

    Complex c4(-7, 0);
    !c4;                //��
    c4.Display();

    if (c1 > c2)        //����
    {
        cout << "c1 > c2" << endl;
    }
    else
    {
        cout << "c1 < c2" << endl;
    }
    
    //Complex c5;
    //cin >> c5;              // >> ������������� (���Complpex��������)
    //cout << c5 << endl;     // << ������������ (���Complpex�������)
    //c1 << cout;             // ����ϰ����������ʹ�� cin>> �� cout<< ��(ʹ����Ԫ���������������)�������ʹ�ó�Ա���������ػ���� d1<<cout; ���ֲ���Ȼ�Ĵ��루��Ӧ�������壺ostream& operator<<(ostream& output)����         
    
    //test��
    printf("---%d\n", c4 << c3);    // ��Ӧ����Ĳ��Զ� (<<���ΪComplex�������c1��c2......�����ԣ��ұ߸��������������)

    Complex c6(15, 2018);
    cout << &c6 << endl;
    c6++;
    //++c6;
    c6.Display();

    Complex c7 = c6;        //��ֵ =
    c7.Display();

    Complex c8 = c7(5, 7, 9);   //() �����
    c8.Display();

    cout << "===" << endl;
    Complex c9;
    cout << c9[15] << endl;     //�±� []

    cout << "m:" << c9->m << '\t' << "n:" << c9->n << endl;  //->ָ�����

    getchar();
    Sleep(5000);
    return 0;
}

/*
    ����++������������������������������������������������

    A(int a = 0, int b)     //���ֱ�������������ͨ����Ĭ�ϵĲ�������������һ��������ʼ�����ǰ1����Ĭ�ϵĲ������������ȫĬ�ϲ��С�
    A(int a, int b = 0)     //����Ĭ�Ϲ���
*/