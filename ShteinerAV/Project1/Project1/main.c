#include <stdio.h>
#include <locale.h>
#define n 9
//#define FIND_BAR
//#define REVERSE
//#define KOL_DIFFERENT
//#define SAM_WORK
//#define BIN_FIND
//#define KOL_SIMILAR
//#define ARRAY_DIFFERENT


int main() {
	setlocale(LC_ALL, "rus");
#ifdef FIND_BAR
	// ПОИСК ЭЛЕМЕНТОВ С БАРЬЕРОМ
	int arr[n + 1], i, target, orig_elem;

	printf("Введи %d символов в список:\n", n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	printf("Введите число, которое будем искать: ");
	scanf_s("%d", &target);

	arr[n] = target;

	i = 0;
	while (arr[i] != target) {
		i++;
	}

	if (i < n - 1) {
		printf("%d", i);
	}
	else {
		printf("Нет элемента");
	}
#endif

#ifdef REVERSE
	int arr[n];

	printf("Введите %d элементов\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n / 2; i++) {
		int buf = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = buf;
	}

	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
	}

#endif

#ifdef KOL_DIFFERENT
	int arr[n], cnt = 1;

	printf("Введите %d элементов\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 1; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] == arr[i]) {
				flag = 0;
				break;
			}
		}
		cnt += flag;
	}

	printf("Кол-во различных чисел: %d", cnt);
#endif

#ifdef SAM_WORK
	int num1, num2 = 0;
	int arr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	printf("Введи число: ");
	scanf_s("%d", &num1);

	while (num1 > 0) {
		arr[(num1 % 10) - 1]++;
		num1 /= 10;
	}

	for (int i = 8; i >= 0; i--) {
		num2 += arr[i];
		num2 *= 10;
	}

	num2 /= 10;
	printf("%d", num2);
#endif

#ifdef BIN_FIND
	int arr[n], i, right = n - 1, left = 0, mid, target, id = -1;

	printf("Введи %d символов в список:\n", n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	printf("Введи искомое число: ");
	scanf_s("%d", &target);

	while (left <= right) {
		mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			id = mid;
			break;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	if (id >= 0) {
		printf("Число %d находится на индексе %d", arr[id], id);
	}
	else {
		printf("Такого числа нету!");
	}

#endif

#ifdef KOL_SIMILAR
	int arr[n];

	printf("Введите %d элементов\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int cnt = 1, flag = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] == arr[j]) {
					cnt++;
				}
			}
			printf("%d - %d ", arr[i], cnt);
		}
	}
#endif

#ifdef ARRAY_DIFFERENT
	int arr[n], new_arr[n], id_n = 0;

	printf("Введите %d элементов\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			new_arr[id_n++] = arr[i];
		}
	}

	for (int i = 0; i < id_n; i++) {
		printf("%d", new_arr[i]);
	}
#endif

	return 0;
}