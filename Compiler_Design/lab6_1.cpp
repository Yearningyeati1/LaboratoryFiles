#include <bits/stdc++.h>
using namespace std;


void cleaner(map<string, vector<string>> &gram, int n)
{
    vector<string> temp;
    string s;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {   cout<<"Enter Production:"<<'\n';
        getline(cin,s);
        temp.push_back(s);
    }

    
    for (int i = 0; i < n; i++)
    {
        string prod = "", rhs = "";
        vector<string> temp1;
        int state = 0; 

        for (int j = 0; j < temp[i].size(); j++)
        {
            char c = temp[i][j];
	    if(c==' ');

            else if (state == 0 && c != '-' && c != '>')
            {
                prod += c; 
            }
            else if (c == '>')
            {
                state = 1; 
            }
            else if (c == '|')
            {
                temp1.push_back(rhs); 
                rhs = "";            
            }
            else if (c == ';')
            {
                temp1.push_back(rhs); 
                break;
            }
            else if (state == 1)
            {
                rhs += c; 
            }
        }

        gram[prod] = temp1;
    }
}

/*
bool chkindirect(string start, string current, map<string, vector<string>> &gram, set<string> &visited)
{
    if (visited.count(current))
        return false;

    visited.insert(current); 

    for (string rhs : gram[current])
    {
        if (rhs[0] == start[0]) 
        {
            return true;
        }
        else if (rhs[0] >= 'A' && rhs[0] <= 'Z') 
        {
            if (chkindirect(start, string(1, rhs[0]), gram, visited))
            {
                return true;
            }
        }
    }

    return false;
}
*/

void rmdirectrecur(string non_terminal, map<string, vector<string>> &gram)
{
    vector<string> alpha; 
    vector<string> beta;  

    for (string rhs : gram[non_terminal])
    {
        if (rhs[0] == non_terminal[0]) 
        {
            alpha.push_back(rhs.substr(1)); 
        }
        else
        {
            beta.push_back(rhs); 
        }
    }

    if (!alpha.empty()) 
    {
        string new_non_terminal = non_terminal + "'"; 

        
        vector<string> new_prod;
        for (string b : beta)
        {
            new_prod.push_back(b + new_non_terminal); 
        }

        
        vector<string> new_nonter;
        for (string a : alpha)
        {
            new_nonter.push_back(a + new_non_terminal); 
        }
        new_nonter.push_back("ε"); 

        
        gram[non_terminal] = new_prod;
        gram[new_non_terminal] = new_nonter;
    }
}


void removeIndirectLeftRecursion(map<string, vector<string>> &gram)
{
    vector<string> non_terminals;
    for (auto &p : gram)
    {
        non_terminals.push_back(p.first); 
    }

    
    for (int i = 0; i < non_terminals.size(); i++)
    {
        string A = non_terminals[i];

        for (int j = 0; j < i; j++)
        {
            string B = non_terminals[j];

            vector<string> new_productions;
            for (string rhs : gram[A])
            {
                if (rhs[0] == B[0]) 
                {
                    for (string B_rhs : gram[B])
                    {
                        new_productions.push_back(B_rhs + rhs.substr(1)); 
                    }
                }
                else
                {
                    new_productions.push_back(rhs); 
                }
            }
            gram[A] = new_productions; 
        }

        
        rmdirectrecur(A, gram);
    }
}

int main()
{
    int n;
    cout << "Enter the number of productions: ";
    cin >> n;
    map<string, vector<string>> gram;
    cleaner(gram, n);

    
    removeIndirectLeftRecursion(gram);

    
    cout << "Grammar after removing left recursion:" << endl;
    for (auto i : gram)
    {
        cout << i.first << " -> ";
        for (int j = 0; j < i.second.size(); j++)
        {
            if (j > 0)
                cout << " | ";
            cout << i.second[j];
        }
        cout << ";" << endl;
    }

    return 0;
}
