#include <iostream>

using namespace std;

class CRectangle{
public:
    int w,h;
    int Area(){
        return w*h;
    }
    int Perimeter(){
        return 2*(w+h);
    }
    void Init(int w_,int h_){
        w = w_;
        h = h_;
    }
};

void PrintRectangle(CRectangle & r){
   cout << r.Area() << "," << r.Perimeter()<<endl;
}

int main()
{
    int  w,h;
    CRectangle r;
    cin >> w >> h;
    r.Init(w,h);
    CRectangle r3;
    CRectangle & rr = r3;
    rr.h = 5;
    rr.Init(5,4);
    PrintRectangle(r3);
    cout << r.Area() << endl << r.Perimeter();
    return 0;
}
