#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAX_PRODUCTS 5

struct Product {
    int id;
    char name[50];
    int stock;
    int sold;
};

struct Product products[MAX_PRODUCTS];
int totalStock = 0;

void inputInitialStock();
void showCurrentStatus();
void displayMenu();
void processChoice(int choice);
void inputProductNames();
void processSales();

int main() {
    int choice;
    
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i].id = i + 1;
        products[i].stock = 0;
        products[i].sold = 0;
        sprintf(products[i].name, "상품명%d", i + 1);
    }
    
    while (1) {
        displayMenu();
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력, 5. 종료): ");
        scanf("%d", &choice);
        
        processChoice(choice);
        if (choice == 5) break;
    }
    return 0;
}

void displayMenu() {
    printf("\n1. 입고 2. 판매 3. 상품현황 4. 상품명 입력 5. 종료\n");
}

void processChoice(int choice) {
    switch (choice) {
        case 1:
            inputInitialStock();
            break;
        case 2:
            processSales();
            break;
        case 3:
            showCurrentStatus();
            break;
        case 4:
            inputProductNames();
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            break;
    }
}

void inputProductNames() {
    printf("\n4 << 상품명입력 메뉴 실행\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        char tempName[50];
        printf("ID %d 상품명 : ", i + 1);
        scanf("%s", tempName);
        strcpy(products[i].name, tempName);
    }
}

void inputInitialStock() {
    totalStock = 0;
    
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        int stock;
        printf("상품 ID %d (%s)의 재고수량을 입력하세요: ", i + 1, products[i].name);
        scanf("%d", &stock);
        products[i].stock = stock;
        totalStock += stock;
    }
}

void showCurrentStatus() {
    printf("\n상품 현황:\n");
    printf("ID\t상품명\t\t재고\t판매량\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%d\t%-15s\t%d\t%d\n", products[i].id, products[i].name, products[i].stock, products[i].sold);
    }

    printf("\n총 재고수량: %d\n", totalStock);
    int totalSold = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        totalSold += products[i].sold;
    }
    float salesRate = (totalSold > 0) ? ((float)totalSold / (totalSold + totalStock)) * 100 : 0;
    printf("총 판매량: %d (판매율 %.2f%%)\n", totalSold, salesRate);
    
    int maxSoldId = 0, minSoldId = 0;
    for (int i = 1; i < MAX_PRODUCTS; i++) {
        if (products[i].sold > products[maxSoldId].sold) maxSoldId = i;
        if (products[i].sold < products[minSoldId].sold) minSoldId = i;
    }
    printf("가장 많이 판매된 상품: %s (ID %d), 판매량 %d\n", products[maxSoldId].name, products[maxSoldId].id, products[maxSoldId].sold);
    printf("가장 적게 판매된 상품: %s (ID %d), 판매량 %d\n", products[minSoldId].name, products[minSoldId].id, products[minSoldId].sold);
    
    printf("\n재고 부족 경고:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].stock <= 2) {
            printf("%s (ID %d) : 재고부족(%d)\n", products[i].name, products[i].id, products[i].stock);
        }
    }
}

void processSales() {
    printf("\n2 << 판매 메뉴 실행\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        int salesAmount;
        printf("%s (ID %d)의 판매량을 입력하세요: ", products[i].name, i + 1);
        scanf("%d", &salesAmount);
        
        if (salesAmount <= products[i].stock) {
            products[i].stock -= salesAmount;
            products[i].sold += salesAmount;
            totalStock -= salesAmount;
            printf("판매 완료. %s의 남은 재고: %d\n", products[i].name, products[i].stock);
        } else {
            printf("재고 부족. %s의 현재 재고: %d, 판매 요청량: %d\n", products[i].name, products[i].stock, salesAmount);
        }
    }
}
