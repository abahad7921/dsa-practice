#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node * next;

	node(int x)
	{
		this->data = x;
	}
};

void insertAtHead(node* &head,int x)
{
	if(head == NULL)
	{
		head = new node(x);
		head->next = NULL;
		return;
	}

	node *temp = new node(x);
	temp->next = head;
	head = temp;
}

void printLL(node* head)
{	
	node * temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main()
{
	
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif
  
	node* head = NULL;

	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);

	printLL(head);

	return 0;

}
