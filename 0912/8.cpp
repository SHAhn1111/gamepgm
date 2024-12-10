#include <stdio.h>

void draw_square(int size);

int main(void) {
    int n;
    printf("정사각형그리기\n\n");
    printf("정사각형의길이(최대37)를\n");
    printf("입력하고Enter>");
    scanf("%d", &n);
    
    // 입력 값 검증
    if (n < 1 || n > 37) {
        printf("1에서 37 사이의 값을 입력하세요.\n");
        return 1;
    }
    
    draw_square(n);
    return 0;
}

void draw_square(int size) {
    int i, j;

    // 상단 테두리 출력
    printf("┌");
    for (i = 0; i < size * 2; i++) { // 가로 길이를 2배로 늘림
        printf("─");
    }
    printf("┐\n");

    // 정사각형 내부 출력
    for (i = 0; i < size; i++) {
        printf("│"); // 좌측 테두리
        for (j = 0; j < size * 2; j++) { // 가로 공백을 2배로 늘림
            printf(" ");
        }
        printf("│\n"); // 우측 테두리
    }

    // 하단 테두리 출력
    printf("└");
    for (i = 0; i < size * 2; i++) { // 가로 길이를 2배로 늘림
        printf("─");
    }
    printf("┘\n");
}
