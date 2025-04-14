//this is where the functions are
#include <iostream>
#include <string>
#include <sstream>

std::string NeedPrintZero(int thenum, bool needstring = true) {
    if (thenum < 10 && needstring) {
        return ("0" + std::to_string(thenum));
    }
    else if (needstring) {
        return std::to_string(thenum);
    }
    else {
        return "";
    }
}
bool NumberRangeCheck(int lowerbound, int upperbound, double testsubject) {
    if (testsubject >= lowerbound && testsubject <= upperbound) {
        return true;
    }
    else if (testsubject < lowerbound) {
        return false;
    }
    else if (testsubject > upperbound) {
        return false;
    }
    else {
        //fail case, should in practice be impossible to reach...
        std::cout << "Critical failure, numbers or testsubject doesn't exist!";
        return false;
    }
}
int string2int(std::string extracted_string, int x = 0) {
    int tempint = 0;
    std::string TempValueStr = extracted_string.substr(x, 2);
    std::istringstream isstemp(TempValueStr);
    isstemp >> tempint;
    return tempint;
}
bool validate_user_string(int whatnum, int& hours, int& mins)
{
    std::string user_input;
    std::cout << "What is time #" << whatnum << ": ";
    std::getline(std::cin, user_input);
    if (user_input.length() != 5) {
        return true;
    }
    else if (user_input.at(2) != ':') {
        return true;
    }
    else {
        //correct user input
        hours = string2int(user_input);
        if (hours == 0 && user_input.substr(0,2) != "00") {
            //checks if the hour is 0 via it not being a valid input
            return true;
        }
        //continues on if the hours is a valid input.
        if (NumberRangeCheck(0, 24, hours)) {
            mins = string2int(user_input, 3);
            if (mins == 0 && user_input.substr(3, 2) != "00") {
                //checks if the mins is 0 via it not being a valid input
                return true;
            }
            if (hours == 24 && mins > 0) {
                return true;
            }
            if (NumberRangeCheck(0, 59, mins)) {
                //validates minutes
                return false;
            }
        }
        else {
            return true;
        }

    }
}
void ValidateUserInput(int whatnum, int& hours, int& mins) {
    bool UserInvalidInput = true;
    while (UserInvalidInput)
    {
        if (validate_user_string(whatnum, hours, mins)) {
            std::cout << "\nInvalid Input! Please only enter your time in XX:XX formatting...\nTry again!\n";
        }
        else {
            UserInvalidInput = false;
        }
    }
}
int HowManyMinutes(int fH, int fM, int sH, int sM) {
    int totaltimeFirst = (fH * 60) + fM;
    int totaltimeSecond = (sH * 60) + sM;
    int time_difference = totaltimeSecond - totaltimeFirst;
    if (time_difference < 0) {
        time_difference += 1440;
    }
    return time_difference;
}
int HowManyHoursAndMins(int x, int fH, int fM, int sH, int sM) {
    int totaltime = HowManyMinutes(fH, fM, sH, sM);
    int hours = 0;
    for (; 60 <= totaltime; hours++) {
        totaltime = (totaltime - 60);
    }
    if (x == 0) {
        if (hours < 0) {
            hours += 24;
        }
        std::cout << NeedPrintZero(hours, false);
        return hours;
    }
    else
    {
        if (totaltime < 0) {
            totaltime += 1440;
        }
        std::cout << NeedPrintZero(totaltime, false);
        return totaltime;
    }
}
double HowManyHoursAndMinsWithDecimal(int fH, int fM, int sH, int sM) {
    double totaltime = HowManyMinutes(fH, fM, sH, sM);
    int hours = 0;
    for (; 60 <= totaltime; hours++) {
        totaltime = (totaltime - 60);
    }
    double tempint = totaltime;
    totaltime = (tempint / 60) + hours;
    if (totaltime < 0) {
        totaltime += 24;
    }
    return totaltime;
}
