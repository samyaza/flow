#include <iostream>
#include <thread>
#include "flow.h"
using namespace std;

void print_function(FlowConsumer<string> que,int id){
    string out;
    do{
        out = que.get();
        cout << "From " << id << ": " << out << endl;
    }while(out != "exit");
}

int main(int argc, char** argv) {
	
    FlowQueue<string> test;     
    auto pro = test.get_producer();
	thread t1(print_function, test.get_consumer(),1);
	thread t2(print_function, test.get_consumer(),2);
	string out;
	do{
	   cin >> out;
	   pro.put(out);
	}while(out != "exit");
	pro.put(out);
	t1.join();
	t2.join();
	return 0;
}

