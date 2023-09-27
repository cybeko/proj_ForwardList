#include <iostream>
using namespace std;


struct Element
{
	char data;
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);
	void AddPos(char data, int pos);
	int SearchPos(char data);


	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	void DelPos(int pos);
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
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
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}

// �������� ������
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
