#pragma once
#ifndef SOURCECODE_H
#define SOURCECODE_H

#include <iostream>

int string2int(std::string extracted_string, int x = 0);
bool validate_user_string(int whatnum, int& hours, int& mins);
void ValidateUserInput(int whatnum, int& hours, int& mins);
int HowManyMinutes(int fH, int fM, int sH, int sM);
int HowManyHoursAndMins(int x, int fH, int fM, int sH, int sM);
double HowManyHoursAndMinsWithDecimal(int fH, int fM, int sH, int sM);
bool NumberRangeCheck(int lowerbound, int upperbound, double testsubject);
std::string NeedPrintZero(int thenum, bool needstring);

#endif