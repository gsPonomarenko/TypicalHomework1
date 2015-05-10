// Copyright 2015 <Grigory Ponomarenko>

#pragma once

#include <iostream>
#include <string>

class ExNotFound : public std::exception{
 public:
    ExNotFound(const std::string& fName, const std::string& lName);
    const char* what() const;

 protected:
    std::string ErrorMessage;
};

class ExExist : public std::exception{
 public:
    ExExist(const std::string& fName, const std::string& lName);
    const char* what() const;

 protected:
    std::string ErrorMessage;
};

class ExDepartmentToSmall : public std::exception{
 public:
    explicit ExDepartmentToSmall(int i);
    const char* what() const;

 protected:
    std::string ErrorMessage;
};

class ExNullPtr : public std::exception{
 public:
    ExNullPtr();
    const char* what() const;

 protected:
    std::string ErrorMessage;
};
