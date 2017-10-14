#include <stdio.h>
#include <limits.h>

int iteraSearch(int nums[], int numsSize)
{
    int maxSum = INT_MIN;
    int curSum = 0;

    for(int i =0; i < numsSize; i++){
        curSum += nums[i];
        if(maxSum < curSum) maxSum = curSum;
        if(curSum < 0) curSum =0;
    }

    return maxSum;
}

int main(int argc, char *argv[])
{
    int array[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

    printf("the array is:");
    for (int i =0; i < 16; i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    int maxSum = iteraSearch(array,16);
    printf("the maxSum is %d \n", maxSum);
    return 0;
}
