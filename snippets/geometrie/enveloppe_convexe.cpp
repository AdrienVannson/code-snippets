template<class T>
vector<Vect<T>> getToit (vector<Vect<T>> &points)
{
    sort(points.begin(), points.end(), [](Vect<T> &a, Vect<T> &b) {
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.y < b.y;
    });

    vector<Vect<T>> toit;

    for (int iPoint=0; iPoint<(int)points.size(); iPoint++) {
        const Vect<T> &point = points[iPoint];

        while (toit.size() >= 2 && ( (toit.back() - toit[toit.size()-2]) ^ (point - toit[toit.size()-2]) ) >= 0) {
            toit.pop_back();
        }
        toit.push_back(point);
    }

    return toit;
}

template<class T>
vector<Vect<T>> getEnveloppeConvexe (vector<Vect<T>> points)
{
    vector<Vect<T>> enveloppe = getToit(points);
    enveloppe.pop_back();

    for (Vect<T> &point : points) point *= -1;

    vector<Vect<T>> bas = getToit(points);
    bas.pop_back();
    for (Vect<T> &point : bas) point *= -1;

    for (Vect<T> v : bas) enveloppe.push_back(v);

    return enveloppe;
}
