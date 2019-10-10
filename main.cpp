#include <iostream>
#include <vector>
#include <fstream>
#include "heap.h"
using namespace std;

int main()
{

    heap<vector<int>> h;

    h.load_from();
    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(50);
    h.insert(10);
    h.insert(10,20,400,1000);
    h.get_max();

    cout << "heap" << endl;
    cout << h<<endl;

    //cin >> h;

    /*
    cout << "heap" << endl;
    cout << h;
    cin >> h;
    cout << "heap" << endl;
    cout << h;
    insert(h, 100, 200);
    cout << "heap" << endl;
    cout << h;
    load_from("data.txt", h);
    cout << h;
     */
    return 0;
}