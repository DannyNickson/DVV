#include <iostream>
using namespace std;
class Node
{
public:
	Node* ptr;
	int data = 0;
	Node(int data1)
	{
		ptr = nullptr;
		data = data1;
	}

};
class List
{
	
public:
	Node* first = nullptr;
	Node* last = nullptr;
	List()
	{
		this->first = nullptr;
		this->last = nullptr;
	}
	List(Node* fr)
	{
		this->first = fr;
		this->last = nullptr;
	}
	void add_Node(int data)
	{
		Node* current = first;
		Node* New = new Node(data);
		if (first == nullptr)
		{
			first = New;
		}
		else
		{
			last ->ptr = New;
		}
		last = New;
	}
	void Print()
	{
		Node* current = first;
		while (current != nullptr)
		{
			cout << "Data - " << current->data << endl;
			current = current->ptr;
			
		}
		cout << endl;
		cout << endl;
	}
	
};
Node* summ(Node* head1, Node* head2)
{
	Node* curr;

	if (head1->data > head2->data) {

		curr = head2;

		head2 = head2->ptr;

	}

	else {

		curr = head1;

		head1 = head1->ptr;

	}

	Node* head = curr;

	while (head1 && head2) {

		if (head1->data < head2->data) {

			curr->ptr = head1;

			head1 = head1->ptr;

			curr = curr->ptr;

		}

		else {

			curr->ptr = head2;

			head2 = head2->ptr;

			curr = curr->ptr;

		}

	}

	while (head1) {

		curr->ptr = head1;

		head1 = head1->ptr;

		curr = curr->ptr;

	}

	while (head2) {

		curr->ptr = head2;

		head2 = head2->ptr;

		curr = curr->ptr;

	}

	return head;
}
int main()
{
	List a;
	List b;
	a.add_Node(10);
	a.add_Node(15);
	a.add_Node(20);
	a.Print();
	b.add_Node(9);
	b.add_Node(16);
	b.add_Node(19);
	b.Print();
	List ab(summ(a.first, b.first));
	ab.Print();
	return 0;
}