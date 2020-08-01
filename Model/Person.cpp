#include "Person.h"

using namespace std;

Person::Person(std::string firstName, std::string lastName, double workHours)
   :   firstName{move(firstName)}, lastName{move(lastName)}, workHours{workHours}  {}


const std::string &Person::getFirstName() const {
    return firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

double Person::getWorkHours() const {
    return workHours;
}

void Person::setFirstName(const string &firstName) {
    Person::firstName = firstName;
}

void Person::setLastName(const string &lastName) {
    Person::lastName = lastName;
}

void Person::setWorkHours(double workHours) {
    Person::workHours = workHours;
}
