#include <string>
#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include "common.h"

using namespace std;

int max3(int a, int b, int c)
{
//	return max (max(a,b), c);
	int z = a;
	if (z < b) z=b;
	if (z < c) z=c;
	return z;
}
/*************************************************/
int max2(int a, int b)
{
	int z = a;
	if (z < b) z=b;
	return z;
}
/**************************************************/
int min2(int a, int b)
{
	int z = a;
	if (z > b) z=b;
	return z;
}
/**************************************************/
void wo (FILE *f, char *n, char *s, char *q) {
	int m = min(strlen(q), strlen(s));
	s[m] = q[m] = 0;
	fprintf(f, "@%s\n%s\n+\n%s\n", n, s, q);
}
/***********************************************************/
char checkNs (char *s) {
	int nc = 0, c = 0;
	while (*s) nc += (*s == 'N'), s++, c++;
	return (nc > 10 ? 0 : 1);
}
/**********************************************************/
string reverse_complement ( const string &str )
{
	const char *revComp = "TBGDEFCHIJKLMNOPQRSAUVWXYZ";

	string x;
	for (int i = str.size() - 1; i >= 0; i--)
		x += revComp[str[i] - 'A'];
	return x;
}
/*******************************************************************/
string reverse ( const string &str )
{
	string x;
	for (int i = str.size() - 1; i >= 0; i--)
		x += str[i];
	return x;
}
/*******************************************************************/
string S (const char* fmt, ...) {
	char *ptr = 0;
    va_list args;
    va_start(args, fmt);
    vasprintf(&ptr, fmt, args);
    va_end(args);
    string s = ptr;
    free(ptr);
    return s;
}
/********************************************************************/
int check_AT_GC(const string &contig, const double &MAX_AT_GC)
{
	double AT_count = 0, GC_count = 0, A_count = 0, T_count = 0, G_count = 0, C_count = 0;
	int clen        = contig.length();
	for(int i = 0; i < clen-1; i++)
	{
		if((contig[i] == 'A' && contig[i+1] == 'T') ||(contig[i] == 'T' && contig[i+1] == 'A')) AT_count++;
		if((contig[i] == 'C' && contig[i+1] == 'G') ||(contig[i] == 'G' && contig[i+1] == 'C'))	GC_count++;
		if((contig[i] == 'A' && contig[i+1] == 'A')) A_count++;
		if((contig[i] == 'T' && contig[i+1] == 'T')) T_count++;
		if((contig[i] == 'G' && contig[i+1] == 'G')) G_count++;
		if((contig[i] == 'C' && contig[i+1] == 'C')) C_count++;
	}
	if(AT_count/(double)clen >= MAX_AT_GC || GC_count/(double)clen >= MAX_AT_GC || A_count/(double)clen >=MAX_AT_GC || T_count/(double)clen >=MAX_AT_GC || G_count/(double)clen >=MAX_AT_GC || C_count/(double)clen >=MAX_AT_GC )
		return 0;
	else
		return 1;
}
/*******************************************************************/
