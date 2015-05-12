// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include "Department.h"
#include "Exception.h"
#include <list>
#include <string>
#include <algorithm>
#include <functional>

Department::Department() {
  name = "";
  numberDepartment = 0;
}

Department::Department(std::string n) {
  name = n;
  numberDepartment = 0;
}


Department::Department(const Department& Dep) {
  name = Dep.name;
  numberDepartment = Dep.numberDepartment;
  ifSomeoneCharged = Dep.ifSomeoneCharged;
  ifDepartmentCharged = Dep.ifDepartmentCharged;
  std::list<Employee>::operator = (Dep);
}

Department::Department(const std::string& n, int nD) {
  name = n;
  numberDepartment = nD;
}

void Department::setNumberDepartment(int nD) {
  numberDepartment = nD;
}

int Department::getNumberDepartment() const {
  return numberDepartment;
}

bool Department::add(const Department& Dep) {
  for (std::list<Employee>::const_iterator itAdd = Dep.begin();
    itAdd != Dep.end(); itAdd++) {
    if (!has(*itAdd))
      push_back(*itAdd);
  }
  return true;
}

bool Department::add(const Employee& Emp) {
  auto ifAdd = !(has(Emp));
  if (ifAdd)
    push_back(Emp);
  return ifAdd;
}

bool Department::add(std::shared_ptr<Employee> pE) {
  auto ifAdd = !(has(*pE));
  if (ifAdd)
    push_back(*pE);
  return ifAdd;
}

pr::pr(const std::string& fName, const std::string& lName) {
      firstName = fName;
      lastName = lName;
    }

bool pr::operator()(const Employee& Emp) const {
      std::string fName = Emp.getFirstName();
      std::string lName = Emp.getLastName();
      return fName == firstName && lName == lastName;
}


bool Department::del(const std::string& fName, const std::string& lName) {
  auto it = std::find_if(cbegin(), cend(), pr(fName, lName));
  if (it != cend()) {
    erase(it);
    return true;
  }
  throw ExNotFound(fName, lName);
}

Employee& Department::get(int i) {
  auto it = begin();
  if (i < 0) {
    throw ExIndexBelowZero();
  }
  if (i > size()) {
    throw ExDepartmentToSmall(i);
  }

  std::advance(it, i-1);
  return *it;
}

bool Department::remove(int i) {
  auto it = begin();
  Employee E;

  if (i < 0) {
    throw ExIndexBelowZero();
  }
  if (i < size()) {
    throw ExDepartmentToSmall(i);
  }

  std::advance(it, i - 1);
  erase(it);
  return true;
}

bool Department::remove(const Employee& Emp) {
  auto it = find(begin(), end(), Emp);
    if (it != end()) {
      erase(it);
      return true;
    }
  return false;
}

bool Department::has(const Employee& Emp) {
  auto it = find(begin(), end(), Emp);
  return it != end();
}

void Department::checkCharging() {
  int i = 0;
  for (const_iterator it = begin(); it != end(); it++) {
    i += it->getIfCharged();
  }

  if (i == 0) {
    ifDepartmentCharged = 0;
    ifSomeoneCharged = 0;
  } else if (i > 0 && i < size()) {
    ifDepartmentCharged = 0;
    ifSomeoneCharged = 1;
  } else {
    ifDepartmentCharged = 1;
    ifSomeoneCharged = 1;
  }
}

void Department::printChargingInfo() {
  std::string fName;
  std::string lName;

  checkCharging();
  if (empty()) {
    std::cout << "There are no employees in department." << std::endl;
  } else {
    if (ifDepartmentCharged) {
      std::cout << "All employees have got the salary." << std::endl;
    } else if (ifSomeoneCharged) {
      std::cout << "Pay started. This employyes have got the salary:"
                << std::endl;
      for (const_iterator it = begin(); it != end(); it++) {
        if (it->getIfCharged()) {
          it->getName(&fName, &lName);
          std::cout << fName << " " << lName << std::endl;
        }
      }
    } else {
      std::cout << "Nobody has got the salary in department "
                << name << " ." << std::endl;
    }
  }
}

void Department::setChargingInfo(bool charged) {
  if (!empty()) {
    for (iterator it = begin(); it != end(); it++) {
      it->setIfCharged(charged);
    }
  }
}

int Department::getSummarySalary() {
  int salary = 0;
  if (empty()) {
    return 0;
  } else {
    for (const_iterator it = cbegin(); it != end(); it++) {
      salary += it->getSalary();
    }
  }
  return salary;
}

bool Department::operator ==(const Department& Dep2) const {
  return this->name == Dep2.name
                && this->numberDepartment == Dep2.numberDepartment
                && this->size() == Dep2.size()
                && std::operator == (*this, Dep2);
}

Department& Department::operator=(const Department& Dep) {
  if (this != &Dep) {
    name = Dep.name;
    numberDepartment = Dep.numberDepartment;
    ifSomeoneCharged = Dep.ifSomeoneCharged;
    ifDepartmentCharged = Dep.ifDepartmentCharged;

    clear();
    this->std::list<Employee>::operator = (Dep);
  }
  return *this;
}

Department Department::operator+(const Department& Dep2) const {
  Department Dep;

  Dep.std::list<Employee>::operator = (*this);
  for (std::list<Employee>::const_iterator it = Dep2.begin();
    it != Dep2.end(); it++) {
    Dep.add(*it);
  }

  Dep.checkCharging();

  return Dep;
}

Department Department::operator+(const Employee& Emp) const {
  Department depTemp = *this;
  depTemp.add(Emp);
  return depTemp;
}

Department operator +(const Employee& E1, const Employee& E2) {
  Department Dep;
  Dep.add(E1);
  Dep.add(E2);
  return Dep;
}

std::ostream& operator <<(std::ostream& os, const Department& Dep) {
  os << "*****************************" << std::endl;
  os << "Department name: " << Dep.name << std::endl;
  os << "Department number: " << Dep.numberDepartment << std::endl;
  os << "Department size: " << Dep.size() << std::endl;
  if (Dep.empty()) {
    os << "There are no employees in this department." << std::endl;
  } else {
    os << "Employees:" << std::endl;
    for (std::list<Employee>::const_iterator it = Dep.begin();
         it != Dep.end(); it++) {
      os << *it;
    }
  }
  return os;
}

void Department::setName(const std::string& n) {
  name = n;
}

const std::string& Department::getName() const {
  return name;
}

void Department::printOn() const {
  std::cout << *this;
}
