#define GRAPHE_EST_ORIENTE
#define GRAPHE_EST_PONDERE

const int NB_MAX_NOEUDS = 1000*1000;


struct Arc
{
    int cible;

#ifdef GRAPHE_EST_PONDERE
    int ponderation;
#endif
};

struct Noeud
{
    vector<Arc> voisins[NB_MAX_NOEUDS];
};

int nbNoeuds;
Noeud noeuds[NB_MAX_NOEUDS];
