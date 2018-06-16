/* ----------------------------------------------------------------------- *
 * 
 *   Author: Leandro Augusto Lacerda Campos <llacerdacampos@gmail.com>
 * 
 *   Data Structures and Algorithms Specialization,
 *   by University of California, San Diego, 
 *   and National Research University Higher School of Economics
 * 
 *   Course 1: Algorithmic Toolbox
 * 
 *   Solution for Longest Common Subsequence of Two Sequences Problem
 * 
 * ----------------------------------------------------------------------- */

#include <stdio.h>

/* maximum sequence size */
#define SEQMAX 100

/* the keyword typeof is not available in programs compiled with -std */
#define typeof __typeof__

/* 
 * _cmp: compares two values of the same or compatible types.
 */
#define _cmp(x, y, op) ((x) op (y) ? (x) : (y))

/* 
 * _cmp_once: compares two values of the same or compatible types
 * avoiding multiple evaluations of the arguments.
 */
#define _cmp_once(x, y, op) ({      \
		typeof(x) _x = (x);         \
		typeof(y) _y = (y);         \
		_cmp(_x, _y, op); })

/* 
 * min: returns the minimum of two values of the same or compatible types.
 */
#define min(x, y) _cmp_once(x, y, <)

/* 
 * min3: returns the minimum of three values of the same or compatible types.
 */
#define min3(x, y, z) min((typeof(x))min(x, y), z)

/* 
 * max: returns the maximum of two values of the same or compatible types.
 */
#define max(x, y) _cmp_once(x, y, >)

/* 
 * max3: returns the maximum of three values of the same or compatible types.
 */
#define max3(x, y, z) max((typeof(x))max(x, y), z)

/*
 * lcslen: computes the length of a longest common subsequence of two 
 * sequences xs and ys with n and m elements, respectively.
 */
unsigned short lcslen(const int *xs, const int *ys, 
                      unsigned short n, unsigned short m,
                      unsigned short d[SEQMAX+1][SEQMAX+1])
{
    unsigned short i, j;

    for (i = 0; i <= n; i++)
        d[i][0] = 0;
    for (j = 1; j <= m; j++)
        d[0][j] = 0;
    for (j = 1; j <= m; j++)
        for (i = 1; i <= n; i++) {
            if (xs[i-1] == ys[j-1])
                d[i][j] = max3(d[i][j-1], d[i-1][j], d[i-1][j-1] + 1);
            else
                d[i][j] = max3(d[i][j-1], d[i-1][j], d[i-1][j-1]);
        }
    return d[n][m];
}

int main()
{
    int xs[SEQMAX], ys[SEQMAX];
    unsigned short d[SEQMAX+1][SEQMAX+1];
    unsigned short n, m;
    unsigned short i;

    scanf("%hu", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &xs[i]);
    scanf("%hu", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &ys[i]);
    printf("%d\n", lcslen(xs, ys, n, m, d));
    return 0;
}