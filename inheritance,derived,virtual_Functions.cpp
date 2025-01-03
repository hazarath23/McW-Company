#include<iostream>
using namespace std;
class Base
{
    private:
    int incee;//It is not accessible to the derived class at any cost.
    public:
    int Basemember;
    void baseFunction()
    {
        cout<<"Base function has been called"<<"\n";
    } 
};
class Derived : public Base//By default it is set as private we can change to public,if is struct it will be public by default
{
    public:
    int derivedmember;
    void derivedFunction()
    {
        cout<<"Derived function has been called"<<"\n";
    }
};
class A
{
    protected:
    //Data Members
    A()
    {
        cout<<"A's constructor has been called"<<"\n";
    }
    ~A()
    {
        cout<<"A's Deconstructor has been called"<<"\n";
    }
};
class B: public A
{
    protected:
    //Data Members
    B()
    {
        cout<<"B's constructor has been called"<<"\n";
    }
    ~B()
    {
        cout<<"B's Deconstructor has been called"<<"\n";
    }
};
class C: public B//This can't be protected because to enable the members to main function.
{
    public:
    //Data Members
    C()
    {
        cout<<"C's constructor has been called"<<"\n";
    }
    ~C()
    {
        cout<<"C's Deconstructor has been called"<<"\n";
    }
};
//If we are planning not to inherit an class then we can make members as private or else we can make them as protected.
//a->b->c,Three classes are created as per given parent-child relationship
//constructor execution sequence: a,b,c Deconstructor execution sequence: c,b,a
class Rectangle
{
    public:
    int width,height;
    Rectangle(int u,int v)
    {
        width=u;height=v;
    }
    virtual void area()//virtual is needed to be added to override the base class function in the derived classes.
    {
        cout<<"The area of the rectangle is :"<<width*height<<"\n";
    }
};
class square : public Rectangle
{
    public:
    square(int u) : Rectangle(u,u)// format like super() in java inheritance
    {

    }
};
class Shape
{
    public:
    //Data members
    virtual void whatIam()
    {
        cout<<"I don't know which shape Iam"<<"\n";
    }
};
class circle : public Shape
{
    public:
    //Data members
    void whatIam()
    {
        cout<<"Iam an circle"<<"\n";
    }
};
class oval : public Shape
{
    public:
    //Data members
    void whatIam()
    {
        cout<<"Iam an oval"<<"\n";
    }
};
int main()
{
    Derived *d;
    d = new Derived;
    d->derivedFunction();
    d->baseFunction();
    C *x;
    x = new C;
    delete x;
    square *y;
    y = new square(10);
    y->area();
    Shape *s1,*s2;
    s1 = new circle;
    s2 = new oval;
    s1->whatIam();s2->whatIam();
}