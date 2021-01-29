#include <iostream>
#include <algorithm>
#include <omp.h>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int range = 10;
int A[10][10];
int C[10][10];
int a[5][5];
int b[5][5];

void MultiplySubmatrices(int startX,int startY)
{
    int i, j, k;
    for(i = 0;i<5;i++)
    {
        for(j =0;j<5;j++)
        {
            for(k=0;k<5;k++)
            {
                C[startX+i][startY+j] += a[i][k] * b[k][j];
                cout<<C[startX+i][startY+j] << " ";
            }
        }
    }
}

void generateSubMatrix(int startX,int startY)
{
    for(int r=0;r<5;r++)
    {
        for(int c=0;c<5;c++)
        {
            a[r][c] = A[startX+r][startY+c];
            b[r][c] = A[startX+r][startY+c];
        }
    }
}

void traditionalMatrixMult()
{
    for(int r= 0;r<range;r+=5)
    {
        for(int c=0;c<range;c+=5)
        {
            generateSubMatrix(r,c);
            MultiplySubmatrices(r,c);
        }
    }
}

int main() {

    for(int r=0;r<range;r++)
    {
        for(int c=0;c<range;c++)
        {
            int n = rand()%10+1;
            A[r][c] = n;
        }
    }

    traditionalMatrixMult();

    return 0;
}
