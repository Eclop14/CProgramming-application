#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int number[10];

    srand(time(NULL)); //time�Լ��κ��� �ð����� �޾ƿ� srand�Լ��� �õ尪�� �Ѱ��ָ� �õ尪 �������� ������ ������

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