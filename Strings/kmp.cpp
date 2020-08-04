/*
 Author: Keshav
 Algorithms (with slight changes) from "Fast pattern matching in strings"
 https://pdfs.semanticscholar.org/4479/9559a1067e06b5a6bf052f8f10637707928f.pdf
 pg 4 and 6
*/

#include <iostream>
#include <vector>

void kmp_precompute(std::string& pattern, std::vector<int>& T)
{	
	int m = pattern.length();
	int i, j;
	
	T[0] = -1;
	i = -1;
	j = 0;
	
	while (j < (m - 1)) {
		while ((i >= 0) && (pattern[i] != pattern[j]))
			i = T[i];
		i++; j++;
		
		if (pattern[i] == pattern[j])
			T[j] = T[i];
		else
			T[j] = i;
	}
}

// Note: In this version, matches can overlap
void kmp_match(std::string& text, std::string& pattern, std::vector<int>& T)
{
	int m = pattern.length();
	int n = text.length();
	
	int i,j;
	
	i = j = 0;
	
	while ((i < m) && (j < n)) {
		while ((i >= 0) && (text[j] != pattern[i]))
			i = T[i];
		i++; j++;
		
		// Match found
		if (i == m) {
			std::cout << "Match at " << j - i << std::endl;
			/*
			To disallow overlapped matches, just don't set j 
			There is an optimization for i, but I need to read
			Cormen to understand it first 
			*/
			j = j - i + 1;
			i = 0;
		}
	}
	
}

int main(int argc, char** argv)
{
	if (argc != 3) {
		std::cerr << "KMP pattern matching" << std::endl << "Usage: " 
		<< argv[0] << " text" << " pattern" << std::endl << 
		"If the strings contain spaces, place them in single quotes" 
		<< std::endl;
		     
		return -1;
	}

	std::string text(argv[1]);
	std::string pattern(argv[2]);
		
	std::vector<int> T;
	T.reserve(pattern.length());
	
	kmp_precompute(pattern, T);
	kmp_match(text, pattern, T);
	
	return 0;
}