#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 비교 함수
void compareArr(char ** arr, int col, int row)
{
        
    int indCol = 1, indRow = 0;
    int indTemp = 0;
    
    char *temp = (char*)malloc(sizeof(char) * row); 
    char *indexArr = (char*)malloc(sizeof(char) * row); 
    
    temp = arr[0];
    
// indexArr 배열 초기화
    for(int i = 0; i < row; i++)
        {
            indexArr[i] = 0;
        }

    
// 값 비교
    while(1)
        {
            if(arr[indCol][indRow] == '\0'){
                indRow = 0;
                indTemp = 0;
                indCol++;
            }

            
            if(indCol == col){
                break;
            }

            
            if(arr[indCol][indRow] == temp[indTemp])
            {
                // printf("arr : %c\n", arr[indCol][indRow]);
                // printf("indTemp : %d\n", indTemp);
                indexArr[indTemp]++;
            }
            indRow++;
            indTemp++;
        }

    // 값에 ?넣기
    for(int i = 0; i < strlen(temp); i++)
        {
            if(indexArr[i] < col - 1)
            {
                temp[i] = '?';
            }
        }

    // 출력
    for(int i = 0; i < strlen(temp) ; i++){
        printf("%c", temp[i]);
    }
}


int main()
{

    int col = 0, row = 50;
    
    scanf("%d", &col);

    char **textArr = (char**)malloc(sizeof(char*) * col);
    for(int i = 0; i < col; i++)
        {
            *(textArr + i) = (char*)malloc(sizeof(char) * row);        
            scanf("%s", textArr[i]);
        }
    
    if(col == 1){
        printf("%s",textArr[0]);
    }
    else{
        compareArr(textArr,col, row);
    }

}