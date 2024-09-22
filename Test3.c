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


struct Product products[MAX_PRODUCTS];
int productCount = 0;


void inputData(int type);
void calculateStats();
void displayMenu();
void processChoice(int choice);

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);
        processChoice(choice);
        if (choice == 4) break;
    }
    return 0;
}

void displayMenu() {
    printf("1. 입고 2. 판매 3. 상품현황 4. 종료\n");
}

void processChoice(int choice) {
    switch (choice) {
    case 1:
        inputData(1);  // 입고
        break;
    case 2:
        inputData(2);  // 판매
        break;
    case 3:            //재고수량
        calculateStats();
        break;
    case 4:
        printf("프로그램을 종료합니다.\n");
        break;
    default:
        printf("잘못된 선택입니다. 다시 선택해주세요.\n");
    }
}

void inputData(int type) {
    if (productCount == 0) {
        printf("상품 개수: ");
        scanf("%d", &productCount);
    }

    printf("%s\n", type == 1 ? "입고" : "판매");
    for (int i = 0; i < productCount; i++) {
        int quantity;
        scanf("%d", &quantity);
        products[i].id = i + 1;
        if (type == 1) {
            products[i].incoming += quantity;
            products[i].stock += quantity;
        }
        else {
            products[i].outgoing += quantity;
            products[i].stock -= quantity;
        }
    }
}

void calculateStats() {
    int totalStock = 0;
    int totalSold = 0;
    int maxSold = 0, minSold = products[0].outgoing;
    int maxId = 0, minId = 0;

    for (int i = 0; i < productCount; i++) {
        totalStock += products[i].stock;
        totalSold += products[i].outgoing;

        if (products[i].outgoing > maxSold) {
            maxSold = products[i].outgoing;
            maxId = products[i].id;
        }
        if (products[i].outgoing < minSold) {
            minSold = products[i].outgoing;
            minId = products[i].id;
        }
    }

    printf("재고수량: ");
    for (int i = 0; i < productCount; i++) {
        printf("%d ", products[i].stock);
    }
    printf("\n총 재고수량: %d\n", totalStock);
    printf("총 판매량: %d (판매율 %.2f%%)\n", totalSold, (float)totalSold / (totalStock + totalSold) * 100);

    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxId, maxSold);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minId, minSold);

    printf("\n재고 부족 경고:\n");
    for (int i = 0; i < productCount; i++) {
        if (products[i].stock <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", products[i].id, products[i].stock);
        }
    }

}