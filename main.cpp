//Código de María Gil e Isabella Ramírez

#include <iostream>
#include "CompactChainList.h"
#include <list>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
typedef int Element;

void imprimirMapa(const map<int, list<Element>>& mapa) {
    map<int, list<Element>>::const_iterator itMapa = mapa.begin();
    while (itMapa != mapa.end()) {

        cout << "{" << itMapa->first << ": [";

        list<Element>::const_iterator itLista = itMapa->second.begin();
        while (itLista != itMapa->second.end()) {
            cout << *itLista;

            list<Element>::const_iterator itSiguiente = itLista;
            ++itSiguiente;
            if (itSiguiente != itMapa->second.end()) {
                cout << ", ";
            }

            ++itLista;
        }

        cout << "]}" << endl;

        ++itMapa;
    }
}

int main() {

    int i, casos, v, n;
  vector<Element> vec1 = {10, 10, 10, 10, 3, 3, 3, 5, 5, 6, 7, 8, 3, 3, 3, 3, 5, 11, 11, 4};
  vector<Element> vec2 = {10, 10, 10, 10, 3, 3, 3, 3, 6, 7, 8, 9};
  vector<Element> vec3 = {8, 8, 8, 8, 8, 8, 8, 8, 8, 11, 11, 2, 2, 2, 2, 2, 2, 2, 5, 6, 3, 4, 4, 4, 4};
  vector<Element> vec4;
  list<Element> lis;
  CompactChainList ccl1, ccl2, ccl3, ccl4, ccl5, ccl6;

  ccl1 = CompactChainList(vec1);
  ccl2 = CompactChainList(ccl1);
  ccl3 = CompactChainList(vec2);
  ccl4 = CompactChainList(vec3);
  printf("*************** Creación **************\n");
  ccl1.printPairs();
  ccl3.printPairs();
  ccl4.printPairs();

  printf("**************** Copia ***************\n");
  ccl2.printPairs();

  printf("*************** Igualdad **************\n");
  if(ccl1 == ccl2)
    printf("Son iguales ccl1 y ccl2\n");
  else
    printf("No son iguales ccl1 y ccl2\n");
    
  if(ccl1 == ccl3)
    printf("Son iguales ccl1 y ccl3\n");
  else
    printf("No son iguales ccl1 y ccl3\n");

  printf("************ Comparación **************\n");
  if(ccl3 < ccl1)
    printf("ccl3 es menor que ccl1\n");
  else
    printf("ccl3 no es menor que ccl1\n");

  if(ccl2 < ccl1)
    printf("ccl2 es menor que ccl1\n");
  else
    printf("ccl2 no es menor que ccl1\n");

  if(ccl1 < ccl2)
    printf("ccl1 es menor que ccl2\n");
  else
    printf("ccl1 no es menor que ccl2\n");

  printf("*************** Acceso ****************\n");
  for(i = 0; i < ccl1.size(); ++i){
    if(i < ccl1.size() - 1)
      printf("(%d, %d),", i, ccl1[i]);
    else
      printf("(%d, %d)\n", i, ccl1[i]);
  }

  printf("******** Fusión Lexicográfica *********\n");
  ccl5 = ccl1 + ccl4;
  ccl6 = ccl2 + ccl5;

  ccl5.printPairs();
  ccl6.printPairs();

  printf("********* Agregar Elementos ***********\n");
  ccl1.push_back(11, 2);
  ccl1.push_front(7, 3);
  ccl2.push_front(7, 1);
  ccl2.insertElement(5, 6);
  ccl3.printPairs();
  ccl3.insertElement(4, 14);
  ccl3.insertElement(3, 16);
  ccl1.printPairs();
  ccl2.printPairs();
  ccl3.printPairs();

  printf("******** Modificar Elementos **********\n");
  ccl2.set(0, 20);
  ccl2.set(ccl2.size() - 1, 50);
  ccl2.set(20, 40);
  ccl2.printPairs();
  ccl2.modifyAllOcurrences(10, 88);
  ccl2.modifyAllOcurrences(19, 60);
  ccl2.printPairs();

  printf("*********** Quitar Elementos ***********\n");
  ccl4.printPairs();
  ccl4.removeFirstOcurrence(8);
  ccl4.removeFirstOcurrence(5);
  ccl4.printPairs();
  ccl4.removeAllOcurrences(8);
  ccl4.printPairs();
  ccl3.printPairs();
  ccl3.removeBlockPosition(6);
  ccl3.removeBlockPosition(4);
  ccl3.printPairs();

  printf("*************** Consultas ***************\n");
  ccl1.printPairs();
  printf("El elemento 11 aparece en ccl1 en la posición %d\n", ccl1.searchElement(11));
  printf("El elemento 7 aparece en ccl1 en la posición %d\n", ccl1.searchElement(7));
  printf("El elemento 66 aparece en ccl1 en la posición %d\n", ccl1.searchElement(66));

  vec4 = {7, 7, 10, 10, 10};
  printf("El vector {7, 7, 10, 10, 10} aparece de forma consecutiva en ccl1 en la posición: %d\n", ccl1.getIndexFirstConsecutiveOcurrence(vec4));
  vec4 = {7, 7, 10, 10, 10, 3};
  printf("El vector {7, 7, 10, 10, 10, 3} aparece de forma consecutiva en ccl1 en la posición: %d\n", ccl1.getIndexFirstConsecutiveOcurrence(vec4));
  vec4 = {7, 7, 10, 10, 10, 10, 3, 3, 3, 5};
  printf("El vector {7, 7, 10, 10, 10, 10, 3, 3, 3, 5} aparece de forma consecutiva en ccl1 en la posición: %d\n", ccl1.getIndexFirstConsecutiveOcurrence(vec4));
  vec4 = {5, 6, 7, 8, 3};
  printf("El vector {5, 6, 7, 8, 3} aparece de forma consecutiva en ccl1 en la posición: %d\n", ccl1.getIndexFirstConsecutiveOcurrence(vec4));

  vec4 = {7, 10, 10, 6, 3};
  printf("El vector {7, 10, 10, 6, 3} aparece de forma no consecutiva en ccl1 en la posición: %d\n", ccl1.getIndexFirstOcurrence(vec4));
  vec4 = {7, 10, 10, 10, 10, 10, 6, 3};
  printf("El vector {7, 10, 10, 10, 10, 10, 6, 3} aparece de forma no consecutiva en ccl1 en la posición: %d\n", ccl1.getIndexFirstOcurrence(vec4));
  vec4 = {6, 7, 8, 3, 11, 11};
  printf("El vector {6, 7, 8, 3, 11, 11} aparece de forma no consecutiva en ccl1 en la posición: %d\n", ccl1.getIndexFirstOcurrence(vec4));

  vec4 = {7, 7, 10};
  printf("El vector {7, 7, 10} aparece de forma consecutiva en ccl1 %d veces\n", ccl1.getConsecutiveOcurrences(vec4));
  vec4 = {3, 3, 5};
  printf("El vector {3, 3, 5} aparece de forma consecutiva en ccl1 %d veces\n", ccl1.getConsecutiveOcurrences(vec4));
  vec4 = {3, 3};
  printf("El vector {3, 3} aparece de forma consecutiva en ccl1 %d veces\n", ccl1.getConsecutiveOcurrences(vec4));

  vec4 = {7, 7, 10};
  //printf("El vector {7, 7, 10} aparece de forma no consecutiva en ccl1 %d veces\n", ccl1.getOcurrences(vec4));
  vec4 = {3, 3, 5};
  //printf("El vector {3, 3, 5} aparece de forma no consecutiva en ccl1 %d veces\n", ccl1.getOcurrences(vec4));
  vec4 = {3, 3};
  //printf("El vector {3, 3} aparece de forma no consecutiva en ccl1 %d veces\n", ccl1.getOcurrences(vec4));
  vec4 = {3, 3, 5, 11};
  //printf("El vector {3, 3, 5, 11} aparece de forma no consecutiva en ccl1 %d veces\n", ccl1.getOcurrences(vec4));
  vec4 = {3, 3, 5, 6, 5, 11, 11, 11};
  //printf("El vector {3, 3, 5, 6, 5, 11, 11, 11} aparece de forma no consecutiva en ccl1 %d veces\n", ccl1.getOcurrences(vec4));
  vec4 = {3, 3, 5, 6, 5, 11, 11, 11, 4};
  //printf("El vector {3, 3, 5, 6, 5, 11, 11, 11, 4} aparece de forma no consecutiva en ccl1 %d veces\n", ccl1.getOcurrences(vec4));

  lis = ccl1.expand();
  for(list<Element>::iterator it = lis.begin(); it != lis.end(); ++it)
    printf("%d ", *it);
  printf("\n");
  lis = ccl2.expand();
  for(list<Element>::iterator it = lis.begin(); it != lis.end(); ++it)
    printf("%d ", *it);
  printf("\n");
  lis = ccl5.expand();
  for(list<Element>::iterator it = lis.begin(); it != lis.end(); ++it)
    printf("%d ", *it);
  printf("\n");


   /*
    vector<char> vectorPrueba = {'a', 'a', 'b', 'b', 'f', 'c', 'k', 't', 'c', 'k', 'k', 'a', 'z'};
    vector<char> vectorPrueba2 = {'a', 'a', 'd', 'b', 'c', 'c', 'k', 'm', 'c', 'k', 'z', 'a', 'z'};
    vector<char> vectorPrueba3 = {'a', 'a', 'd', 'b', 'c', 'c', 'k', 'm', 'c', 'k', 'z', 'a', 'z'};
    vector<char> vectorPrueba4 = {'a', 'a', 'd', 'b', 'c', 'c', 'k', 'm', 'c', 'k', 'z', 'a', 'z'};
    CompactChainList ccl1(vectorPrueba);
    CompactChainList ccl2(vectorPrueba2);
    CompactChainList ccl4(vectorPrueba3);

    //Prueba Punto 15:
    cout << "Uso de la funcion lexicografica:" << endl;
    ccl1.printPairs();
    ccl2.printPairs();
    CompactChainList ccl5 = ccl1.getLexicographicFusion(ccl2);
    ccl5.printPairs();
    cout << endl;

    ccl1.printPairs();
    ccl1.set(4, 'c');
    ccl1.printPairs();
    ccl1.removeBlockPosition(2);
    ccl1.printPairs();
    ccl1.insertElement(5, 'k');
    ccl1.printPairs();
    cout << ccl1[6] << endl;
    map<int, list<Element>> resultado = ccl1.elementoPorOcurrencia();
    imprimirMapa(resultado);
    bool comparacion;
    comparacion = ccl2<ccl1;
    cout << comparacion;

    // Pruba Punto 17 (sobrecarga ==)
    cout << "sobrecarha ==:" << endl;
    ccl2.printPairs();
    ccl4.printPairs();
    if(ccl2 == ccl4) {
        cout << "Son iguales" << endl;
    } else {
        cout << "No son iguales" << endl;
    }

    // Prueba punto 17 (+)
    cout << "get lexicographic fusion:" << endl;
    ccl1.printPairs();
    ccl2.printPairs();
    CompactChainList ccl3 = ccl1 + ccl2;
    ccl3.printPairs();

    // Prueba punto 11 (get consecutive occurrences)
    cout << "get consecutive Ocurrences de k:" << endl;
    vector<char> pruebaSub = {'k'};
    ccl1.printPairs();
    int ocu = ccl1.getConsecutiveOcurrences(pruebaSub);
    cout << ocu << endl;

    // Prueba punto 12 (get index first consecutive occurrence)
    cout << "get index first consecutive Ocurrence de k:" << endl;
    ccl1.printPairs();
    int indexConsec = ccl1.getIndexFirstConsecutiveOcurrence(pruebaSub);
    cout << indexConsec << endl;

    // Prueba punto 4 (search element)
    cout << "Search Element: c" << endl;
    ccl1.printPairs();
    cout << ccl1.searchElement('c') << endl;

    // Prueba punto 6 (remove first occurrence)
    cout << "Remove firsr occurence b:" << endl;
    ccl1.removeFirstOcurrence('b');
    ccl1.printPairs();

    // Prueba punto 7 (remove all occurrences)
    cout << "Remove all ocurreences: b" << endl;
    ccl1.removeAllOcurrences('b');
    ccl1.printPairs();

    // Pruba punto 9 (size)
    cout << "size:" << endl;
    ccl1.printPairs();
    int tam = ccl1.size();
    cout << tam << endl;

    // Prueba punto 19 (push front)
    cout << "push front:" << endl;
    ccl1.push_front('y', 3);
    ccl1.printPairs();

    // Prueba punto 20 (push back)
    cout << "Push back:" << endl;
    ccl1.push_back('x', 3);
    ccl1.printPairs();

    // Prueba punto 18 (modify all occurrences)
    cout << "Modify all occurences a, k:" << endl;
    ccl1.modifyAllOcurrences('a', 'k');
    ccl1.printPairs();

    // prueba punto 16 (expand)
    cout << "expand:" << endl;
    list<char> implistexpand = ccl1.expand();
    for(char ele : implistexpand) {
        cout << ele << " ";
    }
    cout << endl;
    */

    return 0;
}

