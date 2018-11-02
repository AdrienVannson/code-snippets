const int NB_MAX_INTERVALLES;

int nbIntervalles;
Intervalle intervalles[NB_MAX_INTERVALLES];

void lireIntervalles ()
{
    scanf("%d", &nbIntervalles);

    for (int iIntervalle=0; iIntervalle<nbIntervalles; iIntervalle++) {
        scanf("%d %d", &intervalles[iIntervalle].debut, &intervalles[iIntervalle].fin);
    }
}
