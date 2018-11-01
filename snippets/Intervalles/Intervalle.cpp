struct Intervalle
{
    int debut, fin;

    Intervalle (const int debut_=0, const int fin_=0) :
        debut (debut_),
        fin (fin_)
    {}

    inline int taille () const
    {
        return fin - debut;
    }
};

Intervalle getUnion (const Intervalle &a, const Intervalle &b)
{
    return Intervalle (min(a.debut, b.debut), max(a.fin, b.fin));
}

Intervalle getIntersection (const Intervalle &a, const Intervalle &b)
{
    return Intervalle (max(a.debut, b.debut), min(a.fin, b.fin));
}
