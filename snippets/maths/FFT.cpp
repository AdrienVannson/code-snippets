// Renvoie les valeurs prises par le polynome pour les n racines n-ième de l'unité (avec n = nbCoefs)
vector<complex<double>> FFT (const vector<complex<double>> &coefs)
{
    if (coefs.size() == 1) {
        return {coefs[0]};
    }

    vector<complex<double>> coefsSuivants[2]; // {coefs pairs, coefs impairs}
    for (int i=0; i<(int)coefs.size(); i++) {
        coefsSuivants[i%2].push_back(coefs[i]);
    }

    const vector<complex<double>> resPairs = FFT(coefsSuivants[0]);
    vector<complex<double>> resImpairs = FFT(coefsSuivants[1]);

    for (int k=0; k<(int)coefs.size()/2; k++) {
        resImpairs[k] *= exp(2.0*M_PI*complex<double>(0, 1) * (double)k / (double)coefs.size());
    }

    vector<complex<double>> res;

    for (int k=0; k<(int)coefs.size()/2; k++) {
        res.push_back(resPairs[k] + resImpairs[k]);
    }

    for (int k=0; k<(int)coefs.size()/2; k++) {
        res.push_back(resPairs[k] - resImpairs[k]);
    }

    return res;
}

vector<complex<double>> iFFT (vector<complex<double>> valeurs)
{
    for (complex<double> &v : valeurs) v = conj(v);

    vector<complex<double>> res = FFT(valeurs);

    for (complex<double> &v : res) v = conj(v) / (double)valeurs.size();

    return res;
}

vector<int> multiplier (const vector<int> &a, const vector<int> &b)
{
    int nbCoefs = 1;
    while (nbCoefs < (int)a.size() + (int)b.size() - 1) {
        nbCoefs *= 2;
    }

    vector<complex<double>> c_a, c_b;
    for (const int x : a) c_a.push_back(x);
    while ((int)c_a.size() < nbCoefs) c_a.push_back(0);

    for (const int x : b) c_b.push_back(x);
    while ((int)c_b.size() < nbCoefs) c_b.push_back(0);

    c_a = FFT(c_a);
    c_b = FFT(c_b);

    vector<complex<double>> c_r;
    for (int i=0; i<nbCoefs; i++) c_r.push_back(c_a[i] * c_b[i]);
    c_r = iFFT(c_r);

    vector<int> res;
    for (int i=0; i<(int)a.size() + (int)b.size() - 1; i++) {
        res.push_back(round(c_r[i].real()));
    }
    return res;
}
