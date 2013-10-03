#include <iostream>
#include <thread>
#include "flow.h"
using namespace std;

void print_function(FlowQueue<string> *que,int id){
    string out;
    do{
       // out = que->get();
        cout << "From " << id << ": " << out << endl;
    }while(out != "exit");
}

int main(int argc, char** argv) {
    cout << "TET";
//    FlowQueue<string> test; 
//    
//    auto pro = test.get_producer();
//    pro.put("Test");
//    cout << "hee";
//    auto con = test.get_consumer();
//    cout << con.get() << endl;
//    thread t1(print_function, &test,1);
//    thread t2(print_function, &test,2);
//    string out;
//    do{
//        cin >> out;
//        test.put(out);
//    }while(out != "exit");
//    test.put(out);
//    t1.join();
//    t2.join();
    return 0;
}

