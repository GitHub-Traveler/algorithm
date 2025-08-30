#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> mem;
    bool isScramble(string s1, string s2) {       
        int n = s1.length();
        if (s2.length() != n)
            return false;
        if (s1 == s2)
            return true;
        if (n == 1)
            return false;

        string key = s1 + '*' + s2;
        if (mem.find(key) != mem.end())
            return mem[key];
        
        for (int i = 1; i < n; i++) {
            //ex of without swap: gr|eat and rg|eat
            bool withoutswap = (
                //left part of first and second string
                isScramble(s1.substr(0,i),s2.substr(0,i)) 
                
                &&
                
                //right part of first and second string;
                isScramble(s1.substr(i),s2.substr(i))
                );
            
            
            
            //if without swap give us right answer then we do not need 
            //to call the recursion withswap
            if(withoutswap)
                return true;
            
            //ex of withswap: gr|eat  rge|at
			//here we compare "gr" with "at" and "eat" with "rge"
            bool withswap = (
                //left part of first and right part of second 
                isScramble(s1.substr(0,i),s2.substr(n-i)) 
                
                &&
                
                //right part of first and left part of second
                isScramble(s1.substr(i),s2.substr(0,n-i)) 
                );
            
            
            
            //if withswap give us right answer then we return true
            //otherwise the for loop do it work
            if(withswap)
                return true;
            //we are not returning false in else case 
            //because we want to check further cases with the for loop
        }
        
        
        return mem[key] = false;
    }

};