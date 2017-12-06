#include <iostream>
using namespace std;
int main() {

    int c, r, N;
    cin>>r>>c>>N;
    while(r != 0 || c != 0)
    {
        bool ri[1002], co[1002];
        for(int i=0; i<=1001; i++)
            ri[i] = co[i] = false;
        
        int nr = 0, nc = 0;
        for(int i=0; i<N; i++)
        {
            int a, b;
            cin>>a>>b;
            if(!ri[a]) nr++;
            if(!co[b]) nc++;
            ri[a] = true;
            co[b] = true;
        }   
        
        if(nr < nc)
        {
            cout<<nr;
            for(int i=0; i<=1001; i++)
                if(ri[i])
                    cout<<" r"<<i;
            cout<<"\n";
        }
        else
        {
            cout<<nc;
            for(int i=0; i<=1001; i++)
                if(co[i])
                    cout<<" c"<<i;
            cout<<"\n";
        }
        
        cin>>r>>c>>N;
    }
}