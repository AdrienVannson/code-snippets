int dists[NB_MAX_NOEUDS];

void BFS (const int iNoeud)
{
    fill(dists, dists+NB_MAX_NOEUDS, +oo);

    queue< pair<int, int> > aVoir; // {iNoeud, dist}
    aVoir.push( make_pair(iNoeud, 0) );

    while (aVoir.size()) {
        const int iNoeud = aVoir.front().first;
        const int dist = aVoir.front().second;
        aVoir.pop();

        if (dists[iNoeud] != +oo) {
            continue;
        }
        dists[iNoeud] = dist;

        for (const int voisin : noeuds[iNoeud].voisins) {
            aVoir.push( make_pair(voisin, dist+1) );
        }
    }
}
