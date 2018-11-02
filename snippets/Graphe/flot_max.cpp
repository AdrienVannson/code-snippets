bool estVu[NB_MAX_NOEUDS];

int getIArcVers (const int iNoeud, const int iVoisin)
{
    for (int iArc=0; iArc<(int)noeuds[iNoeud].voisins.size(); iArc++) {
        if (noeuds[iNoeud].voisins[iArc].cible == iVoisin) {
            return iArc;
        }
    }

    noeuds[iNoeud].voisins.push_back(Arc{iVoisin, 0});
    return noeuds[iNoeud].voisins.size()-1;
}

int parcourir (const int iNoeud, const int ponderationMin)
{
    if (ponderationMin == 0) {
        return 0;
    }

    Noeud &noeud = noeuds[iNoeud];

    if (estVu[iNoeud]) {
        return 0;
    }
    estVu[iNoeud] = true;

    if (iNoeud == nbNoeuds-1) {
        return ponderationMin;
    }

    for (Arc &arc : noeud.voisins) {
        const int res = parcourir(arc.cible, min(ponderationMin, arc.ponderation));

        if (res > 0) { // On a atteint l'arrivée
            arc.ponderation -= res;
            noeuds[arc.cible].voisins[ getIArcVers(arc.cible, iNoeud) ].ponderation += res;
            return res;
        }
    }

    return 0;
}

// Calcul de graphe résiduel
// --> chaque arc représente le débit d'eau que l'on pourrait ajouter de la source vers la cible
int getFlotMax ()
{
    int flotMax = 0;
    int gain;

    do {
        gain = parcourir(0, +oo);
        flotMax += gain;
        fill(estVu, estVu+nbNoeuds, false);
    } while (gain);

    return flotMax;
}
