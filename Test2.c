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

// ���� ����
struct Product products[MAX_PRODUCTS];
int productCount = 0;

// �Լ� ����
void inputData();
void calculateStats();


int main() {
    inputData();
    calculateStats();
    return 0;
}

void inputData() {
    int productId, incoming, outgoing;

  
    printf("��ǰ ����:");
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

    printf("������:");
    for (int i = 0; i < productCount; i++) {
        printf("%d ", products[i].stock);
    }

    printf("\n�� ������: %d\n", totalStock);
    printf("�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", totalSold, (float)totalSold / (totalStock + totalSold) * 100);

 
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

    printf("\n���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", maxId, maxSold);
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", minId, minSold);

    // ��� ���� ���
    printf("\n��� ���� ���:\n");
    for (int i = 0; i < productCount; i++) {
        if (products[i].stock <= 2) {
            printf("��ǰ ID %d:\t������(%d)\n", products[i].id, products[i].stock);
        }
    }
}
