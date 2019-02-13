const int NB_MAX_VALEURS;

int nbValeurs;
int valeurs[NB_MAX_VALEURS];

int sommesAvant[NB_MAX_VALEURS+1];

void mettreAJourCumulatif ()
{
    sommesAvant[0] = 0;

    for (int iValeur=0; iValeur<nbValeurs; iValeur++) {
        sommesAvant[iValeur+1] = sommesAvant[iValeur] + valeurs[iValeur];
    }
}

int getSomme (const int debut, const int fin)
{
    return sommesAvant[fin] - sommesAvant[debut];
}
