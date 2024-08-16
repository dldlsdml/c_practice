#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main_numberMaster(void) {
	srand(time(NULL));

	int count = 0;
	for (int i = 1; i <= 5; i++) {
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		showQuestion(i, num1, num2);
		int answer = -1;
		scanf_s("%d", &answer);
		if (answer == -1) {
			printf("closed\n");
			exit(0);
		}
		else if (answer == num1 * num2) {
			success();
			count++;
		}
		else {
			fail();
			printf("answer is'%d'\n\n", (num1 * num2));
		}

	}
	printf("\n\n You got %d questions right\n", count);
	return 0;
}
int getRandomNumber(int level) {
	return rand() % (level * 9) + 1;
}
void showQuestion(int level, int num1, int num2) {
	printf("Question level %d \n", level);
	printf("\t% d x % d = ? \t \n", num1, num2);
	printf("\t Enter your answer(If you want to quit this quiz, then enter '-1') >> \n");
	printf("----------------------------------------\n");

}
void success() {
	printf("\n!Correct!\n");
}
void fail() {
	printf("\n!Wrong!\n");
}