#include <iostream>
#include <string>
#include <map>
using namespace std;
 
int main() {
     // Initialize a map through
     map<string, string> wordMap;
     wordMap["key1"] = "1";
     wordMap["key2"] = "2";
     wordMap["key3"] = "3";

     // iterate throuth the map
     for (map<string, string>::iterator p = wordMap.begin( );
          p != wordMap.end( ); ++p ) {

          if(p->first == "key1"){     // find the key to delete
               wordMap.erase(p);
          }
     }
     for (auto element : wordMap)
          cout << element.first << " :: " << element.second << endl;
 
     return 0;
}