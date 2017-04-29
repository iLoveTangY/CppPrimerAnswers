#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

int main(void)
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};

    string letterGrade;
    int grade;

    std::cin >> grade;

    letterGrade = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];
    letterGrade += (grade < 60 || grade == 100) ? "" : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";

//    if(grade < 60)
//        letterGrade = scores[0];
//    else
//    {
//        letterGrade = scores[(grade - 50)/10];
//        if(grade != 100)
//            if(grade % 10 > 7)
//                letterGrade += "+";
//            else if(grade % 10 < 3)
//                letterGrade += "-";
//    }
    std::cout << letterGrade << std::endl;

    return 0;
}

