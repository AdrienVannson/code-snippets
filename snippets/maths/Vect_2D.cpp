template<class T>
class Vect
{
public:
    inline Vect (const T x=0, const T y=0) :
        m_x (x),
        m_y (y)
    {}

    inline T x () const { return m_x; }
    inline void setX (const T x) { m_x = x; }

    inline T y () const { return m_y; }
    inline void setY (const T y) { m_y = y; }

    inline double norm () const { return sqrt(m_x*m_x + m_y*m_y); };

    inline void normalize ()
    {
        const double currentNorm = norm();

        m_x /= currentNorm;
        m_y /= currentNorm;
    }

    inline Vect<T> operator- () const { return Vect<T> (-m_x, -m_y); };

    inline void operator*= (const T k) { m_x*=k; m_y*=k; }
    inline void operator/= (const T k) { m_x /= k; m_y /= k; }
    inline void operator+= (const Vect<T> &v) { m_x += v.m_x; m_y += v.m_y; }
    inline void operator-= (const Vect<T> &v) { m_x -= v.m_x; m_y -= v.m_y; }

protected:
    T m_x, m_y;
};

template<class T>
inline Vect<T> operator+ (const Vect<T> &a, const Vect<T> &b) { return Vect<T>(a.x()+b.x(), a.y()+b.y()); }

template<class T>
inline Vect<T> operator- (const Vect<T> &a, const Vect<T> &b) { return Vect<T>(a.x()-b.x(), a.y()-b.y()); }

template<class T>
inline T operator* (const Vect<T> &a, const Vect<T> &b) // Dot product
{
    return a.x()*b.x() + a.y()*b.y();
}

template<class T>
inline T operator^ (const Vect<T> &a, const Vect<T> &b) // Cross product on z
{
    return a.x() * b.y() - b.x() * a.y();
}

template<class T>
inline Vect<T> operator* (const T k, const Vect<T> &v) { return Vect<T>(k*v.x(), k*v.y()); }

template<class T>
inline Vect<T> operator* (const Vect<T> &v, const T k) { return Vect<T>(k*v.x(), k*v.y()); }

template<class T>
inline double dist (const Vect<T> &a, const Vect<T> &b) { return (a-b).norm(); }
