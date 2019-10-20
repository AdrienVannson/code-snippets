int dists[NB_MAX_NOEUDS];

void bellmanFord (const int noeudDepart)
{
    vector<pair<pair<int, int>, int>> arcs; // {depart, arrivee}, ponderation}
    for (int i=0; i<nbNoeuds; i++) {
        for (const Arc &arc : noeuds[i].arcs) {
            arcs.push_back(make_pair(make_pair(i, arc.cible), arc.ponderation));
        }
    }

    fill(dists, dists+NB_MAX_NOEUDS, +oo);
    dists[noeudDepart] = 0;

    // Calcul du plus court chemin
    for (int iIteration=0; iIteration<nbNoeuds; iIteration++) {
        for (const auto &arc : arcs) {
            dists[arc.first.second] = min(dists[arc.first.first] + arc.second,
                                          dists[arc.first.second]);
        }
    }

    // Prise en compte des cycles négatifs
    for (int iIteration=0; iIteration<nbNoeuds; iIteration++) {
        for (const auto &arc : arcs) {
            if (dists[arc.first.first] + arc.second < dists[arc.first.second]) {
                dists[arc.first.second] = -oo;
            }
        }
    }
}
