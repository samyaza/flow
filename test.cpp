#include <iostream>
#include <thread>
#include "flow.h"
using namespace std;

void print_function(FlowQueue<string> *que){
    string out;
    do{
        out = que->get();
        cout << out << endl;
    }while(out != "exit");
}

int main(int argc, char** argv) {
    
    FlowQueue<string> test; 
    thread t1(print_function, &test);
    string out;
    do{
        cin >> out;
        test.put(out);
    }while(out != "exit");
    
    t1.join();
    return 0;
}

