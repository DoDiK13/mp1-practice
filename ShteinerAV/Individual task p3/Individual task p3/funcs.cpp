#include <iostream>
#include <string>
#include <fstream>
#include <sstream>  
#include "funcs.h"
using namespace std;

void u_answer(string& user, int max) {
	int choice;
	char c;

	while (1) {
		int cnt = 0, is_valid = 1, i;
		cout << "Enter your choice: ";
		cin >> user;

		while ((c = getchar()) != '\n') {
			cnt++;
		}

		for (i = 0; user[i] != '\0'; i++) {
			if (!isdigit(user[i])) {
				is_valid = 0;
				break;
			}
		}

		if (user[0] == '\0') {
			is_valid = 0;
		}

		if (is_valid && cnt == 0) {
			choice = stoi(user);
			if (choice >= 0 && choice <= max) {
				break;
			}
		}

		cout << "The command was entered incorrectly!\n\n";
	}
}

void enter_the_vcn(string& users_choice) {
	while (1) {
		int i, flag = 0, cnt = 0, c = 0;

		cout << "Enter the post to search: ";
		cin >> users_choice;

		while ((c = getchar()) != '\n') cnt++;

		for (i = 0; i < users_choice.length(); i++) {
			if (users_choice[i] < 65 || (users_choice[i] > 90 && users_choice[i] < 97) || users_choice[i] > 122) {
				flag = 1;
				break;
			}
		}

		if (flag == 1 || cnt != 0) {
			cout << "Input error!\n";
		}
		else {
			break;
		}
	}
}
