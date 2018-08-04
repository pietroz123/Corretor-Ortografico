void MostraFbs(No *N) {
    if (N == NULL)  return;
    cout << N->P.getPalavra() << " = " << N->Fb << endl;
    MostraFbs(N->Filho_Esquerdo);
    MostraFbs(N->Filho_Direito);
}
int altura(No *N) {
    if (N == NULL)  return 0;
    int He = altura(N->Filho_Esquerdo); // He = Altura Esquerda
    int Hd = altura(N->Filho_Direito);  // Hd = Altura Direita
    if (Hd > He)
        return Hd + 1;
    else
        return He + 1;
}
int Fb(No *N) {
    return altura(N->Filho_Direito) - altura(N->Filho_Esquerdo);
}
void AtualizaFbs(No *N) {
    if (N == NULL)  return;
    N->Fb = Fb(N);
    AtualizaFbs(N->Filho_Esquerdo);
    AtualizaFbs(N->Filho_Direito);
}