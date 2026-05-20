//#pragma once
//#include <iostream>
//using namespace std;
//
//
//class Vector {
//private:
//	int n;
//	double* arr;
//public:
//	Vector(int n);
//	Vector(const Vector&);
//	~Vector();
//
//	int size() const;
//	double len() const;
//	Vector input();
//	Vector operator+(const Vector&) const;
//	Vector operator-(const Vector&) const;
//	Vector operator*(const double) const;
//	double operator*(const Vector&) const;
//	Vector operator-()const;
//	bool operator == (const Vector&) const;
//	bool operator != (const Vector&) const;
//	Vector& operator = (const Vector&);
//
//	friend ostream& operator << (ostream&, const Vector&);
//	friend istream& operator >> (istream&, Vector&);
//
//	const double& operator[](int)const;
//	double& operator[](int);
//};
//
//
//
//Vector::Vector(int n) {
//	if (n <= 0) {
//		throw("The size is entered incorrectly");
//	}
//
//	this->n = n;
//	this->arr = new double[n];
//	cout << endl << "Create object - " << this << endl;
//}
//
//Vector::Vector(const Vector& V) {
//	this->n = V.n;
//	this->arr = new double[n];
//
//	for (int i = 0; i < n; i++) {
//		this->arr[i] = V.arr[i];
//	}
//}
//
//int Vector::size() const {
//	return this->n;
//}
//
//double Vector::len() const {
//	double summ = 0.0;
//	for (int i = 0; i < this->n; i++) {
//		summ += this->arr[i] * this->arr[i];
//	}
//
//	return sqrt(summ);
//}
//
//Vector Vector:: operator+(const Vector& V) const {
//	if (this->n != V.n) {
//		throw("Different length");
//	}
//
//	Vector res(n);
//
//	for (int i = 0; i < this->n; i++) {
//		res[i] = (*this)[i] + V[i];
//	}
//
//	return res;
//}
//
//Vector Vector:: operator-(const Vector& V) const {
//	if (this->n != V.n) {
//		throw("Different length");
//	}
//
//	return *this + (-V);
//}
//
//Vector Vector:: operator-() const {
//	Vector res(n);
//
//	for (int i = 0; i < this->n; i++) {
//		res[i] = -(this->arr[i]);
//	}
//
//	return res;
//}
//
//Vector Vector:: operator*(const double scalar) const {
//	Vector res(n);
//
//	for (int i = 0; i < this->n; i++) {
//		res[i] = (*this)[i] * scalar;
//	}
//
//	return res;
//}
//
//double Vector:: operator*(const Vector& V) const {
//	if (this->n != V.n) {
//		throw("Different length");
//	}
//
//	int summ = 0.0;
//
//	for (int i = 0; i < this->n; i++) {
//		summ += (*this)[i] * V[i];
//	}
//
//	return summ;
//}
//
//bool Vector:: operator == (const Vector& V) const {
//	if (this->n != V.n) {
//		return false;
//	}
//
//	for (int i = 0; i < this->n; i++) {
//		if ((*this)[i] != V[i]) {
//			return false;
//		}
//	}
//
//	return true;
//}
//
//bool Vector::operator != (const Vector& V) const {
//	return !((*this) == V);
//}
//
//Vector& Vector:: operator=(const Vector& V) {
//	delete[] this->arr;
//	this->n = V.n;
//	this->arr = new double[n];
//
//	for (int i = 0; i < n; i++) {
//		(*this)[i] = V[i];
//	}
//
//	return (*this);
//
//}
//
//double& Vector::operator [](int index) {
//	if (index < 0 || index > n - 1) {
//		throw("There is no such index");
//	}
//
//	return this->arr[index];
//}
//
//std::ostream& operator<<(std::ostream& os, const Vector& v) {
//	os << "[";
//	for (int i = 0; i < v.size(); ++i) {
//		os << v.arr[i];
//		if (i < v.size() - 1) {
//			os << ", ";
//		}
//	}
//	os << "]";
//	return os;
//}
//
//std::istream& operator >> (std::istream& is, Vector& v) {
//	for (int i = 0; i < v.size(); ++i) {
//		is >> v[i];
//		if (!is) break;
//	}
//	return is;
//}
//
//const double& Vector:: operator[](int index) const {
//	if (index < 0 || index > n - 1) {
//		throw("There is no such index");
//	}
//
//	return this->arr[index];
//}
//
//Vector:: ~Vector() {
//	delete[]this->arr;
//	cout << endl << "Delete object - " << this << endl;
//}