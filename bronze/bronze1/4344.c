#include <stdio.h>
#include <stdlib.h>

void present(int **arrResult, double * averArr, int n);

int main()
{
    int n, stdN, value;
    double average = 0.0;
    scanf("%d", &n);
    
    int ** arr = (int**)malloc(sizeof(int*) * n);
    double * averArr = (double *)malloc(sizeof(double) * n); 
    
    for(int i = 0; i < n; i++)
        {
            scanf("%d", &stdN);
            arr[i] = (int*)malloc(sizeof(int) * (stdN + 1));
            
            for(int j = 0; j < stdN + 1; j++)
                {
                    if(j == 0)
                    {
                        arr[i][j] = stdN;
                    }
                    else
                    {
                        scanf("%d", &value);
                        average = (value + average);
                        arr[i][j] = value;    
                    }
                }
            
            average = average / stdN;
            // printf("average : %f\n", average); --> 이렇게 하면 present함수에서 arrResult가 돌아갈때 arr에 값이 완전히 들어가지 않은 상태이므로 할꺼면 present를 for문 하나로 돌려야함
            averArr[i] = average;
            average = 0;
        }
        present(arr, averArr, n);
    
}


void present(int **arrResult, double *averArr, int arrSize)
{
    int cnt = 0;
    double result;
    
    for(int i = 0; i < arrSize; i++)
        {
            cnt = 0;
            for(int j = 1; j < arrResult[i][0] + 1; j++)
                {
                    if(arrResult[i][j] > averArr[i])
                    {
                        cnt++;
                    }
                }
            // printf("cnt : %d\n", cnt);
            // printf("arrResult : %d\n", arrResult[i][0]);
            result = ((double)cnt * 100 / (double)arrResult[i][0]);
            printf("%0.3f%s\n", result, "%");
        }
}

