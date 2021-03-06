int dists[NB_MAX_NOEUDS];

void dijkstra (const int iNoeudDepart)
{
    fill(dists, dists+NB_MAX_NOEUDS, +oo);

    priority_queue< pair<int, int> > aVoir; // {-dist, iNoeud}
    aVoir.push( make_pair(0, iNoeudDepart) );

    while (aVoir.size()) {
        const int iNoeud = aVoir.top().second;
        const int dist = -aVoir.top().first;
        aVoir.pop();

        if (dists[iNoeud] != +oo) {
            continue;
        }
        dists[iNoeud] = dist;

        for (const Arc &arc : noeuds[iNoeud].arcs) {
            aVoir.push( make_pair(-dist-arc.ponderation, arc.cible) );
        }
    }
}
