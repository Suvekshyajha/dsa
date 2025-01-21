//circular queue as adt
#include<iostream>
#define max 5
using namespace std;
class circular{
	public:
		int rear;
		int front;
		int q[max];
		circular(){
			rear=max-1;
			front=max-1;
		}
		bool isempty(){
			return rear==front;
		}
		bool isfull(){
			return front==(rear+1)%max;
		}
		void enqueue(){
			if(isfull()){
				cout<<"queue is full."<<endl;
				
			}
			else{
				char item;
				cout<<"enter item"<<endl;
				rear=(rear+1)%max;
				cin>>q[rear];
			}
		}
		void dequeue(){
			if(isempty()){
				cout<<"queue is empty"<<endl;
			}
			else{
				cout<<"item at top is "<<q[front];
				front=(front+1)%max;
				cout<<"dequeue operation has been performed."<<endl;
			}
		}
		void traverse(){
			if(isempty()){
				cout<<"queue is empty"<<endl;
			}
			else{
				for(int i=(front+1)%max;i<=rear;i=(i+1)%max){
					cout<<q[i]<<" ";
				}
			}
		}
};
int main(){
	char ch;
	circular obj;
	do{
		cout<<"menu:"<<endl;
		cout<<"1.enqueue"<<endl;
		cout<<"2.dequeue"<<endl;
		cout<<"3.traverse"<<endl;
		
		cout<<"enter your choice(1-3) or 'n' to exit:"<<endl;
		cin>>ch;
		switch(ch){
			case '1':{
				obj.enqueue();
				break;
			}
			case '2':{
				obj.dequeue();
				break;
			}
			case'3':{
				obj.traverse();
				break;
			}
			
			case'n':{
				cout<<"exiting......"<<endl;
				break;
			}
			default:{
				cout<<"invalid choice!"<<endl;
				break;
			}
		}
	}while(ch!='n');
	return 0;
}
