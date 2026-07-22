#ifndef FUNCTII-EXTE1_H_INCLUDED
#define FUNCTII-EXTE1_H_INCLUDED
#include <fstream>
#include <iostream>
using namespace std;
//problema 1
void afisareVector(int v[], int dim)

{
    for(int i=0; i<dim ; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void perecheSuma(int v[],int n,int S,int &pi,int &pj)
{
    pi=-1;
    pj=-1;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
              if(v[i]+v[j]==S)
            {
                pi=i;
                pj=j;
            }
        }
    }
}
//problema 2
int profitMaxim(int v[],int n)
{
    int minim=v[0];
    int profit=0;
    for(int i=1; i<n; i++)
    {
        if(v[i]-minim>profit)
        {
            profit=v[i]-minim;

        }
        if(v[i]<minim)
        {
            minim=v[i];
        }
    }
    return profit;
}

//3
void mutaZerouri(int v[],int n)
{
    int p=0;
    for(int i=0;i<n;i++)
        if(v[i]!=0)
        {
            v[p]=v[i];
            p++;
        }
    while(p<n)
    {
        v[p]=0;
        p++;
    }
}

//4
int maxUnuConsecutiv(int v[],int n)
{
    int nr=0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==1)
        {
            nr++;
            if(nr>maxi)
            {
                 maxi=nr;
            }
        }else
            nr=0;
    }
    return maxi;
}

//5
int stergereDubluri(int v[], int n )
{
    int k=1;
    for(int i=1; i<n; i++)
    {
        if(v[i]!=v[k-1])
        {
            v[k]=v[i];
            k++;
        }
    }
    return k;

}
#endif // FUNCTII-EXTE1_H_INCLUDED
