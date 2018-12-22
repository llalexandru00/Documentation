#include <bits/stdc++.h>

using namespace std;

const int limita = 100000; // Ciurul va determina numerele prime pana la aceasta limita impusa (in cazul acesta precizam explicit limita)
int Ciur[limita+5]; // De regula Ciurul se face suficient de mare pentru a acoperi toate numerele ce pot aparea in problema (daca avem numere mai mari de 10^6/10^7, nu putem construi un ciur)
long long i, j;

void build()
{
    Ciur[0]=1; // 0 nu este prim
    Ciur[1]=1; // 1 nu este prim
    for (i=2; i<=limita; i++) // cautam numerele prime ("netaiate")
    {
        if (Ciur[i]==0) // cand am gasti un numar prim
        {
            for (j=i*i; j<=limita; j+=i) // eliminam toti multiplii sai incepand cu multiplul i*i
                Ciur[j]=1; //taiem efectiv elementul ce nu este prim (deoarece se divide cu i)
        }
    }
}

int main()
{
    build(); // obligatoriu de apelat funcia ce construieste ciurul INAINTE sa folosim ciurul
    for (int i=1; i<=limita; i++) // un algoritm ce afiseaza numerele prime gasite de ciur mai mici sau egale cu limita
        if (Ciur[i]==0) // daca e 1 inseamna ca e "taiat" deci neprim, daca e 0 inseamna ca este prim
            cout<<i<<" "; // si il scriem
    return 0;
}