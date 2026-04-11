#pragma once

#include "data.h"
#define max_simbols_in_line 512

void u_answer(string& user, int max);
int scan_company(const string& link);
int scan_vacancy(const string& link);
void fill_company(DbCompanies& Db, const string& link);
void fill_vacancy(DbVacancies& Db, const string& link);
void enter_the_vcn(string& users_choice);

