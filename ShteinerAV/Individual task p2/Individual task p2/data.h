#pragma once

#include <string>
using namespace std;

struct Company{
	int company_id;
	string name;
	string address;
	
	friend ostream& operator << ( ostream&, const Company&);
};

struct Vacancy {
	int vacancy_id;
	int company_id;
	string name;
	string conditions;
	string requirements;
	float salary;
	
	friend ostream& operator << (ostream&, const Vacancy&);
};

struct DbCompanies {
	Company* arr;
	int size;

	DbCompanies() : arr(nullptr), size(0) {}
	DbCompanies(int size);
	DbCompanies(const DbCompanies& Db);

	~DbCompanies();

	Company& operator[](int);
	const Company& operator[](int) const;

	friend std::ostream& operator <<(std::ostream&, const DbCompanies&);
};

struct DbVacancies {
	Vacancy* arr;
	int size;

	DbVacancies() : arr(nullptr), size(0) {}
	DbVacancies(){}
	DbVacancies(int size);
	DbVacancies(const DbVacancies& Db);

	~DbVacancies();
	
	Vacancy& operator[](int);
	const Vacancy& operator[](int) const;
	void print_vacancy(Company&); 
};


void find_vacancy(const DbCompanies& comp_s, const DbVacancies& vcn_s,
	DbCompanies& new_comp_s,const string& users_choice);
void different_company(const DbCompanies& old_valid, DbCompanies& new_valid);
