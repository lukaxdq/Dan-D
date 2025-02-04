#include <iostream>
#include <iomanip>
#include <ctime>

void printMonth(int year, int month) {
    const char* months[] = { "January", "February", "March", "April", "May", "June", 
                             "July", "August", "September", "October", "November", "December" };
    const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    std::cout << "     " << months[month - 1] << " " << year << std::endl;
    std::cout << " Su Mo Tu We Th Fr Sa" << std::endl;

    std::tm time_in = { 0, 0, 0, 1, month - 1, year - 1900 };
    std::time_t time_temp = std::mktime(&time_in);
    const std::tm *time_out = std::localtime(&time_temp);

    int dayOfWeek = time_out->tm_wday;
    int days = daysInMonth[month - 1];

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        days = 29;
    }

    for (int i = 0; i < dayOfWeek; ++i) {
        std::cout << "   ";
    }

    for (int day = 1; day <= days; ++day) {
        std::cout << std::setw(2) << day << " ";
        if ((day + dayOfWeek) % 7 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void printYear(int year) {
    for (int month = 1; month <= 12; ++month) {
        printMonth(year, month);
        std::cout << std::endl;
    }
}

int main() {
    int year, month;
    std::cout << "Enter year: ";
    std::cin >> year;
    std::cout << "Enter month (1-12) or 0 to print the entire year: ";
    std::cin >> month;

    if (month < 0 || month > 12) {
        std::cerr << "Invalid month!" << std::endl;
        return 1;
    }

    if (month == 0) {
        printYear(year);
    } else {
        printMonth(year, month);
    }
    return 0;
}