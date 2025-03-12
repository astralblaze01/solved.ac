#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d", &num);

    int *arr = (int *)malloc(sizeof(int) * num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = 0, first = 0, last = 0, difference = 0;
    while (num > 0)
    {
        if (arr[first] >= arr[last])
        {
            first = last;
        }
        else
        {
            difference = arr[last] - arr[first];
            if (arr[last] >= arr[last + 1])
            {
                first = last + 1;
            }
        }

        if (max < difference)
        {
            max = difference;
        }
        last++;
        num--;
    }

    printf("%d", max);
    free(arr);
    return 0;
}
