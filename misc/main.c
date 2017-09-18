#include <stdio.h>

#define SWAP(x,y)\
    do{\
        int temp = x;\
        x = y;\
        y = temp;\
    }while(0)

#define TWO(x) (x&(x-1))?1:0&&(x!=1)

int main(int argc, char *argv[])
{
    int a = 16;
    char c = 'c';
    int b = 20;
    printf("a = %d b = %d\n",a,b);
    printf("a address = %d b address = %d\n",&a,&b);
    printf("c address = %d\n",&c);

    SWAP(a,b);
    printf("a = %d b = %d\n",a,b);

    if(TWO(a)) printf("a is 2");
    if(TWO(b)) printf("b is 2");
    return 0;
}
