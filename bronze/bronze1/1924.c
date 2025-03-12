#include <stdio.h>
// 제라의 공식으로 프로그래밍함

int main()
{
    
    int y = 2007;
    char dayOfWeek[7][4] = {"SAT","SUN", "MON", "TUE", "WED", "THU", "FRI"}; 
    
    int m, q;
    scanf("%d %d", &m, &q);
    if(m == 1 || m == 2)
        {
            m = m + 12;   
            y = y - 1;
            
        }


    int j = y / 100;
    int k = y % 100;
    
    int h = (q + (13*(m + 1) / 5) + k + (k / 4) + (j / 4) +5*j) % 7;

    printf("%s", dayOfWeek[h]);
}