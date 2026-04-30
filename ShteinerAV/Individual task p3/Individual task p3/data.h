#pragma once

#include <string>
using namespace std;

class Company {
private:	
	int company_id;
	string name;
	string address;
public:
	Company(): company_id(0), name(""), address("") {}
	void set_id(int id) { this->company_id = id; }
	void set_name(string name) { this->name = name; }
	void set_address(string address) { this->address = address; }

	int get_id() const { return company_id; }
	string get_name() const { return name; }
	string get_address() const { return address; }
	
	friend ostream& operator << (ostream&, const Company&);
};

struct Vacancy {
private:
	int vacancy_id;
	int company_id;
	string name;
	string conditions;
	string requirements;
	float salary;
public:
	Vacancy() : vacancy_id(0), company_id(0), name(""), conditions(""), requirements(""), salary(0.0) {}
	void set_v_id(int id) { vacancy_id = id; }
	void set_c_id(int id) { company_id = id; }
	void set_name(string name) { this->name = name; }
	void set_conditions(string conditions) { this->conditions = conditions; }
	void set_requirements(string requirements) { this->requirements = requirements; }
	void set_salary(float salary) { this->salary = salary; }
	
	int get_v_id() const { return vacancy_id; }
	int get_c_id() const { return company_id; }
	string get_name() const { return name; }
	string get_conditions() const { return conditions; }
	string get_requirements() const { return requirements; }
	float get_salary() const { return salary; }

	friend ostream& operator << (ostream&, const Vacancy&);
};

struct DbVacancies;

struct DbCompanies {
private:
	Company* arr;
	int size;
public:
	DbCompanies() : arr(nullptr), size(0) {}
	DbCompanies(int size);
	DbCompanies(const DbCompanies& Db);
	~DbCompanies();

	DbCompanies find_vacancy(const DbVacancies&, const string&);
	void different_company();
	int get_size() const { return size; }
	void arr_new_size(int size);

	friend std::ostream& operator <<(std::ostream&, const DbCompanies&);
	Company& operator[](int);
	const Company& operator[](int) const;
};

class DbVacancies {
private:
	Vacancy* arr;
	int size;
public:
	DbVacancies() : arr(nullptr), size(0) {}
	DbVacancies(int size);
	DbVacancies(const DbVacancies& Db);
	~DbVacancies();

	void print_vacancy(Company&);
	int get_size() const { return size; }

	Vacancy& operator[](int);
	const Vacancy& operator[](int) const;
};
