//#include <iostream>
//
//using namespace std;
//
//class my_class
//{
//public:
//    //explicit operator int()//定义了一个将类转化为int的转换函数
//    //{
//    //    cout << "convert_to_int" << endl;
//    //    return 1;
//    //}
//
//    operator int()//定义了一个将类转化为int的转换函数
//    {
//        cout << "convert_to_int" << endl;
//        return 1;
//    }
//};
//
//int main()
//{
//    my_class a;
//    int i_a = (int)a;   //第一次显式的转换
//    cout << a << endl;  //第二次默认 <隐式> 的转换  相当于：cout << (int)a << endl;  在使用explicit修饰函数时，该语句编译出错
//    cout << (double)a << endl;
//
//    return 0;
//}
//
///*
//    C++中的explicit:
//    这时候就要在这个构造器前面加上explicit修饰， 指定这个构造器只能被明确的调用/使用， 不能作为类型转换操作符被隐含的使用
//    注意谨慎使用隐式转换函数，因为当你在不需要使用转换函数时，这些函数缺可能会被调用运行; 这些不正确的程序会做出一些意想不到的事情，而你又很难判断出原因。
//*/


//#include <iostream>
//using namespace std;
//
//struct node
//{
//    int d;
//    node(int d) : d(d)
//    {
//    
//    }
//};
//
//class A
//{
//private:
//    node *n;
//public:
//    A() : n(new node(123))
//    {
//    }
//    node* operator ->()
//    {
//        return n;
//    }
//};
//
//int main()
//{
//    A a;
//    cout << a->d << endl;
//
//    getchar();
//    return 0;
//}