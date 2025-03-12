#include <stdio.h>
#include <stdlib.h>
// 그냥 갑자기 아이디어가 떠오름
// x를 1로 바꾼다음에 각각의 행과 열의 합을 구해서 0의 갯수가 큰수를 출력하면
// 최솟값을 구할수 있음


int main()
{
    int col, row;
    scanf("%d %d", &col, &row);
    
    int *arrCol = (int*)malloc(sizeof(int) * col);
    int *arrRow = (int*)malloc(sizeof(int) * row);
    char **strArr = (char **)malloc(sizeof(char*) * col);
    for(int i = 0; i < col; i++)
        {
            strArr[i] = (char*)malloc(sizeof(char) * row);
            scanf("%s", strArr[i]);
        }

    
    for(int i = 0; i < col; i++)
        {
            for(int j = 0; j < row; j++)
                {
                    if(strArr[i][j] == 'X')
                    {
                        arrCol[i]++;
                        arrRow[j]++;

                    }
                }
        }
    
    int cntCol = 0, cntRow = 0;
    
    for(int i = 0; i < col; i++)
        {
            // printf("arrCol[%d] : %d\n", i, arrCol[i]);
            if(arrCol[i] == 0) cntCol++;
        }

    for(int i = 0; i < row; i++)
        {
            // printf("arrRow[%d] : %d\n", i, arrRow[i]);
            if(arrRow[i] == 0) cntRow++;
        }

    if(cntCol > cntRow) printf("%d", cntCol);
    else printf("%d", cntRow);

    
}