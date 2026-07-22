#ifndef FUNCTII-EXTE1_H_INCLUDED
#define FUNCTII-EXTE1_H_INCLUDED
#include <fstream>
#include <iostream>
using namespace std;
//problema 1

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

#endif // FUNCTII-EXTE1_H_INCLUDED
