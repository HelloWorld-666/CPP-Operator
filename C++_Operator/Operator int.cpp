//#include <iostream>
//
//using namespace std;
//
//class my_class
//{
//public:
//    //explicit operator int()//������һ������ת��Ϊint��ת������
//    //{
//    //    cout << "convert_to_int" << endl;
//    //    return 1;
//    //}
//
//    operator int()//������һ������ת��Ϊint��ת������
//    {
//        cout << "convert_to_int" << endl;
//        return 1;
//    }
//};
//
//int main()
//{
//    my_class a;
//    int i_a = (int)a;   //��һ����ʽ��ת��
//    cout << a << endl;  //�ڶ���Ĭ�� <��ʽ> ��ת��  �൱�ڣ�cout << (int)a << endl;  ��ʹ��explicit���κ���ʱ�������������
//    cout << (double)a << endl;
//
//    return 0;
//}
//
///*
//    C++�е�explicit:
//    ��ʱ���Ҫ�����������ǰ�����explicit���Σ� ָ�����������ֻ�ܱ���ȷ�ĵ���/ʹ�ã� ������Ϊ����ת����������������ʹ��
//    ע�����ʹ����ʽת����������Ϊ�����ڲ���Ҫʹ��ת������ʱ����Щ����ȱ���ܻᱻ��������; ��Щ����ȷ�ĳ��������һЩ���벻�������飬�����ֺ����жϳ�ԭ��
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