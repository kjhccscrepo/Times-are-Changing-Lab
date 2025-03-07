// TimeChange Assert Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <string>
#include <sstream>

#include "TimeChangeHeader.h";

int main()
{
    std::cout << "Starting tests..." << std::endl;
    std::cout << "Part A, String to Int Conversion Function..." << std::endl;
    assert(string2int("12") == 12);
    assert(string2int("4321") == 43);
    assert(string2int("12:30", 3) == 30);
    std::cout << "Part B, Total minutes raw..." << std::endl;
    assert(HowManyMinutes(20, 2, 24, 0) == 238);
    assert(HowManyMinutes(0, 0, 24, 0) == 1440);
    assert(HowManyMinutes(0, 0, 0, 0) == 0);
    std::cout << "Part C-1, Total minutes, not including hours..." << std::endl;
    assert(HowManyHoursAndMins(1, 0, 2, 0, 50) == 48);
    assert(HowManyHoursAndMins(1, 1, 0, 2, 0) == 0);
    assert(HowManyHoursAndMins(1, 1, 30, 2, 45) == 15);
    std::cout << "Part C-2, Total hours, not including minutes..." << std::endl;
    assert(HowManyHoursAndMins(0, 0, 2, 0, 50) == 0);
    assert(HowManyHoursAndMins(0, 1, 0, 2, 0) == 1);
    assert(HowManyHoursAndMins(0, 1, 20, 2, 30) == 1);
    assert(HowManyHoursAndMins(0, 1, 40, 2, 30) == 0);
    std::cout << "Part D, Total hours and minutes as decimal value..." << std::endl;
    assert(HowManyHoursAndMinsWithDecimal(1, 0, 2, 30) == 1.5);
    assert(HowManyHoursAndMinsWithDecimal(2, 0, 4, 15) == 2.25);
    assert(HowManyHoursAndMinsWithDecimal(3, 0, 3, 45) == 0.75);
    std::cout << "Part E, Checking if the function to check if a ''0'' needs printing" << std::endl;
    std::string tempstring = "10";
    assert(NeedPrintZero(10, true) == tempstring);
    tempstring = "00";
    assert(NeedPrintZero(0, true) == tempstring);
    tempstring = "05";
    assert(NeedPrintZero(5, true) == tempstring);
    tempstring = "";
    assert(NeedPrintZero(0, false) == tempstring);
    assert(NeedPrintZero(10, false) == tempstring);
    assert(NeedPrintZero(5, false) == tempstring);
    std::cout << "Part F, Number Range funtion checking, console will print..." << std::endl;
    assert(NumberRangeCheck(0, 12, 10));
    assert(NumberRangeCheck(0, 12, 0));
    assert(NumberRangeCheck(0, 12, 12));
    assert(NumberRangeCheck(0, 59, 10));
    assert(NumberRangeCheck(0, 59, 0));
    assert(NumberRangeCheck(0, 59, 59));
    assert(!NumberRangeCheck(0, 59, 60));
    assert(!NumberRangeCheck(0, 12, -1));
    //I tried for a while to figure out a way to gett assert to work with
        //bool validate_user_string
        //and 
        //void ValidateUserInput
    //But I really couldn't figure it out at all. For future projects I should really just not have the getline in the function,
    //but instead have a getline(the function), and have it break up so I can actually test it.

    std::cout << std::endl << "Tests succussfull!" << std::endl;
}