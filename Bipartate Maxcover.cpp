#include<iostream>
#include<cmath>
using namespace std;

class shape{
    protected:
        float area, perimeter;
    public:
        shape(){ area = perimeter = 0.0;}
        virtual void initialize() = 0;
        virtual float computeArea() = 0;
        virtual float computePerimeter() = 0;
        virtual ~shape(){cout<<"\nShape destructor called";}
};

class Triangle : public shape{
    int a, b, c;
    float s;
    public:
        void initialize(){ a=5; b=6; c=7;}
        float computeArea(){
            s = (a+b+c)/2.0;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }
        float computePerimeter(){
            return (a+b+c);
        }
        //~shape(){cout<<"\nTriangle destructor called\n";}
};

class Rectangle : public shape{
    int len, bred;
    public:
        void initialize(){cout<<"\nRectangle initialize called"; len = 2; bred = 6;}
        float computeArea(){
            return len*bred;
        }
        float computePerimeter(){
            return 2*(len+bred);
        }
      //  ~shape(){cout<<"\nRectangle destructor called\n";}
};

int main(){
    Triangle t;
    Rectangle r;
    shape *s;

    cout<<"\nTriangle:";
    s = &t;
    s->initialize();
    cout<<"\nArea: "<<s->computeArea();
    cout<<"\nPerimeter: "<<s->computePerimeter();

    cout<<"\n\nRectangle:";
    s = &r;
    s->initialize();
    cout<<"\nArea: "<<s->computeArea();
    cout<<"\nPerimeter: "<<s->computePerimeter()<<endl;

}