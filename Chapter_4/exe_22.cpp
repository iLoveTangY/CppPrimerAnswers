#include <iostream>
#include <string>

using std::string;

int main(void)
{
    double grade;
    string finalGrade;

    //version 1
    std::cin >> grade;
    finalGrade = (grade > 90) ? "High Pass"
                              : (grade > 75) ? "Pass"
                              : (grade > 60) ? "Low Pass" : "Fail";
    std::cout << finalGrade << std::endl;

    finalGrade = "";
    //version 2
    if(grade > 90)
        finalGrade = "High Pass";
    else if(grade > 75)
        finalGrade = "Pass";
    else if(grade > 60)
        finalGrade = "Low Pass";
    else
        finalGrade = "Fail";
    std::cout << finalGrade << std::endl;

    return 0;
}
