#include <bits/stdc++.h>
using namespace std;


void cleaner(map<string, vector<string>> &gram, int n) {
 vector<string> temp;
 string s;
 cin.ignore(); 

 for (int i = 0; i < n; i++) {
 cout << "Enter Production:" << '\n';
 getline(cin, s);
 temp.push_back(s);
 }


 for (int i = 0; i < n; i++) {
 string prod = "", rhs = "";
 vector<string> temp1;
 int state = 0; 

 for (int j = 0; j < temp[i].size(); j++) {
 char c = temp[i][j];
 if (c == ' ');

 else if (state == 0 && c != '-' && c != '>') {
 prod += c; 
 } else if (c == '>') {
 state = 1; 
 } else if (c == '|') {
 temp1.push_back(rhs); 
 rhs = ""; 
 } else if (c == ';') {
 temp1.push_back(rhs); 
 break;
 } else if (state == 1) {
 rhs += c; 
 }
 }

 gram[prod] = temp1;
 }
}


set<string> findFirst(const string &str, const map<string, vector<string>> &gram, map<string, set<string>> &firstSets, set<string> &visited) {
 set<string> firstSet;
 if (str.empty()) return firstSet;


 if (islower(str[0])) {
 firstSet.insert(string(1, str[0]));
 return firstSet;
 }


 if (visited.find(str) != visited.end()) return firstSets[str];

 visited.insert(str);
 
 
 
 for (const string &production : gram.at(str)) {
 if (production.empty()) continue;

 
 
 if (production == "ε") {
 firstSet.insert("ε");
 continue;
 }

 bool isEpsilon = true;
 for (char symbol : production) {
 if (islower(symbol)) {
 firstSet.insert(string(1, symbol));
 isEpsilon = false;
 break;
 } else {

 set<string> first = findFirst(string(1, symbol), gram, firstSets, visited);
 firstSet.insert(first.begin(), first.end());

 
 
 if (first.find("ε") == first.end()) {
 isEpsilon = false;
 break;
 }
 }
 }

 if (isEpsilon) {
 firstSet.insert("ε");
 }
 }

 firstSets[str] = firstSet;
 return firstSet;
}

int main() {
 int n;
 cout << "Enter the number of productions: ";
 cin >> n;
 map<string, vector<string>> gram;
 cleaner(gram, n);

 map<string, set<string>> firstSets;
 for (const auto &entry : gram) {
 set<string> visited;
 set<string> firstSet = findFirst(entry.first, gram, firstSets, visited);
 cout << "First(" << entry.first << ") = { ";
 for (const auto &symbol : firstSet) {
 cout << symbol << " ";
 }
 cout << "}" << endl;
 }
 
 return 0;
}
