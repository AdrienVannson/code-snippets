template<class T>
T getPuissance (const T &actuel, const int puissance)
{
    if (puissance == 1) {
        return actuel;
    }

    if (puissance % 2 == 0) {
        return getPuissance(actuel * actuel, puissance / 2);
    }
    else {
        return actuel * getPuissance(actuel * actuel, (puissance-1) / 2);
    }
}
