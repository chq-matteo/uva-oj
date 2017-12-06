#include <iostream>
using namespace std;
// C++ program to find adjoint and inverse of a matrix
#include<bits/stdc++.h>

#define N 4
// Iterative C++ program to find modular inverse using
// extended Euclid algorithm
#include <stdio.h>

// Returns modulo inverse of a with respect to m using
// extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e., gcd(a, m) = 1
int modInverse(int a, int m)
{
   int m0 = m, t, q;
   int x0 = 0, x1 = 1;

   if (m == 1)
     return 0;

   while (a > 1)
   {
       // q is quotient
       q = a / m;

       t = m;

       // m is remainder now, process same as
       // Euclid's algo
       m = a % m, a = t;

       t = x0;

       x0 = x1 - q * x0;

       x1 = t;
   }

   // Make x1 positive
   if (x1 < 0)
      x1 += m0;

   return x1;
} 
// Function to get cofactor of A[p][q] in temp[][]. n is current
// dimension of A[][]
void getCofactor(long long A[N][N], long long temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding determinant of matrix.
   n is current dimension of A[][]. */
long long determinant(long long A[N][N], int n)
{
    long long D = 0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];
 
    long long temp[N][N]; // To store cofactors
 
    long long sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (long long f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D = (D + (sign * A[0][f] * determinant(temp, n - 1)) % mod) % mod;
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}
 
// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(long long A[N][N], long long adj[N][N])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }
 
    // temp is used to store cofactors of A[][]
    int sign = 1, temp[N][N];
 
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, N);
 
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;
 
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}
 
// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(int A[N][N], int inverse[N][N])
{
    // Find determinant of A[][]
    int det = determinant(A, N);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }
 
    // Find adjoint
    int adj[N][N];
    adjoint(A, adj);
 
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i][j] = (adj[i][j] * mod_inv(det, mod)) % mod;
 
    return true;
}
long long mod = 1000000007;
long long pow(n, k, p) {
    long long ans = 1;
    int t = 1;
    while (t < k) {
        if (k & t) {
            ans = (ans * n) % p;
        }
        n = (n * n) % p;
        t *= 2;
    }
    return ans;
}
int main() {
    long long t, n, k;
    cin >> t;
    for (long long tc = 0; tc < t; tc++) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {

        }
    }
}