//initializer_list, move, default, delete, move итераторы

// в классе поле std::vector vec
#include "Vec1.h"
#include "VEC_1.h"

// private наследование 
#include "Vec2.h"
#include "VEC_2.h"

#include "MyString.h"
#include "MyUniquePTR.h"
#include <vector>
#include <list>


int main()
{
	std::setlocale(LC_ALL, "Russian");
	//Задание 1. Создайте класс, 
	// который должен предоставлять функциональность вектора 
	//с УНИКАЛЬНЫМИ значениями любого типа в заданном диапазоне.

	//Например:
	//В нашей структуре хранятся целые с уникальными значениями и данных задан диапазон[1, 10]. 
	//Пользователь хочет добавить в наш вектор{ 2,-1,3,33, 5,2 }. 
	//В результате в нашем векторе должны храниться значения{ 2,3,5 }
	//Внимание: при инициализации или присваивании НЕ нужно менять порядок значений, 
	//заданный пользователем! При наличии повторяющихся значений нужно оставить первое!
	//•	Для хранения элементов используйте std::vector.

	//o	Вариант 1 : использовать std::vector в качестве внедренного объекта
	//o	Вариант 2 : наследовать свой класс от std::vector – 
	// при этом важно каким должен быть спецификатор наследования
	
	//Реализовать оба варианта!
	//•	Реализуйте конструктор, который может принимать любое количество 
	// значений(значения могут повторяться)
	//•	Реализуйте метод добавления любого количества значений(значения могут повторяться)
	//•	Реализуйте метод удаления любого количества значений(значения могут повторяться)
	//•	Предусмотрите возможность изменения диапазона хранимых значений
	//•	Реализуйте метод сортировки, который будет принимать в качестве параметра 
	// условие сортировки(по возрастанию / по убыванию / по модулю…)
	//•	и другие(полезные на Ваш взгляд) методы
	//•	явно обозначьте – какие методы вы делегируете сгенерировать компилятору автоматически
	//•	реализуйте возможность копирования из нашей структуры данных значения в другое хранилище, 
	//например:
	std::vector<int> v;

	{
		std::cout << "////////////////////////////////////////" << std::endl;
		std::cout << "диапазон задается в шаблонных параметрах      VEC1<int, X, Y>" << std::endl;
		VEC1<int, 1, 10> my1; // диапазон в параметрах шаблона - нельзя менять

		my1.push_back(3);
		my1.push_back(10);
		my1.push_back(15);
		my1.push_back(4);
		my1.push_back(20);
		my1.push_back(7);
		my1.push_back(-2);
		my1.push_back(5);
		std::cout << my1 << std::endl;
		bool c = my1.find(10);
		std::copy(my1.begin(), my1.end(), std::back_inserter(v));
		my1.sort(std::less<decltype(*my1.begin() + *my1.begin())>());
		// или
		//my1.sort([](auto x, auto y) { return x < y; });
		std::cout << my1 << std::endl;
		//my1.insert_range(my1.begin(), {1, 2});
		//my1.insert(my1.begin(), 1);
		std::cout << my1 << std::endl;
		//my1.insert_range(my1.begin(), std::vector{ 1, 3, 2, 7, 9 }); //  РАБОТАЕТ
		my1.insert_range(my1.begin(), std::initializer_list{ 1, 3, 2, 7, 9 });  //  РАБОТАЕТ
		//my1.insert_range(my2.begin(), { 1, 3, 2, 7, 9} );  // НЕ РАБОТАЕТ
		std::cout << my1 << std::endl;
		//std::cout << "new beginner element: " << * (my1.erase(my1.begin())) << std::endl;  //  РАБОТАЕТ
		std::cout << my1 << std::endl;
		//std::cout << "new beginner element: " << *(my1.erase(my1.cbegin())) << std::endl;  //  РАБОТАЕТ
		std::cout << my1 << std::endl;
		//my1.erase(++my1.begin(), ++(++(++my1.begin())));  //  РАБОТАЕТ
		std::cout << my1 << std::endl;
	}
	

	/////////////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << std::endl << "////////////////////////////////////////" << std::endl;
		std::cout << "класс со сменным диапазоном    Vec1<int>" << std::endl;
		Vec1 my2(1, 10); // диапазон можно менять
		my2.push_back(3);
		my2.push_back(10);
		my2.push_back(15);
		my2.push_back(4);
		my2.push_back(20);
		my2.push_back(7);
		my2.push_back(-2);
		my2.push_back(5);
		std::cout << my2 << std::endl;
		my2.set_range(4, 6);
		std::cout << my2 << std::endl;
		my2.sort(std::greater<int>());
		std::cout << my2 << std::endl;
		my2.insert(my2.begin(), 6);
		std::cout << my2 << std::endl;
		my2.set_range(1, 10);
		my2.insert_range(my2.begin(), std::vector{ 1, 3, 2, 7, 9 }); //  РАБОТАЕТ 
		//my2.insert_range(my2.begin(), std::initializer_list{ 1, 3, 2, 7, 9 }); //  РАБОТАЕТ
		//my2.insert_range(my2.begin(), { 1, 3, 2, 7, 9} );   // НЕ РАБОТАЕТ 
		std::cout << my2 << std::endl;
		//std::cout << "new beginner element: " << * (my2.erase(my2.begin())) << std::endl;  //  РАБОТАЕТ
		std::cout << my2 << std::endl;
		//std::cout << "new beginner element: " << *(my2.erase(my2.cbegin())) << std::endl;  //  РАБОТАЕТ
		std::cout << my2 << std::endl;
		//my2.erase(++my2.begin(), ++(++(++my2.begin())));  //  РАБОТАЕТ
		std::cout << my2 << std::endl;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	///*
	{
		std::cout << std::endl << "////////////////////////////////////////" << std::endl;
		std::cout << "диапазон задается в шаблонных параметрах    VEC2<int, X, Y>" << std::endl;
		VEC2<int, 1, 10> myVEC2; // диапазон в параметрах шаблона - нельзя менять

		myVEC2.push_back(3);
		myVEC2.push_back(10);
		myVEC2.push_back(15);
		myVEC2.push_back(4);
		myVEC2.push_back(20);
		myVEC2.push_back(7);
		myVEC2.push_back(-2);
		myVEC2.push_back(5);
		int s = myVEC2.size();
		std::cout << myVEC2 << std::endl;

		std::copy(myVEC2.begin(), myVEC2.end(), std::back_inserter(v));
		myVEC2.sort(std::less<decltype(*myVEC2.begin() + *myVEC2.begin())>());
		// или
		//my1.sort([](auto x, auto y) { return x < y; });
		std::cout << myVEC2 << std::endl;
		//my1.insert_range(my1.begin(), {1, 2});
		//my1.insert(my1.begin(), 1);
		std::cout << myVEC2 << std::endl;
		myVEC2.insert_range(myVEC2.begin(), std::vector{ 1, 3, 2, 7, 9 }); //   РАБОТАЕТ
		//myVEC2.insert_range(myVEC2.begin(), std::initializer_list{ 1, 3, 2, 7, 9 });  // РАБОТАЕТ
		//myVEC2.insert_range(myVEC2.begin(), { 1, 3, 2, 7, 9} );  // НЕ РАБОТАЕТ

		std::cout << myVEC2 << std::endl;
		bool a = myVEC2.find(3);
		std::cout << myVEC2 << std::endl;
		//std::cout << "new beginner element: " << * (myVEC2.erase(myVEC2.begin())) << std::endl;  //  РАБОТАЕТ
		std::cout << myVEC2 << std::endl;
		//std::cout << "new beginner element: " << *(myVEC2.erase(myVEC2.cbegin())) << std::endl;  //  РАБОТАЕТ
		std::cout << myVEC2 << std::endl;
		//myVEC2.erase(++myVEC2.begin(), ++(++(++myVEC2.begin())));  //  РАБОТАЕТ
		std::cout << myVEC2 << std::endl;

	}
	//*/
	///*
	/////////////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << std::endl << "////////////////////////////////////////" << std::endl;
		std::cout << "класс со сменным диапазоном    Vec2<int>" << std::endl;
		Vec2 myVec2(1, 10); // диапазон можно менять
		myVec2.push_back(3);
		myVec2.push_back(10);
		myVec2.push_back(15);
		myVec2.push_back(4);
		myVec2.push_back(20);
		myVec2.push_back(7);
		myVec2.push_back(-2);
		myVec2.push_back(5);
		std::cout << myVec2 << std::endl;
		myVec2.set_range(4, 6);
		std::cout << myVec2 << std::endl;
		myVec2.sort(std::greater<int>());
		std::cout << myVec2 << std::endl;
		myVec2.insert(myVec2.begin(), 6);
		std::cout << myVec2 << std::endl;
		myVec2.set_range(1, 10);
		myVec2.insert_range(myVec2.begin(), std::vector{ 1, 3, 2, 7, 9 }); //  РАБОТАЕТ 
		//myVec2.insert_range(myVec2.begin(), std::initializer_list{ 1, 3, 2, 7, 9 }); //  РАБОТАЕТ
		//myVec2.insert_range(myVec2.begin(), { 1, 3, 2, 7, 9} );   // НЕ РАБОТАЕТ 
		std::cout << myVec2 << std::endl;

		bool a = myVec2.find(3);
		std::cout << myVec2 << std::endl;
		//std::cout << "new beginner element: " << * (myVec2.erase(myVec2.begin())) << std::endl;  //  РАБОТАЕТ
		std::cout << myVec2 << std::endl;
		//std::cout << "new beginner element: " << *(myVec2.erase(myVec2.cbegin())) << std::endl;  //  РАБОТАЕТ
		std::cout << myVec2 << std::endl;
		//myVec2.erase(++myVec2.begin(), ++(++(++myVec2.begin())));  //  РАБОТАЕТ
		std::cout << myVec2 << std::endl;
		std::cout << myVec2.at(1) << " " << myVec2[0] << std::endl;
	}
	//*/

	/////////////////////////////////////////////////////////////////////////////////////////
	//Задание 2. Реализуйте шаблон класса MyUniquePTR, 
	//который является оберткой для указателя на объект любого типа.
	//Задача – класс должен обеспечивать единоличное владение динамически создаваемым объектом. 
	//Проверить функционирование шаблона на примере MyString :
	{
		MyUniquePTR<MyString> p1(new MyString("abc"));
		std::cout << p1->GetString() << std::endl;
		//p1->SetNewString("qwerty");
		MyString  s2 = *p1;
		//MyUniquePTR<MyString> p2 = p1; //здесь компилятор должен выдавать ошибку => 
		//Исправьте!
		if (p1) { std::cout << "No object!" << std::endl; } //а это должно работать


		MyUniquePTR<MyString> p3(new MyString("vvv"));
		//p3 = p2; //и здесь компилятор должен выдавать ошибку

		////////////////////////////////////////////////////////////////////////////////////
		//std::vector<MyUniquePTR<MyString>> v{ std::move(MyUniquePTR(new MyString("qwe"))),  // НЕ РАБОТАЕТ
		//									std::move(MyUniquePTR(new MyString("rfg"))),
		//									std::move(MyUniquePTR(new MyString("ujh"))) }; //как проинициализировать???
		std::list<MyUniquePTR<MyString>> l;
		//как скопировать из v в l ???   НЕЛЬЗЯ КОПИРОВАТЬ
		//for (auto it = v.begin(); it != v.end(); ++it) // почему не работает?
		//	l.push_back(std::move(*it));
		

		////////////////////////////////////////////////////////////////////////////////////
		MyString m0;
		MyString m1{ "m1" };
		MyString m2{ "m2" };
		MyString m3{ "m3" };
		m1 = m0 + m1 + m3;
		m0 += m1 + m2;

		std::cout << std::endl << m1;
	}

	return 0;
}

// MyString   утечка памяти