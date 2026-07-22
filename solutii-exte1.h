#ifndef SOLUTII-EXTE1_H_INCLUDED
#define SOLUTII-EXTE1_H_INCLUDED
#include "functii-exte1.h"

void solutie1a()
{
    int v[100]={2,7,11,15,3};
    int n=5;
    int S=9;
    int pi , pj;
    for(int i=0;i<n;i++)
    {
        perecheSuma(v,n,S,pi,pj);
    }
    cout<<pi<<" "<<pj;
}
void solutie2a()
{
    int v[100]={7,1,5,3,6,4};
    int n=6;
    cout<<profitMaxim(v,n);
}

void solutie3a()
{
    int v[100]={0,1,0,3,12};
    int n=5;
    mutaZerouri(v,n);
    afisareVector(v,n);
}

void solutie4a()
{
    int v[1000]={1,1,0,1,1,1};
    int n=6;
    cout<<maxUnuConsecutiv(v,n);

}

void solutie5a()
{
    int v[100]={1,1,2,2,3,3,3,5,5,7,7};
    int n=10;
    int k=stergereDubluri(v,n);
    cout<<k<<endl;
    afisareVector(v,n);
}

void solutie6a()
{
    int v[100]={2,2,1,1,1,2,2};
    int n=7;
    cout<<elementMajoritar(v,n);
}

void solutie7a()
{
    int v[100]={1,2,3,4,5,6,7};
    int n=7;
    int k=3;
    rotesteDreapta(v,n,k);
    afisareVector(v,n);
}
#endif // SOLUTII-EXTE1_H_INCLUDED
