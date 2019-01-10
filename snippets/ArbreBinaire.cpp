const int PROFONDEUR;
const int NB_NOEUDS = 1<<PROFONDEUR;
const int PREMIERE_FEUILLE = NB_NOEUDS / 2;

int noeuds[NB_NOEUDS];

void appelSurPosition (const int pos)
{
    for (int iNoeud=PREMIERE_FEUILLE+pos; iNoeud>=1; iNoeud/=2) {
        // ...
    }
}

void appelSurIntervalle (const int debut, const int fin,
                         const int debutActuel=0, const int finActuelle=PREMIERE_FEUILLE, const int iNoeud=1)
{
    if (finActuelle <= debut || debutActuel >= fin) {
        return;
    }

    if (debutActuel >= debut && finActuelle <= fin) {
        // ...

        return;
    }

    const int milieuActuel = (debutActuel + finActuelle) / 2;

    appelSurIntervalle(debut, fin, debutActuel, milieuActuel, iNoeud*2);
    appelSurIntervalle(debut, fin, milieuActuel, finActuelle, iNoeud*2+1);
}
