# 0926 REPORT

---

### 1. 높은 단위부터 출력

- 높은단위부터출력하려면입력된숫자가최대몇자리의정수인지를계산해야하는데이를계산하는방법으로라이브러리함수log10을이용.
- 몇자리숫자인지를계산했다면 단위별숫자로나누어주는데이때$x^y$를계산하는 라이브러리함수pow(x,y)를이용

![image](https://github.com/user-attachments/assets/84f39fd2-4b25-4fb5-a8c9-543d5f8413ae)


```cpp
#include <stdio.h>
#include <string.h>

int main(void)
{
  char number[20];
  int length, i;
  printf("금액을 입력하고 Enter>");
  scanf("%s", number);
  length=strlen(number);
  
  for(i=0;i<length;i++)
     printf("%c\n", number[i]);
     
  return 0;
}
```

### 2. 낮은 단위부터 출력

- 나머지연산자를이용하여10으로나눈나머지를이용

![image 1](https://github.com/user-attachments/assets/3550808a-a858-432b-a01b-884298f205ee)


```cpp
#include <stdio.h>
#include <string.h>

int main(void)
{
  char number[20];
  int length, i;
  printf("금액을 입력하고  Enter>");
  scanf("%s", number);
  length=strlen(number);
  
  for(i=length;i>=0;i--)
     printf("%c\n", number[i]);
     
  return 0;
}
```

### 3. 높은낮은 단위 동시 출력

![image 2](https://github.com/user-attachments/assets/3b5a84eb-806a-472a-a8c4-1cb062f4e20b)


```cpp
#include <stdio.h>
#include <conio.h>
#include <math.h>
void serial_number(long number);
void reverse_number(long number);
int main(void)
{
	long number=12345698;
	printf("입력 숫자 : %ld\n\n", number);
	printf("높은 단위부터 출력\n");
	serial_number(number);
	printf("\n낮은 단위부터 출력\n");
	reverse_number(number);
	 
	printf("press any key to continue.......");
	getch();
	return 0;
} 
void serial_number(long number)
{
	int num;
	int i, length=0;
	length=(int)(log10(number)+1);  //최대 자리수 계산
	for(i=length;i>=1;i--)
	{
		num=number/(long) pow(10, i-1);
		printf("%ld\n", num);
		number=number-num*(long) pow(10,i-1);
	}
	printf("\n");
}
void reverse_number(long number)
{
	while(number>0)
	{
		printf("%ld\n", number%10);
		number/=10;
	}
}
```

### 3. 재귀적 호출을 이용한 높은낮은 단위 동시 출력

![image 3](https://github.com/user-attachments/assets/c84196ce-4cf7-4368-a21e-f3cb7caba9d2)


```cpp
#include<stdio.h>
#include<conio.h>
#include<math.h>
void serial_number(long number);
void reverse_number(long number);

int main(void)
{
	long number=12345698;
	printf("입력 숫자: %ld\n\n", number);
	printf("높은 단위부터 출력\n");
	serial_number(number);
	printf("\n낮은단위부터출력\n");
	reverse_number(number);
	printf("press any key to continue.......");
	getch();
	return 0;
}
void serial_number(long number)
{
	if (number>0)
	{
 		serial_number(number/10);
 		printf("%ld\n", number%10);
 	}
 	else
 		return;
}
void reverse_number(long number)
{
 	printf("%ld\n", number%10);
 	if((number/10)>0)
 		reverse_number(number/10);
 	else
 		return;
}

```

### 4. 디지털 숫자

![image 4](https://github.com/user-attachments/assets/4274a0f0-72bd-4f66-a529-a42d4dff1fd1)

```cpp
#include<stdio.h>

void number_check(int k, int i);
void digit_print(int dim[], int line);

int zero[20] =
	{1,1,1,1,
	1,0,0,1,
	1,0,0,1,
	1,0,0,1,
	1,1,1,1};
	
int one[20]=
	{0,0,1,0,
	0,0,1,0,
	0,0,1,0,
	0,0,1,0,
	0,0,1,0};
	
int two[20]=
	{1,1,1,1,
	0,0,0,1,
	1,1,1,1,
	1,0,0,0,
	1,1,1,1};
	
int three[20]=
	{1,1,1,1,
	0,0,0,1,
	1,1,1,1,
	0,0,0,1,
	1,1,1,1};
	
int four[20]=
	{1,0,0,1,
	1,0,0,1,
	1,1,1,1,
	0,0,0,1,
	0,0,0,1};
	
int five[20]=
	{1,1,1,1,
	1,0,0,0,
	1,1,1,1,
	0,0,0,1,
	1,1,1,1};
	
int six[20]=
	{1,0,0,0,
	1,0,0,0,
	1,1,1,1,
	1,0,0,1,
	1,1,1,1};
	
int seven[20]=
	{1,1,1,1,
	0,0,0,1,
	0,0,0,1,
	0,0,0,1,
	0,0,0,1};
	
int eight[20]=
	{1,1,1,1,
	1,0,0,1,
	1,1,1,1,
	1,0,0,1,
	1,1,1,1};
	
int nine[20] =
	{1,1,1,1,
	1,0,0,1,
	1,1,1,1,
	0,0,0,1,
	0,0,0,1
	};

int main(void)
{
	int num, line;
	printf("디지털 숫자 출력 프로그램\n");
	printf("1 이상의 정수만 입력합니다. \n\n");
	printf("\n정수 숫자입력 후 Enter> ");
	scanf("%d", &num);
	printf("\n\n");
	for(line=0;line<=4;line++)
	{
		number_check(num, line);
		printf("\n");
	}
	return 0;
}
void digit_print(int dim[], int line)
{
	int i;
 	for(i=line*4;i<=line*4+3; i++)
  	if (dim[i]==1)
		printf("■");
  	else
		printf("  ");
 	printf("  ");
}
void number_check(int k, int i)
{
 	if (k>=1)
  	{
    	number_check(k/10, i);
     	switch(k%10)
     	{
        	case 0 :
	  			digit_print(zero, i);
	  			break;
        	case 1 : 
	  			digit_print(one, i);
	  			break;
        	case 2 : 
	  			digit_print(two, i);
	  			break;
        	case 3 : 
	  			digit_print(three, i);
	  			break;
        	case 4 : 
	  			digit_print(four, i);
	  			break;
        	case 5 : 
	  			digit_print(five, i);
	  			break;
        	case 6 : 
	  			digit_print(six, i);
	  			break;
        	case 7 : 
	  			digit_print(seven, i);
	  			break;
        	case 8 : 
	  			digit_print(eight, i);
	  			break;
        	case 9 : 
          		digit_print(nine, i);
	  			break;
     	}
  	}
}

```

### 5. 수평 수직 슬라이드바

- 긴막대부분(bar)의 표시는 사각형을그리는함수draw_rectangle을 이용 화살표키의이동은함수move_arrow_key를, 현재의 크기를 나타낼 검은 사각형부분(슬라이드, slide) 은확장아스키코드에서기호■을사용
- 적당한위치에bar가움직인크기를숫자로나타낸다.
- 좌우방향의화살표키는수평슬라이드바에서의증가(→)와감소(←)를제어하고, 상하방향의화살표키는수직슬라이드바에서증가(↑)와감소(↓)를제어한다고가정 수평과수직슬라이드바의크기는입력값에의해결정하고, 바의표현은직사각형을그리는함수인draw_rectangle을 이용
- 함수에서매개변수char *s는 슬라이드 바의움직임을표시할문자열을의미. 이예에서는특수기호■(완성형)을이용

![image 5](https://github.com/user-attachments/assets/11343fcf-759e-42f6-87eb-3e0265be2ad0)

![image 6](https://github.com/user-attachments/assets/71b7d44b-0887-473a-9a8d-00ab269cd0c9)

### 6. 도형의 연속적 이동과 회전

- 화면에표시된임의의도형을화살표(방향) 키를이용하여연속적으로이동시키거나시계방향또는반시계방향으로회전시키는프로그램

![0926_6](https://github.com/user-attachments/assets/9166667e-ba8c-4252-8437-3e12d3dbe2ab)

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void rotation_right(int m[][3]);
void move_shape(int m[][3]);
void print_shape(int m[][3]);
void move_control(int m[][3]);
void gotoxy(int x, int y);
void print_direction(void);

int x=35, y=12;
int inx=0, iny=0;

int main(void)
{
	int shape1[3][3]= {0,1,0,
			       		0,1,0,
			       		1,1,1};
	move_control(shape1);
	return 0;
}

void rotation_right(int m[][3])
{
	int i, j;
	int temp[3][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			temp[j][2-i]=m[i][j];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m[i][j]=temp[i][j];
}

void print_direction(void)
{
	gotoxy(25, 1);
	printf("화살표:이동,  스페이스 키:회전");
}

void move_control(int m[][3])
{
	char key;
	do
	{
		while(!kbhit())
		{
			system("cls");
			move_shape(m);		
		}
		key=getch();
		switch(key)
		{
			case 32 : 
				rotation_right(m);
				move_shape(m);	
					
				break;
			case 72 : 
				inx=0; iny=-1;
				move_shape(m);
						
				break;
			case 75 : 
				inx=-1; iny=0;
				move_shape(m);
						
				break;
			case 77 : 
				inx=1; iny=0;
				move_shape(m);	
					
				break;
			case 80 : 
				inx=0; iny=1;
				move_shape(m);
						
				break;
			default :
				break;
		}
	}while(key!=27);
	printf("\n");
}

void print_shape(int m[][3])		
{
	int i, j;
	for(i=0;i<3;i++)
	{
		gotoxy(x,y+i);
		for(j=0;j<3;j++)
			if (m[i][j]==1)
				printf("□");
			else
				printf("  ");
		printf("\n");
	}
}

void move_shape(int m[][3])		
{
	do
	{
		system("cls");
		print_shape(m);
		print_direction();
		x=x+inx;
		y=y+iny;
		if (y>23)
			y=23;
		else if (y<2)
			y=2;
		if (x>75)
			x=75;
		else if (x<1)
			x=1;
		Sleep(100);
	}while(!kbhit());
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
```
