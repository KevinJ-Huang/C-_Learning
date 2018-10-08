#include <iostream>
using namespace std;
/*
class Location {
private :
int x, y;
public:
void init( int x=0 , int y = 0 );
void valueX( int val ) { x = val ;}
int valueX() { return x; }
};

void Location::init( int X, int Y)
{
x = X;
y = Y;
}

int main() {
Location A,B;
A.init(5);
A.valueX(5);
cout << A.valueX();
return 0;
}
*/
/*
class Complex{
private:
    double real,imag;
public:
    void Set(double r,double i);
};//编译器自动生成默认的构造函数

Complex c1;//默认构造函数被调用
Complex *pc = new Complex;//默认构造函数被调用


class Complex{
private:
    double real,imag;
public:
    Complex(double r,double i = 0);
};
Complex::Complex(double r,double i){ // 构造函数
    real = r;
    imag = i;
}
Complex c1;//error,缺少构造函数的参数
Complex *pc = new Complex;//error,没有参数
Complex c1(2);//OK
Complex c1(2,4),c2(3,5);
Complex *pc = new Complex(3,4);
*/

/*
class Complex{
private:
    double real,imag;
public:
    void Set(double r,double i);
    Complex(double r,double i);
    Complex(double r);
    Complex(Complex c1,Complex c2);
};

Complex::Complex(double r,double i){
    real = r;imag = i;
}

Complex::Complex(double r){
    real = r;
    imag = 0;
}

Complex::Complex(Complex c1,Complex c2){
    real = c1.real+c2.real;
    imag = c1.imag+c2.imag;
}
Complex c1(3),c2(1,0),c3(c1,c2);
//c1 ={3,0},c2={1,0},c3={4,0};
*/
/*
class CSample{
private:
    CSample(){
    }
};
int main(){
    CSample Obj;//err.唯一的构造函数是private
    return 0;
}
*/
/*
class CSample{
    int x;
public:
    CSample(){
        cout << "Constructor 1 Called"<<endl;
    }
    CSample(int n){
        x = n;
        cout << "Constructed 2 Called"<<endl;
    }
};

int main(){
    CSample array1[2];
    cout << "step1"<<endl;
    CSample array2[2] ={4,5};
    cout << "step2"<<endl;
    CSample array3[2]={3};
    cout << "step3"<<endl;
    CSample *array4=new CSample[2];
    delete []array4;
    return 0;
}
*/
/*
class Test{
public:
    Test(int n){}   //(1)
    Test(int n,int m) //(2)
    Test(){}   //(3)
};
Test array1[3]={1,Test(1,2)};
//三个元素分别用（1）（2）（3）初始化
Test array2[3]={Test(2,3),Test(1,2),1};
//三个元素分别用(2)(2)(1)初始化
Test *pArray[3]={new Test(4),new Test(1,2)};
//两个元素分别用(1)(2)初始化
*/
/*
class Complex{
private:
    double real,imag;
};
Complex c1;//调用缺省无参构造函数
Complex c2(c1);//调用缺省的复制构造函数，将c2初始化成和c1一样
*/

/*
class Complex{
public:
    double real,imag;
Complex(){}
Complex(const Complex &c){
    real = c.real;
    imag = c.imag;
    cout << "Copy Constructor called";
}
};
Complex c1;
Complex c2(c1);
*/
/*
class CSample{
    CSample(CSample c){
    }//错，不允许这样的构造函数
};
*/
/*
class A{
public:
    A(){};
    A(A&a){
        cout<<"Copy constructor called"<<endl;
    }
};

void Func(A a1){ }
int main(){
    A a2;
    Func(a2);
    return 0;
}
*/
/*
A Func(){
    A b(4);
    return b;
}
int main(){
    cout << Func().v<<endl;
    return 0;
}
*/
/*
class CMyclass{
public:
    int n;
    CMyclass() {};
    CMyclass(CMyclass &c){
        n = 2*c.n;
    }
};

int main(){
    CMyclass c1,c2;
    c1.n = 5;
    c2 = c1;
    CMyclass c3(c1);
    cout << "c2.n="<<c2.n<<",";
    cout << "c3.n="<<c3.n<<endl;
    return 0;
}
*/

/*
class Complex{
public:
    double real,imag;
    Complex(int i){//类型转换构造函数
        cout << "IntConstructor called"<<endl;
        real = i;imag = 0;
    }
    Complex(double r,double i){
        real = r;imag = i;
    }
};

int main(){
    Complex c1(7,8);
    Complex c2=12;
    c1 = 9;//9被自动转换成一个临时Complex对象
    cout<<c1.real<<","<<c1.imag<<endl;
    return 0;
}
*/
/*
class String{
private:
    char *p;
public:
    String(){
        p = new char[10];
    }
    ~ String();
};

String::~ String()
{
    delete []p;
}
*/
/*
class Ctest{
public:
    ~Ctest(){
        cout<<"destructor called"<<endl;
    };
};
int main(){
    Ctest array[2];
    cout <<"End Main"<<endl;
    return 0;
}
*/
/*
class CMyclass{
public:
    ~CMyclass(){
        cout << "destructor"<< endl;
    };
};
CMyclass obj;
CMyclass fun(CMyclass sobj){//参数对象消亡也会导致析构函数被调用
    return sobj;//函数调用返回时生成临时对象返回
}
int main(){
    obj = fun(obj);//函数调用的返回值（临时对象）被用过后，该临时对象析构函数被调用
    return 0;
}
*/
/*
class Demo{
    int id;
public:
    Demo(int i){
        id = i;
        cout << "id="<<id<<" constructed"<<endl;
    }
    ~Demo(){
        cout << "id="<<id<<" destructed"<<endl;
    }
};

Demo d1(1);
void Func(){
    static Demo d2(2);
    Demo d3(3);
    cout << "func"<<endl;
}
int main(){
    Demo d4(4);
    d4 = 6;
    cout << "main"<<endl;
    {
        Demo d5(5);
    }
    Func();
    cout <<"main ends"<<endl;
    return 0;
}
*/

class CMyclass{
public:
    CMyclass(){};
    CMyclass(CMyclass & c){
        cout << "copy constructor"<<endl;
    }
    ~CMyclass(){
        cout << "destructor"<< endl;
    }
};
void fun(CMyclass obj_){
    cout << "fun"<<endl;
}
CMyclass c;
CMyclass Test(){
    cout<<"test"<<endl;
    return c;
}
int main(){
    CMyclass c1;
    fun(c1);
    Test();
    return 0;
}
