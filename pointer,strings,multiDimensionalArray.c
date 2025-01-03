#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a=100,b=50;
    int *p = &a;
    int **s = &p;
    printf("%d\n",*p);
    swap(&a,&b);
    printf("%d %d\n",a,b);
    int arr[30];int *arrad[30];
    for(int i=0;i<30;i++)
    {
        arr[i]=((i*4)+2)%10;arrad[i]= &arr[i];
    }
    for(int i=0;i<30;i++)
    {
        for(int j=i+1;j<30;j++)
        {
            if(*arrad[i]>*arrad[j])
            {
                int *t = arrad[i];
                arrad[i]=arrad[j];
                arrad[j]=t;
            }
        }
    }
    for(int i=0;i<30;i++)
    printf("%d ",arr[i]);
    printf("\n");
    for(int i=0;i<30;i++)
    printf("%d ",*arrad[i]);
    printf("\n");
    //Multidimensional arrays
    int mat[3][3];//A 3x3 matrix formulated.
    //An array of strings can also be represented using single array of all pointers to strings
    char x1[]="Hello";
    char x2[]="Hi";
    char x3[]="Bye";
    char *all[3] = {x1,x2,x3};
    return 0;
}