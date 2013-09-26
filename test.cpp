/* 
 * File:   test.cpp
 * Author: Chris
 *
 * Created on September 24, 2013, 7:35 PM
 */

#include <cstdlib>
#include <iostream>
#include "flow.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    BaseQueue<int> test; 
    int d = 10;
    test.put(10);
    cout << test.get() << endl;
    test.put(20);
    cout << test.get() << endl;
    test.put(30);
    test.put(40);
    test.put(45);
    cout << test.get() << endl;
    cout << test.get() << endl;
    cout << test.get() <<endl;
    cout <<"DONE";
    return 0;
}

