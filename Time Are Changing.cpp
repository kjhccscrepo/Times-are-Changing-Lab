// Time Are Changing.cpp
#include <iostream>
#include <string>
#include <iomanip>

#include "TimeChangeHeader.h";

int main()
{
    int first_time_hour;
    int first_time_mins;
    int second_time_hour;
    int second_time_mins;
    std::cout << std::endl << "Welcome to the Time Interval Calculation Program!" << std::endl;
    ValidateUserInput(1, first_time_hour, first_time_mins);
    ValidateUserInput(2, second_time_hour, second_time_mins);
    std::cout << "The time interval between " << NeedPrintZero(first_time_hour, true) << ":" << NeedPrintZero(first_time_mins, true);
    std::cout << " and " << NeedPrintZero(second_time_hour, true) << ":" << NeedPrintZero(second_time_mins, true);
    std::cout << " can be written as:" << std::endl << std::endl;
    std::cout << "    * " << HowManyMinutes(first_time_hour, first_time_mins, second_time_hour, second_time_mins) << " minute(s)" << std::endl;
    std::cout << "    * " << HowManyHoursAndMins(0, first_time_hour, first_time_mins, second_time_hour, second_time_mins) << " hour(s) and ";
    std::cout << HowManyHoursAndMins(1, first_time_hour, first_time_mins, second_time_hour, second_time_mins) << " minute(s)" << std::endl;
    std::cout << "    * "; 
    //the printf is for rounding the decimal place
    printf("%.2f", HowManyHoursAndMinsWithDecimal(first_time_hour, first_time_mins, second_time_hour, second_time_mins));
    std::cout << " hour(s)" << std::endl;
    std::cout << std::endl << "Thanks for using the Time Interval Calculation Program!" << std::endl << std::endl;
    return 0;
}