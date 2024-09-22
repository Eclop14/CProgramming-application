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
        printf("�޴��� �����ϼ���: ");
        scanf("%d", &choice);
        processChoice(choice);
        if (choice == 4) break;
    }
    return 0;
}

void displayMenu() {
    printf("1. �԰� 2. �Ǹ� 3. ��ǰ��Ȳ 4. ����\n");
}

void processChoice(int choice) {
    switch (choice) {
    case 1:
        inputData(1);  // �԰�
        break;
    case 2:
        inputData(2);  // �Ǹ�
        break;
    case 3:            //������
        calculateStats();
        break;
    case 4:
        printf("���α׷��� �����մϴ�.\n");
        break;
    default:
        printf("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n");
    }
}

void inputData(int type) {
    if (productCount == 0) {
        printf("��ǰ ����: ");
        scanf("%d", &productCount);
    }

    printf("%s\n", type == 1 ? "�԰�" : "�Ǹ�");
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

    printf("������: ");
    for (int i = 0; i < productCount; i++) {
        printf("%d ", products[i].stock);
    }
    printf("\n�� ������: %d\n", totalStock);
    printf("�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", totalSold, (float)totalSold / (totalStock + totalSold) * 100);

    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", maxId, maxSold);
    printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", minId, minSold);

    printf("\n��� ���� ���:\n");
    for (int i = 0; i < productCount; i++) {
        if (products[i].stock <= 2) {
            printf("��ǰ ID %d: ������(%d)\n", products[i].id, products[i].stock);
        }
    }

}