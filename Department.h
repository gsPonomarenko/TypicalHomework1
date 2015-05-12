// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include "Employee.h"
#include <list>
#include <string>
#include <functional>

class Department:  public std::list<Employee> {
 public :
    Department();

    explicit Department(std::string n);
    Department(const Department& dep);

    Department(const std::string& n, int nD);

    bool add(const Department& Dep);
    bool add(const Employee& Emp);
    bool add(std::shared_ptr<Employee> pE);
    bool del(const std::string& fName, const std::string& lName);

    Employee& get(int i);
    bool remove(int i);
    bool remove(const Employee& Emp);
    bool has(const Employee& Emp);

    void setNumberDepartment(int nD);
    int getNumberDepartment() const;

    void checkCharging();
    void printChargingInfo();
    void setChargingInfo(bool charged);
    int getSummarySalary();

    bool operator ==(const Department& Dep) const;
    Department& operator =(const Department& Dep);
    Department operator +(const Department& Dep2) const;
    Department operator +(const Employee& Emp) const;
    friend Department operator +(const Employee& E1, const Employee& E2);
    friend std::ostream& operator <<(std::ostream& os,
      const Department& Dep);
      Employee& operator[](int i);

    void setName(const std::string& n);
    const std::string& getName() const;
    void printOn() const;


 protected :
    std::string name;
    int numberDepartment;

    bool ifSomeoneCharged;
    bool ifDepartmentCharged;
};

class pr {
    std::string firstName;
    std::string lastName;
 public:
    pr(const std::string& fName, const std::string& lName);
    bool operator()(const Employee& Emp) const;
};
