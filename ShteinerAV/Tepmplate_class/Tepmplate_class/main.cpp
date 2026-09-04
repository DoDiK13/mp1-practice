#include <iostream>
#include "template.h"

int main() {

	try {
	Container<int> int_c(5, 1);
	Container <double> double_c(2, 2);
	Container <int*> ind_int_c(1, 3);

	int* a = new int(8);
	ind_int_c.InsertElement(a);

	// заполнение
	for (int i = 0; i < 5; i++) {
		int_c.InsertElement(i + 3);
	}
	for (int i = 0; i < 8; i++) {
		double_c.InsertElement(i + 0.25);
	}
	for (int i = 0; i < 5; i++) {
		ind_int_c.InsertElement(a+1);
	}

	// вывод
	std::cout << int_c << std::endl;
	std::cout << double_c << std :: endl;
	std::cout << ind_int_c << std::endl;

	std::cout << "-----------------------------------------------------------\n";
	// поиск 
	std::cout << int_c.SearchElement(5) << std::endl;
	std::cout << double_c.SearchElement(2.03) << std::endl;
	std::cout << ind_int_c.SearchElement(ind_int_c[4]) << std::endl;

	std::cout << "-----------------------------------------------------------\n";
	// удаление 
	int_c.DeleteElement(5);
	double_c.DeleteElement(3.25);
	ind_int_c.DeleteElement(ind_int_c[2]);


	std::cout << int_c << std::endl;
	std::cout << double_c << std::endl;
	std::cout << ind_int_c << std::endl;

	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
	

	return 0;
}
