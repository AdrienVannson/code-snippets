const string chaine = recherche + "_" + chaineDepart;

vector<int> plusLongsBords;
plusLongsBords.push_back(-1);

for (int iCaractere=0; iCaractere<(int)chaine.size(); iCaractere++) {
    int plusLongBord = plusLongsBords.back();
    while (plusLongBord != -1 && chaine[iCaractere] != chaine[plusLongBord]) {
        plusLongBord = plusLongsBords[plusLongBord];
    }

    plusLongsBords.push_back(plusLongBord + 1);

    if (plusLongsBords.back() == (int)recherche.size()) {
        cout << "CHAINE TROUVEE : " << iCaractere - 2*recherche.size() << endl;
    }
}
