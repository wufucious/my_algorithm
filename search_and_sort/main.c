#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

int select(int arr[], int low, int high, int sel)
{
    int ret = -1;

    if (low < high)
    {
        int pi = partition(arr, low, high);
        if(sel == pi){
            return arr[pi];
        }else if (sel < pi) {
            ret = select(arr, low, pi - 1, sel);
        }else{
            ret = select(arr, pi + 1, high, sel);
        }
    }

    return ret;
}

void merge(int *a, int low, int middle, int high)
{
    int n1 = middle - low + 1;
    int n2 = high - middle;
    int l[n1+1];
    int r[n2+1];

    for(int i=0; i < n1; i++){
        l[i] = a[i+low];
    }
    l[n1] = INT_MAX;

    for(int i=0; i < n2; i++){
        r[i] = a[i+middle+1];
    }
    r[n2] = INT_MAX;

    int j=0;
    int k=0;
    for(int i=low; i< high+1; i++){
        if(l[j] < r[k]){
            a[i] = l[j];
            j++;
        }else{
            a[i] = r[k];
            k++;
        }
    }
}

void mergeSort(int *a, int low, int high)
{
    if(low < high){
        int middle = (low+high)/2;
        mergeSort(a, low,      middle);
        mergeSort(a, middle+1, high);
        merge(a, low, middle, high);
    }
}

int insertSort(int *a, int n)
{
    int i,j;
    for(i=1; i < n; i++){
        j = i-1;
        int key = a[i];
        while (j>=0&&a[j]>key) {
            a[j+1] = a [j];
            j--;
        }
        a[j+1] = key;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int a[10] = {5,4,10,2,1,7,8,9,6,3};

    printf("The unsorted arrary is");
    for(int n=0; n < 10; n++){
        printf("%d ", a[n]);
    }
    printf("\n");

//    insertSort(a,10);
//    quickSort(a,0,9);
//    mergeSort(a,0,9);

    printf("The sorted arrary is");
    for(int n=0; n < 10; n++){
        printf("%d ", a[n]);
    }

    printf("The selected %d number is %d",6,select(a,0,9,9));
    printf("\n");
    return 0;
}
