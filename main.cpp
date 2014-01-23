
#include "fastparser.h"

#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    FastParser fp;
    while(true) {
        cout << ">> ";
        string s;
        cin >> s;
        cout << fp.evalToString(s) << endl;
    }
    return 0;
}

