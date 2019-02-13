const int NB_MAX_LIGNES;
const int NB_MAX_COLONNES;

int nbLignes, nbColonnes;
int valeurs[NB_MAX_LIGNES][NB_MAX_COLONNES];

int sommesAvant[NB_MAX_LIGNES+1][NB_MAX_COLONNES+1];

void mettreAJourCumulatif ()
{
    for (int iColonne=0; iColonne<=nbColonnes; iColonne++) {
        sommesAvant[0][iColonne] = 0;
    }

    for (int iLigne=0; iLigne<nbLignes; iLigne++) {
        sommesAvant[iLigne][0] = 0;

        for (int iColonne=0; iColonne<nbColonnes; iColonne++) {
            sommesAvant[iLigne+1][iColonne+1] = sommesAvant[iLigne+1][iColonne] + sommesAvant[iLigne][iColonne+1]
                                              - sommesAvant[iLigne][iColonne] + valeurs[iLigne][iColonne];
        }
    }
}

int getSomme (const int ligneDebut, const int ligneFin, const int colonneDebut, const int colonneFin)
{
    return sommesAvant[ligneFin][colonneFin] - sommesAvant[ligneFin][colonneDebut]
         - sommesAvant[ligneDebut][colonneFin] + sommesAvant[ligneDebut][colonneDebut];
}
