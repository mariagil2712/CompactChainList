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

// Punto 11:
int CompactChainList::getConsecutiveOcurrences(vector<Element> &subsecuencia) {
    int ocurrences = 0;
    CompactChainList subS(subsecuencia);
    //Caso donde la subsecuencia solo tiene un elemento
    if(subS.l.size() == 1) {
        list<pair<Element, int>>::iterator itsub = subS.l.begin();
        for(list<pair<Element, int>>::iterator itlist = l.begin(); itlist != l.end(); ++itlist) {
            if((*itlist).first == (*itsub).first) {
                    ocurrences += ((*itlist).second - (*itsub).second) + 1;
                }
        }
    } else {
        list<pair<Element, int>>::iterator itlist = l.begin();
        while(itlist != l.end()) {
            bool match = true;
            list<pair<Element, int>>::iterator itsub = subS.l.begin();
            list<pair<Element, int>>::iterator itlistcopy = itlist;
            while(itsub != subS.l.end() && match == true && itlistcopy != l.end()) {
                //El elemento debe coincidir
                if((*itlistcopy).first != (*itsub).first) {
                    match = false;
                }
                // El itlist.second >= que el itsub.second
                else if((*itsub).second > (*itlistcopy).second) {
                    match = false;
                }
                //las parejas en la mitad deben ser excatamente iguales
                else if(itsub != subS.l.begin() && itsub != --subS.l.end()) {
                    if((*itlistcopy).second != (*itsub).second) {
                        match = false;
                    }
                }
                ++itsub;
                ++itlistcopy;
            }
            if(match == true && itsub == subS.l.end()) 
                ocurrences += 1;

            ++itlist;
        }
    }
    return ocurrences;
}

//Punto 12:
int CompactChainList::getIndexFirstConsecutiveOcurrence(vector<Element> &subsecuencia) {
    CompactChainList subS(subsecuencia);
    int pos = -1;
    //Caso donde la subsecuencia solo tiene un elemento
    if(subS.l.size() == 1) {
        bool isfirst = false;
        list<pair<Element, int>>::iterator itsub = subS.l.begin();
        list<pair<Element, int>>::iterator itlist = l.begin();
        while(itlist != l.end() && isfirst == false) {
            if((*itlist).first == (*itsub).first) {
                pos += 1;
                isfirst = true;
            } else {
                pos += (*itlist).second;
            }
            ++itlist;
        }
        if(isfirst == false) {
            pos = -1;
        }
    } else {
        bool isfirst = false;
        list<pair<Element, int>>::iterator itlist = l.begin();
        while(itlist != l.end() && isfirst == false) {
            bool match = true;
            list<pair<Element, int>>::iterator itsub = subS.l.begin();
            list<pair<Element, int>>::iterator itlistcopy = itlist;
            while(itsub != subS.l.end() && match == true && itlistcopy != l.end()) {
                //El elemento debe coincidir
                if((*itlistcopy).first != (*itsub).first) {
                    match = false;
                    pos += (*itlistcopy).second;
                }
                // El itlist.second >= que el itsub.second
                else if((*itsub).second > (*itlistcopy).second) {
                    match = false;
                    pos += (*itlistcopy).second;
                }
                //las parejas en la mitad deben ser excatamente iguales
                else if(itsub != subS.l.begin() && itsub != --subS.l.end()) {
                    if((*itlistcopy).second != (*itsub).second) {
                        match = false;
                        pos += (*itlistcopy).second;
                    }
                }
                ++itsub;
                ++itlistcopy;
            }
            if(match == true && itsub == subS.l.end()) {
                isfirst = true;
                pos += ((*itlist).second - (*itsub).second);
            }

            ++itlist;
        }
        if(isfirst == false && itlist == l.end()) {
            pos = -1;
        }
    }
    return pos;
}

//Punto 15:
CompactChainList getLexicographicFusion(CompactChainList &oth);

//Punto 16:
list<Element> CompactChainList::expand() {
    list<Element> ans;
    for(list<pair<Element, int>>::iterator it = l.begin(); it != l.end(); ++it) {
        Element ele = (*it).first;
        int rep = (*it).second;
        for(int i = 0; i < rep; ++i){
            ans.push_back(ele);
        }
    }
    return ans;
}

//Punto 18:
void CompactChainList::modifyAllOcurrences(Element e1, Element e2) {
    for(list<pair<Element, int>>::iterator it = l.begin(); it != l.end(); ++it) {
        if ((*it).first == e1) {
            (*it).first = e2;
        }
    }
}

//Punto 19:
void CompactChainList::push_front(Element e, int o) {
    pair<Element, int> pareja;
    pareja.first = e;
    pareja.second = o;
    l.push_front(pareja);
}

//Punto 20:
void CompactChainList::push_back(Element e, int o) {
    pair<Element, int> pareja;
    pareja.first = e;
    pareja.second = o;
    l.push_back(pareja);
}