#include <iostream>
#include <memory>
#include <string>
#include <list>

using namespace std;


class Employee{
public:
	Employee();
	Employee(string fName, string lName, string pos, int sen, int sal);
	Employee(string fName, string lName, string pos, int sen, int sal, float in, bool charged);

	Employee(Employee& E);
	Employee(Employee* pE);

	void setAllParametrs(string fName, string lName, string pos, int sen, int sal, float in, bool charged);
	void getAllParametrs(string& fName, string& lName, string& pos, int& sen, int& sal, float& in, bool& charged);

	void setPosition(string pos);
	string getPosition() const;

	void setSenyority(int sen);
	int getSenyority() const;

	void setSalary(int sal);
	int getSalary() const;

	void setIndex(float in);
	float getIndex() const;

	void setIfCharged(bool charged);
	bool getIfCharged() const;

	friend bool operator ==(const Employee& Emp1, const Employee& Emp2);
	Employee& operator =(Employee& E);
	friend Employee operator+(Employee& E1, Employee& E2);
	friend ostream& operator <<(ostream& os, const Employee& Emp);

	virtual void setName(string firstName, string lastName);
	virtual void getName(string& fName, string& lName) const;
	virtual void printOn() const;
protected:
	string firstName;
	string lastName;
	string position;

	/** Senyority (стаж) -- год начала работы в компании*/
	int senyority;

	/** salary (оклад) -- фиксированная базовая ставка в рублях
	index (коэффициент) -- индексация зарплаты в большую или меньшую сторону */
	int salary;
	float index;
	bool ifCharged;
};

Employee::Employee(){
	firstName = "";
	lastName = "";
	position = "";

	senyority = 0;
	salary = 0;
	index = 0;
	ifCharged = 0;
}

Employee::Employee(string fName, string lName, string pos, int sen, int sal){
	firstName = fName;
	lastName = lName;
	position = pos;

	senyority = sen;
	salary = sal;
	index = 0;
	ifCharged = 0;
}

Employee::Employee(string fName, string lName, string pos, int sen, int sal, float in, bool charged){
	firstName = fName;
	lastName = lName;
	position = pos;

	senyority = sen;
	salary = sal;
	index = in;
	ifCharged = charged;
}

Employee::Employee(Employee& E){
	E.getName(firstName, lastName);
	position = E.getPosition();

	senyority = E.getSenyority();
	salary = E.getSalary();
	index = E.getIndex();
	ifCharged = E.getIfCharged();
}

Employee::Employee(Employee* pE){
	pE->getName(firstName, lastName);
	position = pE->getPosition();

	senyority = pE->getSenyority();
	salary = pE->getSalary();
	index = pE->getIndex();
	ifCharged = pE->getIfCharged();
}

void Employee::setAllParametrs(string fName, string lName, string pos, int sen, int sal, float in, bool charged){
	firstName = fName;
	lastName = lName;
	position = pos;

	senyority = sen;
	salary = sal;
	index = in;
	ifCharged = charged;
}

void Employee::getAllParametrs(string& fName, string& lName, string& pos, int& sen, int& sal, float& in, bool& charged){
	fName = firstName;
	lName = lastName;
	pos = position;

	sen = senyority;
	sal = salary;
	in = index;
	charged = ifCharged;
}

void Employee::setPosition(string pos){
	position = pos;
}
string Employee::getPosition() const{
	return position;
}

void Employee::setSenyority(int sen){
	senyority = sen;
}
int Employee::getSenyority() const{
	return senyority;
}

void Employee::setSalary(int sal){
	salary = sal;
}
int Employee::getSalary() const{
	return salary;
}

void Employee::setIndex(float in){
	index = in;
}
float Employee::getIndex() const{
	return index;
}

void Employee::setIfCharged(bool charged){
	ifCharged = charged;
}
bool Employee::getIfCharged() const{
	return ifCharged;
}

void Employee::setName(string fName, string lName){
	firstName = fName;
	lastName = lName;
}
void Employee::getName(string& fName, string& lName) const{
	fName = firstName;
	lName = lastName;
}

bool operator ==(const Employee& Emp1, const Employee& Emp2){
	if (Emp1.firstName == Emp2.firstName
		&& Emp1.lastName == Emp2.lastName
		&& Emp1.position == Emp2.position
		&& Emp1.senyority == Emp2.senyority
		&& Emp1.salary == Emp2.salary
		&& Emp1.index == Emp2.index
		&& Emp1.ifCharged == Emp2.ifCharged){
		return true;
	}

	else return false;
}


Employee& Employee::operator =(Employee& E){
	string fName;
	string lName;
	if (*this == E)
		return *this;
	else{
		E.getName(fName, lName);
		this->setAllParametrs(fName, lName, E.getPosition(), E.getSenyority(), E.getSalary(),
			E.getIndex(), E.getIfCharged());
		return *this;
	}
}

Employee operator+(Employee& E1, Employee& E2){
	Employee sumE;
	string fName;
	string lName;
	E1.getName(fName, lName);
	sumE.setName(fName, lName);
	sumE.setPosition(E1.getPosition());
	sumE.setSenyority(E1.getSenyority());
	sumE.setSalary(E1.getSalary() + E2.getSalary());
	sumE.setIndex(E1.getIndex());
	sumE.setIfCharged(E1.getIfCharged());
	return &sumE;
}

ostream& operator <<(ostream& os, const Employee& Emp){
	string fName;
	string lName;
	Emp.getName(fName, lName);
	cout << "ФИ: " << fName << " " << lName << endl;
	cout << "Должность: " << Emp.getPosition() << endl;
	cout << "Стаж: " << Emp.getSenyority() << endl;
	cout << "Оклад: " << Emp.getSalary() << endl;
	cout << "Индексация зарплаты: " << Emp.getIndex() << endl;
	if (Emp.getIfCharged() != 0) cout << "Выплачено." << endl << endl;
	else cout << "Не выплачено." << endl << endl;

	return os;
}

void Employee::printOn() const{
	cout << "ФИ: " << firstName << " " << lastName << endl;
	cout << "Должность: " << position << endl;
	cout << "Стаж: " << senyority << endl;
	cout << "Оклад: " << salary << endl;
	cout << "Индексация зарплаты: " << index << endl;
	if (ifCharged != 0) cout << "Выплачено." << endl << endl;
	else cout << "Не выплачено." << endl << endl;
}
