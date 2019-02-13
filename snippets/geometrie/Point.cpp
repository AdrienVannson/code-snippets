struct Point
{
    int x, y;

    Point (const int x_=0, const int y_=0) :
        x (x_),
        y (y_)
    {}
};

Point operator+ (const Point &a, const Point &b)
{
    return Point (a.x + b.x, a.y + b.y);
}

Point operator- (const Point &a, const Point &b)
{
    return Point (a.x - b.x, a.y - b.y);
}
