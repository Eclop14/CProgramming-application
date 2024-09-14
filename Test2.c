#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)
#define MAX_PRODUCTS 100

struct Product {
    int id;
    int stock;
    int incoming;
    int outgoing;
};

// 전역 변수
struct Product products[MAX_PRODUCTS];
int productCount = 0;

// 함수 선언
void inputData();
void calculateStats();


int main() {
    inputData();
    calculateStats();
    return 0;
}

void inputData() {
    int productId, incoming, outgoing;

  
    printf("상품 개수:");
    scanf("%d", &productCount);


    for (int i = 0; i < productCount; i++) {
        scanf("%d", &incoming);
        products[i].id = i + 1;
        products[i].incoming = incoming;
    }


    for (int i = 0; i < productCount; i++) {
        scanf("%d", &outgoing);
        products[i].outgoing = outgoing;
    }
}

void calculateStats() {
    int totalStock = 0;
    int totalSold = 0;

    for (int i = 0; i < productCount; i++) {
        products[i].stock = products[i].incoming - products[i].outgoing;
        totalStock += products[i].stock;
        totalSold += products[i].outgoing;
    }

    printf("재고수량:");
    for (int i = 0; i < productCount; i++) {
        printf("%d ", products[i].stock);
    }

    printf("\n총 재고수량: %d\n", totalStock);
    printf("총 판매량: %d (판매율 %.2f%%)\n", totalSold, (float)totalSold / (totalStock + totalSold) * 100);

 
    int maxSold = 0, minSold = products[0].outgoing;
    int maxId = 0, minId = 0;

    for (int i = 0; i < productCount; i++) {
        if (products[i].outgoing > maxSold) {
            maxSold = products[i].outgoing;
            maxId = products[i].id;
        }
        if (products[i].outgoing < minSold) {
            minSold = products[i].outgoing;
            minId = products[i].id;
        }
    }

    printf("\n가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxId, maxSold);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minId, minSold);

    // 재고 부족 경고
    printf("\n재고 부족 경고:\n");
    for (int i = 0; i < productCount; i++) {
        if (products[i].stock <= 2) {
            printf("상품 ID %d:\t재고부족(%d)\n", products[i].id, products[i].stock);
        }
    }
}
