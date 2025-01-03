#include<stdio.h>
#include<string.h>//string header file included here
void swap(int *x,int *y)//call by reference using pointers
{
    int t = *x;
    *x = *y;
    *y =t;
}
char * getMessage()
{
    char *p;
    char s[]="Hello!How are you doing?";p=s;
    return p;
}
int main()
{
    int a=10;
    int *f = &a;// Pointer stores memory address of an variable and can access and modify the data at particular location at any time.
    //physial memory is the memory that is contained by the computer physical resorces.Produced by MMU.{Memory management unit}.
    //virtual memory is the obstractive memory location provided by the os.Produced by CPU{central processing unit}.
    printf("%d\n",*f);
    int b=20;
    printf("%d %d\n",a,b);
    swap(&a,&b);
    printf("%d %d\n",a,b);
    printf("%s\n",getMessage());
    int x[1001];
    for(int i=0;i<1001;i++)
    x[i]=i;
    int* p = &x[0];
    char *pc = (char*)p;
    printf("%d %d\n",*((int*)(pc+12)),*(p+3));//The incrementation of address mainly depends on the type of data we are using here.
    printf("%ld %ld\n",sizeof(x)/sizeof(x[0]),sizeof(x[0]));
    //String Functions
    char ss[]="Hello! Iam Fine here.";
    char cpy[1001];
    strcpy(cpy,ss);
    printf("%s\n",cpy);//copy the entire string
    char ncpy[1001];
    strncpy(ncpy,ss,3);
    printf("%s\n",ncpy);//copy n number of characters from one string to another string.
    printf("String Length: %ld\n",strlen(ss));
    printf("The str1>str2: %d\n",strcmp(ss,ncpy));
    //+ve vlaue tells str1 is bigger and 0 tells both are equal and -ve value tells str2 is greater.
    //strncmp for comparing n character sub srings of the both available strings.
    strcat(ss,ncpy);//concatenating one string to the other string.
    printf("%s\n",ss);
}