#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_PRODUCTS 5

// 상품 구조체 정의
struct Product {
    int id;             // 상품 ID
    char name[50];      // 상품명
    int price;          // 가격
    int stock;          // 재고수량
    int sold;           // 판매수량
};

struct Product products[MAX_PRODUCTS];
int totalStock = 0;

// 함수 선언
void displayMenu();
void processChoice(int choice);
void inputProduct();
void processSales();
void showIndividualProduct();
void showAllProducts();

int main() {
    int choice;
    
    // 초기화
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i].id = i + 1;
        products[i].stock = 0;
        products[i].sold = 0;
        sprintf(products[i].name, "상품명%d", i + 1);
        products[i].price = 0;
    }
    
    while (1) {
        printf("\n원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료): ");
        scanf("%d", &choice);
        
        processChoice(choice);
        if (choice == 5) break;
    }
    return 0;
}

void processChoice(int choice) {
    switch (choice) {
        case 1:
            inputProduct();
            break;
        case 2:
            processSales();
            break;
        case 3:
            showIndividualProduct();
            break;
        case 4:
            showAllProducts();
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다.\n");
    }
}

void inputProduct() {
    printf("\n1 << 입고메뉴실행(상품 갯수 조과 시 메시지 출력)\n");
    int id;
    printf("상품ID : ");
    scanf("%d", &id);
    
    if (id < 1 || id > MAX_PRODUCTS) {
        printf("존재하지 않는 상품ID입니다.\n");
        return;
    }
    
    printf("상품명 : ");
    scanf("%s", products[id-1].name);
    printf("입고량 : ");
    scanf("%d", &products[id-1].stock);
    printf("판매가격 : ");
    scanf("%d", &products[id-1].price);
}

void processSales() {
    printf("\n2 << 판매메뉴실행\n");
    int id;
    printf("상품ID : ");
    scanf("%d", &id);
    
    if (id < 1 || id > MAX_PRODUCTS) {
        printf("존재하지 않는 상품ID입니다.\n");
        return;
    }
    
    if (products[id-1].stock == 0) {
        printf("오류메시지 출력\n");
        return;
    }
    
    printf("판매량 : ");
    int salesAmount;
    scanf("%d", &salesAmount);
    
    if (salesAmount <= products[id-1].stock) {
        products[id-1].stock -= salesAmount;
        products[id-1].sold += salesAmount;
        printf("판매가 완료되었습니다.\n");
    } else {
        printf("재고가 부족합니다.\n");
    }
}

void showIndividualProduct() {
    printf("\n3. 개별현황 메뉴 : 상품 ID를 입력받아 상품정보(상품명, 가격,...)를 출력한다.\n");
    int id;
    printf("상품ID : ");
    scanf("%d", &id);
    
    if (id < 1 || id > MAX_PRODUCTS) {
        printf("존재하지 않는 상품ID입니다.\n");
        return;
    }
    
    printf("\n상품정보:\n");
    printf("ID: %d\n", products[id-1].id);
    printf("상품명: %s\n", products[id-1].name);
    printf("가격: %d\n", products[id-1].price);
    printf("재고: %d\n", products[id-1].stock);
    printf("판매량: %d\n", products[id-1].sold);
}

void showAllProducts() {
    printf("\n4. 전체현황 메뉴 : 앞서 개발한 상품현황(판매율...)을 출력한다.\n");
    printf("\n전체 상품 현황:\n");
    printf("ID\t상품명\t\t가격\t재고\t판매량\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].price > 0) {  // 입고된 상품만 표시
            printf("%d\t%-15s\t%d\t%d\t%d\n", 
                products[i].id, 
                products[i].name, 
                products[i].price, 
                products[i].stock, 
                products[i].sold);
        }
    }
    
    // 판매율 계산 및 출력
    int totalSold = 0, totalStock = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        totalSold += products[i].sold;
        totalStock += products[i].stock;
    }
    
    if (totalSold + totalStock > 0) {
        float salesRate = ((float)totalSold / (totalSold + totalStock)) * 100;
        printf("\n총 판매율: %.2f%%\n", salesRate);
    }
}
