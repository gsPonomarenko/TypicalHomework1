// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include "Employee.h"
#include <string>

Employee::Employee() {
  firstName = "";
  lastName = "";
  position = "";

  senyority = 0;
  salary = 0;
  index = 0;
  ifCharged = 0;
}

Employee::Employee(const std::string& fName, const std::string& lName,
                   const std::string& pos, int sen, int sal) {
  firstName = fName;
  lastName = lName;
  position = pos;

  senyority = sen;
  salary = sal;
  index = 0;
  ifCharged = 0;
}

Employee::Employee(const std::string& fName, const std::string& lName,
                   const std::string& pos, int sen, int sal,
                   float in, bool charged) {
  firstName = fName;
  lastName = lName;
  position = pos;

  senyority = sen;
  salary = sal;
  index = in;
  ifCharged = charged;
}

Employee::Employee(const Employee& E) {
  E.getName(&firstName, &lastName);
  position = E.getPosition();

  senyority = E.getSenyority();
  salary = E.getSalary();
  index = E.getIndex();
  ifCharged = E.getIfCharged();
}

Employee::Employee(Employee* pE) {
  if (pE == 0)
    throw ExNullPtr();
  pE->getName(&firstName, &lastName);
  position = pE->getPosition();

  senyority = pE->getSenyority();
  salary = pE->getSalary();
  index = pE->getIndex();
  ifCharged = pE->getIfCharged();
}

void Employee::setAllParametrs(const std::string& fName,
                               const std::string& lName,
                               const std::string& pos, int sen, int sal,
                               float in, bool charged) {
  firstName = fName;
  lastName = lName;
  position = pos;

  senyority = sen;
  salary = sal;
  index = in;
  ifCharged = charged;
}

void Employee::getAllParametrs(std::string* fName, std::string* lName,
                               std::string* pos, int* sen, int* sal,
                               float* in, bool* charged) const {
  if (!(fName != 0 && lName != 0 && pos != 0 && sen != 0 &&
      sal != 0 && in != 0 && charged != 0))
    throw ExNullPtr();
  *fName = firstName;
  *lName = lastName;
  *pos = position;

  *sen = senyority;
  *sal = salary;
  *in = index;
  *charged = ifCharged;
}

const std::string& Employee::getFirstName() const {
  return firstName;
}

const std::string& Employee::getLastName() const {
  return lastName;
}

void Employee::setPosition(const std::string& pos) {
  position = pos;
}
const std::string& Employee::getPosition() const {
  return position;
}

void Employee::setSenyority(int sen) {
  senyority = sen;
}
int Employee::getSenyority() const {
  return senyority;
}

void Employee::setSalary(int sal) {
  salary = sal;
}
int Employee::getSalary() const {
  return salary;
}

void Employee::setIndex(float in) {
  index = in;
}
float Employee::getIndex() const {
  return index;
}

void Employee::setIfCharged(bool charged) {
  ifCharged = charged;
}
bool Employee::getIfCharged() const {
  return ifCharged;
}

void Employee::setName(const std::string& fName, const std::string& lName) {
  firstName = fName;
  lastName = lName;
}

void Employee::getName(std::string* fName, std::string* lName) const {
  if (!(fName != 0 && lName != 0))
    throw ExNullPtr();
  *fName = firstName;
  *lName = lastName;
}

bool operator ==(const Employee& Emp1, const Employee& Emp2) {
  return Emp1.firstName == Emp2.firstName
      && Emp1.lastName == Emp2.lastName
      && Emp1.position == Emp2.position
      && Emp1.senyority == Emp2.senyority
      && Emp1.salary == Emp2.salary
      && Emp1.index == Emp2.index
      && Emp1.ifCharged == Emp2.ifCharged;
}

bool operator !=(const Employee& Emp1, const Employee& Emp2) {
  return !(Emp1 == Emp2);
}

Employee& Employee::operator =(const Employee& E) {
  std::string fName;
  std::string lName;
  if (this != &E) {
    E.getName(&fName, &lName);
    this->setAllParametrs(fName, lName, E.getPosition(),
                          E.getSenyority(), E.getSalary(),
                          E.getIndex(), E.getIfCharged());
  }
  return *this;
}

std::ostream& operator <<(std::ostream& os, const Employee& Emp) {
  std::string fName;
  std::string lName;
  Emp.getName(&fName, &lName);
  os << "Name: " << fName << " " << lName << std::endl;
  os << "Position: " << Emp.getPosition() << std::endl;
  os << "Senyority: " << Emp.getSenyority() << std::endl;
  os << "Fixed salary: " << Emp.getSalary() << std::endl;
  os << "Index: " << Emp.getIndex() << " %" << std::endl;
  if (Emp.getIfCharged() != 0) {
    os << "Paid." << std::endl << std::endl;
  } else {
    os << "Not paid." << std::endl << std::endl;
  }

  return os;
}

void Employee::printOn() const {
  std::cout << *this;
}
