#include <stdexcept>
#include "View.h"

using namespace std;

View::View(Controller controller)
   : controller{move(controller)} {}

void View::makeMenus( Menu* root ){
    // make main Menu
    auto commandsFromFile = new CommandsFromFileMenu{"Commands From File", root};
    auto studentMenu = new InternalMenu{"Student Menu", root};
    auto professorMenu = new InternalMenu{"Professor Menu", root};
    auto managerMenu = new InternalMenu{"Manager Menu", root};
    auto MathClass = new InternalMenu{"Math Class", root};
    root->setSubMenus(vector<Menu*>
            {commandsFromFile, studentMenu, professorMenu, managerMenu,MathClass});

    // make Student Menu
    auto showThisSemesterCourses = new LeafMenu{"Show This Semester Courses", studentMenu};
    auto takeCourse = new LeafMenu{"Take Course", studentMenu};
    auto dropCourse = new LeafMenu{"Drop Course", studentMenu};
    auto showMyCourses = new LeafMenu{"Show Student Courses In Current Semester", studentMenu};
    auto calculateMySalary = new LeafMenu{"Calculate Student Salary", studentMenu};
    studentMenu->setSubMenus(vector<Menu*>
              {showThisSemesterCourses, takeCourse, dropCourse, showMyCourses, calculateMySalary});

    // make Professor Menu
    auto showMyCoursesInThisSemester =
            new LeafMenu{"Show Professor Courses In Current Semester", professorMenu};
    auto submitGrade = new LeafMenu{"Submit Grade", professorMenu};
    auto profCalculateMySalary = new LeafMenu{"Calculate Professor Salary", professorMenu};
    professorMenu->setSubMenus(vector<Menu*>
                       {showMyCoursesInThisSemester, submitGrade, profCalculateMySalary});

    // make Manger Menu
    auto peopleMenu = new InternalMenu{"People", managerMenu};
    auto coursesMenu = new InternalMenu{"Courses", managerMenu};
    managerMenu->setSubMenus( vector<Menu*> {peopleMenu, coursesMenu});

    // make People Menu
    auto addProfessor = new LeafMenu{"Add Professor", peopleMenu};
    auto showProfessors = new LeafMenu{"Show Professors", peopleMenu};
    auto addStudent = new LeafMenu{"Add Student", peopleMenu};
    auto showStudents = new LeafMenu{"Show Students", peopleMenu};
    peopleMenu->setSubMenus(vector<Menu*>
                                    {addProfessor, showProfessors, addStudent, showStudents});

    // make Coureses Menu
    auto addCourses = new LeafMenu{"Add Course", coursesMenu};
    auto managerShowThisSemesterCourses =
            new LeafMenu{"Show Current Semester Courses", coursesMenu};
    auto showAllCourses = new LeafMenu{"Show All Courses", coursesMenu};
    coursesMenu->setSubMenus(vector<Menu*>
            {addCourses, managerShowThisSemesterCourses, showAllCourses});

    // make Math Menu Menu
    auto ReadMembersFromFiles = new LeafMenu{"ReadMembersFromFiles",  MathClass};
    auto CalculateTotalSalary = new LeafMenu{"CalculateTotalSalary",  MathClass};
}

void View::exec(){
    try {
        controller.load();
        Menu::setController(controller);
        Menu *mainMenu = new InternalMenu{"Main Menu", nullptr};
        makeMenus(mainMenu);
        Menu::setCurrentMenu(mainMenu);

        while (true) {
            try {
                Menu::getCurrentMenu()->showSubMenus();
                Menu::getCurrentMenu()->run();
            }
            catch( const invalid_argument& e){
                cout << e.what() << endl;
            }
        }
    }

    catch( const invalid_argument& e){
        cout << e.what() << endl;
    }
}


