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
  pListOfNear = Dep.pListOfNear;
  std::list<Employee>::operator = (Dep);
}

Department::Department(const std::string& n, int nD) {
  name = n;
  numberDepartment = nD;
}

Department::Department(const std::string& n, int nD, int s) {
  name = n;
  numberDepartment = nD;
  for (int i = 0; i < s; i++) {
    push_back(Employee());
  }
}

void Department::setNumberDepartment(int nD) {
  numberDepartment = nD;
}

int Department::getNumberDepartment() const {
  return numberDepartment;
}

bool Department::add(const Department& Dep) {
  bool ifSoonContain = false;
  for (std::list<Employee>::const_iterator itAdd = Dep.begin();
    itAdd != Dep.end(); itAdd++) {
    for (std::list<Employee>::const_iterator itThis = begin();
      itThis != end() && ifSoonContain == false; itThis++) {
      if (*itAdd == *itThis)
        ifSoonContain = true;
    }
    if (ifSoonContain == false) {
      push_back(*itAdd);
    }
    ifSoonContain = false;
  }
  return true;
}

bool Department::add(const Employee& Emp) {
  for (const_iterator it = begin(); it != end(); it++) {
    if (*it == Emp) {
      return false;
    }
  }
  push_back(Emp);
  std::cout << "Employee is added seccessfully." << std::endl;
  return true;
}

bool Department::add(std::shared_ptr<Employee>& pE) {
  for (const_iterator it = begin(); it != end(); it++) {
    if (*it == *pE) {
      return 0;
    }
  }
  push_back(*pE);
  std::cout << "Employee is added seccessfully." << std::endl;
  return 1;
}

pr::pr(std::string fName, std::string lName) {
      firstName = fName;
      lastName = lName;
    }

bool pr::operator()(const Employee Emp) const {
      std::string fName = Emp.getFirstName();
      std::string lName = Emp.getLastName();
      return fName == firstName && lName == lastName;
}


bool Department::del(const std::string& fName, const std::string& lName) {
  auto it = std::find_if(cbegin(), cend(), pr(fName, lName));
  if (it != cend()) {
    erase(it);
    std::cout << "Information about " << fName << " " << lName <<
      " is deleted seccessfully." << std::endl;
    return true;
  }
  throw ExNotFound(fName, lName);
}

Employee& Department::get(int i) {
  auto it = begin();
  if (i > size()) {
    throw ExDepartmentToSmall(i);
  }

  std::advance(it, i-1);
  return *it;
}

bool Department::remove(int i) {
  auto it = begin();
  Employee E;

  if (i < size()) {
    throw ExDepartmentToSmall(i);
  } else {
    std::advance(it, i - 1);
    erase(it);
    std::cout << "Employee number " << i <<
                 " is delete seccesfully" << std::endl;
    return true;
  }
}

bool Department::remove(const Employee& Emp) {
  iterator it;
    it = find(begin(), end(), Emp);
    if (it != end()) {
      erase(it);
      std::cout << "Employee is delete seccesfully" << std::endl;
      return true;
    }
  return false;
}

bool Department::has(const Employee& Emp) {
  auto it = find(begin(), end(), Emp);
  if (it != end())
    return true;
  return false;
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

void Department::getChargingInfo() {
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
  if (empty()) {
    std::cout << "There are no employees in department." << std::endl;
  } else {
    for (iterator it = begin(); it != end(); it++) {
      it->setIfCharged(charged);
    }
  }
}

int Department::getSummarySalary() {
  int salary = 0;
  if (empty()) {
    std::cout << "There are no employees in department." << std::endl;
    return 0;
  } else {
    for (const_iterator it = cbegin(); it != end(); it++) {
      salary += it->getSalary();
    }
  }
  return salary;
}

bool operator ==(const Department& Dep1, const Department& Dep2) {
  bool ifDuplicate = 0;
  if (Dep1.name == Dep2.name
                && Dep1.numberDepartment == Dep2.numberDepartment
                && Dep1.size() == Dep2.size())
    ifDuplicate = true;

  std::list<Employee>::const_iterator it1 = Dep1.cbegin();
  std::list<Employee>::const_iterator it1End = Dep1.cend();
  std::list<Employee>::const_iterator it2 = Dep2.cbegin();
  std::list<Employee>::const_iterator it2End = Dep2.cend();

  while (it1 != it1End && it2 != it2End && ifDuplicate == 0) {
    if (*it1 == *it2)
      ifDuplicate = true;
    it1++;
    it2++;
  }
  return ifDuplicate;
}

Department& Department::operator=(const Department& Dep1) {
  if (Dep1 == *this) {
    return *this;
  } else {
    name = Dep1.name;
    numberDepartment = Dep1.numberDepartment;
    ifSomeoneCharged = Dep1.ifSomeoneCharged;
    ifDepartmentCharged = Dep1.ifDepartmentCharged;
    pListOfNear = Dep1.pListOfNear;

    clear();
    for (std::list<Employee>::const_iterator it = Dep1.begin();
      it != Dep1.end(); it++) {
      push_back(*it);
    }

    return *this;
  }
}

Department Department::operator+(const Department& Dep2) const {
  Department Dep;

  Dep.std::list<Employee>::operator = (*this);
  for (std::list<Employee>::const_iterator it = Dep2.begin();
    it != Dep2.end(); it++) {
    Dep.push_back(*it);
  }

  Dep.checkCharging();

  return Dep;
}

Department operator+(const Department& Dep, const Employee& Emp) {
  bool add = 0;
  Department depTemp;
  std:: string fName;
  std::string lName;

  std::list<Employee>::const_iterator it = Dep.begin();
  for (; it != Dep.end(); it++) {
    if (*it == Emp) {
      Emp.getName(&fName, &lName);
      throw ExExist(fName, lName);
    }
  }

  if (add == 0) {
    depTemp = Dep;
    depTemp.push_back(Emp);
  }
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

void Department::getName(std::string* pName) const {
  *pName = name;
}

void Department::printOn() const {
  std::cout << *this;
}
