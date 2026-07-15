#ifndef SOLUTII_H_INCLUDED
#define SOLUTII_H_INCLUDED
#include  "fisier.h"

void solutie1()
{
    int v[100],n;
    citireVector(v,n);
    int mn=valMin(v,n);
    int nr=nrAp(v,n,mn);

    cout<<" Numarul minim este"<< mn << endl;
    cout<<" Apare de " << nr << "ori"<<endl ;

}


void solutie12()
{
    int v[100], f[10000], n ;
    citireVector(v,n);
    frecventa(v,n,f);
    int mn = valMinima(f);
    cout<<" Numarul minim este " << mn << endl;
    cout<<" Apare de " << f[mn] << " ori " <<endl ;
}

#endif // SOLUTII_H_INCLUDED
