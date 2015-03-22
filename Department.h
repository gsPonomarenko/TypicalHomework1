#include "Employee.h"

class Department : public list<Employee>{
public:
	Department();
	Department(string n);
	Department(string n, int nD);
	Department(string n, int nD, int s);

	bool addEmployee(Employee& Emp);
	bool addEmployee(Employee* pE);
	bool delEmployee(string fName, string lName);

	void setNumberDepartment(int nD);
	int getNumberDepartment();

	int getSize();
	void doResize(int s);
	void checkCharging();
	void getChargingInfo();
	void setChargingInfo(bool charged);
	int getSummarySalary();

	friend bool operator ==(Department& Dep1, Department& Dep2);
	Department& operator =(Department& Dep1);
	friend Department& operator+(Department& Dep1, Department& Dep2);
	friend void operator+(Department& Dep, Employee& Emp);
	friend ostream& operator <<(ostream& os, const Department& Dep);

	virtual void setName(string n);
	virtual void getName(string& n) const;
	virtual void printOn() const;


protected:
	string name;
	int numberDepartment;
	int size;

	bool ifSomeoneCharged;
	bool ifDepartmentCharged;

	Department* pListOfNear;
};

Department::Department(){
	name = "";
	numberDepartment = 0;
	size = 0;
}

Department::Department(string n){
	name = n;
	numberDepartment = 0;
	size = 0;
}

Department::Department(string n, int nD){
	name = n;
	numberDepartment = nD;
	size = 0;
}

Department::Department(string n, int nD, int s){
	name = n;
	numberDepartment = nD;
	size = s;
	for (int i = 0; i < s; i++)
	{
		push_back(Employee());
	}

}

void Department::setNumberDepartment(int nD){
	numberDepartment = nD;
}

int Department::getNumberDepartment(){
	return numberDepartment;
}

bool Department::addEmployee(Employee& Emp){
	for (const_iterator it = begin(); it != end(); it++){
		if (*it == Emp){
			cout << "Невозможно добавить сотрудника, так как он уже присустсвует в базе." << endl;
			return 0;
		}
	}
	push_back(&Emp);
	size++;
	cout << "Сотрудник успешно внесён в базу." << endl;
	return 1;
}

bool Department::addEmployee(Employee* pE){
	
	for (const_iterator it = begin(); it != end(); it++){
		if (*it == *pE){
			cout << "Невозможно добавить сотрудника, так как он уже присустсвует в базе." << endl;
			return 0;
		}
	}
	push_back(pE);
	size++;
	cout << "Сотрудник успешно внесён в базу." << endl;
	return 1;
}

bool Department::delEmployee(string fName, string lName){
	string fN;
	string lN;
	const_iterator it;
	int check = 0;
	for (it = begin(); (check == 0) && it != end(); it++){
		it->getName(fN, lN);
		if (fN == fName && lN == lName){
			check++;
			erase(it);
			size--;
			cout << "Информация о сотруднике " << fName << " " << lName << " успешно удалена." << endl;
			return 1;
		}
	}
	cout << "Сотрудник " << fName << " " << lName << " не найден." << endl;
	return 0;
}

void Department::doResize(int s){
	int n = 0;
	if (s > size){
		n = s - size;
		for (int i = 0; i < n; i++){
			push_back(Employee());
			size++;
		}
	}
	else cout << "В отделе уже не меньше " << s << " сотрудников." << endl;

}

int Department::getSize(){
	return size;
}

void Department::checkCharging(){
	int i = 0;
	for (const_iterator it = begin(); it != end(); it++){
		i += it->getIfCharged();
	}

	if (i == 0){
		ifDepartmentCharged = 0;
		ifSomeoneCharged = 0;
	}
	else if (i > 0 && i < size){
		ifDepartmentCharged = 0;
		ifSomeoneCharged = 1;
	}
	else{
		ifDepartmentCharged = 1;
		ifSomeoneCharged = 1;
	}
}

void Department::getChargingInfo(){
	string fName;
	string lName;

	checkCharging();
	if (empty())
		cout << "В отделе нет сотрудников." << endl;
	else{
		if (ifDepartmentCharged)
			cout << "Зарплата выплачена всему отделу." << endl;
		else if (ifSomeoneCharged){
			cout << "Началась выплата зарплаты. Получили зарплату:" << endl;
			for (const_iterator it = begin(); it != end(); it++){
				if (it->getIfCharged()){
					it->getName(fName, lName);
					cout << fName << " " << lName << endl;
				}
			}
		}
		else cout << "Выплата зарплаты в отеделе " << name << " не производилась." << endl;
	}
}

void Department::setChargingInfo(bool charged){
	if (empty())
		cout << "В отделе нет сотрудников." << endl;
	else{
		for (iterator it = begin(); it != end(); it++){
			it->setIfCharged(charged);
		}
	}
}

int Department::getSummarySalary(){
	int salary = 0;
	if (empty()){
		cout << "В отделе нет сотрудников." << endl;
		return 0;
	}
	else{
		for (const_iterator it = begin(); it != end(); it++){
			salary += it->getSalary();
		}
	}
	return salary;
}

bool operator ==(Department& Dep1, Department& Dep2){
	bool ifDuplicate = 0;
	if (Dep1.name == Dep2.name
		&& Dep1.numberDepartment == Dep2.numberDepartment
		&& Dep1.size == Dep2.size)
		ifDuplicate = true;

	list<Employee>::iterator it1 = Dep1.begin();
	list<Employee>::iterator it1End = Dep1.end();
	list<Employee>::iterator it2 = Dep2.begin();
	list<Employee>::iterator it2End = Dep2.end();

	while (it1 != it1End && it2 != it2End && ifDuplicate == 0){
		if (*it1 == *it2)
			ifDuplicate = true;
		it1++;
		it2++;
	}
	return ifDuplicate;
}

Department& Department::operator=(Department& Dep1){
	if (Dep1 == *this)
		return *this;
	else splice(end(), Dep1);
	return *this;
}

Department& operator+(Department& Dep1, Department& Dep2){
	list<Employee>::iterator it = Dep1.end();
	Dep1.splice(Dep1.cend(), Dep2);
	return Dep1;
}

void operator+(Department& Dep, Employee& Emp){
	bool add = 0;
	list<Employee>::const_iterator it = Dep.begin();
	for (; it != Dep.end(); it++){
		if (*it == Emp){
			cout << "Невозможно добавить сотрудника, так как он уже присустсвует в базе." << endl;
			add++;
		}
	}
	if (add == 0){
		Dep.push_back(&Emp);
		Dep.size++;
	}
}

ostream& operator <<(ostream& os, const Department& Dep){
	cout << "*****************************" << endl;
	cout << "Название отдела: " << Dep.name << endl;
	cout << "Номер отдела: " << Dep.numberDepartment << endl;
	cout << "Размер отдела: " << Dep.size << endl;
	if (Dep.empty())
		cout << "В отделе нет сотрудников." << endl;
	else{
		cout << "Сотрудники:" << endl;
		for (list<Employee>::const_iterator it = Dep.begin(); it != Dep.end(); it++){
			cout << *it;
		}
	}
	return os;
}

void Department::setName(string n){
	name = n;
}

void Department::getName(string& n) const{
	n = name;
}

void Department::printOn() const{
	cout << "*****************************" << endl;
	cout << "Название отдела: " << name << endl;
	cout << "Номер отдела: " << numberDepartment << endl;
	cout << "Размер отдела: " << size << endl;
	if (empty())
		cout << "В отделе нет сотрудников." << endl;
	else{
		cout << "Сотрудники:" << endl;
		for (const_iterator it = begin(); it != end(); it++){
			cout << *it;
		}
	}
}
