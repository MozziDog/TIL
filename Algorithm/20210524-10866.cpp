// 백준 10866번 문제 : 덱을 직접 구현
// 21.05.24 성공

#include <iostream>
#include <string>
using namespace std;
#define null 0

class Element{
public:
	Element *before, *next;
	int value;
	Element(){
		before = null;
		next = null;
	}
	bool hasBefore(){
		return before != null ? true : false;
	}
	bool hasNext(){
		return next != null ? true : false;
	}
};
class Deque{	
	Element *front, *back;
public:
	Deque(){
		front = null;
		back = null;
	}
	void push_front(int x){
		Element *newElement = new Element();
		newElement->value = x;
		newElement->next = front;
		if(front != null)
			front->before = newElement;
		front = newElement;
		if(back == null)
			back = front;
	}
	void push_back(int x){
		Element *newElement = new Element();
		newElement->value = x;
		newElement->before = back;
		if(back != null)
			back->next = newElement;
		back = newElement;
		if(front == null)
			front = back;
	}
	int pop_front(){
		if(front == null){
			return -1;
		}
		else{
			int value = front->value;
			Element *tmp = front;
			front = front->next;
			if(front == null)
				back = null;
			else
				front->before = null;
			delete tmp;
			return value;
		}
	}
	int pop_back(){
		if(back == null){
			return -1;
		}
		else{
			int value = back->value;
			Element *tmp = back;
			back = back->before;
			if(back == null)
				front = null;
			else
				back->next = null;
			delete tmp;
			return value;
		}
	}
	int size(){
		int s = 0;
		for(Element *tmp = front; tmp != null; tmp = tmp->next){
			s++;
		}
		return s;
	}
	int empty(){
		if(front == null)
			return 1;
		else
			return 0;
	}
	int get_front(){
		if(front == null)
			return -1;
		else
			return front->value;
	}
	int get_back(){
		if(back == null)
			return -1;
		else
			return back->value;
	}
};
Deque *deck;

void command(string arg){
	size_t found = arg.find("push_front");
	if(found != string::npos){
		int value;
		cin>>value;
		deck->push_front(value);
		return;
	}
	found = arg.find("push_back");
	if(found != string::npos){
		int value;
		cin>>value;
		deck->push_back(value);
		return;
	}
	found = arg.find("pop_front");
	if(found != string::npos){
		int result = deck->pop_front();
		cout<<result<<"\n";
		return;
	}
	found = arg.find("pop_back");
	if(found != string::npos){
		int result = deck->pop_back();
		cout<<result<<"\n";
		return;
	}
	found = arg.find("size");
	if(found != string::npos){
		int result = deck->size();
		cout<<result<<"\n";
		return;
	}
	found = arg.find("empty");
	if(found != string::npos){
		int result = deck->empty();
		cout<<result<<"\n";
		return;
	}
	found = arg.find("front");
	if(found != string::npos){
		int result = deck->get_front();
		cout<<result<<"\n";
		return;
	}
	found = arg.find("back");
	if(found != string::npos){
		int result = deck->get_back();
		cout<<result<<"\n";
		return;
	}
}
int main(){
	deck = new Deque();
	int n;
	string com;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>com;
		command(com);
	}
}