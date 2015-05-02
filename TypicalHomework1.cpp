// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include "Department.h"
#include "Exception.h"
#include <string>

void main() {
  /** Test of "Employee" class*/
  std::cout << "Test of \"Employee\" class" << std::endl;
  std::string fName;
  std::string lName;
  std::string position;
  int senyority;
  int salary;
  float index;
  bool ifCharged;

  Employee E1;
  E1.printOn();

  Employee E2("Dmitry", "Semenov", "first officer", 2007, 100000);
  std::cout << E2;

  Employee E3("Konstantin", "Smolensky", "co-pilot", 2012, 60000, 5.0, true);

  E3.getName(&fName, &lName);
  position = E3.getPosition();
  senyority = E3.getSenyority();
  salary = E3.getSalary();
  index = E3.getIndex();
  ifCharged = E3.getIfCharged();

  std::shared_ptr<Employee> pE (new Employee);
  pE->setAllParametrs(fName, lName, position, senyority,
                      salary, index, ifCharged);
  std::cout << *pE;

  Employee* ppE = &E1;
  E2.getAllParametrs(&fName, &lName, &position, &senyority,
                     &salary, &index, &ifCharged);

  ppE->setName(fName, lName);
  ppE->setPosition(position);
  ppE->setSenyority(senyority);
  ppE->setSalary(salary);
  ppE->setIndex(index);
  ppE->setIfCharged(ifCharged);

  ppE->printOn();

  Employee E4(E2);
  E4.setName("Nikita", "Assorov");
  std::cout << E2 << E4;

  Employee E5;
  E5 = E4;
  E5.setPosition("flight dispatcher");
  std::cout << E4 << E5;

  Employee E6 = E5 + E3;
  std::cout << E6;

  /** Test of "Department" class */
  std::cout << "Test of \"Department\" class" << std::endl;
  std::string name;
  int numberDepartment;
  int size;
  int sumSalary;

    Department D1;
    std::cout << D1;
    D1.add(E1);


    Department D2("Delta Airlines");
    std::cout << D2;
    D2.add(pE);
    std::cout << D2;

  try {
    D2 = D2 + E3;
    std::cout << D2;
  }
  catch (ExExist ex) {
    std::cout << ex.what() << std::endl;
  }

    D2.getName(&name);
    D1.setName(name);
    numberDepartment = D2.getNumberDepartment();
    D1.setNumberDepartment(numberDepartment);
    size = D2.getSize();
    D1.doResize(size);
    size++;
    D1.doResize(size);

  D1 = D2 + D1;
  std::cout << D1;

  /**Check if paid*/
  D1.getChargingInfo();

  /** All employees have got the salaty.*/
  D1.setChargingInfo(true);
  D1.getChargingInfo();

  /** Completly paid*/
  sumSalary = D1.getSummarySalary();
  std::cout << "Completly paid " << sumSalary << std::endl;

  /** Nobody have got the salary*/
  D1.setChargingInfo(false);
  D1.getChargingInfo();

  std::shared_ptr<Department> pD3 (new Department("American Eagle", 3));
  pD3->printOn();

  try {
    Department D4("Pan American", 4, 1);
    D4.printOn();
    D4.del("Max", "Kabanov");
    D4.del("", "");
    D4.printOn();
  }
  catch (ExNotFound ex) {
    std::cout << ex.what() << std::endl;
  }

  system("pause");
}
