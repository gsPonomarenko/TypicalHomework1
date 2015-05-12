// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include "Exception.h"
#include <string>

ExNotFound::ExNotFound(const std::string& fName,
                       const std::string& lName)  {
  ErrorMessage = "Employee " + fName + ' ' + lName + " not found.";
}

const char* ExNotFound::what() const {
  return ErrorMessage.c_str();
}

/***********************************************************************/
/********************* Employee soon exist *****************************/
/***********************************************************************/

ExExist::ExExist(const std::string& fName,
                 const std::string& lName) {
  ErrorMessage = "Employee " + fName + ' ' + lName +
                               " soon exist in this department.";
}

const char* ExExist::what() const {
  return ErrorMessage.c_str();
}

/***********************************************************************/
/********************* Department is to small **************************/
/***********************************************************************/

ExDepartmentToSmall::ExDepartmentToSmall(int i) {
  ErrorMessage = "There are less than " + std::to_string(i) +
                                          " employees in this department.";
}

const char* ExDepartmentToSmall::what() const {
  return ErrorMessage.c_str();
}

/***********************************************************************/
/************************* Ptr points at 0 *****************************/
/***********************************************************************/

ExNullPtr::ExNullPtr() {
  ErrorMessage = "Ptr points at 0.";
}

const char* ExNullPtr::what() const {
  return ErrorMessage.c_str();
}

/***********************************************************************/
/************************ Index is below 0 *****************************/
/***********************************************************************/

ExIndexBelowZero::ExIndexBelowZero() {
  ErrorMessage = "Index is below zero.";
}

const char* ExIndexBelowZero::what() const {
  return ErrorMessage.c_str();
}
