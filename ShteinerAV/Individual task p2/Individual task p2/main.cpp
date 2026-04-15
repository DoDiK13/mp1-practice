#include <iostream>
#include <string>
#include "funcs.h"
#include "data.h"

using namespace std;

int main(int argc, char** argv) {
    int flag1 = 0, cnt_company, cnt_vacancy;    

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
        cout << "|  1. Scan the list              |\n";
        cout << "|  2. Search for vacancies       |\n";
        cout << "|  0. Exit                       |\n";
        cout << "|--------------------------------|\n";

        string user1;
        u_answer(user1, 2);
        system("cls");

        if (user1 == "1") {
            cnt_company = scan_company(file1);
            cnt_vacancy = scan_vacancy(file2);
            flag1 = 1;
        }
        else if (user1 == "2") {
            if (flag1 == 0) {
                cout << "The file has not been scanned!\n";
            }
            else {
                DbCompanies comp_s(cnt_company);
                DbVacancies vcn_s(cnt_vacancy);                
                DbCompanies dif_valid_com_s;
                string users_choice, user2;
               
                system("cls");
                fill_company(comp_s, file1);
                fill_vacancy(vcn_s, file2);

                enter_the_vcn(users_choice);
                DbCompanies valid_comp_s = comp_s.find_vacancy(vcn_s, users_choice);
                different_company(valid_comp_s, dif_valid_com_s);

                system("cls");
                cout << dif_valid_com_s;

                if (dif_valid_com_s.size != 0) {
                    u_answer(user2, dif_valid_com_s.size);

                    if (user2 == "0") {
                        break;
                    }
                    else {
                        int id = stoi(user2);
                        vcn_s.print_vacancy(dif_valid_com_s[id - 1]);
                    }
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