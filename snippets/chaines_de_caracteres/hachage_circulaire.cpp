class Hash
{
public:
    static const ll M = 1000*1000*1000 + 7;
    static const ll R = 128;
    static const ll INVERSE_R = 570312504;

    Hash () :
        m_hash (0),
        m_rSuivant (1)
    {}

    void push_front (const char ajout)
    {
        m_hash = ((R * m_hash) + ajout) % M;
        m_caracteres.push_front(ajout);
        m_rSuivant = (m_rSuivant * R) % M;
    }

    void pop_front ()
    {
        m_hash = ((m_hash - m_caracteres.front()) * INVERSE_R) % M;
        if (m_hash < 0) m_hash += M;

        m_caracteres.pop_front();
        m_rSuivant = (m_rSuivant * INVERSE_R) % M;
    }

    void push_back (const char ajout)
    {
        m_hash = (m_hash + m_rSuivant*ajout) % M;
        m_caracteres.push_back(ajout);
        m_rSuivant = (m_rSuivant * R) % M;
    }

    void pop_back ()
    {
        m_rSuivant = (m_rSuivant * INVERSE_R) % M;

        m_hash = (m_hash - m_rSuivant*m_caracteres.back()) % M;
        if (m_hash < 0) m_hash += M;

        m_caracteres.pop_back();
    }


    deque<char> m_caracteres;
    ll m_hash;

private:
    ll m_rSuivant;
};
