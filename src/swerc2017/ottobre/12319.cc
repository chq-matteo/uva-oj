#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>
using namespace std;

struct node : vector<int>
{
    int dist;
};

void bfs(node*nodes, int N, int act)
{
    for(int i=1; i<=N; i++)
        nodes[i].dist = -1;
    nodes[act].dist = 0;
    queue<int> Q;
    Q.push(act);
    while(!Q.empty())
    {
        act = Q.front();
        Q.pop();
        for(int i=0; i<nodes[act].size(); i++)
            if(nodes[nodes[act][i]].dist == -1 || nodes[act].dist + 1 < nodes[nodes[act][i]].dist)
            {
                nodes[nodes[act][i]].dist = nodes[act].dist + 1;
                Q.push(nodes[act][i]);
            }    
    }
}

int main()
{
    int N;
    //cin>>N;
    while(cin>>N and N)
    {
        //cout<<N<<endl;
        node nodes[N+1];
        node dirnodes[N+1];
        set<int> dire[N+1];
        cin.ignore();
        for(int i=0; i<N; i++)
        {
            string s;
            getline(cin, s);
            //cout<<i<<" "<<s<<endl;
            istringstream iss (s);
            int first, c;
            iss>>first;
            while(iss>>c)
            {
                nodes[first].push_back(c);
                //nodes[c].push_back(first);
            }
        }
        //cout<<endl<<endl;
        for(int i=0; i<N; i++)
        {
            string s;
            getline(cin, s);
            //cout<<s<<endl;
            istringstream iss2 (s);
            int first, c;
            iss2>>first;
            while(iss2>>c)
            {
                dirnodes[first].push_back(c);    
                dire[first].insert(c);
            }
        }
      
        /*for(int i=1; i<=N; i++)
        {
           for(int j=0; j<nodes[i].size(); j++)
                if(dire[i].find(nodes[i][j]) == dire[i].end() && dire[nodes[i][j]].find(i) == dire[nodes[i][j]].end())
                {
                   dirnodes[i].push_back(nodes[i][j]);
                   dirnodes[nodes[i][j]].push_back(i); 
                } 
        }*/
        
        int A, B;
        //cin.ignore();
        cin>>A>>B;
        //cout<<A<<" "<<B;
        bool good = true;
    
        for(int i=1; i<=N; i++)
        {
            bfs(nodes, N, i);
            bfs(dirnodes, N, i);
            for(int j=1; j<=N; j++)
                if(nodes[j].dist * A + B < dirnodes[j].dist || (dirnodes[j].dist == -1 && nodes[j].dist != -1))
                    good = false;

        }

        if(good)
            cout<<"Yes\n";
        else 
            cout<<"No\n";
        //return 0;
        //cin>>N;
    }
    return 0;
}