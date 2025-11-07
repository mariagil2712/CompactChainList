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
    list<char> implistexpand = ccl1.expand();
    // Ver lista expandida
    for(char ele : implistexpand) {
        cout << ele << " ";
    } 
    cout << endl;

    ccl1.push_front('y', 3);
    ccl1.printPairs();
    return 0;
}

