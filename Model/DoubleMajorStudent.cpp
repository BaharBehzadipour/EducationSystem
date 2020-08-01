//
// Created by pars on 8/1/2020.
//

#include "DoubleMajorStudent.h"
using namespace std;
DoubleMajorStudent::DoubleMajorStudent(const std::string &studentId, std::string first, std::string last,
                                       double workHours, std::vector<std::string> passedCourses,
                                       std::map<std::string, double> currentSemesterCourses, std::string major2)
 : Student(studentId, move(first),  move(last),workHours,move(passedCourses),move(currentSemesterCourses)) ,
 major2{move(major2)} {}


  std::ostream& operator<<(std::ostream & output, const DoubleMajorStudent& student){
      output << student.studentId << '\t' << student.getFirstName() << '\t' << student.getLastName()
             << '\t' << student.getWorkHours() << '\t' << student.passedCourses.size() << '\t';

      for(const auto& course : student.passedCourses){
          output << course << '\t';
      }

      output << student.currentSemesterCourses.size() << '\t';

      for(const auto& item : student.currentSemesterCourses){
          output << item.first << '\t' << item.second << '\t';
      }
     output<<student.major2<<endl;
      return output;
}
  std::istream& operator>>(std::istream & input, DoubleMajorStudent& student){}