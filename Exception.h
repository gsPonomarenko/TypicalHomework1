// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include <iostream>
#include <string>

class ExNotFound : public std::exception{
 public:
    ExNotFound();
    ExNotFound(const std::string& fName, const std::string& lName);
    std::string what();

 protected:
    std::string firstName;
    std::string lastName;
};

class ExExist : public std::exception{
 public:
    ExExist();
    ExExist(const std::string& fName, const std::string& lName);
    std::string what();

 protected:
    std::string firstName;
    std::string lastName;
};
