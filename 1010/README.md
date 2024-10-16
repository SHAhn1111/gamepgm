# 1010 report - 업그레이드

---

원래 타이틀에서 게임시작,조작 정보, 종료만 있었으나 제작자 정보를 추가함

![image](https://github.com/user-attachments/assets/bff4d402-ca05-40a4-9d89-1ef17b716775)

![image 1](https://github.com/user-attachments/assets/04751a2b-9c60-4b76-8166-b85a2b16af6e)


추가한 코드

```cpp
void creatorDraw() {
	system("cls");

	gotoxy(15,3);
	printf("[제작자]");

	gotoxy(13,5);
	printf("2024학년도 2학기");
	gotoxy(11,6);
	printf("게임프로그래밍 과제");
	gotoxy(13,8);
	printf("20학번 안소현");
	gotoxy(9,10);
	printf("원래 소스코드에서 기능을");
	gotoxy(9,11);
	printf("추가&수정해 오목게임 제작");

	gotoxy(11,13);
	printf("스페이스바를 누르면 \n");
	gotoxy(9,14);
	printf("메인화면으로 돌아갑니다.");

	while(1) {
		if(keyControl()==SUBMIT)
			break;
	}
}
```
