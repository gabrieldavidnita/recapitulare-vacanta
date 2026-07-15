#ifndef SOLUTII_H_INCLUDED
#define SOLUTII_H_INCLUDED
#include  "functii.h"

void solutie1()
{
    int v[300],n;
    citireVector(v,n);
    int mn=valMin(v,n);
    int nr=nrAp(v,n,mn);
    cout<<" Numarul minim este"<< mn << endl;
    cout<<" Apare de " << nr << "ori"<<endl ;

}


void solutie12()
{
    int v[300], f[10000], n ;
    citireVector(v,n);
    frecventaNumarVector(v,n,f);
    int mn = valMinima(f);
    cout<<" Numarul minim este " << mn << endl;
    cout<<" Apare de " << f[mn] << " ori " <<endl ;
}

void solutie2()
{
    int v[300],f[10]{},n;
    citireVector(v,n);
    int cifMax=cifMaxVector(v,n);
    int pozMa=pozMax(v,n);
    int pozMi=pozMin(v,n);
    if(n>13){
        int  ct=contorCif(v[12],cifMax);
        cout<<" Apare de " << ct << " ori "<<endl;
    }else{
        cout<<"Lungimea vectorului nu este coresponzutaoare"<<endl;
    }
    v[pozMa]=0;
    v[pozMi]=0;
    frecventaCifraVector(v,n,f);
    cout<<cifMax<<" apare de "<<f[cifMax]<<" ori"<<endl;




}
#endif // SOLUTII_H_INCLUDED
