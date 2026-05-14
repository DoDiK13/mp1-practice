#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "data.h"

using namespace std;

DbCompanies DbCompanies::find_vacancy(const DbVacancies& vcn_s, const string& users_choice) {
	int cnt = 0;
	for (int i = 0; i < vcn_s.get_size(); i++) {
		if (vcn_s[i].get_name().find(users_choice) != string::npos) {
			cnt++;
		}
	}

	DbCompanies new_comp_s(cnt);

	int k = 0;
	for (int i = 0; i < vcn_s.get_size(); i++) {
		if (vcn_s[i].get_name().find(users_choice) != string::npos) {
			int id = vcn_s[i].get_c_id() - 1;
			new_comp_s[k].set_id(arr[id].get_id());
			new_comp_s[k].set_name(arr[id].get_name());
			new_comp_s[k].set_address(arr[id].get_address());
			k++;
		}
	}
	return new_comp_s;
}

void DbCompanies :: different_company() {
	int i, j, cnt = 0, k = 0;
	for (i = 0; i < this->get_size(); i++) {
		int flag = 1;
		for (j = 0; j < i; j++) {
			if ((*this)[i].get_id() == (*this)[j].get_id()){
				flag = 0;
				break;
			}
		}

		if (flag) {
			cnt++;
		}
	}

	DbCompanies new_valid(cnt);

	for (i = 0; i < (*this).get_size(); i++) {
		int flag = 1;
		for (j = 0; j < i; j++) {
			if ((*this)[i].get_id() == (*this)[j].get_id()) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			new_valid[k].set_id((*this)[i].get_id());
			new_valid[k].set_name((*this)[i].get_name());
			new_valid[k++].set_address((*this)[i].get_address());
		}
	}

	(*this).arr_new_size(cnt);
	
	for (int i = 0; i < k; i++) {
		(*this)[i].set_id(new_valid[i].get_id());
		(*this)[i].set_name(new_valid[i].get_name());
		(*this)[i].set_address(new_valid[i].get_address());
	}

}

//Company
std::ostream& operator << (std::ostream& os, const Company& comp_s) {
	os << comp_s.name << ", ";
	os << comp_s.address << endl;

	return os;
}

//DbCompany
DbCompanies::DbCompanies(int size) {
	this->size = size;
	this->arr = new Company[size];
}

DbCompanies::DbCompanies(const string& link) {
	ifstream file(link);
	string str;
	int cnt = 0;

	if (!file.is_open()) {
		cout << "Opening error 1!\n";
	}

	while (std::getline(file, str)) {
		cnt++;
	}

	cout << "The file1 has been scanned.\n";

	this->size = cnt-1;
	this->arr = new Company[size];

	fill_company(link);
}

DbCompanies::DbCompanies(const DbCompanies& Db) {
	this->size = Db.size;
	this->arr = new Company[size];

	for (int i = 0; i < this->size; i++) {
		this->arr[i] = Db.arr[i];
	}
}

DbCompanies :: ~DbCompanies() {
	delete[]this->arr;
}

Company& DbCompanies :: operator[](int index) {
	if (index < 0 || index > this->size - 1) {
		throw("There is not such index!");
	}

	return this->arr[index];
}

const Company& DbCompanies :: operator[](int index) const {
	if (index < 0 || index > this->size - 1) {
		throw("There is not such index!");
	}

	return this->arr[index];
}

std::ostream& operator << (std::ostream& os, const DbCompanies& Db) {
	int cnt = 1;
	for (int i = 0; i < Db.size; i++) {
		os << "--------------------------------------------------\n" << cnt++ << '.' << Db[i];
	}

	os << "--------------------------------------------------\n";
	return os;
}

void DbCompanies :: arr_new_size(int size) {
	if (this->size != 0) {
		this->size = size;
		delete[] this->arr;
	}
	
	this->size = size;
	this->arr = new Company[size];
}

void DbCompanies :: fill_company(const string& link) {
	ifstream file(link);
	string str;
	int cnt = 0, current_comp = 0;

	if (!file.is_open()) {
		cout << "Opening error 1!\n";
		return;
	}

	std::getline(file, str);
	while (std::getline(file, str)) {
		stringstream ss(str);
		string token = "";

		std::getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		(*this)[current_comp].set_id(stoi(token));

		std::getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		(*this)[current_comp].set_name(token);

		std::getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		(*this)[current_comp++].set_address(token);
	}

}

//Vacancy
std::ostream& operator << (std::ostream& os, const Vacancy& vcn_s) {
	os << "| Name: " << vcn_s.name << endl;
	os << "| Conditions: " << vcn_s.conditions << endl;
	os << "| Requirements: " << vcn_s.requirements << endl;
	os << "| Salary: " << vcn_s.salary << endl << endl;

	return os;
}

// DbVacancy
DbVacancies::DbVacancies(int size) {
	this->size = size;
	this->arr = new Vacancy[size];
}

DbVacancies::DbVacancies(const string& link) {
	ifstream file(link);
	string str;
	int cnt = 0;

	if (!file.is_open()) {
		cout << "Opening error 2!\n";
	}

	while (getline(file, str)) {
		cnt++;
	}

	cout << "The file2 has been scanned.\n";

	this->size = cnt - 1;
	this->arr = new Vacancy[size];

	fill_vacancy(link);
}

DbVacancies :: ~DbVacancies() {
	delete[]this->arr;
}

Vacancy& DbVacancies :: operator[](int index) {
	if (index < 0 || index > this->size - 1) {
		throw("There is not such index!");
	}

	return this->arr[index];
}

const Vacancy& DbVacancies :: operator[](int index) const {
	if (index < 0 || index > this->size - 1) {
		throw("There is not such index!");
	}

	return this->arr[index];
}

DbVacancies::DbVacancies(const DbVacancies& Db) {
	this->size = Db.size;
	this->arr = new Vacancy[size];

	for (int i = 0; i < this->size; i++) {
		this->arr[i] = Db.arr[i];
	}
}

void DbVacancies::print_vacancy(Company& valid_comp) {
	int i;
	system("cls");
	cout << "ID: " << valid_comp.get_id() << "\nCompany: " << valid_comp.get_name() << " " << valid_comp.get_address() << endl;
	cout << "________________________________________\n";
	for (i = 0; i < this->size; i++) {
		if (this->arr[i].get_c_id() == valid_comp.get_id()) {
			cout << this->arr[i];
		}
	}
}

void DbVacancies::fill_vacancy(const string& link) {
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

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		(*this)[current_comp].set_v_id(stoi(token));

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		(*this)[current_comp].set_c_id(stoi(token));

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		(*this)[current_comp].set_name(token);

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		(*this)[current_comp].set_conditions(token);

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		(*this)[current_comp].set_requirements(token);

		getline(ss, token, ';');
		while (token[0] == ' ') token = token.substr(1);
		(*this)[current_comp++].set_salary(stoi(token));
	}
}