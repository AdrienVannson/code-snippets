const int NB_MAX_LIGNES;
const int NB_MAX_COLONNES;

#if 1
const int NB_DIRECTIONS = 4;
const int DELTAS_DIRECTIONS[NB_DIRECTIONS][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};
#elif
const int NB_DIRECTIONS = 8;
const int DELTAS_DIRECTIONS[NB_DIRECTIONS][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
#endif

int nbLignes, nbColonnes;
bool estLibre[NB_MAX_LIGNES][NB_MAX_COLONNES];

void BFS ()
{
    queue< pair<pair<int, int>, int> > aVoir; // { {iLigne, iColonne}, dist}
    aVoir.push(make_pair(make_pair(0, 0), 0));

    while (aVoir.size()) {
        const int iLigne = aVoir.front().first.first;
        const int iColonne = aVoir.front().first.second;
        const int dist = aVoir.front().second;
        aVoir.pop();

        // Vérification de la validité
        if (iLigne < 0 || iLigne >= nbLignes
         || iColonne < 0 || iColonne >= nbColonnes
         || !estLibre[iLigne][iColonne]) {
            continue;
        }
        estLibre[iLigne][iColonne] = false;

        if (/* ... */) { // Succès
            // ...
            return;
        }

        for (int iDirection=0; iDirection<NB_DIRECTIONS; iDirection++) {
            aVoir.push( make_pair(make_pair(iLigne+DELTAS_DIRECTIONS[iDirection][0], iColonne+DELTAS_DIRECTIONS[iDirection][1]), dist+1) );
        }
    }
}
