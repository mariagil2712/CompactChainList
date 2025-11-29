//Código de María Gil e Isabella Ramírez

#include "CompactChainList.h"
#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
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

CompactChainList::CompactChainList(const CompactChainList &lista) { //3
    this->l = lista.l;
}

int CompactChainList::searchElement(Element e) { // 4
    int i = -1;
    bool encontrado = false;
    list<pair<Element, int>>::iterator it = l.begin(); //it apunta a la primera pair

    while (it != l.end() && !encontrado) {
        if (it->first == e) {
            encontrado = true;
            i  = i + 1;
        }
        else {
            i = i + it->second;
            ++it;
        }
    }
    if(encontrado == false) {
        i = -1;
    }

    return i;
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

        // Fusionar bloques adyacentes con el mismo valor
        if (l.size() > 1) {
            auto itFusion = l.begin();
            auto siguienteFusion = itFusion;
            ++siguienteFusion;

            while (siguienteFusion != l.end()) {
                if (itFusion->first == siguienteFusion->first) {
                    itFusion->second += siguienteFusion->second;
                    siguienteFusion = l.erase(siguienteFusion);
                } else {
                    ++itFusion;
                    ++siguienteFusion;
                }
            }
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

void CompactChainList::removeBlockPosition(int pos) { //8
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
    l.erase(it);
}

//Punto 9:
int CompactChainList::size() {
    int acum = 0;

    for(list<pair<Element, int>>::iterator it = l.begin(); it != l.end(); ++it) {
        acum += (*it).second;
    }

    return acum;
}

void CompactChainList::insertElement(int pos, Element e) { //10
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

    int k = pos - i;

    //caso 1: si el elemento es del mismo tipo del pair en el que está
    if (e == it->first) {
        it->second = it->second + 1;
    }
    //caso 2: si toca insertar en la posicion de un elemento que solo está una vez
    else if (it->second == 1) {
        l.insert(it, {e, 1});
    }
    //caso 3: insertar al inicio del bloque
    else if (k == 0) {
        l.insert(it, {e, 1});
    }
    //general: si toca insertar y separar
    else {
        Element valorOriginal = it->first;
        int longitudAntes = k;
        int longitudDespues = it->second - k;

        it->second = longitudAntes;
        list<pair<Element, int>>::iterator siguiente = it;
        ++siguiente;
        l.insert(siguiente, {e, 1});
        l.insert(siguiente, {valorOriginal, longitudDespues});
    }

    // Fusionar bloques adyacentes con el mismo valor
    if (l.size() > 1) {
        list<pair<Element, int>>::iterator itFusion = l.begin();
        list<pair<Element, int>>::iterator siguienteFusion = itFusion;
        ++siguienteFusion;

        while (siguienteFusion != l.end()) {
            if (itFusion->first == siguienteFusion->first) {
                itFusion->second = itFusion->second + siguienteFusion->second;
                siguienteFusion = l.erase(siguienteFusion);
            } else {
                ++itFusion;
                ++siguienteFusion;
            }
        }
    }
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
                //Cuenta las ocurrencias cuando las repeticiones de una pareja en la secuencia son mayores a las de la subsecuencia y la subsecuencia tiene un solo elemento
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
                //Ajusta la posicion cuando el bloque donde se encuentra la primera ocurrencia tiene varias repetciones
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

int CompactChainList::getOcurrences(vector<Element> &subsecuencia) { //13
    int contador = 0;
    list<pair<Element, int>>::iterator it = l.begin();
    int posActual = 0;

    // Contar desde cada posición donde aparece el primer elemento
    while (it != l.end()) {
        if (it->first == subsecuencia[0]) {
            // Por cada aparición del primer elemento
            for (int rep = 0; rep < it->second; rep = rep + 1) {
                int posBusqueda = posActual + rep + 1;

                // Contar cuántas formas hay de completar la subsecuencia desde aquí
                int combinaciones = contarDesde(subsecuencia, 1, posBusqueda);
                contador = contador + combinaciones;
            }
        }
        posActual = posActual + it->second;
        ++it;
    }

    return contador;
}

int CompactChainList::contarDesde(vector<Element> &subsecuencia, int indice, int posDesde) { //operacion auxiliar para poder hacer la 13
    // Caso base: si ya procesamos toda la subsecuencia
    if (indice >= subsecuencia.size()) {
        return 1;
    }

    int total = 0;
    list<pair<Element, int>>::iterator it = l.begin();
    int posActual = 0;

    // Buscar el elemento actual de la subsecuencia
    while (it != l.end()) {
        if (posActual >= posDesde && it->first == subsecuencia[indice]) {
            // Por cada aparición de este elemento
            for (int rep = 0; rep < it->second; rep = rep + 1) {
                int posSiguiente = posActual + rep + 1;

                // Contar recursivamente desde la siguiente posición
                int combinaciones = contarDesde(subsecuencia, indice + 1, posSiguiente);
                total = total + combinaciones;
            }
        }
        posActual = posActual + it->second;
        ++it;
    }

    return total;
}

int CompactChainList::getIndexFirstOcurrence(vector<Element> &subsecuencia) { //14
    int posActual = 0;
    int posInicio = -1;
    int indiceSubsec = 0;
    bool encontrado = false;

    list<pair<Element, int>>::iterator it = l.begin();

    while (it != l.end() && !encontrado) {
        if (it->first == subsecuencia[indiceSubsec]) {
            if (indiceSubsec == 0) {
                posInicio = posActual;
            }

            indiceSubsec = indiceSubsec + 1;

            if (indiceSubsec == subsecuencia.size()) {
                encontrado = true;
            }
        }

        posActual = posActual + it->second;
        ++it;
    }

    // Si no encontró toda la subsecuencia, retornar -1
    if (!encontrado) {
        posInicio = -1;
    }

    return posInicio;
}

//Punto 15:
CompactChainList CompactChainList::getLexicographicFusion(CompactChainList &oth) {
    CompactChainList ans = *this + oth;
    return ans;
}

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

//Punto 17:
//sobrecarga +
CompactChainList CompactChainList::operator+(CompactChainList &oth) {
    CompactChainList l3;
    list<pair<Element, int>>::iterator itlist = l.begin(); 
    list<pair<Element, int>>::iterator itoth = oth.l.begin();

    while(itlist != l.end() && itoth != oth.l.end()) {
        if((*itlist).first < (*itoth).first) {
            l3.l.push_back((*itlist));
            ++itlist;
        } else if((*itoth).first < (*itlist).first) {
            l3.l.push_back((*itoth));
            ++itoth;
        } else if((*itlist).first == (*itoth).first) {
            //Si son iguales, se suman las longitudes
            Element e = (*itlist).first;
            int longi = (*itlist).second + (*itoth).second;
            l3.l.push_back({e, longi});
            ++itlist;
            ++itoth;
        }
    }
    //Si el ciclo anterior termino pero a alguna de las dos ccl todavia tiene elementos para agregar
    while(itlist != l.end()) {
        l3.l.push_back((*itlist));
        ++itlist;
    }
    while(itoth != oth.l.end()) {
        l3.l.push_back((*itoth));
        ++itoth;
    }

    return l3;
}

//sobrecarga ==
bool CompactChainList::operator==(const CompactChainList &oth) {
    bool ans = (l == oth.l);
    return ans;
}

//sobrecarga []
Element CompactChainList::operator[](int pos) {
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
    return it->first;
}

//sobrecarga <

bool CompactChainList::operator<(const CompactChainList &oth) const {
    bool ans = false;
    bool encontradoDiferencia = false;
    list<pair<Element, int>>::const_iterator it = l.begin();
    list<pair<Element, int>>::const_iterator it2 = oth.l.begin();

    while (it != l.end() && it2 != oth.l.end() && !encontradoDiferencia) {
        // si los elementos son diferentes
        if (it->first != it2->first) {
            ans = it->first < it2->first;
            encontradoDiferencia = true;
        }
        // si los elementos son iguales pero con diferente cantidad
        else if (it->second != it2->second) {
            ans = it->second < it2->second;
            encontradoDiferencia = true;
        }
        // si el bloque es igual, continuar al siguiente
        else {
            ++it;
            ++it2;
        }
    }

    // si uno se acaba antes del otro sin que halla diferencia, el que se acaba primero es menor por cantidad de parejas/bloques
    if (!encontradoDiferencia) {
        ans = (it == l.end() && it2 != oth.l.end());
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

void CompactChainList::sortVectorCCL(vector<CompactChainList> &ccls) { //21
    sort(ccls.begin(), ccls.end());
}

map<int, list<Element>> CompactChainList::elementoPorOcurrencia() { //22
    map<int, list<Element>> mapa;
    list<pair<Element, int>>::iterator itLista = l.begin();
    while (itLista != l.end()) {
        map<int, list<Element>>::iterator itMapa = mapa.find(itLista->second);

        // verificar si la clave YA está
        if (itMapa != mapa.end()) {
            // agregar el Element si no está repetido
            bool existe = false;
            list<Element>::iterator itListElem = itMapa->second.begin();
            while (itListElem != itMapa->second.end()) {
                if (*itListElem == itLista->first) {
                    existe = true;
                }
                ++itListElem;
            }
            if (!existe) {
                itMapa->second.push_back(itLista->first);
            }
        } else {
            // si no está la clave, crearla con una lista que empiece con el elemento
            list<Element> nuevaLista;
            nuevaLista.push_back(itLista->first);
            mapa.insert(pair<int, list<Element>>(itLista->second, nuevaLista));
        }

        ++itLista;
    }

    // ordenar cada lista del mapa
    map<int, list<Element>>::iterator itOrden = mapa.begin();
    while (itOrden != mapa.end()) {
        itOrden->second.sort();
        ++itOrden;
    }

    return mapa;
}
