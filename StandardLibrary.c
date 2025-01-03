#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
void sum(int num,...)//Function that can process variable number of arguments.
{
    va_list ap;
    int s=0;
    va_start(ap,num);
    while(num>0)
    {
        s += va_arg(ap,int);
        num--;
    }
    va_end(ap);
    printf("The sum of given integers is %d\n",s);
}
void aexit_1()
{
    printf("Atexit_1 is being executed\n");
}
void aexit_2()
{
    printf("Atexit_2 is being executed\n");
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",a);
    FILE *p = fopen("Hello.txt","w");
    char s[100];
    // fread(s,4,p);
    // printf("%s",s);
    //ctype.h functions
    char u[]="Hi!,90";
    for(int i=0;i<strlen(u);i++)
    {
        if(isalpha(u[i]))
        {
        if(isupper(u[i]))
        printf("%c is an upper alphabet\n",u[i]);
        else
        printf("%c is an lower alphabet\n",u[i]);
        }
        else if(isdigit(u[i]))
        printf("%c is an digit\n",u[i]);
        else if(ispunct(u[i]))
        printf("%c is an punctuation\n",u[i]);
    }
    //string functions
    char x[]="Hello";char y[]="Hi"; 
    memcpy(x,y,2);
    printf("%s %s\n",x,y);//same copy function,memmov() also provides same functionality.
    printf("%d\n",memcmp(x,y,2));//Same as compare function
    char z[10];
    memset(z,'a',5);//set first n charcters with the given character.
    printf("%s\n",z);
    //stdlib.h fucntions
    char t1[]="12.3",t2[]="145",t3[]="1220202";
    float f=atof(t1);int i2=atoi(t2);long l=atol(t3);
    printf("%f %d %ld\n",f,i2,l);
    //abort(); To abort the function in the given fuction and exit out of the funtion
    //exit(0); exit the current program in a success way buy providing an success message to the os with value
    int r=rand();
    printf("The randomly generated integer is: %d\n",r);
    void (*ptr)(void) = &aexit_1;void (*ptr1)(void) = &aexit_2;
    int e=atexit(*ptr);int ee=atexit(*ptr1);
    //v=atexit(function pointer)//executes all the instruction backward after the termination of program.
    system("pwd");//To eecutes commands on cmd.
    //assert make sures that errors doesnt occur and shows a error message if it occurs.
    assert(a%2==0);//executes only if given expression is not true or it has an error as per mentioned above.
    //stdarg.h hrader file is used to process variable number ogf arguments to an function.
    sum(4,1,2,3,4);sum(7,1,2,3,4,5,6,7);
    time_t currentTime = time(NULL);
    struct tm *ct;
    ct=localtime(&currentTime);
    printf("%d/%d/%d\n",ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900);
    return 0;
}