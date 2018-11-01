void lireGraphe ()
{
    int nbArcs;
    scanf("%d %d", &nbNoeuds, &nbArcs);

    for (int iArc=0; iArc<nbArcs; iArc++) {
        int source, cible;
        scanf("%d %d", &source, &cible);
        // source--, cible--;

#ifdef GRAPHE_EST_PONDERE
        int ponderation;
        scanf("%d", &ponderation);

        noeuds[source].voisins.push_back(Arc{cible, ponderation});
#else
        noeuds[source].voisins.push_back(Arc{cible});
#endif

#ifndef GRAPHE_EST_ORIENTE

#ifdef GRAPHE_EST_PONDERE
        noeuds[cible].voisins.push_back(Arc{source, ponderation});
#else
        noeuds[cible].voisins.push_back(Arc{source});
#endif
#endif

    }
}
