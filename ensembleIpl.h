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
    // compl�ter
}

// lower_bound
// localise la premiere position ou l'element n'est
// pas plus petit que celui recu en parametre

template<typename TYPE>
typename ensemble<TYPE>::iterator ensemble<TYPE>::lower_bound(const TYPE &t) const {
    // compl�ter
    size_t indexLevel = m_avant->m_suiv.size() - 1;
    cellule *c = m_avant;
    cellule *prev_c = nullptr;
    cellule *apres = m_avant->m_prec[0];

    while (c->m_suiv[0] != apres)
        if (t < *c->m_suiv[indexLevel]->m_contenu) {
            prev_c = c->m_prec[indexLevel];
            while (prev_c->m_prec[indexLevel] == m_avant && indexLevel != 0) {
                indexLevel--;
            }
            if (prev_c->m_prec[indexLevel] != prev_c) {
                if(prev_c->m_prec[indexLevel] == apres)
                    break;
                c = prev_c->m_prec[indexLevel];
            } else
                break;
        } else if (*c->m_suiv[indexLevel]->m_contenu < t) {
            prev_c = c->m_suiv[indexLevel];
            while (prev_c->m_suiv[indexLevel] == apres && indexLevel != 0) {
                indexLevel--;
            }
            if (prev_c->m_suiv[indexLevel] != prev_c) {
                if(prev_c->m_suiv[indexLevel] == apres)
                    break;
                c = prev_c->m_suiv[indexLevel];
            } else
                break;
        } else
            break;
    return iterator(c->m_suiv[0]);
}

template<typename TYPE>
typename ensemble<TYPE>::iterator ensemble<TYPE>::upper_bound(const TYPE &x) const {
}

/////////////////////////////////////////////////////////////////
// erase(VAL)
// elimine VAL de l'ensemble, si present

template<typename TYPE>
size_t ensemble<TYPE>::erase(const TYPE &VAL) {
    // compl�ter
}

// erase(it)
// elimine de l'ensemble l'element en position it

template<typename TYPE>
typename ensemble<TYPE>::iterator ensemble<TYPE>::erase(iterator it) {
    // compl�ter
}
