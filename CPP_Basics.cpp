#include<iostream>
using namespace std;
int twice(int a=5)//default data 
{
    return a*2;
}
void passbyreference(int &a)//The address is considered as the pass by refernece 
{
    a*=3;
}
int Add(int a,int b)
{
    return a+b;
}
double Add(double a,double b)
{
    return a+b;
}
string Add(string a,string b)
{
    return a+b;
}
inline int pow(int exp,int base);
const int var=10;
int main()
{
    int a;
    a=10; //Initializing an variable.(single line comment)
    /* This is an multiline comment.
    b=10010;*/
    cin>>a; // >> and cout is used for getting input from the user.
    cout<<a<<"\n"; // << and cout is mainly useful for displaying the output.
    char c='a';
    cout<<"The type casting of character 'a' into int is given as: "<<(int)c<<"\n";
    const int x=100;// used instead of #define in c which cannot be changed.
    cout<<twice(a)<<" "<<twice()<<"\n";
    passbyreference(a);
    cout<<"Value after calling the passbyrefernce fucntion is given as: "<<a<<"\n";
    int &p = a; //The address of variable a is stored in the pointer p(int &p; gives an error)
    /* Function Overloading 
       Same function name with different signatures */\
    cout<<"The sum of 2 and 3 is: "<< Add(2,3)<<"\n";
    cout<<"The sum of 2.3 and 3.4 is: "<< Add((double)2.30,(double)3.40)<<"\n";
    cout<<"The concatenation of two strings is: "<< Add("hello ","hi")<<"\n";
    // If there is no exact type of the data type it checks for conversions according to the rules.
    cout<<"The double sum of two numbers is: "<<Add((float)3.3,(float)5.5)<<"\n";
    /* New and Delete operations for memory allocation and Dealloacation*/
    int* array= new int[1001]; //Allocation of memory has happened same as malloc()/calloc()
    delete[] array; //Deallocation of the memory same as free
    /* It is better to initialize a variable in this way because if there is no memory left zero is stored in the variable*/
    int var= 15;
    int r= ::var;// scope resolution to access the global variable having same name as local variable.
    cout<<r<<"\n";
    // Inline Funcions 
    cout<<"The value of 2^3 is: "<<pow(3,2)<<"\n";
    //By using the inline fucntion we can easily decrese the time of execution,but if called multiple times it may easily occupies more space which is not advisable.Macros are mostly not used because of dirst substitution instead inline functions are majorly recommended.
    return 0;
}
inline int pow(int e,int b)
{
    int p=1;
    if(e<0)
    return 0;
    else{
        for(int i=0;i<e;i++)
        p*=b;
        return p;
    }
}