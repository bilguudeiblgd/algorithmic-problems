#include<iostream>
#include<string>
using namespace std;

int main () {
   string str;
   cin >> str;
   size_t len = str.size();
   char * pal = (char *) malloc(len+1);
   
   int table[26];
   for(size_t i = 0 ; i < 26; i++) {
    table[i] = 0;
   }
   for(size_t i = 0 ; i < len ;i++) {
     table[str[i]-65]++;
   }

    if(len % 2 == 0) {
        for(int i = 0; i < 26; i++) {
            if(table[i] == 1) {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    }
    else {
        
    }
}