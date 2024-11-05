//
//  setImpl.h
//  SkipList
//
//  Jean Goulet 2017
//
//  Devoir fait par
//     Co�quipier 1 : Mathieu Roy
//     Co�quipier 2 : Nicolas Gagnon
//

/////////////////////////////////////////////////////////////////
// copieur et destructeur de liste
#include "ensemble.h"

template<typename TYPE>
ensemble<TYPE>::ensemble(const ensemble<TYPE> &src)
        : ensemble() {
    // compl�ter
}

template<typename TYPE>
ensemble<TYPE>::~ensemble() {
    // compl�ter
}

/////////////////////////////////////////////////////////////////
// find
// localise un �l�ment, retourne la fin si absent

template<typename TYPE>
typename ensemble<TYPE>::iterator ensemble<TYPE>::find(const TYPE &x) const {
    auto i = lower_bound(x);

    if ( x < *i){
        i = iterator(m_avant->m_prec[0]);
    }

    return i;
}

// lower_bound
// localise la premiere position ou l'element n'est
// pas plus petit que celui recu en parametre

template<typename TYPE>
typename ensemble<TYPE>::iterator ensemble<TYPE>::lower_bound(const TYPE &t) const {
    cellule *c = m_avant;

    for (size_t i = c->m_suiv.size(); i > 0;) {
        for (--i; c->m_suiv[i] != m_avant->m_prec[0]; c = c->m_suiv[i]) {
            if (!(*c->m_suiv[i]->m_contenu < t)) { break; }
        }
    }

    return iterator(c->m_suiv[0]);
}

template<typename TYPE>
typename ensemble<TYPE>::iterator ensemble<TYPE>::upper_bound(const TYPE &x) const {
    auto i = lower_bound(x);
    if (!(x < *i)){
        i++;
    }
    return i;
}

/////////////////////////////////////////////////////////////////
// erase(VAL)
// elimine VAL de l'ensemble, si present

template<typename TYPE>
size_t ensemble<TYPE>::erase(const TYPE &VAL) {
    // compl�ter
    return 0;
}

// erase(it)
// elimine de l'ensemble l'element en position it

template<typename TYPE>
typename ensemble<TYPE>::iterator ensemble<TYPE>::erase(iterator it) {
    // compl�ter
    return iterator(nullptr);
}
