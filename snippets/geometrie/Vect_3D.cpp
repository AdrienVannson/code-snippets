template<class T>
class Vect
{
public:
    inline Vect (const T x_=0, const T y_=0, const T z_=0) :
        x (x_),
        y (y_),
        z (z_)
    {}

    inline double norm () const { return sqrt(x*x + y*y + z*z); };

    inline void normalize ()
    {
        const double currentNorm = norm();

        x /= currentNorm;
        y /= currentNorm;
        z /= currentNorm;
    }

    inline Vect<T> operator- () const { return Vect<T> (-x, -y, -z); };

    inline void operator*= (const T k) { x *= k; y *= k; z *= k; }
    inline void operator/= (const T k) { x /= k; y /= k; z /= k; }
    inline void operator+= (const Vect<T> &v) { x += v.x; y += v.y; z += v.z; }
    inline void operator-= (const Vect<T> &v) { x -= v.x; y -= v.y; z -= v.z; }

    T x, y, z;
};

template<class T>
inline Vect<T> operator+ (const Vect<T> &a, const Vect<T> &b) { return Vect<T>(a.x+b.x, a.y+b.y, a.z+b.z); }

template<class T>
inline Vect<T> operator- (const Vect<T> &a, const Vect<T> &b) { return Vect<T>(a.x-b.x, a.y-b.y, a.z-b.z); }

template<class T>
inline T operator* (const Vect<T> &a, const Vect<T> &b) // Dot product
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

template<class T>
inline Vect<T> operator^ (const Vect<T> &a, const Vect<T> &b) // Cross product
{
    return Vect<T> (a.y * b.z - b.y * a.z,
                    a.z * b.x - b.z * a.x,
                    a.x * b.y - b.x * a.y);
}

template<class T>
inline Vect<T> operator* (const T k, const Vect<T> &v) { return Vect<T>(k*v.x, k*v.y, k*v.z); }

template<class T>
inline Vect<T> operator* (const Vect<T> &v, const T k) { return Vect<T>(k*v.x, k*v.y, k*v.z); }

template<class T>
inline double dist (const Vect<T> &a, const Vect<T> &b) { return (a-b).norm(); }
