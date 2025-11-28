#include <iostream>
#include "CompactChainList.h"
#include <vector>
#include <list>

using namespace std;

int main() {
    vector<char> vectorPrueba = {'a', 'a', 'b', 'b', 'f', 'c', 'k', 't', 'c', 'k', 'k', 'a', 'z'};
    vector<char> vectorPrueba2 = {'a', 'a', 'd', 'b', 'c', 'c', 'k', 'm', 'c', 'k', 'z', 'a', 'z'};
    vector<char> vectorPrueba3 = {'a', 'a', 'd', 'b', 'c', 'c', 'k', 'm', 'c', 'k', 'z', 'a', 'z'};
    CompactChainList ccl1(vectorPrueba);
    CompactChainList ccl2(vectorPrueba2);
    CompactChainList ccl4(vectorPrueba3);

    // Pruba Punto 17 (sobrecarga ==)
    cout << "sobrecarha ==:" << endl;
    ccl2.printPairs();
    ccl4.printPairs();
    if(ccl2 == ccl4) {
        cout << "Son iguales" << endl;
    } else {
        cout << "No son iguales" << endl;
    }


    // Prueba punto 17 (get lexicographic fusion)
    cout << "get lexicographic fusion:" << endl;
    ccl1.printPairs();
    ccl2.printPairs();
    CompactChainList ccl3 = ccl1 + ccl2;
    ccl3.printPairs();

    // Prueba punto 11 (get consecutive occurrences)
    vector<char> pruebaSub = {'a', 'z'};
    int ocu = ccl1.getConsecutiveOcurrences(pruebaSub);
    cout << ocu << endl;

    // Prueba punto 12 (get index first consecutive occurrence)
    int indexConsec = ccl1.getIndexFirstConsecutiveOcurrence(pruebaSub);
    cout << indexConsec << endl;

    // Prueba punto 4 (search element)
    cout << ccl1.searchElement('c') << endl;

    // Prueba punto 6 (remove first occurrence)
    ccl1.removeFirstOcurrence('b');
    ccl1.printPairs();

    // Prueba punto 5 (set)
    ccl1.set(5, 'k');
    ccl1.printPairs();

    // Prueba punto 7 (remove all occurrences)
    ccl1.removeAllOcurrences('b');
    ccl1.printPairs();

    // Pruba punto 9 (size)
    int tam = ccl1.size();
    cout << tam << endl;

    // Prueba punto 19 (push front)
    ccl1.push_front('y', 3);
    ccl1.printPairs();

    // Prueba punto 20 (push back)
    ccl1.push_back('x', 3);
    ccl1.printPairs();

    // Prueba punto 18 (modify all occurrences)
    ccl1.modifyAllOcurrences('a', 'k');
    ccl1.printPairs();

    // prueba punto 16 (expand)
    list<char> implistexpand = ccl1.expand();
    for(char ele : implistexpand) {
        cout << ele << " ";
    } 
    cout << endl;

    return 0;
}

