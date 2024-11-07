#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_PRODUCTS 5
#define FILENAME "products.txt"

// 상품 구조체 정의
struct Product {
    int id;
    char name[50];
    int price;
    int stock;
    int sold;
};

// 전역 변수 선언
struct Product products[MAX_PRODUCTS];
int totalStock = 0;

// 함수 선언
void displayMenu();
void processChoice(int choice);
void inputProduct();
void processSales();
void showIndividualProduct();
void showAllProducts();
void saveToFile();
void loadFromFile();
void initializeProducts();
void clearInputBuffer();

// 초기화 함수
void initializeProducts() {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i].id = i + 1;
        products[i].stock = 0;
        products[i].sold = 0;
        sprintf(products[i].name, "상품명%d", i + 1);
        products[i].price = 0;
    }
}

// 입력 버퍼를 비우는 함수
void clearInputBuffer() {
    while (getchar() != '\n');
}

// 파일 저장 함수
void saveToFile() {
    FILE* fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }
    
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        fprintf(fp, "%d|%s|%d|%d|%d\n",
            products[i].id,
            products[i].name,
            products[i].price,
            products[i].stock,
            products[i].sold
        );
    }
    
    fclose(fp);
}

// 파일 로드 함수
void loadFromFile() {
    FILE* fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("파일이 존재하지 않습니다. 새로운 데이터를 생성합니다.\n");
        initializeProducts();
        return;
    }
    
    char line[256];
    int i = 0;
    totalStock = 0;
    
    while (fgets(line, sizeof(line), fp) && i < MAX_PRODUCTS) {
        char name_temp[50];
        sscanf(line, "%d|%[^|]|%d|%d|%d",
            &products[i].id,
            name_temp,
            &products[i].price,
            &products[i].stock,
            &products[i].sold
        );
        strcpy(products[i].name, name_temp);
        totalStock += products[i].stock;
        i++;
    }
    
    if (i < MAX_PRODUCTS) {
        for (; i < MAX_PRODUCTS; i++) {
            products[i].id = i + 1;
            products[i].stock = 0;
            products[i].sold = 0;
            sprintf(products[i].name, "상품명%d", i + 1);
            products[i].price = 0;
        }
    }
    
    fclose(fp);
}

// 입고 처리 함수
void inputProduct() {
    printf("\n1 << 입고메뉴실행(상품 갯수 초과 시 메시지 출력)\n");
    int id;
    printf("상품ID : ");
    scanf("%d", &id);
    clearInputBuffer();
    /*
    if (id < 1 || id > MAX_PRODUCTS) {
        printf("존재하지 않는 상품ID입니다.\n");
        return;
    }
    */
    printf("상품명 : ");
    fgets(products[id-1].name, sizeof(products[id-1].name), stdin);
    products[id-1].name[strcspn(products[id-1].name, "\n")] = 0;
    
    printf("입고량 : ");
    scanf("%d", &products[id-1].stock);
    clearInputBuffer();
    
    printf("판매가격 : ");
    scanf("%d", &products[id-1].price);
    clearInputBuffer();
    
    totalStock += products[id-1].stock;
    printf("입고가 완료되었습니다.\n");
    
    saveToFile();
}

// 판매 처리 함수
void processSales() {
    printf("\n2 << 판매메뉴실행\n");
    int id;
    printf("상품ID : ");
    scanf("%d", &id);
    clearInputBuffer();
    
    if (id < 1 || id > MAX_PRODUCTS) {
        printf("존재하지 않는 상품ID입니다.\n");
        return;
    }
    
    if (products[id-1].stock == 0) {
        printf("재고가 없습니다.\n");
        return;
    }
    
    printf("판매량 : ");
    int salesAmount;
    scanf("%d", &salesAmount);
    clearInputBuffer();
    
    if (salesAmount <= products[id-1].stock) {
        products[id-1].stock -= salesAmount;
        products[id-1].sold += salesAmount;
        totalStock -= salesAmount;
        printf("판매가 완료되었습니다.\n");
    } else {
        printf("재고가 부족합니다.\n");
    }
    
    saveToFile();
}

// 개별 상품 조회 함수
void showIndividualProduct() {
    printf("\n3. 개별현황 메뉴\n");
    int id;
    printf("상품ID : ");
    scanf("%d", &id);
    clearInputBuffer();
    
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

// 전체 상품 현황 조회 함수
void showAllProducts() {
    printf("\n4. 전체현황 메뉴\n");
    printf("\n전체 상품 현황:\n");
    printf("ID\t상품명\t\t가격\t재고\t판매량\n");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].price > 0) {
            printf("%d\t%-15s\t%d\t%d\t%d\n", 
                products[i].id, 
                products[i].name, 
                products[i].price, 
                products[i].stock, 
                products[i].sold);
        }
    }
    
    int totalSold = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        totalSold += products[i].sold;
    }
    
    if (totalSold + totalStock > 0) {
        float salesRate = ((float)totalSold / (totalSold + totalStock)) * 100;
        printf("\n총 판매율: %.2f%%\n", salesRate);
    }
}

// 메뉴 처리 함수
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

// 메인 함수
int main() {
    int choice;
    
    loadFromFile();
    
    while (1) {
        printf("\n원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료): ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        processChoice(choice);
        if (choice == 5) break;
    }
    
    return 0;
}
