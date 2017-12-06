#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#define magic 42
using namespace std;
bool ord(int a, int b) {
  return b > a;
}
int gcd(int a, int b)
{
  if(b == 0) return a;
  return gcd(b, a%b);
}

vector<int> good[102];
int sol[102];
int tmp[102];
int migliore;
int mp = 14;
double avg[102];
vector<int> primes = {1,2,3,5,7,11,13,17,19,23,29,31,37,4,8,16,32,9,27,25};
void solve(int ind, int*arr, int N, int cost)
{
/*  if(tmp[0] == 1 and tmp[1] == 2 and tmp[2] == 3)
  {
    cout<<cost<<" "<<migliore<<"\n";
  }*/
  if (migliore == 0) return;
  if(cost > migliore)
    return;
  if(ind == N)
  {
    if(cost < migliore)
    {
      migliore = cost;
      for(int i=0; i<N; i++)
        sol[i] = tmp[i];
    }
    return;
  }

  if (mp > 0 and ind <= 14) {
    vector<int> real_good = good[ind];
    if (ind == 0 and N > 14) {
      real_good = primes;
    }
    for(int i:real_good)
    {
      if (i > 2 * arr[ind]) break;
      int c = abs(arr[ind] - i);
      tmp[ind] = i;
      good[ind+1].clear();
      for(auto &a : good[ind])
        if(gcd(i, a) == 1) {
          good[ind+1].push_back(a);
        }
      int mtemp = migliore;
      if (i > 1) mp--;
      solve(ind+1, arr, N, cost+c);
      if (i > 1) mp++;
    }
  }
  else {
    int i = 1;
    int c = abs(arr[ind] - i);
    tmp[ind] = i;
    good[ind+1].clear();
    good[ind+1].push_back(1);
    if (i > 1) mp--;
    solve(ind+1, arr, N, cost+c);
    if (i > 1) mp++;
  }
}

int main()
{
  int N;
  int t=1;
  cin>>N;

  for(int i=1; i<magic; i++) {
    if (i == 2*3*5) continue;
    good[0].push_back(i);
  }

  while(N != 0)
  {
    int arr[N];
    for(int i=0; i<N; i++)
      cin>>arr[i];

    migliore = 199999999;
    sort(arr, arr+N, ord);
    for (int i = mp+1; i < N; i++) {
      arr[i] = 1;
    }
    solve(0, arr, N, 0);
    cout<<"Case #"<<t<<": ";
    for(int i=0; i<N; i++)
      cout<<sol[i]<<" ";
    cout<<"\n";
    cin>>N;
    t++;
  }
  return 0;
}
