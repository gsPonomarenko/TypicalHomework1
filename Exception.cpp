// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include "Exception.h"
#include <string>

ExNotFound::ExNotFound() : exception("Employee not found") {
  firstName = "";
  lastName = "";
}

ExNotFound::ExNotFound(const std::string& fName,
                       const std::string& lName) :
                       exception(" Employee not found") {
  firstName = fName;
  lastName = lName;
}

std::string ExNotFound::what() {
  std::string sum = firstName + ' ' + lastName + ' ' + exception::what();
  return sum;
}

/***********************************************************************/
/********************* Employee soon exist *****************************/
/***********************************************************************/

ExExist::ExExist() : exception("Employee soon exist in this department") {
  firstName = "";
  lastName = "";
}

ExExist::ExExist(const std::string& fName,
                 const std::string& lName) :
                 exception("Employee soon exist in this department") {
  firstName = fName;
  lastName = lName;
}

std::string ExExist::what() {
  std::string sum = firstName + ' ' + lastName + ' ' + exception::what();
  return sum;
}
