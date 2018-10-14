#include <iostream>

using namespace std;

/*
class Complex {
public:
double real, imag;
void Print() { cout << real << "," << imag ; }
Complex(double r,double i):real(r),imag(i)
{ }
Complex AddOne() {
this->real ++; //等价于 real ++;
this->Print(); //等价于 Print
return * this;
}
};
int main() {
Complex c1(1,1),c2(0,0);
c2 = c1.AddOne();
return 0;
} //输出 2,1
*/

/*
class A{
    int i;
public:
    void Hello(){
        cout<<"Hello"<<endl;
    }
};

int main(){
    A *p=NULL;
    p->Hello();
}
*/
/*
class A{
    int i;
public:
   // void Hello() { cout << i << "hello" << endl; }
    void Hello(A *this){
       cout<<this->i<<"Hello"<<endl;
}
};



int main(){
    A *p=NULL;
    Hello(p);
}
*/
/*
class Crectangle{
private:
    int w,h;
    static int nTotalArea;//静态成员变量
    static int nTotalNumber;
public:
    Crectangle(int w_,int h_);
    ~Crectangle();
    static void PrintTotal();//静态成员函数
};
*/
/*
class CRectangle{
private:
    int  w,h;
    static int nTotalArea;
    static int nTotalNumber;
public:
    CRectangle(int w_,int h_);
    ~CRectangle();
    static void PrintTotal();
};

CRectangle::CRectangle(int w_,int h_){
    w = w_;
    h = h_;
    nTotalNumber++;
    nTotalArea+=w*h;
}

CRectangle::~CRectangle(){
    nTotalNumber--;
    nTotalArea-=w*h;
}

void CRectangle::PrintTotal(){
    cout << nTotalNumber<<","<<nTotalArea<<endl;
}

int CRectangle::nTotalNumber = 0;
int CRectangle::nTotalArea = 0;
//必须在定义类的文件中对静态成员变量进行一次说明或初始化，否则编译能通过，链接通不过。
int main(){
    CRectangle r1(3,3),r2(2,2);
    //cout<<CRectangle::nTotalNumber;//wrong,私有
    CRectangle::PrintTotal();
    r1.PrintTotal();
    return 0;
}
*/
/*
void CRectangle::PrintTotal(){
    cout << w <<","<<nTotalNumber<<","<<nTotalArea<<end;//wrong
}
*/
/*
class Ctyre{
private:
    int radius;
    int width;
public:
    Ctyre(int r,int w):radius(r),width(w){
    }
};

class CEngine{
};

class CCar{
private:
    int price;
    Ctyre tyre;
    CEngine engine;
public:
    CCar(int p,int tr,int w);
};

CCar::CCar(int p,int tr,int w):price(p),tyre(tr,w){
}
int main(){
    CCar car(20000,17,225);
    return 0;
}
*/
/*
class CTyre{
public:
    CTyre(){
        cout << "Ctyre constructor"<<endl;
    }
    ~CTyre(){
        cout << "Ctyre destructor"<<endl;
    }
};

class CEngine{
public:
    CEngine(){
       cout <<"CEngine constructor"<<endl;
    }
    ~CEngine(){
        cout<<"CEngine destructor"<<endl;
    }
};

class CCar{
private:
    CEngine engine;
    CTyre tyre;
public:
    CCar(){
        cout<<"CCar constructor"<<endl;
    }
    ~CCar(){
        cout <<"CCar destructor"<<endl;
    }
};

int main(){
    CCar car;
    return 0;
}
*/
/*
class A{
public:
    A(){
        cout <<"default"<<endl;
    }
    A(A &a){
        cout <<"copy"<<endl;
    }
};

class B{
    A a;
};
int main(){
    B b1,b2(b1);
    return 0;
}
*/
/*
class CCar;
class CDriver{
public:
    void ModifyCar(CCar *pCar);
};
class CCar{
private:
    int price;
    friend int MostExpensiveCar(CCar cars[],int total);//声明友元
    friend void CDriver::ModifyCar(CCar *pCar);
};
void CDriver::ModifyCar(CCar *pCar){
    pCar->price += 1000;
}
int MostExpensiveCar(CCar cars[],int total){
    int tmpMax = -1;
    for(int i = 0;i < total;i++)
        if(cars[i].price>tmpMax)
           tmpMax = cars[i].price;
    return tmpMax;
}
int main(){
    return 0;
}
*/
/*
class CCar{
private:
    int price;
friend class CDriver;
};

class CDriver{
public:
    CCar myCar;
    void ModifyCar(){
        myCar.price+=1000;//可CCar访问私有成员
    }
};

int main(){
    return 0;
}
*/
/*
class Sample{
private:
    int value;
public:
    Sample(){ }
    void SetValue(){
    }
};
const Sample Obj; //常量对象
Obj.SetValue();//错误。常量对象只能使用构造函数、析构函数和有const说明的函数（常量方法）。
*/
/*
class Sample{
private:
    int value;
public:
    void PrintValue() const;
};

void Sample::PrintValue() const{ // 此处不使用const会导致编译出错
    cout << value;
}

void Print(const Sample & o){
    o.PrintValue();//若PrintValue非const则编译错
}
*/
/*
class CTest{
private:
    int n;
public:
    CTest(){
        n=1;
    }
    int GetValue() const{
        return n;
    }
    int GetValue(){
        return 2*n;
    }
};

int main(){
    const CTest objTest1;
    CTest objTest2;
    cout << objTest1.GetValue() <<","<<objTest2.GetValue();
    return 0;
}
*/

class CTest{
public:
    bool GetData() const{
        m_n1++;
        return m_b2;
    }
private:
    mutable int  m_n1;
    bool m_b2;
};
