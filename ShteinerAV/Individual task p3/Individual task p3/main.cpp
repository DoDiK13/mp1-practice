#include <iostream>
#include <string>
#include "funcs.h"
#include "data.h"

using namespace std;

int main(int argc, char** argv) {

    if (argc < 3) {
        cout << "Incorrect number of arguments";
        return 1;
    }
    string file1 = string(argv[1]);
    string file2 = string(argv[2]);

    do {
        system("cls");
        cout << "|--------------------------------|\n";
        cout << "|      SEARCH FOR VACANCIES      |\n";
        cout << "|--------------------------------|\n";
        cout << "|  1. Search for vacancies       |\n";
        cout << "|  0. Exit                       |\n";
        cout << "|--------------------------------|\n";

        string user1;
        u_answer(user1, 2);
        system("cls");

        if (user1 == "1") {
            
            DbCompanies comp_s(file1);
            DbVacancies vcn_s(file2);
            DbCompanies dif_valid_com_s;
            string users_choice, user2;

            system("cls");

            enter_the_vcn(users_choice);
            DbCompanies valid_comp_s = comp_s.find_vacancy(vcn_s, users_choice);
            valid_comp_s.different_company();

            system("cls");
            cout << valid_comp_s;

            if (valid_comp_s.get_size() != 0) {
                u_answer(user2, valid_comp_s.get_size());

                if (user2 == "0") {
                    break;
                }
                else {
                    int id = stoi(user2);
                    vcn_s.print_vacancy(valid_comp_s[id - 1]);
          
                }
            }
        }
        else {
            break;
        }
        system("pause");
    } while (1);

    cout << "End of the program";
    return 0;
}