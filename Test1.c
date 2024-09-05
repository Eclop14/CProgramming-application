#pragma warning(disable:4996)
#include <stdio.h>

int main() {
    int n;
    int total_stock = 0;
    int id;
    int stock[100];
    int sales[100];

    printf("상품의 개수 입력: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }

    printf("상품 ID를 입력하세요: ");
    scanf("%d", &id);

    if (id >= 1 && id <= n) {
        int current_stock = stock[id - 1] - sales[id - 1];
        printf("상품 %d의 현재 재고: %d\n", id, current_stock);
    }
    else {
        printf("잘못된 상품 ID입니다.\n");
    }

    total_stock = 0; 
    for (int i = 0; i < n; i++) {
        total_stock += stock[i] - sales[i];
    }

    printf("전체 상품재고 수량: %d\n", total_stock);

    return 0;
}

