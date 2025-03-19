// C++ implementation to
//print the characters and
// frequencies in order
// of its occurrence
#include <bits/stdc++.h>
using namespace std;

void prCharWithFreq(string s)
{
// Store all characters and
// their frequencies in dictionary
unordered_map<char, int> d;

for(char i : s)
{
	d[i]++;
}

// Print characters and their
// frequencies in same order
// of their appearance
for(char i : s)
{
	// Print only if this
	// character is not printed
	// before
	if(d[i] != 0)
	{
	cout << i << d[i] << " ";
	d[i] = 0;
	}
}
}

// Driver Code
int main()
{
string s="geeksforgeeks";
prCharWithFreq(s);
}

// This code is contributed by rutvik_56
