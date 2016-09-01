#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "genome.h"

using namespace std;

genome::genome(string filename)
{
	fin.open(filename.c_str());
	reference.reserve(300000000);
	reference_name = "";
	char ch;
	fin.get(ch);
}

genome::~genome()
{
}

void genome::load_next(void)
{	
	reference.clear();
	if (fin.eof())
		return;
	
	getline(fin, reference_name);
	string tmp;
	char ch;

	fin.get(ch);
	
	while (ch != '>' && !fin.eof())
	{
		reference+=ch;
		getline(fin, tmp);
		reference+=tmp;
		fin.get(ch);
	}
	transform(reference.begin(), reference.end(), reference.begin(), ::toupper);
}

string genome::extract(const string &rname, int start, int end)
{
	if (rname != reference_name) {
		fprintf(stderr, "%s\n",  reference_name.c_str());
		load_next();
		
	}
	start = max(start, 1);
	end = max(end, 1);
	end = min(end, (int)reference.size());
	return reference.substr(start-1, end-start+1);
}

