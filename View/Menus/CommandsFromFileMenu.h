#ifndef TA_19_COMMANDSFROMFILEMENU_H
#define TA_19_COMMANDSFROMFILEMENU_H

#include <string>
#include "Menu.h"
#include "../../Controller/Controller.h"


class CommandsFromFileMenu : public Menu{
public:
    CommandsFromFileMenu(std::string name, Menu* parent);
    virtual void showSubMenus() const override;
    virtual void run() override;
    static void showStudents();
    static void processAddCourse(std::vector<std::string> vec);
};




#endif //TA_19_COMMANDSFROMFILEMENU_H
