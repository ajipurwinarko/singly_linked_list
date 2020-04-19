#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;	
};
class list
{
	private:
	node *head, *tail;
	public:
	list()
	{
		head=NULL;
		tail=NULL;
	}
	void buat_node(int value)
	{
		node *temp=new node;
		temp->data=value;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else
		{	
			tail->next=temp;
			tail=temp;
		}
	}
	void tampilkan()
	{
		node *temp=new node;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}
	void insert_awal(int value)
	{
		node *temp=new node;
		temp->data=value;
		temp->next=head;
		head=temp;
	}
	void insert_posisi(int pos, int value)
	{
		node *pre=new node;
		node *cur=new node;
		node *temp=new node;
		cur=head;
		for(int i=1;i<pos;i++)
		{
			pre=cur;
			cur=cur->next;
		}
		temp->data=value;
		pre->next=temp;	
		temp->next=cur;
	}
	void delete_awal()
	{
		node *temp=new node;
		temp=head;
		head=head->next;
		delete temp;
	}
	void delete_akhir()
	{
		node *current=new node;
		node *previous=new node;
		current=head;
		while(current->next!=NULL)
		{
			previous=current;
			current=current->next;	
		}
		tail=previous;
		previous->next=NULL;
		delete current;
	}
	void delete_posisi(int pos)
	{
		node *current=new node;
		node *previous=new node;
		current=head;
		for(int i=1;i<pos;i++)
		{
			previous=current;
			current=current->next;
		}
		previous->next=current->next;
	}
};
int main()
{
	list obj;
	obj.buat_node(5);
	obj.buat_node(10);
	obj.buat_node(15);
	obj.buat_node(20);
	cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                  Menampilkan semua node             \n";
	cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	obj.tampilkan();
	cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                  Inserting di awal            \n";
	cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	obj.insert_awal(0);
	obj.tampilkan();
	cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                  Inserting di akhir            \n";
	cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	obj.buat_node(25);
	obj.tampilkan();
	cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                  Inserting di posisi tertentu            \n";
	cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	obj.insert_posisi(3,50);
	obj.tampilkan();
	cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                  Deleting di awal            \n";
	cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	obj.delete_awal();
	obj.tampilkan();
	cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                  Deleting di akhir            \n";
	cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	obj.delete_akhir();
	obj.tampilkan();
	cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"                  Deleting di posisi tertentu           \n";
	cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	obj.delete_posisi(4);
	obj.tampilkan();
	cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	
	return 0;
}
