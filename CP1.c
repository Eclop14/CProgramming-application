#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int number[10];

    srand(time(NULL)); //time함수로부터 시간값을 받아와 srand함수에 시드값을 넘겨주면 시드값 바탕으로 난수가 생성됨

    for (int i = 0; i < 10; i++)
    {
        number[i] = (rand()%100)+1;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("number = %d\n",number[i]);
    }

    return 0;
}