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

  std::cout << E2.getFirstName() << std::endl;
  std::cout << E2.getLastName() << std::endl;

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

  /** Test of "Department" class */
  std::cout << "Test of \"Department\" class" << std::endl;
  std::string name;
  int numberDepartment;
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
  catch (std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }

  name = D2.getName();
  D1.setName(name);
  numberDepartment = D2.getNumberDepartment();
  D1.setNumberDepartment(numberDepartment);

  D1 = D2 + D1;
  std::cout << D1;

  /**Check if paid*/
  D1.printChargingInfo();

  /** All employees have got the salaty.*/
  D1.setChargingInfo(true);
  D1.printChargingInfo();

  /** Completly paid*/
  sumSalary = D1.getSummarySalary();
  std::cout << "Completly paid " << sumSalary << std::endl;

  /** Nobody have got the salary*/
  D1.setChargingInfo(false);
  D1.printChargingInfo();

  Department D3("American Eagle", 3);
  D3.printOn();

  try {
    Department D4("Pan American", 4);
    D4.add(E1);
    D4.printOn();
    D4.del("Dmitry", "Semenov");
    D4.del("Max", "Kabanov");
    D4.printOn();
  }
  catch (std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }

  Department D5 = E5 + E3;
  std::cout << D5;

  system("pause");
}
