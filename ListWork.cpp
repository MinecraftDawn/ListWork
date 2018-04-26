#include <iostream>
#include <cstring>

using namespace std;

class Node{
public:
	Node(char name[100]="",int data=0){
		setData(data);
		setName(name);
		setPtr(NULL);
	}
	
	int getDate(){
		return _data;
	}
	void setData(int data){
		_data = data;
	}
	
	char *getName(){
		return _name;
	}
	void setName(char *name){
		strcpy(_name,name);
	}
	
	Node *getPtr(){
		return _ptr;
	}
	void setPtr(Node *ptr){
		_ptr = ptr;
	}

	/*******************************
	 �s�W��C�ñƦC 
	*******************************/
	void ADappendSort(int data,char name[]){
		Node *node = this;
		
		Node *temPtr = node;
		
		if(node->getDate() > data){ //���J�̫e�� 
			Node *t = new Node;
			
			t->setData(this->getDate());
			t->setName(this->getName());
			t->setPtr(this->getPtr());
			
			this->setData(data);
			this->setPtr(t);
			this->setName(name);

			return;
		}
	
		while(temPtr){
			if(temPtr->getDate() == data){ 
					cout << "���~�I�w�s�b�Ӹ�ơA�L�k�s�W" << endl;
					return;
			}
			
			if(temPtr->getPtr()){//�Y��J�Ȥ����C����
				if(temPtr->getDate()<data && temPtr->getPtr()->getDate()>data){
					Node *t = new Node;
					
					t->setData(data);
					t->setName(name);
					t->setPtr(temPtr->getPtr());
					
					temPtr->setPtr(t);

					return;
				}
			}else if(!temPtr->getPtr()){//�Y��J�Ȥj���Ӧ�C(�w���C����)
				temPtr->setPtr(new Node);
				temPtr = temPtr->getPtr();
				temPtr->setData(data);
				temPtr->setName(name);

				return;
			}
	
			temPtr = temPtr->getPtr();
		}
	
	}
	
	/*******************************
	��ܦ�C�ƭ� 
	*******************************/ 
	void showNode(){
		Node *temPtr = this;
		
		if(temPtr && !temPtr->getPtr()){//��C�u���@�ӭ� 
			if(strlen(temPtr->getName())==0){
				cout << "End" << endl;
				
				return;
			}
				
				
		}
		
		while(temPtr){
			cout << temPtr->getDate() << ": " << temPtr->getName() << " -> ";
			temPtr = temPtr->getPtr();
		}
		cout << "End" << endl;
		
	}
	
	void linerSearch(int data){
		Node *temPtr = this;
		int i=0;
		bool find=false;
		
		if(temPtr==NULL || temPtr->getName()==""){
			cout <<"�d�L���`�I"<<endl;
			return;
		}
		
		while(temPtr){
			i++;
			if(temPtr->getDate()==data){
				find = true;
				break;
			}
			temPtr = temPtr->getPtr();	
		}
		if(find)
		cout << "���F�I " <<  data <<
		" ����C���� " << i << " �Ӧ�m�A�W�r��"<< temPtr->getName() << endl;
		 
		else cout <<"�d�L���`�I"<<endl;  
	}
	
	/***************************
	�R����� 
	***************************/
	void delList(int data){
		Node *temPtr = this;
		
		if(this==NULL){//��C���� 
			cout << "[Warnning]�Ŧ�C�A�L�k�R��" << endl;
			return;
		}
		
		//�R���Y
		if(temPtr->getDate() == data){
			if(temPtr->getPtr()){//��C���U�@�� 
				Node *delPtr = temPtr->getPtr();
				
				temPtr->setData(temPtr->getPtr()->getDate());
				
				temPtr->setName(temPtr->getPtr()->getName());
				
				temPtr->setPtr(temPtr->getPtr()->getPtr());
				
				delete delPtr;
				
				return;
			}else{
				temPtr->setData(0);
				
				temPtr->setName("");
				
				temPtr->setPtr(NULL);
				
				return;
			}
		}
		
		while(temPtr->getPtr()){
			if(temPtr->getPtr()->getDate()==data){
				Node *delPtr = temPtr->getPtr();
				
				if(delPtr->getPtr()){//�b��C���� 
					temPtr->setPtr(delPtr->getPtr());
					
				}else{//�b��C���� 
					temPtr->setPtr(0);
				}
				delete delPtr;
				
				return;
				
			}
			temPtr = temPtr->getPtr();	
		}
		cout << "[Warnning]�d�L����ơA�]�ӵL�k�R��" << endl; 
		
	}
	
private:
	int _data;
	
	Node *_ptr;
	
	char _name[100];
};

class Menu{
	public:
		void run(){

			do{
				showMenu();
				cin >> func; 
				
				switch(func){
					case 1:
						addData();
						break;
						
					case 2:
						delData();
						break;
						
					case 3:
						Search();
						break;
						
					case 4:
						showNode();
				}
			}while(func!=5);
		}
		
		void showMenu(){
			cout << "�п�J�Q������\\��" << endl
			<< "1. �s�W���" << endl
			<< "2. �R�����" << endl
			<< "3. �d�߸��" << endl
			<< "4. �C�L���" << endl
			<< "5. ���}�t��" << endl << endl;
		}
		
	private:
		int func;
		
		Node *myNode=NULL;
		
		void addData(){
			
			int data=0;
			char name[100];
			
			cout << "�п�J�Q�s�W���ƭ�" << endl;
			cin >> data;
			cin.sync();//clear buffer
			cout << "�п�J�Q�s�W���W�r" << endl;
			cin.getline(name,100);
			
			if(!myNode){
				myNode = new Node(name,data);
			} 
			else{
				myNode->ADappendSort(data,name);
			} 
			
		}
		
		void delData(){
			int data=0;
			cout << "�п�J�Q�R������" << endl;
			cin >> data;
			myNode->delList(data);
		}
		
		void Search(){
			int data=0;
			cout << "�п�J�Q�d�ߪ���" << endl;
			cin >> data;
			myNode->linerSearch(data);
		}
		
		void showNode(){
			myNode->showNode();
		}
		
};

/***************************
�D�{�� 
***************************/
int main(){
	Menu myMenu;
	myMenu.run();
}
