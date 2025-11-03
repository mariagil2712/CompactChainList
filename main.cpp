#include <iostream>
#include "CompactChainList.h"
#include <vector>
#include <list>

using namespace std;


//a a b b b c d d a a
//a 2 , b 3 , c 1 , d 2
int main() {
    vector<char> vectorPrueba = {'a', 'a', 'b', 'b', 'b', 'c', 'd', 'd', 'a', 'a'};
    CompactChainList ccl1(vectorPrueba);
    ccl1.printPairs();
    cout << ccl1.searchElement('c') << endl;
    ccl1.set(3, 'c');
    ccl1.printPairs();


    return 0;
}

