#include <sstream>
#include <iostream>
#include <string>
using namespace std;
void demo()
{

}

int main() {

    string line;
    getline( cin, line );
    istringstream in( line );
        while ( in >> x ) sum += x;
        cout << sum << endl;

}
