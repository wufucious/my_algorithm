#include <stdio.h>

int insert_sort(int *a, int n)
{
    int i,j;
    for(i=1; i < n; i++){
        for(j=0; j < i; j++)
            if(a[j]>a[i]){
               int tmp = a[i];
               int p = i;
               while (p != j) {
                   a[p] = a[p-1];
                   p--;
               }
               a[j] = tmp;
            }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int a[5] = {5,2,3,4,1};

    printf("The unsorted arrary is");
    for(int n=0; n < 5; n++){
        printf("%d ", a[n]);
    }
    printf("\n");

    insert_sort(a,5);

    printf("The sorted arrary is");
    for(int n=0; n < 5; n++){
        printf("%d ", a[n]);
    }
    printf("\n");
    return 0;
}
