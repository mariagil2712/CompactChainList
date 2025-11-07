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
    ccl1.removeFirstOcurrence('b');
    ccl1.printPairs();
    ccl1.set(5, 'c');
    ccl1.printPairs();
    //ccl1.removeAllOcurrences('b');
    //ccl1.printPairs();
    ccl1.removeFirstOcurrence('b');
    ccl1.printPairs();
    int tam = ccl1.size();
    cout << tam << endl;
    return 0;
}

