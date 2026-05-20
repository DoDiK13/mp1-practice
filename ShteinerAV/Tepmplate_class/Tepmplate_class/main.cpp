#include <iostream>
#include "template.h"
#include "vector.h"

int main() {

	try {
	Container<int> int_c(5, 1);
	Container <double> double_c(2, 2);

	// заполнение
	for (int i = 0; i < int_c.get_size(); i++) {
		int_c.InsertElement(i + 3);
	}
	for (int i = 0; i < int_c.get_size() + 2; i++) {
		double_c.InsertElement(i + 0.25);
	}


	// вывод
	std::cout << int_c << std::endl;
	std::cout << double_c << std :: endl;
	
	std::cout << "-----------------------------------------------------------\n";
	// поиск 
	std::cout << int_c.SearchElement(5) << std::endl;
	std::cout << double_c.SearchElement(2.03) << std::endl;

	std::cout << "-----------------------------------------------------------\n";
	// удаление 
	int_c.DeleteElement(5);
	double_c.DeleteElement(3.25);

	std::cout << int_c << std::endl;
	std::cout << double_c << std::endl;
	

	}
	catch (const std::exception& ex) {
		std::cout << ex.what();
	}
	

	return 0;
}
