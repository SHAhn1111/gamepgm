#include <stdio.h>

void draw_square(int size);

int main(void) {
    int n;
    printf("���簢�� �׸���\n\n");
    printf("���簢���� ����(�ִ� 37)�� �Է��ϰ� Enter>");
    scanf("%d", &n);
    draw_square(n);
    return 0;
}

void draw_square(int size) {
    int i, j;

    // ��� ����
    for(i = 0; i < size; i++) {
        printf("* ");
    }
    printf("\n");

    // �߰� �κ�
    for(i = 0; i < size - 2; i++) {
        printf("* ");
        for(j = 0; j < size - 2; j++) {
            printf("  ");
        }
        printf("*\n");
    }

    // �ϴ� ����
    for(i = 0; i < size; i++) {
        printf("* ");
    }
    printf("\n");
}

