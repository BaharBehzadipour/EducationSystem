
#ifndef TA_19_DOUBLEMAJORSTUDENT_H
#define TA_19_DOUBLEMAJORSTUDENT_H

#include "Student.h"

class DoubleMajorStudent : public Student{


    friend std::ostream& operator<<(std::ostream & output, const DoubleMajorStudent& student);
    friend std::istream& operator>>(std::istream & input, DoubleMajorStudent& student);

private:
    std::string major2;
public:
      DoubleMajorStudent() : Student(){}

    DoubleMajorStudent(const std::string& studentId, std::string first, std::string last , double workHours,
            std::vector<std::string> passedCourses, std::map<std::string
            , double> currentSemesterCourses,std::string major2);

    virtual double calculateSalary() const override;


};


#endif //TA_19_DOUBLEMAJORSTUDENT_H
