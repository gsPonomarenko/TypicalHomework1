#include "Department.h"

void main(){

	setlocale(LC_ALL, "Russian");

	/** Тестирование функционала класса Employee*/
	cout << "Тестирования функционала класса Employee" << endl;
	string fName;
	string lName;
	string position;
	int senyority;
	int salary;
	float index;
	bool ifCharged;

	Employee E1;
	E1.printOn();

	Employee E2("Dmitry", "Semenov", "first officer", 2007, 100000);
	cout << E2;

	Employee E3("Konstantin", "Smolensky", "co-pilot", 2012, 60000, 5.0, true);
	
	E3.getName(fName, lName);
	position = E3.getPosition();
	senyority = E3.getSenyority();
	salary = E3.getSalary();
	index = E3.getIndex();
	ifCharged = E3.getIfCharged();

	Employee* pE = new Employee;
	pE->setAllParametrs(fName, lName, position, senyority, salary, index, ifCharged);
	cout << *pE;

	Employee* ppE = &E1;
	E2.getAllParametrs(fName, lName, position, senyority, salary, index, ifCharged);
	
	ppE->setName(fName, lName);
	ppE->setPosition(position);
	ppE->setSenyority(senyority);
	ppE->setSalary(salary);
	ppE->setIndex(index);
	ppE->setIfCharged(ifCharged);

	ppE->printOn();

	Employee E4(E2);
	E4.setName("Nikita", "Assorov");
	cout << E2 << E4;

	Employee E5;
	E5 = E4;
	E5.setPosition("flight dispatcher");
	cout << E4 << E5;

	Employee E6 = E5 + E3;
	cout << E6;
	
	/** Тестирования функционала класса Department */
	cout << "Тестирования функционала класса Department" << endl;
	string name;
	int numberDepartment;
	int size;
	int sumSalary;

	Department D1;
	cout << D1;
	D1.addEmployee(E1);
	Department D2("Delta Airlines");
	cout << D2;
	D2.addEmployee(pE);
	cout << D2;

	D2 + E3;
	cout << D2;

	D2.getName(name);
	D1.setName(name);
	numberDepartment = D2.getNumberDepartment();
	D1.setNumberDepartment(numberDepartment);
	size = D2.getSize();
	D1.doResize(size);
	size++;
	D1.doResize(size);
	
	D1 = D1 + D2;
	cout << D1;

	/**Проверка выплаты зарплаты.*/
	D1.getChargingInfo();
	
	/** Зарплату выплатили всем.*/
	D1.setChargingInfo(true);
	D1.getChargingInfo();

	/** Всего выплатили*/
	sumSalary = D1.getSummarySalary();
	cout << "Всего выплатили " << sumSalary << endl;

	/** Зарплату не выплатили никому.*/
	D1.setChargingInfo(false);
	D1.getChargingInfo();

	Department* pD3 =  new Department("American Eagle", 3);
	pD3->printOn();


	Department D4("Pan American", 4, 1);
	D4.printOn();
	D4.delEmployee("Max", "Kabanov");
	D4.delEmployee("", "");
	D4.printOn();
	
	delete pD3;
	delete pE;

	system("pause");
}
