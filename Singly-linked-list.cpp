/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
second, third and final year of department can be granted membership on request. Similarly
one may cancel the membership of club. First node is reserved for president of club and last
node is reserved for secretary of club. Write C++ program to maintain club member‘s
information using singly linked list. Store student PRN and Name. Write functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. Concatenate two lists.
*/
# include<bits/stdc++.h>
using namespace std;
class Node {
public:
	int prn;
	string name;
	Node* next;

	Node()
	{
		prn = 0;
		next = NULL;
	}
	Node(string name1)
	{
		this->name = name1;
		this->next = NULL;
	}
	Node(int prn)
	{
		this->prn = prn;
		this->next = NULL;
	}
	
};

class Linkedlist {
	Node* head;

public:

	Linkedlist() { head = NULL; }
	void insertNode(string);
	void insertNode(int);

	void printList();
	void printListS();
	int count();
	void concat();
	


};


void Linkedlist::concat()
{
	
	int n1;
	string data1;
	cout<<"Enter how many elements you want to enter in linked list 2: ";
	cin>>n1;
	for (int i= 0; i<n1; i++)
	{
		cout<<"Enter Element: ";
		cin>>data1;
		Linkedlist::insertNode(data1);
	}
	
	
}
int Linkedlist::count()
{
	int cnt = 0;
	Node* temp = head;
	if (head == NULL) {
		
		return cnt;
	}

	while (temp != NULL) {
		cnt += 1;
		temp = temp->next;
	}
	return cnt;
}
void Linkedlist::insertNode(string name1)
{
	Node* newNode = new Node(name1);
	if (head == NULL) {
		head = newNode;
		return;
	}


	Node* temp = head;
	while (temp->next != NULL) {

		temp = temp->next;
	}

	temp->next = newNode;
}
void Linkedlist::insertNode(int prn)
{
	Node* newNode = new Node(prn);
	if (head == NULL) {
		head = newNode;
		return;
	}


	Node* temp = head;
	while (temp->next != NULL) {

		temp = temp->next;
	}

	temp->next = newNode;
}

void Linkedlist::printListS()
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->name << "->";
		temp = temp->next;
	}
	if (temp==NULL)
	{
		cout<<"NULL";
	}
}

void Linkedlist::printList()
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->prn << "->";
		temp = temp->next;
	}
	if (temp==NULL)
	{
		cout<<"NULL";
	}
}

int main()
{
	Linkedlist list;
	int prn;
	string name1;
	string yesNO;
	string choice;
	cout<<"What you want to enter 1)PRN 2)Name:";
    cin>>choice;
    while (1)
    {
    	
    	
    	if (choice=="PRN" || choice == "prn")
    	{
    		cout<<"Enter PRN No.: ";
	    	cin>>prn;
	    	list.insertNode(prn);
	    	cout<<"DO you want to continue press y otherwise press n: ";
	    	cin>>yesNO;
	    	if (yesNO=="y")
	    	continue;
	    	else
	    	break;
		}
    	else if (choice=="name" || choice=="Name")
    	{
    		cout<<"Enter Name of student: ";
	    	cin>>name1;
	    	list.insertNode(name1);
	    	cout<<"DO you want to continue press y otherwise press n: ";
	    	cin>>yesNO;
	    	if (yesNO=="y")
	    	continue;
	    	else
	    	break;
		}
			
	}


	cout << "------------------------Elements of the list are ----------------------------\n";

	if(choice=="name" || choice=="Name")
	list.printListS();
	else if(choice=="PRN" || choice == "prn")
	list.printList();
	
	cout<<"\nCount of element in linked list is: "<<list.count()<<endl;
	cout << endl;

	list.concat();
	cout<<"Concatenated link list: ";
	list.printListS();
	cout<<"\nCount of element in concatenated linked list is: "<<list.count()<<endl;
	cout << endl;
	return 0;
}
