#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const char* args[] = {" ", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> v(args,args+10); 
        vector<string> vs(1,"");
        vector<string> tmp;
        if(digits.size()<1) return tmp;
        for (size_t i=0; i<digits.length(); i++){
            const size_t n=vs.size();
            const size_t m=v[digits[i]-'0'].size();
            vs.resize(n*m);
            for(size_t j=1; j<m; j++)
                for (size_t k=0; k<n; k++)
                    vs[n*j+k].append(vs[k]);

            for(size_t j=0; j<m; j++)
                for(size_t k=n*j; k<n*(j+1); k++)
                    vs[k].push_back(v[digits[i]-'0'][j]);
        }
        return vs;
    }
};

int main(){

  string x;
  cout << "Input a string: \n";
  cin >> x;
  cerr << " string is = " << x << endl;

  Solution test;
  vector<string> vs;
  vs=test.letterCombinations(x);
  for(int i=0; i<vs.size(); i++)
      cout << vs[i] << endl;

}


