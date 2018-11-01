const int ETAT_NON_VISITE = 0;
const int ETAT_EN_COURS = 1;
const int ETAT_DEJA_VU = 2;

int etats[NB_MAX_NOEUDS];

void dfs (const int iNoeud)
{
    if (etats[iNoeud] != ETAT_NON_VISITE) {
        return;
    }
    etats[iNoeud] = ETAT_EN_COURS;

    for (const int iVoisin : noeuds[iNoeud].voisins) {
        dfs(iVoisin);
    }

    etats[iNoeud] = ETAT_DEJA_VU;
}
