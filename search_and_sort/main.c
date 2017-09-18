#include <stdio.h>
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int insertSort(int *a, int n)
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
    int a[5] = {5,4,3,2,1};

    printf("The unsorted arrary is");
    for(int n=0; n < 5; n++){
        printf("%d ", a[n]);
    }
    printf("\n");

//    insertSort(a,5);
    quickSort(a,0,4);


    printf("The sorted arrary is");
    for(int n=0; n < 5; n++){
        printf("%d ", a[n]);
    }
    printf("\n");
    return 0;
}
