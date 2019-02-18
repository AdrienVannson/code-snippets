int coefsBinomiaux[100][100]; // Possibilité d'overflow

int getCoefBinomial (const int n, const int k)
{
    if (k < 0 || k > n) {
        return 0;
    }

    int &res = coefsBinomiaux[n][k];

    if (res != 0) {
        return res;
    }

    if (k == 0 || k == n) {
        return res = 1;
    }

    if (k > n-k) {
        return res = getCoefBinomial(n, n-k);
    }

    return res = (getCoefBinomial(n-1, k-1) + getCoefBinomial(n-1, k));
}
