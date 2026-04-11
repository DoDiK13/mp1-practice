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

int scan_company(const string& link) {
	ifstream file(link);
	string str;
	int cnt = 0;

	if (!file.is_open()) {
		cout << "Opening error 1!\n";
		return 1;
	}

	while (getline(file, str)) {
		cnt++;
	}

	cout << "The file1 has been scanned.\n";

	return cnt - 1;
}

int scan_vacancy(const string& link) {
	ifstream file(link);
	string str ;
	int cnt = 0;

	if (!file.is_open()) {
		cout << "Opening error 2!\n";
		return 1;
	}

	while (getline(file, str)) {
		cnt++;
	}

	cout << "The file2 has been scanned.\n";

	return cnt - 1;
}

void fill_company(DbCompanies& Db, const string& link) {
	ifstream file(link);
	string str;
	int cnt = 0, current_comp = 0;

	if (!file.is_open()) {
		cout << "Opening error 1!\n";
		return;
	}

	getline(file, str);
	while (getline(file, str)) {
		stringstream ss(str);
		string token = "";

		Db[current_comp].company_id = 0;
		Db[current_comp].name = "";
		Db[current_comp].address = "";

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		Db[current_comp].company_id = stoi(token);

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		Db[current_comp].name = token;

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		Db[current_comp++].address = token;

	}

}

void fill_vacancy(DbVacancies& Db, const string& link) {
	ifstream file(link);
	string str;
	int cnt = 0, current_comp = 0;

	if (!file.is_open()) {
		cout << "Opening error 1!\n";
		return;
	}

	getline(file, str);
	while (getline(file, str)) {
		stringstream ss(str);
		string token = "";
		
		Db[current_comp].vacancy_id = 0;
		Db[current_comp].company_id = 0;
		Db[current_comp].name = "";
		Db[current_comp].conditions = "";
		Db[current_comp].requirements = "";
		Db[current_comp].salary = 0.0;

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		Db[current_comp].vacancy_id = stoi(token);

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		Db[current_comp].company_id = stoi(token);

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		Db[current_comp].name = token;

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		Db[current_comp].conditions = token;

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		Db.arr[current_comp].requirements = token;

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		Db.arr[current_comp++].salary = stoi(token);
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
