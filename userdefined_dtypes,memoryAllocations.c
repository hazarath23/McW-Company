#include<stdio.h>
#include<stdlib.h>
struct Name //Here the padding comes into play soem time for neat memory allocation
{
    int a;//4
    char c;//1
    //3 padding
    int b;//4
    float f;//4
};
union u
{
    int a;//4
    float f;//4
    char c;//2
    double d;//8
};
struct btfields//bitfileds set the width to be occupied by the data in the total structure in terms of bits.
{
    unsigned int p:1;
    unsigned int q:2;
    unsigned int r:3;
};
int main()
{
    int a;
    struct Name p = {10,'a',20,123.32};
    printf("%d %d %.2f\n",p.a,p.b,p.f);// . to access normally created structures
    struct Name *pcp = &p;
    printf("%d ",pcp->a);//-> to acess the pointer created structures
    printf("%lu",sizeof(p));
    struct Name arr[2]={{10,'a',20,123.32},{20,'b',30,133.32}};//array of structures
    //union stores all the data in the same memory 
    union u cc;
    printf("\n%lu\n",sizeof(cc));//prints size of the highest memory data type among all of them.
    cc.a=10;cc.f=12.3;cc.c='a';cc.d=23.23;
    printf("%f\n",cc.f);//stores at the commom memory location
    struct btfields b;
    printf("The size of btfields structure is: %lu\n",sizeof(b));
    //Memory allocation in c includes three functions: Malloc(),calloc(),free()
    //Malloc takes size as argument,calloc take number,each size like an array,free frees up the allocated memory
    struct Name *nu = (struct Name*)malloc(sizeof(struct Name*));//Memory allocation and type casting is compulsary while using malloc function
    int *array = calloc(100,sizeof(int));//allocates the memory using numeber of blocks and size of each block
    for(int i=0;i<100;i++)
    {
        *(array+i)=i;
    }
    printf("%d\n",*(array+60));
    free(array);free(nu);//frees the allocated memory
    return 0;
}