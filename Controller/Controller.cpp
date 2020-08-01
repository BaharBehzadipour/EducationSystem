#include "Controller.h"
#include <fstream>
#include <vector>
#include <map>

using namespace std;

Controller::Controller(std::string currentSemester)
   : currentSemester{move(currentSemester)} {}


void Controller:: load(){
    ifstream inputStu("students.txt");
    int studentSize;
    inputStu >> studentSize;
    Student stu;
    for( size_t i{0}; i < studentSize; ++i ){
        inputStu >> stu;
        students.push_back(stu);
    }
    inputStu.close();

    ifstream inputProf("professors.txt");
    int profSize;
    inputProf >> profSize;
    Professor prof;
    for( size_t i{0}; i < profSize; ++i){
        inputProf >> prof;
        professors.push_back(prof);
    }
    inputProf.close();

    ifstream inputCourse("courses.txt");
    int courseSize;
    inputCourse >> courseSize;
    Course crs;
    for( size_t i{0}; i < courseSize; ++i){
        inputCourse >> crs;
        courses.push_back(crs);
        if(crs.semester == currentSemester){
            currentSemesterCourses.push_back(crs);
        }
    }
    inputCourse.close();
}

void Controller::save() const{
    ofstream outputStu("students.txt", ios::out);
    outputStu << students.size() << endl;
    for( auto const& stu : students ){
        outputStu << stu << endl;
    }
    outputStu.close();

    ofstream outputProf("professors.txt");
    outputProf << professors.size() << endl;
    for( const auto& prof : professors ){
        outputProf << prof << endl;
    }
    outputProf.close();

    ofstream outputCourse("courses.txt");
    outputCourse << courses.size() << endl;
    for( auto const& crs : courses ){
        outputCourse << crs << endl;
    }
    outputCourse.close();
}

void Controller:: addStudent(std::string ID, std::string first, std::string last){
    if(!inStudents(ID)){
        Student stu{move(ID), move(first), move(last), 0,
                    vector<string>{}, map<string, double>{}};
        students.push_back(stu);
    }
}

void Controller:: addProfessor(std::string ID, std::string first,
        std::string last, std::string title){
    if(!inProfessors(ID)){
        Professor prof{move(ID), move(first), move(last), 0, move(title)};
        professors.push_back(prof);
    }
}

void Controller:: addCourse(std::string courseName, std::string profLast, std::string semester,
               std::vector<std::string> pre){
    if( !inCourses(courseName) && inProfessorsByLastName(profLast) ){
        Course crs{move(courseName), move(profLast), move(semester), move(pre)};
        courses.push_back(crs);
        if( crs.semester == currentSemester){
            currentSemesterCourses.push_back(crs);
        }
    }

}

bool Controller::inStudents(const std::string& ID) const{
    for( const auto& stu : students ){
        if( stu.studentId == ID){
            return true;
        }
    }
    return false;
}

bool Controller::inProfessors(const std::string& ID) const{
    for( const auto& prof : professors ){
        if( prof.profId == ID){
            return true;
        }
    }
    return false;
}

bool Controller::inCourses(const std::string& courseName) const{
    for( const auto& crs : courses ){
        if( crs.courseName == courseName){
            return true;
        }
    }
    return false;
}

bool Controller:: inProfessorsByLastName(const std::string& last) const{
    for( const auto& prof : professors ){
        if( prof.getLastName() == last){
            return true;
        }
    }
    return false;
}

bool Controller::inCurrentSemesterCourses(const std::string& currentSemesterCoursesName) const{

    for( const auto& crs : currentSemesterCourses ){
        if( crs.courseName == currentSemesterCoursesName){
            return true;
        }
    }
    return false;
}

Student& Controller:: findStudent(string ID){
    for( auto& stu : students ){
        if(stu.studentId == ID){
            return stu;
        }
    }
    throw invalid_argument("The Student was not found!!");
}

void Controller:: takeCourse(const std::string& studentID, const std::string& courseName){
    if(inCourses(courseName)){
        findStudent(studentID).currentSemesterCourses.insert({courseName, 0});
    }
}

void Controller::DropCourse(const std::string& studentID, const std::string& courseName){

    if(inCurrentSemesterCourses(courseName)){
        findStudent(studentID).currentSemesterCourses.erase({courseName});
    }
}