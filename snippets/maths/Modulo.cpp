template<class T, int MOD>
class Modulo
{
public:
    Modulo (const T valeur=0) :
        m_valeur (valeur)
    {
        m_valeur %= MOD;

        if (m_valeur < 0) {
            m_valeur += MOD;
        }
    }

    inline operator T () const
    {
        return m_valeur;
    }

private:
    T m_valeur;
};

template<class T, int MOD>
inline Modulo<T, MOD> operator+ (const Modulo<T, MOD> &a, const Modulo<T, MOD> &b)
{
    T res = (T)a + (T)b;
    if (res >= MOD) {
        res -= MOD;
    }
    return Modulo<T, MOD> (res);
}

template<class T, int MOD>
inline Modulo<T, MOD> operator- (const Modulo<T, MOD> &a, const Modulo<T, MOD> &b)
{
    T res = (T)a - (T)b;
    if (res < 0) {
        res += MOD;
    }
    return Modulo<T, MOD> (res);
}

template<class T, int MOD>
inline Modulo<T, MOD> operator* (const Modulo<T, MOD> &a, const Modulo<T, MOD> &b)
{
    return Modulo<T, MOD> ( ((T)a * (T)b) % MOD );
}
