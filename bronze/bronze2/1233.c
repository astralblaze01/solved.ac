#include <stdio.h>
#include <stdlib.h>

int max(int *arr, int arrSize)
{
    int maxNum = *arr;
    int reIndex = -1;
    
    for(int i = 0; i < arrSize; i++)
        {
            if(maxNum < arr[i])
                {
                    maxNum = arr[i];
                    reIndex = i;
                    
                }
        }
    printf("%d", reIndex);
    return reIndex;
}



int main(){
    int s1, s2, s3;
    int sum = 0;
    
    scanf("%d %d %d", &s1, &s2, &s3);

    int arrSize = s1 + s2 + s3;
    int *arr = (int*)malloc(sizeof(int) * arrSize);
    for(int i = 0; i < arrSize; i++)
        {
            arr[i] = 0;
        }
    

    for(int i = 1; i < s1 + 1; i++)
        {
            for(int j = 1; j < s2 + 1; j++)
                {
                    for(int k = 1; k < s3 + 1; k ++){
                        sum = i + j + k;
                        arr[sum]++;
                    }
                }
            }

    // for(int i = 0; i < arrSize; i++)
    //     {
    //         printf("%d", arr[i]);
    //     }
    
    max(arr,arrSize);
}