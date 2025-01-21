//queue as adt
#include<iostream>
#define max 5
using namespace std;
class queue{
	public:
		int rear;
		int front;
		int q[max];
		void makeempty(){
			rear=-1;
			front=0;
		}
		bool isempty(){
			return front>rear;
		}
		bool isfull(){
			return rear==max-1;
			
		}
		void enqueue(){
			if(isfull()){
				cout<<"queue is full "<<endl;
				
			}
			else{
				cout<<"enter a element"<<endl;
				rear++;
				cin>>q[rear];
			}
		}
		void dequeue(){
			if(isempty()){
				cout<<"queue is empty"<<endl;
				
			}
			else{
				cout<<"item at front is "<<q[front];
				front++;
				cout<<"element is deleted."<<endl;
			}
		}
		void traverse(){
			if(isempty()){
				cout<<"queue is empty."<<endl;
				
			}
			else{
				for(int i=front;i<=rear;i++){
					cout<<q[i]<<" ";
				}
			}
		}
};
int main(){
	char ch;
	queue obj;
	do{
		cout<<"menu:"<<endl;
		cout<<"1.enqueue"<<endl;
		cout<<"2.dequeue"<<endl;
		cout<<"3.traverse"<<endl;
		cout<<"4.empty queue"<<endl;
		cout<<"enter your choice(1-4) or 'n' to exit:"<<endl;
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
			case'4':{
				obj.makeempty();
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
