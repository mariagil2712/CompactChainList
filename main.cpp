#include <iostream>
#include "CompactChainList.h"
#include <vector>
#include <list>

using namespace std;

int main() {
    vector<char> vectorPrueba = {'a', 'a', 'b', 'b', 'b', 'c', 'b', 'd', 'd', 'a', 'a', 'b', 'c', 'a', 'a', 'b', 'b'};
    CompactChainList ccl1(vectorPrueba);
    ccl1.printPairs();

    // Prueba punto 11 (count consecutive occurrences)
    vector<char> pruebaSub = {'a', 'a'};
    CompactChainList ccl2(pruebaSub);
    ccl2.printPairs();
    int ocu = ccl1.getConsecutiveOcurrences(pruebaSub);
    cout << ocu << endl;

    cout << ccl1.searchElement('c') << endl;
    ccl1.removeFirstOcurrence('b');
    ccl1.printPairs();
    ccl1.set(5, 'c');
    ccl1.printPairs();
    ccl1.removeAllOcurrences('b');
    ccl1.printPairs();
    ccl1.removeFirstOcurrence('b');
    ccl1.printPairs();

    // Pruba size
    int tam = ccl1.size();
    cout << tam << endl;

    ccl1.push_front('y', 3);
    ccl1.printPairs();

    ccl1.push_back('x', 3);
    ccl1.printPairs();

    ccl1.modifyAllOcurrences('a', 'k');
    ccl1.printPairs();
    // Ver lista expandida
    list<char> implistexpand = ccl1.expand();
    for(char ele : implistexpand) {
        cout << ele << " ";
    } 
    cout << endl;
    return 0;
}

