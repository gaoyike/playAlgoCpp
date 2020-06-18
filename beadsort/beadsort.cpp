#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

#define BEAD(i, j) beads[i*max + j]

void beadsort(int *a, int len)
{
    int max = a[0];
    for(int i = 1; i < len; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    unsigned int beads[max * len]; //positive int only
    memset(beads, 0, sizeof(beads));

    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < a[i]; j++)
        {
            BEAD(i, j) = 1;
        }
    }

    for(int j = 0; j < max; j++)
    {
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += BEAD(i, j);// count the beads
            BEAD(i, j) = 0; // clear the post
        }
        
        for (int i = len - sum; i < len; i++)
        {
            BEAD(i, j) = 1; // gravity down 
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        int j;
        for (j = 0; j < max && BEAD(i, j); j++); // j < max and BEAD(i, j) != null

        a[i] = j;
    }
}