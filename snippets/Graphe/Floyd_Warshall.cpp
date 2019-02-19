for (int pivot=0; pivot<nbNoeuds; pivot++) {
    for (int debut=0; debut<nbNoeuds; debut++) {
        for (int fin=0; fin<nbNoeuds; fin++) {
            dists[debut][fin] = min(dists[debut][pivot] + dists[pivot][fin], dists[debut][fin]);
        }
    }
}
