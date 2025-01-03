#include<stdio.h>
#include<stdlib.h>
enum typ{SQUARE,TRIANGLE,POLYGON,CIRCLE};
struct shape
{
    enum typ type;
    int a;
};
void draw_square(struct shape *p)
{
    printf("The square has been drawn\n");
}
void draw_circle(struct shape *p)
{
    printf("The circle has been drawn\n");
}
void draw_poly(struct shape *p)
{
    printf("The polygon has been drawn\n");
}
void draw_rec(struct shape *p)
{
    printf("The Rectagle has been drawn\n");
}
void (*fp[4])(struct shape *ps) = {&draw_square, &draw_rec, &draw_circle , &draw_poly }; 
//Array of function pointers where each index points to different functions.
void draw ( struct shape  *ps ) 
{
     (*fp[ps->type])(ps); 
     /* call the correct function */
} 
void display(int a)
{
    printf("The number given here is: %d\n",a);
}
int cmp(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
void callback(int (*call)(int,int),int a,int b)
{
    //(*call)(int,int) is an function pointer as an argument which is executed as per required and called as callback.
    printf("The greatest among %d,%d is %d\n",a,b,(*call)(a,b));
}
int main()
{
    // c doesn't allow void variables but allows void pointers.
    //They points to a data type and before usage they should be casted to any of the data type
    void *p;
    printf("%ls",(int *)p);//valid
    //printf("%ls",p);//Invlaid
    //Function pointers also tells us about the callbacks
    void (*k)(int) = &display;
    // Return_type NameofPointer(Arguments dtype list)->Fucntion pointers.
    (*k)(10);
    //Callbacks: These are nothing but passing function declaration to another functions.In c it is done by the help of function pointers.
    callback(cmp,10,20);//cmp is passed as an function pointer here.
    //We can also have an array of function pointers.
    struct shape *sh=(struct shape*)malloc(sizeof(struct shape*));
    sh->type=SQUARE;sh->a=10;
    draw(sh);
    return 0;
}