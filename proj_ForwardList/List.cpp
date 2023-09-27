#include <iostream>
using namespace std;


struct Element
{
	char data;
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);
	void AddPos(char data, int pos);
	int SearchPos(char data);


	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	void DelPos(int pos);
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();
};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
	}
	Count++;

}

void List::AddPos(char data, int pos)
{
	if (pos < 0 || pos > Count)
	{
		return;
	}
	else
	{
		Element* newEl = new Element;
		newEl->data = data;
		newEl->Next = NULL;

		Element* temp = Head;

		while (pos > 2)
		{
			temp = temp->Next;
			pos--;
		}
		newEl->Next = temp->Next;
		temp->Next = newEl;
		Count++;
	}
}
int List::SearchPos(char data)
{
	Element* temp = Head;
	for (int i = 1; i != Count; i++)
	{
		if (temp->data == data)
		{
			return i;
		}
		else
		{
			temp = temp->Next;
		}
	}
	return NULL;
}
void List::DelPos(int pos)
{
	Element* temp = Head;
	while (pos > 2)
	{
		temp = temp->Next;
		pos--;
	}
	Element* del = temp->Next;
	temp->Next = del->Next;
	delete del;
	Count--;
}
void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
	Count--;
}


void List::DelAll()
{
	while (Head != 0)
	{
		Del();
		Count--;
	}
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}

// Тестовый пример
void main()
{
	List lst;
	char s[] = "Hello, World !!!";
	cout << s << "\n";
	int len = strlen(s);

	for (int i = 0; i < len; i++)
	{
		lst.Add(s[i]);
	}
	lst.Print();

	lst.DelPos(3);
	lst.Print();
	lst.AddPos('_', 3);
	lst.Print();
	cout<< lst.SearchPos('_');

}
