
#include "fastparser.h"

#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    FastParser fp;
    while(true) {
        cout << "~> ";
        string s;
        getline(cin, s);
        if(s == ":exit") break;
        fp.print(cout, fp.parseEval(s));
        cout << endl;
    }
    return 0;
}

