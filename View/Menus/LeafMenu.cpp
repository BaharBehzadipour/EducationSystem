#include "LeafMenu.h"
#include <sstream>
#include "../../Controller/Controller.h"

using namespace std;

LeafMenu::LeafMenu(std::string name, Menu* parent)
    : Menu{move(name), parent} {}

void LeafMenu:: showSubMenus() const {}

void LeafMenu::run() {
    setCurrentMenu(parent);

    if(name == "Show This Semester Courses"){
       ShowSemesterCourses();
    }

    else if(name == "Take Course"){
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        string CourseName;
        cout << "Enter courseName: ";
        cin >> CourseName;

        controller.takeCourse(ID,CourseName);
    }

    else if(name == "Drop Course"){
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        string CourseName;
        cout << "Enter courseName: ";
        cin >> CourseName;
       controller.DropCourse(ID,CourseName);
    }

    else if(name == "Show Student Courses In Current Semester"){
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        ShowStudentSemesterCourses(ID);
    }

    else if(name == "Calculate Student Salary"){
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        cout<<"salary of " << controller.findStudent(ID).getFirstName()<<"  "
            << controller.findStudent(ID).getLastName()<<" is: " << CalculateStudentSalary(ID);
    }

    else if(name == "Show Professor Courses In Current Semester"){

    }

    else if(name == "Submit Grade"){

    }

    else if(name == "Calculate Professor Salary"){

    }

    else if(name == "Add Professor"){

    }

    else if(name == "Show Professors"){

    }

    else if(name == "Add Student"){
        string ID;
        cout << "Enter student number: ";
        cin >> ID;
        string first;
        cout << "Enter First Name: ";
        cin >> first;
        string last;
        cout << "Enter Last Name: ";
        cin >> last;
        controller.addStudent(ID, first, last);
    }

    else if(name == "Show Students"){

    }

    else if(name == "Add Course"){

    }

    else if(name == "Show All Courses"){

    }

    else{
        throw invalid_argument("This Menu hase not been defined!!");
    }
}

void LeafMenu::ShowSemesterCourses() {
    for(const auto & crs : controller.currentSemesterCourses){
        cout<<crs.toString()<<endl;
    }

}

void LeafMenu::ShowStudentSemesterCourses( std::string id){
    cout<<"current semester courses for " << controller.findStudent(id).getFirstName()
        <<" "<<controller.findStudent(id).getLastName()<<"are :  ";
        for(const auto& item : controller.findStudent(id).currentSemesterCourses)
            cout <<item.first << '\t' ;
}

double LeafMenu::CalculateStudentSalary(std::string id) {
   double salary= controller.findStudent(id).calculateSalary();
   return salary;
}


