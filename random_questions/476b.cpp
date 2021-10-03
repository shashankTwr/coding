#include <bits/stdc++.h>
using namespace std;
int  combination(int n, int r){
  if(r == 0 || r ==n) return 1;
  return combination(n-1, r) + combination(n-1, r-1);
}
int main(){
  string s1,s2;
  cin >> s1>> s2;
  vector<int> cs1(2,0);
  for(int i=0;i<s1.length();i++){
    if(s1[i] == '+'){
      cs1[0]++;
    }else{
      cs1[1]++;
    }
  }
  vector<int> cs2(3,0);
  for(int i=0;i<s2.length();i++){
    if(s2[i] == '+'){
      cs2[0]++;
    }else if (s2[i] == '-'){
      cs2[1]++;
    }else{
      cs2[2]++;
    }
  }
  cout<< std::setprecision(12);
  int sum1 = cs1[0] -cs1[1];
  int sum2 = cs2[0] - cs2[1];
  int def = sum1 -sum2;
  double ans = 0;
  double n_ways = pow(2.0,(double)cs2[2]);
  //cout << n_ways;
  if(abs(def) > cs2[2]){
    cout<< std::setprecision(12);
    cout << ans;
  }else{
    int moves = abs(def) + (cs2[2] - abs(def))/2;
    //cerr << moves<<"\t"<<cs2[2]<<"\n";
    double n_right_way = (double) combination(cs2[2],moves);
    //cerr<<n_right_way<<"\t"<<n_ways<<"\n";
    cout<< std::setprecision(12);
    cout << n_right_way / n_ways;
  }
  return 0;
}
