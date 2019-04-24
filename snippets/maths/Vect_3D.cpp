template<class T>
class Vect
{
public:
    inline Vect (const T x=0, const T y=0, const T z=0) :
        m_x (x),
        m_y (y),
        m_z (z)
    {}

    inline T x () const { return m_x; }
    inline void setX (const T x) { m_x = x; }

    inline T y () const { return m_y; }
    inline void setY (const T y) { m_y = y; }

    inline T z () const { return m_z; }
    inline void setZ (const T z) { m_z = z; }

    inline double norm () const { return sqrt(m_x*m_x + m_y*m_y + m_z*m_z); };

    inline void normalize ()
    {
        const double currentNorm = norm();

        m_x /= currentNorm;
        m_y /= currentNorm;
        m_z /= currentNorm;
    }

    inline Vect<T> operator- () const { return Vect<T> (-m_x, -m_y, -m_z); };

    inline void operator*= (const T k) { m_x*=k; m_y*=k; m_z*=k; }
    inline void operator/= (const T k) { m_x /= k; m_y /= k; m_z /= k; }
    inline void operator+= (const Vect<T> &v) { m_x += v.m_x; m_y += v.m_y; m_z += v.m_z; }
    inline void operator-= (const Vect<T> &v) { m_x -= v.m_x; m_y -= v.m_y; m_z -= v.m_z; }

protected:
    T m_x, m_y, m_z;
};

template<class T>
inline Vect<T> operator+ (const Vect<T> &a, const Vect<T> &b) { return Vect<T>(a.x()+b.x(), a.y()+b.y(), a.z()+b.z()); }

template<class T>
inline Vect<T> operator- (const Vect<T> &a, const Vect<T> &b) { return Vect<T>(a.x()-b.x(), a.y()-b.y(), a.z()-b.z()); }

template<class T>
inline T operator* (const Vect<T> &a, const Vect<T> &b) // Dot product
{
    return a.x()*b.x() + a.y()*b.y() + a.z()*b.z();
}

template<class T>
inline Vect<T> operator^ (const Vect<T> &a, const Vect<T> &b) // Cross product
{
    return Vect<T> (a.y() * b.z() - b.y() * a.z(),
                    a.z() * b.x() - b.z() * a.x(),
                    a.x() * b.y() - b.x() * a.y());
}

template<class T>
inline Vect<T> operator* (const T k, const Vect<T> &v) { return Vect<T>(k*v.x(), k*v.y(), k*v.z()); }

template<class T>
inline Vect<T> operator* (const Vect<T> &v, const T k) { return Vect<T>(k*v.x(), k*v.y(), k*v.z()); }

template<class T>
inline double dist (const Vect<T> &a, const Vect<T> &b) { return (a-b).norm(); }
