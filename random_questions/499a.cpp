#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, x;
  cin >> n >> x;
  queue<pair<int, int> > best;
  for(int i=0;i<n;i++){
    int first, second;
    cin >> first >> second;
    best.push(make_pair(first, second));
  }
  //cout << best.size()<<"\n";
  int m_watched = 0, curr = 1;
  while(best.size() != 0){
    if((curr + x) <= best.front().first){
      curr = curr + x;
      //cout<< curr<<"\n";
    }else if ( (curr + x) > best.front().first){
      //cout<< curr<<"\t"<<m_watched<<"\t";
      m_watched += (best.front().first - curr ) + (best.front().second - best.front().first) + 1;
      curr = best.front().second + 1;
      best.pop();
      //cout<< curr<<"\t"<<m_watched<<"\n";
    }
  }
  //cout<<"\n";
  cout<< m_watched;
  return 0;
}
