# 0912 REPORT

---

### 1. 커서의 위치 제어

- 함수 gotoxy를 이용해서 커서의 위치를 이동시킴

![0912_1](https://github.com/user-attachments/assets/090f4fdc-67b6-4352-84ed-a2e62439cbf4)


```cpp
#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void) {
	gotoxy(2,4);
	printf("Hello");
	gotoxy(40, 20);
	printf("Hello");
	return 0;
}
void gotoxy(int x, int y) {
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
//커서 위치 제어
```

### 2. 커서의 위치 제어 -3단 출력

- 함수 gotxy를 이용해서 커서의 위치를 이동시킴

![image](https://github.com/user-attachments/assets/a374c740-552c-46b6-99c2-e89d5171a33e)


```cpp
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int main(void) {
	for(int i=1; i<=9; i++) {
		gotoxy(35, 5+i);
		printf("%d*%d=%2d",3,i,3*i);
	}
	printf("\n");
	return 0;
}
//3단 출력
```

### 3. 화면 지우기

- system(”cls”);를 이용해 화면 지우기

![image 1](https://github.com/user-attachments/assets/edb2cc15-5510-4b48-a91a-b558164d5710)


![image 2](https://github.com/user-attachments/assets/ee4cdc9f-fb24-45a1-b1bc-e4bfe3762fe8)


```cpp
#include<stdio.h>
#include<stdlib.h>
int main(void) {
	char ch;

	printf("문자를입력하고Enter>");
	scanf("%c", &ch);
	system("cls");
	printf("입력된문자%c\n", ch);
	return 0;

}

```

### 4. 화면 지우기

- system(”cls”);를 이용해 화면 지우기

![0912_4](https://github.com/user-attachments/assets/0fccf330-15f9-4bda-ad32-402fd645b99e)


```cpp
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(void) {
	int i, j;
	for(j=1; j<=9; j++) {
		system("cls");
		for(i=1; i<=9; i++)
			printf("%d*%d=%d\n", j, i, j*i);
		printf("아무키나누르시오.\n");
		getch();
	}
	return 0;
}
```

### 5.  키보드 입력 -  ASCII 코드인지 확장 키인지 확인

- `getch()`를 사용하여 키보드 입력을 처리하고, 입력된 키가 **일반 ASCII 코드인지**, 아니면 **확장 키인지**를 구분하여 출력
- `getch()`는 키보드 입력을 한 번 받을 때 반환값으로 해당 키의 코드(ASCII 또는 확장 코드)를 반환
    - **확장 키**: 기능 키(F1~F12), 화살표 키, Insert, Delete 등 일반 ASCII 코드로 표현할 수 없는 키들
        - 확장 키를 입력하면 먼저 `0` 또는 `0xe0`을 반환
        - 이후 `getch()`를 한 번 더 호출해야 실제 확장 키의 고유 코드를 반환
    - **ASCII 코드**: 영문자, 숫자, 특수 문자, 제어 문자(예: Enter, Backspace 등) 등 표준 ASCII 값(0~127)에 해당하는 키
        - 확장 키가 아니라면 `getch()`는 즉시 ASCII 코드를 반환

![0912_5](https://github.com/user-attachments/assets/5222ee6f-0b80-4b68-b816-6ee21cfc0317)


```cpp
#include <stdio.h>
#include <conio.h>
int main(void) {
	int chr;
	do {
		chr=getch();
		if (chr==0 || chr == 0xe0) {
			chr=getch();
			printf("확장키 code=%d\n", chr);
		} else
			printf("아스키 code=%d\n", chr);
	} while(1);
	return 0;
}
```

### 6. 화살표 키를 이용하여 문자 `'A'`를 콘솔 화면에서 이동시키기

![0912_6](https://github.com/user-attachments/assets/638e39e0-bc80-4a7c-9dc1-da5558fa30b9)


```cpp
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define X_MAX 79
#define Y_MAX 24

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b) {
	switch(key) {
		case 72:  //위쪽(상) 방향의 화살표 키 입력
			*y1=*y1-1;
			if (*y1<1) *y1=1; //y좌표의 최소값
			break;
		case 75:  //왼쪽(좌) 방향의 화살표 키 입력
			*x1=*x1-1;
			if (*x1<1) *x1=1; //x좌표의 최소값
			break;
		case 77:  //오른쪽(우) 방향의 화살표 키 입력
			*x1=*x1+1;
			if (*x1>x_b)  *x1=x_b; //x좌표의 최대값
			break;
		case 80:  //아래쪽(하) 방향의 화살표 키 입력
			*y1=*y1+1;
			if (*y1>y_b)  *y1=y_b; //y좌표의 최대값
			break;
		default:

			return;
	}
}
void gotoxy(int x, int y) {
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main(void) {
	char key;
	int x =10, y =5;
	do {
		gotoxy(x, y);
		printf("A");
		key=getch();
		move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
	} while(key!=27);
	return 0;
}
```

### 7. 사각형 그리기

- 화면에정사각형모양을표시하기위해서기본적으로4개의모서리를나타내는기호를
연속적으로출력하는방법을이용

![image 3](https://github.com/user-attachments/assets/acfe7443-e03e-4d27-b163-741f5323cbeb)


```cpp
#include <stdio.h>
void draw_basic_square(void);
int main(void) {
	draw_basic_square();
	return 0;
}
void draw_basic_square(void) {
	unsigned char a=0xa6, b[7], i;
	for(i=1; i<7; i++)
		b[i]=0xa0+i;
	printf("%c%c", a, b[3]);
	printf("%c%c", a, b[4]);
	printf("\n");
	printf("%c%c", a, b[6]);
	printf("%c%c", a, b[5]);
	printf("\n");
}
```

### 8. 길이가 n인 표준 사각형 그리기

- **기존 코드는 터미널 환경에서 가로 문자와 세로 줄의 픽셀 비율이 다르기 때문에  정사각형으로 출력이 되지 않았음**. 일반적으로 콘솔이나 터미널 환경에서는 한 줄의 세로 높이가 가로 문자 폭보다 크기 때문에 발생 **가로와 세로의 출력 비율을 조정**해서 정사각형처럼 보이도록 만듦
1. **가로 길이 조정**
    - 가로 길이를 `size * 2`로 늘려서 출력되도록 수정
    - `for` 루프에서 `i < size`를 `i < size * 2`로 변경.
2. **내부 공백 조정**
    - 내부 공백 역시 가로 길이에 맞추어 `size * 2`로 늘림
3. **세로는 기존 그대로 유지**
    - 세로 높이는 기존대로 출력했기 때문에, 결과적으로 터미널에서 정사각형처럼 보이게 됨

![image 4](https://github.com/user-attachments/assets/ba057db3-bf24-469c-b3ea-3bcc52b44f18)


```cpp
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

```

### 9. 메뉴 만들기 1

![0912_9](https://github.com/user-attachments/assets/13815401-16b6-4e35-a570-5db134f3a487)


```cpp
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int menu_display(void);
void hamburger(void);
void spaghetti(void);
void press_any_key(void);
int main(void) {
	int c;
	while((c = menu_display()) != 3) {
		switch(c) {
case 1 :
				hamburger();
				break;
case 2 :
				spaghetti();
				break;
			default :
				break;
		}
	}
	return 0;
}

int menu_display(void) {
	int select;
	system("cls");
	printf("간식만들기\n\n");
	printf("1. 햄버거\n");
	printf("2. 스파게티\n");
	printf("3. 프로그램종료\n\n");
	printf("메뉴번호입력>");
	select = getch()-48;
	return select;
}

void hamburger(void) {
	system("cls");
	printf("햄버거만드는방법\n");
	printf("중략\n");
	press_any_key();
}
void spaghetti(void) {
	system("cls");
	printf("스파게티만드는방법\n");
	printf("중략\n");
	press_any_key();
}
void press_any_key(void) {
	printf("\n\n");
	printf("아무키나누르면메인메뉴로...");
	getch();
}

```

### 10. 메뉴 만들기 2

![0912_10](https://github.com/user-attachments/assets/d5429e91-b667-4c54-b247-bf6354d7de7d)


```cpp
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu_display(void);
int sub_menu_display01(void); //햄버거에 대한 서브 메뉴 출력과 번호 입력
int sub_menu_display02(void); //스파게티에 대한 서브 메뉴 출력과 번호 입력
void sub_main01(void); //햄버거에 대한 서브 메뉴 제어
void sub_main02(void); //스파게티에 대한 서브 메뉴 제어

void chicken_burger(void);
void cheese_burger(void);
void tomato_spaghetti(void);
void cream_spaghetti(void);
void press_any_key(void);  //아무키나 누르면 이전 메뉴로

int main(void) {
	int c;
	while((c=menu_display())!=3) {
		switch(c) {
			case 1 :
				sub_main01();
				break;
			case 2 :
				sub_main02();
				break;
			default :
				break;
		}
	}
	return 0;
}

int menu_display(void) {
	int select;
	system("cls");
	printf("간식 만들기\n\n");
	printf("1. 햄버거 \n");
	printf("2. 스파게티\n");
	printf("3. 프로그램 종료\n\n");
	printf("메뉴번호 입력>");
	select=getch()-48;
	return select;
}

int sub_menu_display01(void) {
	int select;
	system("cls");
	printf("햄버거 만들기\n\n");
	printf("1. 치킨버거\n");
	printf("2. 치즈버거\n");
	printf("3. 메인 메뉴로 이동\n\n");
	printf("메뉴번호 입력>");
	select=getch()-48;
	return select;
}

int sub_menu_display02(void) {
	int select;
	system("cls");
	printf("스파게티만들기\n\n");
	printf("1. 토마토스파게티\n");
	printf("2. 크림스파게티\n");
	printf("3. 메인메뉴로이동\n\n");
	printf("메뉴번호입력>");
	select=getch()-48;
	return select;
}

void sub_main01(void) {
	int c;
	while((c=sub_menu_display01())!= 3) {
		switch(c) {
			case 1 :
				chicken_burger();
				break;
			case 2 :
				cheese_burger();
				break;
			default :
				break;
		}
	}
}

void sub_main02(void) {
	int c;
	while((c=sub_menu_display02())!= 3) {
		switch(c) {
			case 1 :
				tomato_spaghetti();
				break;
			case 2 :
				cream_spaghetti();
				break;
			default :
				break;
		}
	}
}

void chicken_burger(void) {
	system("cls");
	printf("치킨버거 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}

void cheese_burger(void) {
	system("cls");
	printf("치즈버거 만드는 방법\n");
	printf("중략\n");
	press_any_key();
}

void tomato_spaghetti(void) {
	system("cls");
	printf("토마토스파게티만드는방법\n");
	printf("중략\n");
	press_any_key();
}

void cream_spaghetti(void) {
	system("cls");
	printf("크림스파게티만드는방법\n");
	printf("중략\n");
	press_any_key();
}

void press_any_key(void) {
	printf("\n\n");
	printf("아무키나누르면이전메뉴로...");
	getch();
}

```

### 11. 주사위 눈금 난수 생성

- rand()%6+1로 1~6 사이의 난수 생성

![image 5](https://github.com/user-attachments/assets/3bbf351c-024d-473a-b4f0-5039788b9e45)


```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	int i;
	srand(time(NULL));
	for(i=1; i<=10; i++)
		printf("%2d:%d\n",i, rand()%6+1);
	return 0;
}
```

### 12. 1부터 45난수 생성

- rand()%45+1로 1~45사이 난수 생성

![image 6](https://github.com/user-attachments/assets/21f15dcd-cc98-423b-8bce-56c40b52ade5)


![image 7](https://github.com/user-attachments/assets/89e633aa-5dae-4f51-b5b0-3e82d3ced4cc)


```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	int i;
	srand(time(NULL));
	for(i=1; i<=6; i++)
		printf("%2d:%d\n",rand()%45+1);
	return 0;
}
```

### 13. 1부터 45 중복없는 난수 생성

![image 8](https://github.com/user-attachments/assets/c85f17c8-958d-4674-bb16-39a300e93ad5)


```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	int i, j, lotto[6];
	srand(time(NULL));
	for(i=0; i<=5; i++) {
		lotto[i]=rand()%45+1;
		for(j=0; j<i; j++) {
			if (lotto[i] == lotto[j]) {
				i--;
				break;
			}
		}
	}
	for(i=0; i<=5; i++)
		printf("%2d\n", lotto[i]);
	return 0;
}
```

### 14. 1부터 45 중복없는 난수 생성 정렬

![image 9](https://github.com/user-attachments/assets/698354e5-cdbf-484a-804d-62706af70425)


```cpp
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selection_sort(int r[], int n);
int main(void) {
	int i, j, lotto[6];
	srand(time(NULL));
	for(i=0; i<=5; i++) {
		lotto[i]=rand()%45+1;
		for(j=0; j<i; j++) {
			if (lotto[i] == lotto[j]) {
				i--;
				break;
			}
		}
	}
	selection_sort(lotto, 6);
	return 0;
}
void selection_sort(int r[], int n) {
	int i, j, min, temp;
	for (i=0; i<=n; i++) {
		min= i;
		for (j=i+1; j<=n; j++)
			if (r[j] < r[min])
				min= j;
		temp= r[min];
		r[min] = r[i];
		r[i] = temp;
	}
	for(i=0; i<=5; i++)
		printf("%2d\n", r[i]);
}

```

### 15. 가변인수

- 가변인수(variable argument)는 함수를 호출할 때 인수의 개수가 고정되어 있지 않고 변할 수 있는인수
- 예를들어함수printf를 사용할때값을출력할변수의개수는경우에따라달라질수있고, 함수scanf
의경우에도입력할변수의개수는고정되어있지않다.

### 주의점

1. **매개변수의 형식**
    - `va_arg`를 사용할 때 반드시 정확한 데이터 형식을 지정해야 함. 예를 들어, 여기서는 `double`로 설정.
2. **인수 개수**
    - 첫 번째 매개변수(`count`)는 가변 인수의 개수를 정확히 나타내야 함. 잘못된 값을 입력하면 프로그램이 올바르게 작동하지 않을 수 있음.
3. **메모리 관리**
    - `va_start`로 초기화한 `va_list`를 `va_end`로 반드시 종료해야 함.

![image 10](https://github.com/user-attachments/assets/fa039fa2-4411-4ffc-a5a0-7b252252819d)


```cpp
#include<stdio.h>
#include<stdarg.h>
double sum(int count, ...);
int main(void) {
	printf("합계= %lf\n", sum(2, 10.5, 20.23));
	printf("합계= %lf\n", sum(5, 10.3, 245.67, 0.51, 198345.764));
	return 0;
}
double sum(int count, ...) {
	double total=0, number;
	int i=0;
	va_list ap;
	va_start(ap, count);
	while(i<count) {
		number=va_arg(ap, double);  //인수의데이터형은double
		total+=number;
		i++;
	}
	va_end(ap);
	return total;
}

```
