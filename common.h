#ifndef __COMMON__
#define __COMMON__
#include <string>
#include <cstdio>
#include "logger.h"

#define KB  1024LL
#define MB  KB * 1024LL
#define GB  MB * 1024LL

#define VERSION	0x10
#define MAGIC 	(0x07445A00 | VERSION)

#define ERROR(c,...)\
	fprintf(stderr, c"\n", ##__VA_ARGS__)
#define LOG(c,...)\
	fprintf(stderr, c"\n", ##__VA_ARGS__)
#define MAX_CHAR 1000000
//#define max33(a,b,c) max(a, max(b,c))
//#define max33(a,b,c) ( (a>b)?( ( a>c)?a:c ):((b>c)?b:c) )
//#define max22(a,b) (((a)>(b))?(a):(b))
//#define min2(a,b) (((a)<(b))?(a):(b)) 

using namespace std;

void wo (FILE *, char *, char *, char *);
char checkNs (char *);
string reverse_complement ( const string & );
string reverse ( const string & );
string S (const char* fmt, ...);
int check_AT_GC(const string &, const double &);
/*************************************************/
inline int max22(int a, int b)
{
	return (a>b)?a:b;
}
/*************************************************/
inline int min2(int a, int b)
{
	return (b>a)?a:b;
}
/*************************************************/
inline int max33(int a, int b, int c)
{
	int z = a;
	if (z < b) z=b;
	if (z < c) z=c;
	return z;
}

inline char getDNAValue (char ch) {
	#define _ 0
	static char c[128] = {
		_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,// 0 15
		_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,// 16 31
		_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,// 32 47
		_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,// 48 63
		_,0,_,1,_,_,_,2,_,_,_,_,_,_,_,_,// 64 79
		_,_,_,_,3,_,_,_,_,_,_,_,_,_,_,_,// 80 95
		_,0,_,1,_,_,_,2,_,_,_,_,_,_,_,_,// 96 111
		_,_,_,_,3,_,_,_,_,_,_,_,_,_,_,_,// 112 127
	};
	#undef _
	return c[ch];
}

#endif
