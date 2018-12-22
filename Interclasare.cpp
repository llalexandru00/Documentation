#include <bits/stdc++.h>

using namespace std;

int i, j, k, idx, n, m;
int A[100005]; // primul vector - obligatoriu sortat inainte de interclasare
int B[100005]; // al doilea vector - obligatoriu sortat inainte de interclasare
int C[200005]; // vectorul rezultat - cu marimea minima suma marimilor lui A si B, in final va fi sortat

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>A[i];
    cin>>m;
    for (int i=1; i<=m; i++)
        cin>>B[i];
    i=1;
    j=1;
    k=0;
    while (i<=n && j<=m) // partea de interclasare, unde vectorii se interpatrund
    {
        k++;
        if (A[i]<B[j]) // prioroitizam elementul mai mic pentru a fi pus urmatorul in rezultat
        {
            C[k]=A[i];
            i++; // incrementam indicele primului vector
        } else
        {
            C[k]=B[j];
            j++; // incrementam indicele celui de al doilea vector
        }
    }
    if (j==m+1) // in cazul in care cel de al doilea vector a fost epuizat, inseamna ca inca mai avem elemente in primul
        for (idx=i; idx<=n; idx++)
        {
            k++;
            C[k]=A[idx];
        }
    else // altfel mai avem elemente in cel de al doilea vector
        for (idx=j; idx<=m; idx++)
        {
            k++;
            C[k]=B[idx];
        }

    for (idx=1; idx<=k; idx++)
    {
        cout<<C[idx]<<" ";
    }
    return 0;
}