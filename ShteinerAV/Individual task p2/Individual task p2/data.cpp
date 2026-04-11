#include <iostream>
#include <string>
#include "data.h"

using namespace std;

void find_vacancy(const DbCompanies& comp_s,const DbVacancies& vcn_s, DbCompanies& new_comp_s,const string& users_choice) {
	int cnt = 0;
	for (int i = 0; i < vcn_s.size; i++) {
		if (vcn_s[i].name.find(users_choice) != string::npos) {
			cnt++;
		}
	}

	new_comp_s.size = cnt;
	new_comp_s.arr = new Company[cnt];

	int k = 0;
	for (int i = 0; i < vcn_s.size; i++) {
		if (vcn_s[i].name.find(users_choice) != string::npos) {
			int id = vcn_s[i].company_id - 1;
			new_comp_s[k].company_id = comp_s[id].company_id;
			new_comp_s[k].name = comp_s[id].name;
			new_comp_s[k].address = comp_s[id].address;
			k++;
		}
	}
}

void different_company(const DbCompanies& old_valid, DbCompanies& new_valid) {
	int i, j, cnt = 0, k = 0;
	for (i = 0; i < old_valid.size; i++) {
		int flag = 1;
		for (j = 0; j < i; j++) {
			if (old_valid[i].company_id == old_valid[j].company_id) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			cnt++;
		}
	}

	new_valid.size = cnt;
	new_valid.arr = new Company[cnt];

	for (i = 0; i < old_valid.size; i++) {
		int flag = 1;
		for (j = 0; j < i; j++) {
			if (old_valid[i].company_id == old_valid[j].company_id) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			new_valid[k].company_id = old_valid[i].company_id;
			new_valid[k].name = old_valid[i].name;
			new_valid[k++].address = old_valid[i].address;
		}
	}
}

//Company
std::ostream& operator << (std::ostream& os, const Company& comp_s) {
	os << comp_s.name << ", ";
	os << comp_s.address << endl;

	return os;
}

//DbCompany
DbCompanies :: DbCompanies(int size) {
	this->size = size;
	this->arr = new Company[size];
}

DbCompanies::DbCompanies(const DbCompanies& Db) {
	this->size = Db.size;
	this->arr = new Company[size];

	for (int i = 0; i < this->size; i++) {
		this->arr[i] = Db.arr[i];
	}
}

DbCompanies :: ~DbCompanies() {
	delete []this->arr;
}

Company& DbCompanies :: operator[](int index) {
	if (index < 0 || index > this->size-1) {
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

DbVacancies :: ~DbVacancies() {
	delete[]this->arr;
}

Vacancy& DbVacancies :: operator[](int index) {
	if (index < 0 || index > this->size - 1) {
		throw("There is not such index!");
	}

	return this->arr[index];
}

const Vacancy& DbVacancies :: operator[](int index) const{
	if (index < 0 || index > this->size - 1) {
		throw("There is not such index!");
	}

	return this->arr[index];
}

void DbVacancies::print_vacancy(Company& valid_comp) {
	int i;
	system("cls");
	cout << "ID: " << valid_comp.company_id << "\nCompany: " << valid_comp.name << " " << valid_comp.address << endl;
	cout << "________________________________________\n";
	for (i = 0; i < this->size; i++) {
		if (this->arr[i].company_id == valid_comp.company_id) {
			cout << this->arr[i];
		}
	}
}