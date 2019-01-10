int PGCD (const int a, const int b)
{
    if (a == 0) {
        return b;
    }
    return PGCD(b%a, a);
}

int PPCM (const int a, const int b)
{
    return a * b / PGCD(a, b);
}
