#pragma warning(disable:4996)
#include <stdio.h>

int main() {
    int n;
    int total_stock = 0;
    int id;
    int stock[100];
    int sales[100];

    printf("��ǰ�� ���� �Է�: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
    }

    printf("��ǰ ID�� �Է��ϼ���: ");
    scanf("%d", &id);

    if (id >= 1 && id <= n) {
        int current_stock = stock[id - 1] - sales[id - 1];
        printf("��ǰ %d�� ���� ���: %d\n", id, current_stock);
    }
    else {
        printf("�߸��� ��ǰ ID�Դϴ�.\n");
    }

    total_stock = 0; 
    for (int i = 0; i < n; i++) {
        total_stock += stock[i] - sales[i];
    }

    printf("��ü ��ǰ��� ����: %d\n", total_stock);

    return 0;
}

