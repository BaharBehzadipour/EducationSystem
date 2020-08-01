#include "Student.h"
#include <regex>
#include <stdexcept>
#include <sstream>

using namespace std;

bool validate(const string& str, const string& ptn){
    regex pattern{ptn};
    return regex_match(str, pattern);
}

Student::Student(const std::string& studentId, std::string first, std::string last , double workHours,
        std::vector<std::string> passedCourses, std::map<std::string, double> currentSemesterCourses)
        : Person((std::move(first)), (std::move(last)), workHours ),
          passedCourses{std::move (passedCourses)}, currentSemesterCourses{std::move(currentSemesterCourses)}
        {
            if( !validate( studentId, "\\d{9}") ) {
                throw invalid_argument("Student ID must have 9 digits!!");
            }
            this->studentId = studentId;
        }

double Student::calculateSalary() const{
    return 5000 * getWorkHours();
}

std::ostream& operator<<(std::ostream & output, const Student& student){
    output << student.studentId << '\t' << student.getFirstName() << '\t' << student.getLastName()
           << '\t' << student.getWorkHours() << '\t' << student.passedCourses.size() << '\t';

    for(const auto& course : student.passedCourses){
        output << course << '\t';
    }

    output << student.currentSemesterCourses.size() << '\t';

    for(const auto& item : student.currentSemesterCourses){
        output << item.first << '\t' << item.second << '\t';
    }

    return output;
}


std::istream& operator>>(std::istream & input, Student& student){
    string id;
    string first;
    string last;
    double wh;
    vector<string> passed;
    map<string, double> current;
    int passedSize;
    int currentSize;
    string course;
    double grade;
    input >> id >> first >> last >> wh >> passedSize;

    for( size_t i{0}; i < passedSize; ++i ){
        input >> course;
        passed.push_back(course);
    }

    input >> currentSize;
    for( size_t i{0}; i < currentSize; ++i ){
        input >> course >> grade;
        current.insert({course, grade});
    }

    Student stu{id, first, last, wh, passed, current};
    student = stu;

    return input;
}

std::string Student::toString() const{
    ostringstream output;
    output << "ID: " << studentId << "\tName: " << getFirstName()
           << "\tSurname: " << getLastName();

    return output.str();
}

void Student::setPassedCourses(const vector<std::string> &passedCourses) {
    Student::passedCourses = passedCourses;
}

void Student::setCurrentSemesterCourses(const map<std::string, double> &currentSemesterCourses) {
    Student::currentSemesterCourses = currentSemesterCourses;
}

void Student::setStudentId(const string &studentId) {
    Student::studentId = studentId;
}
