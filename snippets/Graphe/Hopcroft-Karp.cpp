/* Forme du graphe :
struct Arc { int cible; int id; };
struct Noeud { vector<Arc> arcs; };

int nbNoeuds[2], nbArretes;
Noeud noeuds[2][NB_MAX_NOEUDS];
*/

bool estLibre[2][NB_MAX_NOEUDS]; // Si un noeud n'est pas libre, il est dans le couplage final
bool estDansCouplage[NB_MAX_ARRETES];

int profondeurVue[2][NB_MAX_NOEUDS];

int getTailleCheminsAugmentation ()
{
    vector<int> aVoir[2];
    for (int i=0; i<nbNoeuds[0]; i++) {
        if (estLibre[0][i]) {
            aVoir[0].push_back(i);
            profondeurVue[0][i] = 0;
        }
    }

    int nbEtapes = 0;

    bool succes = false;

    while (!succes && aVoir[nbEtapes%2].size()) {
        const int etape = nbEtapes % 2;

        for (const int noeud : aVoir[etape]) {
            for (const Arc &arc : noeuds[etape][noeud].arcs) {
                if (profondeurVue[!etape][arc.cible] == -1 && estDansCouplage[arc.id] == etape) {
                    profondeurVue[!etape][arc.cible] = nbEtapes+1;
                    aVoir[!etape].push_back(arc.cible);

                    if (estLibre[!etape][arc.cible]) {
                        succes = true;
                    }
                }
            }
        }

        aVoir[etape].clear();
        nbEtapes++;
    }

    return succes ? nbEtapes : -1;
}

bool utiliserCheminAugmentation (const int groupe, const int noeud)
{
    if (groupe == 0 && estLibre[0][noeud]) {
        estLibre[0][noeud] = false;
        return true;
    }

    const int profondeurActuelle = profondeurVue[groupe][noeud];
    profondeurVue[groupe][noeud] = -1;

    for (const Arc &arc : noeuds[groupe][noeud].arcs) {
        if (profondeurVue[!groupe][arc.cible] == profondeurActuelle-1
            && (groupe == 1 || estDansCouplage[arc.id])) {

            if (utiliserCheminAugmentation(!groupe, arc.cible)) {
                estDansCouplage[arc.id] ^= 1;
                return true;
            }
        }
    }
    return false;
}

int calcCouplageMax ()
{
    fill(*estLibre, *estLibre+2*NB_MAX_NOEUDS, true);
    fill(estDansCouplage, estDansCouplage+NB_MAX_ARRETES, false);

    int couplageMax = 0;

    while (true) {
        fill(*profondeurVue, *profondeurVue+2*NB_MAX_NOEUDS, -1);

        const int tailleCheminsAugmentation = getTailleCheminsAugmentation();
        if (tailleCheminsAugmentation == -1) {
            return couplageMax;
        }

        for (int i=0; i<nbNoeuds[1]; i++) { // Utilisation des chemins d'augmentation de longueur minimale
            if (estLibre[1][i] && profondeurVue[1][i] == tailleCheminsAugmentation) {
                if (utiliserCheminAugmentation(1, i)) {
                    estLibre[1][i] = false;
                    couplageMax++;
                }
            }
        }
    }
}
