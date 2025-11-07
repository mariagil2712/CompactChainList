#include "CompactChainList.h"
using namespace std;

CompactChainList::CompactChainList() {} //1

void CompactChainList::printPairs() { //print
    for (auto& pareja : l) {
        cout << "(" << pareja.first << "," << pareja.second << ") ";
    }
    cout << endl;
}

CompactChainList::CompactChainList(vector<Element> &secuencia) { //2
    int i = 1;
    Element valor = secuencia[0];
    int ocurrencias = 1;

    while (i < secuencia.size()) {
        if (secuencia[i] == valor) {
            ocurrencias = ocurrencias + 1;
        }
        else {
           l.push_back({valor, ocurrencias});
            valor = secuencia[i];
            ocurrencias = 1;
        }
        i = i + 1;
    }

    l.push_back({valor, ocurrencias});
}

CompactChainList::CompactChainList(CompactChainList &lista) { //3
    l = lista.l;
}

int CompactChainList::searchElement(Element e) { // 4
    int i = -1;
    bool encontrado = false;
    list<pair<Element, int>>::iterator it = l.begin(); //it apunta a la primera pair

    while (it != l.end() && !encontrado) {
        if (it->first == e) {
            encontrado = true;
        }
        else {
            i = i + it->second;
            ++it;
        }
    }
    return i+1;
}

void CompactChainList::set(int pos, Element e) { //5
    int i = 0;
    list<pair<Element, int>>::iterator it = l.begin();
    bool encontrado = false;

    // Hallar pair donde está la pos
    while (it != l.end() && !encontrado) {
        if (i + it->second > pos) {
            encontrado = true;
        }
        else {
            i = i + it->second;
            ++it;
        }
    }

    // Si el elemento ya es igual, no hacer nada
    if (it->first != e) {
        int posInterna = pos - i;

        // Si el pair tiene un solo elemento
        if (it->second == 1) {
            it->first = e;
        }
        // Si pos está al inicio del bloque
        else if (posInterna == 0) {
            it->second = it->second - 1;
            l.insert(it, {e, 1});
        }
        // Si pos está al final del bloque
        else if (posInterna == it->second - 1) {
            it->second = it->second - 1;
            auto siguiente = it;
            ++siguiente;
            l.insert(siguiente, {e, 1});
        }
        else {
            Element valorOriginal = it->first;
            int longitudAntes = posInterna;
            int longitudDespues = it->second - posInterna - 1;

            it->second = longitudAntes;
            auto siguiente = it;
            ++siguiente;
            l.insert(siguiente, {e, 1});
            l.insert(siguiente, {valorOriginal, longitudDespues});
        }
    }
}

//Punto 6:
void CompactChainList::removeFirstOcurrence(Element e) {
    list<pair<Element, int>>::iterator it = l.begin();
    bool found = false;

    while(it != l.end() && found == false) {
        if ((*it).first == e) {
            (*it).second -= 1;
            found = true;
        }
        if ((*it).second == 0) {
            it = l.erase(it);
            found = true;
        }
        ++it;
    }
}

//Punto 7:
void CompactChainList::removeAllOcurrences(Element e) {
    list<pair<Element, int>>::iterator it = l.begin();

    while(it != l.end()) {
        if ((*it).first == e) {
            it = l.erase(it);
        } else {
            ++it;
        }
    }
}

//Punto 9:
int CompactChainList::size() {
    int acum = 0;

    for(list<pair<Element, int>>::iterator it = l.begin(); it != l.end(); ++it) {
        acum += (*it).second;
    }

    return acum;
}

//Punto 16:
list<Element> expand();