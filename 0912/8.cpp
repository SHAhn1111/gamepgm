#include <stdio.h>

void draw_square(int size);

int main(void) {
    int n;
    printf("정사각형 그리기\n\n");
    printf("정사각형의 길이(최대 37)를 입력하고 Enter>");
    scanf("%d", &n);
    draw_square(n);
    return 0;
}

void draw_square(int size) {
    int i, j;

    // 상단 라인
    for(i = 0; i < size; i++) {
        printf("* ");
    }
    printf("\n");

    // 중간 부분
    for(i = 0; i < size - 2; i++) {
        printf("* ");
        for(j = 0; j < size - 2; j++) {
            printf("  ");
        }
        printf("*\n");
    }

    // 하단 라인
    for(i = 0; i < size; i++) {
        printf("* ");
    }
    printf("\n");
}

