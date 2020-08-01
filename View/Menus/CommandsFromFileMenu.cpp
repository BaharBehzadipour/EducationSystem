#include "CommandsFromFileMenu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdexcept>

using namespace std;

CommandsFromFileMenu::CommandsFromFileMenu(std::string name, Menu* parent)
    : Menu{move(name), parent} {}

void CommandsFromFileMenu:: showSubMenus() const {}

void CommandsFromFileMenu::run() {
    setCurrentMenu(parent);
    int numOfCommands;
    cout << "Enter number of commands: ";
    cin >> numOfCommands;

    string command;
    char * cmd = new char[1000];
    ifstream input("Commands.txt");

    for(size_t i{1}; i <= numOfCommands; ++i){
        try {
            input.getline(cmd, 1000);
            command = (string) cmd;
            istringstream iss{command};
            vector<string> results{istream_iterator<string>{iss}, istream_iterator<string>()};

            if (results[0] == "add" && results[1] == "student") {
                controller.addStudent(results[2], results[3], results[4]);

            } else if (results[0] == "add" && results[1] == "professor") {
                controller.addProfessor(results[2], results[3], results[4], results[5]);

            } else if (results[0] == "add" && results[1] == "course") {
                processAddCourse(results);

            } else if (results[0] == "take" && results[1] == "course") {
                controller.takeCourse(results[2],results[3]);

            } else if (results[0] == "show" && results[1] == "students") {
                showStudents();

            } else {
                throw invalid_argument("This command is not defined!!");
            }
        }
        catch( const invalid_argument& e){
            cout << e.what() << endl;
        }

    }

}

void CommandsFromFileMenu:: showStudents(){
    for(const auto& stu : controller.students){
        cout << stu.toString() << endl;
    }
}

void CommandsFromFileMenu:: processAddCourse(vector<string> vec){
    int numOfPre;
    numOfPre = stoi(vec[5]);
//    stringstream ss;
//    ss << vec[5];
//    ss >> numOfPre;
    vector<string> pre;
    for( size_t i{0}; i < numOfPre; ++i){
        pre.push_back(vec[6+i]);
    }
    controller.addCourse(vec[2], vec[3], vec[4], pre);
}



