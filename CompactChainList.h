//Código de María Gil e Isabella Ramírez

#ifndef COMPACTCHAINLIST_H
#define COMPACTCHAINLIST_H

#include <list>
#include <vector>
#include <map>

using namespace std;
typedef int Element;

class CompactChainList {
private:
    list<pair<Element, int>> l;

public:
    // Constructores
    CompactChainList(); //1
    CompactChainList(vector<Element> &secuencia); //2
    CompactChainList(const CompactChainList &lista); //3
    CompactChainList getLexicographicFusion(CompactChainList &oth); //15

    // Analizadoras
    int searchElement(Element e); //4
    int size(); //9
    int getConsecutiveOcurrences(vector<Element> &subsecuencia); //11
    int getIndexFirstConsecutiveOcurrence(vector<Element> &subsecuencia); //12
    int getOcurrences(vector<Element> &subsecuencia); // 13
    int getIndexFirstOcurrence(vector<Element> &subsecuencia); // 14
    list<Element> expand(); //16
    map<int, list<Element>> elementoPorOcurrencia(); //22

    // Modificadoras
    void set(int pos, Element e); //5
    void removeFirstOcurrence(Element e); //6
    void removeAllOcurrences(Element e); //7
    void removeBlockPosition(int pos); //8
    void insertElement(int pos, Element e); //10
    void modifyAllOcurrences(Element e1, Element e2); //18
    void push_front(Element e, int o); //19
    void push_back(Element e, int o); //20
    static void sortVectorCCL(vector<CompactChainList> &ccls); // 21

    // Sobrecarga de operadores
    CompactChainList operator+(CompactChainList &oth); //17
    Element operator[](int pos); //17
    bool operator<(const CompactChainList &oth) const; //17
    bool operator==(const CompactChainList &oth); //17

    //Print
    void printPairs();

};

#endif //COMPACTCHAINLIST_H