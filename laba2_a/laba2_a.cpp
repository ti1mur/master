#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

//Открыть консольное приложение.
//Задать два не абстрактных класса, связанных в полиморфную иерархию : Class1(базовый) и Class2.
//В главной функции программы создать несколько автоматических объектов этих типов.
//Затем посредством вызова функции my_copy скопировать эти объекты в базу данных(использовать vector), 
//т.е.в базе данных должны оказаться копии созданных автоматических объектов.
//Далее, вывести на консоль информацию о типах хранимых в БД объектах, используя typeid.
//Исключить утечку памяти.

class Class1 {
public:
	Class1() {}
	virtual ~Class1() 
	{
		std::cout << "Class 1" << std::endl;
	}
	virtual Class1* clone() const{
		return new Class1(*this);
	}
};
class Class2 : public Class1 {
public:
	Class2* clone() const{
		return new Class2(*this);
	}
	Class2() {}
	~Class2() 
	{
		std::cout << "Class 2" << std::endl;
	}
};
class data_base {
private:
	vector <Class1*> base;
public:
	data_base()
	{
		base.reserve(10);
	}
	void my_copy(const Class1 &obj) {
		base.emplace_back(obj.clone());
	}
	void type() const {
		for (Class1* element : base) {
			cout << typeid(element).name() << endl;
		}
	}
	~data_base() 
	{
		std::cout << "Delete copied classes" << std::endl;
		for (Class1* element : base)
		{
			delete element;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	data_base basa;
	{
		Class1 obj1;
		Class2 obj2;
		basa.my_copy(obj1);
		basa.my_copy(obj2);
	}
	std::cout << "delete local objects" << std::endl;
	basa.type();
	return 0;
}
