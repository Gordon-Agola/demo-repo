#include <iostream>
using namespace std;

class Node{
	public:
	    int data;
	    int key;
	    Node* next;
	    Node* prev;
	    
	    Node(){
	    	key=0;
	    	data=0;
	    	next=NULL;
	    	prev=NULL;
		}
		Node(int k, int d){
			key=k;
			data=d;
		}
};

class DoublyLinkedList{
	public:
		Node* head;
		
		DoublyLinkedList(){
			head=NULL;
		}
		
		DoublyLinkedList(Node* n){
			head=n;
			
		}
		//check if node exist using key
		Node* checkIfNodeExist(int k){
			Node* temp =NULL;
			Node* ptr = head;
			
			while(ptr!=NULL){
				if(ptr->key==k){
					temp=ptr;
				}
				ptr=ptr->next;
			}
			return temp; 
		}
		//append a node to the end
		void appendNode(Node* n){
			if(checkIfNodeExist(n->key)!=NULL){
				cout<<"Node already exist with key value: "<<n->key<<" Append another node with different key value"<<endl;
			}
			else{
				if(head==NULL){
					head=n;
					cout<<"Node appended as head"<<endl;
				}
				else{
				Node* ptr=head;
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				ptr->next=n;
				n->prev=ptr;
				cout<<"Node appended"<<endl;
				}
			}
		}
			//prepend
			void prependNode(Node* n)
			{
				if(checkIfNodeExist(n->key)!=NULL){
					cout<<"The node is already exists with key value: "<<n->key<<". Append another node"<<endl;
				}else{
				if(head==NULL){
					head=n;
					cout<<"Node prepended as head"<<endl;
				}else{
					head->prev=n;
					n->next=head;
					head=n;
					
					cout<<"Node prepended"<<endl;
				}
					
				}
			}
			
		
		//insert a node after a particular node in the list
		void insertNodeAfter(int k, Node* n){
			Node* ptr = checkIfNodeExist(k);
			if(ptr==NULL){
				cout<<"No node with key value: "<<k<<endl;
			}
			else{
				if(checkIfNodeExist(n->key)!=NULL){
				cout<<"Node already exist with key value: "<<n->key<<" Append another node with different key value"<<endl;
			}
			else{
				cout<<"inserting"<<endl;
				Node* nextNode = ptr->next;
				//inserting at the end
				if(nextNode==NULL){
					ptr->next=n;
					n->prev=ptr;
					
					cout<<"Node Inserted"<<endl;
				}
				//inserting in between
				else{
					n->next=nextNode;
					nextNode->prev=n;
					n->prev=ptr;
					ptr->next=n;
					
					cout<<"Node inserted in between"<<endl;
				}
			}
			}
		} 
		//delete node
		void deleteNodeByKey(int k){
			Node* ptr = checkIfNodeExist(k);
			if(ptr==NULL){
				cout<<"No node exists with key value "<<k<<endl;
			}
			else{
				
				if(head->key==k){
					head=head->next;
					cout<<"Node UNLINKED with key value: "<<k<<endl;
				}
				else{
					Node* nextNode=ptr->next;
					Node* prevNode=ptr->prev;
					//deleting at the end
					if(nextNode==NULL){
						prevNode->next=NULL;
						cout<<"Node deleted at the end"<<endl;
					}
					//deleting at the end
					else{
						prevNode->next=nextNode;
						nextNode->prev=prevNode;
						cout<<"Node deleted successfully"<<endl;
					}
				}
			} 
		
	}
		//update node
		void updateNodeBYKey(int k, int d){
			Node* ptr=checkIfNodeExist(k);
			if(ptr!=NULL){
				ptr->data=d;
				cout<<"Node Data Updated Successfully";
			}else{cout<<"Node Doesn't exists"<<endl;
			}
		}
		//print
		void printList(){
			if(head==NULL){
				cout<<"NO Nodes in Doubly Linked List";
			}
			else{
				cout<<endl<<"Doubly Linked List values: "<<endl;
				Node* temp = head;
				
				while(temp!=NULL){
					cout<<"("<<temp->key<<","<<temp->data<<") <--->";
					temp = temp->next;
				}
			}
		}
};

int main(){
	DoublyLinkedList obj;
	int option;
	int key1,k1,data1;
	do{
		cout<<"\nWhat operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
		cout<<"1 appendNode()"<<endl;
		cout<<"2 prependNode()"<<endl;
		cout<<"3 insertNodeAfter()"<<endl;
		cout<<"4 deleteNodeByKey()"<<endl;
		cout<<"5 updateNodeByKey()"<<endl;
		cout<<"6 print()"<<endl;
		cout<<"7 Clear Screen()"<<endl;
		
		cin>>option;
		Node* n1 = new Node();
		//Node n1
		
		switch(option){
			case 0:
				break;
			case 1:
				cout<<"Append Node Operation\n Enter key & data of the Node to be Appended"<<endl;
				cin>>key1;
				cin>>data1;
				
				n1->key=key1;
				n1->data=data1;
				obj.appendNode(n1);
				break;
				
			case 2:
				cout<<"prepend Node Operation\n Enter key & data of the Node to be prepended"<<endl;
				cin>>key1;
				cin>>data1;
				
				n1->key=key1;
				n1->data=data1;
				obj.prependNode(n1);
				break;
			case 3:
				cout<<"Insert Node after Operation\n Enter key of existing Node after which you want to insert new node"<<endl;
				cin>>k1;
				cout<<"Enter key and data of new node: "<<endl;
				cin>>key1;
				cin>>data1;
				
				n1->key=key1;
				n1->data=data1;
				obj.insertNodeAfter(k1,n1);
				break;
				
			case 4:
				cout<<"Delete node by key - \nEnter key of Node to be deleted: "<<endl;
				cin>>k1;
				obj.deleteNodeByKey(k1);
				
				break;
				
			case 5:
				cout<<"Update node by key - \nEnter key and New data to be updated: "<<endl;
				cin>>key1;
				cin>>data1;
				obj.updateNodeBYKey(key1,data1);
				
				break;
				
			case 6:
				obj.printList();
				break;
			case 7:
				system("cls");
				break;
				
			default:
				cout<<"Enter proper operation";
				
				
		}
	}while(option!=0);
	
	return 0;
}
