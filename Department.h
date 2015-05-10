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
    Department(const std::string& n, int nD, int s);

    bool add(const Department& Dep);
    bool add(const Employee& Emp);
    bool add(std::shared_ptr<Employee>& pE);
    bool del(const std::string& fName, const std::string& lName);

    Employee& get(int i);
    bool remove(int i);
    bool remove(const Employee& Emp);
    bool has(const Employee& Emp);

    void setNumberDepartment(int nD);
    int getNumberDepartment() const;

    void checkCharging();
    void getChargingInfo();
    void setChargingInfo(bool charged);
    int getSummarySalary();

    const std::string& getFirstName() const;
    const std::string& getLastName() const;

    friend bool operator ==(const Department& Dep1, const Department& Dep2);
    Department& operator =(const Department& Dep1);
    Department operator +(const Department& Dep2) const;
    friend Department operator +(const Employee& E1, const Employee& E2);
    friend Department operator +(const Department& Dep, const Employee& Emp);
    friend std::ostream& operator <<(std::ostream& os,
      const Department& Dep);
      Employee& operator[](int i);

    void setName(const std::string& n);
    void getName(std::string* pName) const;
    void printOn() const;


 protected :
    std::string name;
    int numberDepartment;

    bool ifSomeoneCharged;
    bool ifDepartmentCharged;

    std::shared_ptr<Department> pListOfNear;
};

class pr : public std::unary_function<Employee*, std::string> {
    std::string firstName;
    std::string lastName;
 public:
    pr(std::string fName, std::string lName);
    bool operator()(const Employee Emp) const;
};
