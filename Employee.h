// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include "Exception.h"
#include <iostream>
#include <memory>
#include <string>
#include <list>

class Employee{
 public:
    Employee();

    Employee(const std::string& fName, const std::string& lName,
             const std::string& pos, int sen, int sal);
    Employee(const std::string& fName, const std::string& lName,
             const std::string& pos, int sen, int sal,
             float in, bool charged);

    Employee(const Employee& E);
    explicit Employee(Employee* pE);

    void setAllParametrs(const std::string& fName, const std::string& lName,
                         const std::string& pos, int sen, int sal,
                         float in, bool charged);
    void getAllParametrs(std::string* fName, std::string* lName,
                         std::string* pos, int* sen, int* sal,
                         float* in, bool* charged) const;

    void setFirstName(std::string fName);
    const std::string& getFirstName() const;
    void setLastName(std::string lName);
    const std::string& getLastName() const;

    void setPosition(const std::string& pos);
    const std::string& getPosition() const;

    void setSenyority(int sen);
    int getSenyority() const;

    void setSalary(int sal);
    int getSalary() const;

    void setIndex(float in);
    float getIndex() const;

    void setIfCharged(bool charged);
    bool getIfCharged() const;

    bool operator ==(const Employee& Emp) const;
    bool operator !=(const Employee& Emp) const;
    Employee& operator =(const Employee& E);
    friend std::ostream& operator <<(std::ostream& os, const Employee& Emp);
    void setName(const std::string& firstName,
                         const std::string& lastName);
    void getName(std::string* fName, std::string* lName) const;
    void printOn() const;

 protected:
    std::string firstName;
    std::string lastName;
    std::string position;

    /** Senyority (����) -- year of the beginnning
                            of the work in the company */
    int senyority;

    /** salary (�����) -- fixed salary in rubles
    index (�����������) -- salary index in percents */
    int salary;
    float index;
    bool ifCharged;
};
