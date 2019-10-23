const int NB_MAX_NOEUDS;

struct Arc
{
    int cible;
    // int ponderation;
};
struct Noeud
{
    vector<Arc> arcs;
};

int nbNoeuds;
Noeud noeuds[NB_MAX_NOEUDS];
