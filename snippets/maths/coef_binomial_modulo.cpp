const int N_MAX;
const int MODULO; // doit être premier

int facts[N_MAX]; // Premières factorielles

void initialiserCoefsBinomiaux ()
{
    facts[0] = 1;
    for (int i=1; i<N_MAX; i++) facts[i] = (ll)facts[i-1] * (ll)i % (ll)MODULO;
}

array<int,3> PGCD_coef_bezout (const int x, const int y) // {pgcd, a,b} tels que ax+by=pgcd
{
    if (y == 0) return {x, 1, 0};
    const array<int,3> suivant = PGCD_coef_bezout(y, x%y);
    return {suivant[0], suivant[2], suivant[1] - (x/y)*suivant[2]};
}

inline int getInverse (const int x)
{
    return PGCD_coef_bezout(x, MODULO)[1];
}

int getCoefBinomial (const int n, const int k)
{
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;

    const int res = ( (ll)facts[n]
                    * (ll)getInverse(facts[k]) % (ll)MODULO)
                    * (ll)getInverse(facts[n - k]) % (ll)MODULO;

    return res < 0 ? res + MODULO : res;
}
