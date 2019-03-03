void enraciner (const int iNoeud, const int iParent)
{
    Noeud &noeud = noeuds[iNoeud];

    for (const int voisin : noeud.voisins) {
        if (voisin != iParent) {
            noeud.enfants.push_back(voisin);
        }
    }

    for (int enfant : noeud.enfants) {
        enraciner(enfant, iNoeud);
    }
}
