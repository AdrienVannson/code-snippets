const int NOEUD_SOURCE;
const int NOEUD_PUITS;

bool estVu[NB_MAX_NOEUDS];

int getIArcVers (const int iNoeud, const int iVoisin)
{
    for (int iArc=0; iArc<(int)noeuds[iNoeud].arcs.size(); iArc++) {
        if (noeuds[iNoeud].arcs[iArc].cible == iVoisin) {
            return iArc;
        }
    }

    noeuds[iNoeud].arcs.push_back(Arc{iVoisin, 0});
    return noeuds[iNoeud].arcs.size()-1;
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

    if (iNoeud == NOEUD_PUITS) {
        return ponderationMin;
    }

    for (Arc &arc : noeud.arcs) {
        const int res = parcourir(arc.cible, min(ponderationMin, arc.ponderation));

        if (res > 0) { // On a atteint l'arrivée
            arc.ponderation -= res;
            noeuds[arc.cible].arcs[ getIArcVers(arc.cible, iNoeud) ].ponderation += res;
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
        fill(estVu, estVu+nbNoeuds, false);
        gain = parcourir(NOEUD_SOURCE, +oo);
        flotMax += gain;
    } while (gain);

    return flotMax;
}
