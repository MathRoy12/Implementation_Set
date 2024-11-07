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
    for (auto it = src.begin(); it != src.end() ; ++it) {
        insert(*it);
    }
}

template<typename TYPE>
ensemble<TYPE>::~ensemble() {
    clear();
    delete m_avant->m_suiv[0];
    delete m_avant;
    m_avant = nullptr;
}

/////////////////////////////////////////////////////////////////
// find
// localise un �l�ment, retourne la fin si absent

template<typename TYPE>
typename ensemble<TYPE>::iterator ensemble<TYPE>::find(const TYPE &x) const {
    auto i = lower_bound(x);

    if (i.m_pointeur == m_avant->m_prec[0])
        i = iterator(m_avant->m_prec[0]);
    else if (x < *i)
        i = iterator(m_avant->m_prec[0]);


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
    auto i = find(VAL);

    if(i == m_avant->m_prec[0])
        return 0;

    erase(i);

    return 1;
}

// erase(it)
// elimine de l'ensemble l'element en position it

template<typename TYPE>
typename ensemble<TYPE>::iterator ensemble<TYPE>::erase(iterator it) {
    if (it == m_avant || it == m_avant->m_prec[0] || it == nullptr)
        return it;

    cellule* cel_suiv = nullptr;
    cellule* cel_prec = nullptr;
    for (size_t i = 0; i < it.m_pointeur->m_suiv.size(); ++i) {
        cel_suiv = it.m_pointeur->m_suiv[i];
        cel_prec = it.m_pointeur->m_prec[i];

        cel_suiv->m_prec[i] = it.m_pointeur->m_prec[i];
        cel_prec->m_suiv[i] = it.m_pointeur->m_suiv[i];
    }
    auto ret_val = iterator(it.m_pointeur->m_suiv[0]);
    delete it.m_pointeur;
    m_taille--;

    return ret_val;
}
