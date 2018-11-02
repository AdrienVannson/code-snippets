#define GRAPHE_EST_ORIENTE
#define GRAPHE_EST_PONDERE

const int NB_MAX_NOEUDS;


struct Arc
{
    int cible;

#ifdef GRAPHE_EST_PONDERE
    int ponderation;
#endif
};

struct Noeud
{
    vector<Arc> voisins;
};

int nbNoeuds;
Noeud noeuds[NB_MAX_NOEUDS];
