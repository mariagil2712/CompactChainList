#include <iostream>
#include "CompactChainList.h"
#include <vector>
#include <list>

using namespace std;

int main() {
    vector<char> vectorPrueba = {'a', 'a', 'b', 'b', 'c', 'c', 'k', 't', 'c', 'k', 'a', 'a', 'z'};
    CompactChainList ccl1(vectorPrueba);
    ccl1.printPairs();

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

