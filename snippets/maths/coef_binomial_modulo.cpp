const int N_MAX;
const int MODULO; // doit être premier

ll factorielles[N_MAX];

void initialiserCoefsBinomiaux ()
{
    factorielles[0] = 1;
    for (int i=1; i<N_MAX; i++) {
        factorielles[i] = factorielles[i-1] * i % MODULO;
    }
}

int xGCD (int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    const int gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (ll)(a / b) * y1;
    return gcd;
}

inline ll getInverse (const int a)
{
    int x, y;
    xGCD(a, MODULO, x, y);
    return x;
}

int getCoefBinomial (const int n, const int k)
{
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }

    const int res = (factorielles[n] * getInverse(factorielles[k]) % MODULO) * getInverse(factorielles[n - k]) % MODULO;

    if (res < 0) {
        return res + MODULO;
    }
    return res;
}
