// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include "Employee.h"
#include <list>
#include <string>


class Department:  public std::list<Employee> {
 public :
    Department();

    explicit Department(std::string n);
    Department(const Department& dep);

    Department(std::string n, int nD);
    Department(std::string n, int nD, int s);

    bool add(const Department& Dep);
    bool add(const Employee& Emp);
    bool add(const std::shared_ptr<Employee>& pE);
    bool del(const std::string& fName, const std::string& lName);

    Employee& get(int i);
    bool remove(int i);
    bool remove(const Employee& Emp);
    bool has(const Employee& Emp);

    void setNumberDepartment(int nD);
    int getNumberDepartment() const;

    int getSize() const;
    void doResize(int s);
    void checkCharging();
    void getChargingInfo();
    void setChargingInfo(bool charged);
    int getSummarySalary();

    friend bool operator ==(const Department& Dep1, const Department& Dep2);
    Department& operator =(const Department& Dep1);
    Department operator +(const Department& Dep2) const;
    friend Department operator +(const Department& Dep, const Employee& Emp);
    friend std::ostream& operator <<(std::ostream& os,
      const Department& Dep);
      Employee& operator[](int i);

    virtual void setName(const std::string& n);
    virtual void getName(std::string* pName) const;
    virtual void printOn() const;


 protected :
    std::string name;
    int numberDepartment;
    int size;

    bool ifSomeoneCharged;
    bool ifDepartmentCharged;

    std::shared_ptr<Department> pListOfNear;
};
