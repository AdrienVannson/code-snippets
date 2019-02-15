int factorielles[NB_MAX_VALEURS];

void initialiserFactorielles ()
{
    factorielles[0] = 1;
    for (int i=1; i<NB_MAX_VALEURS; i++) {
        factorielles[i] = factorielles[i-1] * i;
    }
}
