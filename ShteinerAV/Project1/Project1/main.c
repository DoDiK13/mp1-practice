#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define DEBUG

int* user_input() {
	int static arr[5];

	for (int i = 0; i < 5; i++) {
		printf("Число %d: ", i + 1);
		scanf_s("%d", &arr[i]);
		getchar();

		while (arr[i] < 0 || arr[i] > 9) {
			printf("\nТы ввёл число неверно! Попробуй ещё раз.\n");
			printf("Число %d: ", i + 1);
			scanf_s("%d", &arr[i]);
			getchar();
		}
	}

	return arr;
}

int find(int arr[], int size, int target) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] == target) {
			return 1;
		}
	}

	return 0;
}

int main() {
	setlocale(LC_ALL, "rus");
	srand((unsigned int)time(0));

	int digget[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int generate_arr[5];
	int is_play = 1, cnt_try = 0, len;

	len = 1 + rand() % 4;

	//Генерация чисел с рандомными неповторяющимися элементами
	for (int i = 0; i < len; i++) {
		int number = rand() % 10;
		if (i == 0 && number == 0) {
			number = 1 + rand() % 9;
		}
		while (digget[number] != 0) {
			number = rand() % 10;
		}
		digget[number] = 1;
		generate_arr[i] = number;
	}

	int user_num;
	int user_arr[len];

	scanf_s("%d", &user_num);

	int i = len - 1;
	while (user_num != 0) {
		user_arr[i--] = user_num % 10;
		user_num /= 10;
	}



#ifdef DEBUG
	printf("***Загаданная комбинация - ");
	for (int i = 0; i < 5; i++) {
		printf("%d", generate_arr[i]);
	}
	printf("***\n--------------------------------------\n");
#endif 

	do {
		int cnt_bulls = 0, cnt_cows = 0;
		cnt_try += 1;

		for (int i = 0; i < 5; i++) {

			if (generate_arr[i] == user_nums[i]) {
				cnt_bulls += 1;
			}
			else if (find(generate_arr, 5, user_nums[i])) {
				cnt_cows += 1;
			}

		}

		if (cnt_bulls == 5) {
			is_play = 0;
		}

		printf("\n");
		for (int i = 0; i < 5; i++) {
			printf("%d", user_nums[i]);
		}

		printf("\nКол-во быков: %d\n", cnt_bulls);
		printf("Кол-во коров: %d\n--------------------------------------\n", cnt_cows);

	} while (is_play);

	printf("Ты выйграл за %d попыток!", cnt_try);

	return 777;
}