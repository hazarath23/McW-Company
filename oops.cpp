#include<iostream>
using namespace std;
struct Node
{
    //data Members
    int a;
    char c;
    string Name;
    //Member Functions
    void Hello()
    {
        cout<<"Hello! How are you?";
    }
};
//one of the main differences between struct and classes is all members of struct are public and all members of class are private.
class Employee
{
    public:
    //Data Members
    long id;
    string Name;
    float salary;
    //Member Fucntions
    Employee()//constructor used to initialize the data of the object.
    {
        this->id=1001;
        this->Name="Madhav";
        this->salary=100.0;
    }
    Employee(string u,long v,float w)
    {
        this->id=v;
        this->Name=u;
        this->salary=w;
    }
    ~Employee()//This is destructor ~className() with no return type which is called when the object is deleting.
    {
        cout<<"The object is getting deleted"<<"\n";
    }
    void printDetails()//Tells that member function belongs to that particular class.
    {
        this->Name="Harish";
    }
};
class EXample
{
    friend class printt;
    private:
    long fullsalary=1001;
};
class printt
{
    public:
    void get(EXample *ee);
};
void printt::get(EXample *ee)
{
    cout<<"The full salary is given as "<<ee->fullsalary<<"\n";
}
int main()
{
    Node d;
    Employee head;
    //The scope of an object declaration is till the end of the function till it is ended.Later it will be automatlically deallocated(Object is destroyed).
    //creation of objects
    Employee emp;//Normal creation and members are accessed using the dot operator
    Employee *p;
    p = new Employee();//It is created using pointer which has an high scope compared to others and also accessed using the dot opeerator.
    p->Name="Hazarath";//Pointer specified object using "->" operator
    head.Name="Bharath";// Normally created object using the "." operator
    cout<<p->Name<<" "<<head.Name<<"\n";
    //The this object pointer points to the current working object using this keyword.Mainly used when the current member fucntion want to pass or store address of the current working object.
    head.printDetails();
    cout<<p->Name<<" "<<head.Name<<"\n";
    //when an object is created using the new keyword it is our responsibility also to free the allocated space
    delete p;//free the space occiped by the p object
    Employee *e1;
    e1 = new Employee("Shanku",1001,1000.00);
    cout<<e1->id<<" "<<e1->Name<<" "<<e1->salary<<"\n";
    //Access specifiers: public->accessible by the scope,Private->accessible to same or friends,protected->same as private but allows for derived also 
    //Friend fucntion is used to access the private members of the other class
    EXample* h;
    h = new EXample;
    printt* pr;
    pr = new printt;
    pr->get(h);
    return 0;
}