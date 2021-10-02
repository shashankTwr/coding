#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> in_str;
  while(true){
    int ins;
    cin >> ins;
    if(ins == 0){
      break;
    }
    vector<string> in(ins);
    for(int i=0;i<ins;i++){
      //cout<<i<<"\n";
      cin >> in[i];
    }
    /*
    for(int i = 0 ; i<ins ; i++){
      cout<< "insignificant characters in this test case are"<< in[i]<<"\n";
    }*/
    string s;
    while(true){
      getline(cin,s);
      //cout << "string 1 is "<< s<<"\n";
      if(s.compare("LAST CASE") == 0){
        break;
      }
      for(int i = 0 ; i < ins; i++){
        s = regex_replace(s,regex(in[i]+" "),"");
      }
      if(s.compare(""))
        in_str.push_back(s);
    }
  }


  string sample = "",text= "";
  /*
  for(int i=0 ; i<in_str.size();i++){
     cout<<in_str[i].length()<<"\n";
  }
  */
  //cout<<in_str.size();
  for(int i=0 ; i<in_str.size();i++){
     sample = "",text= "";
    for(int j = 0;j<in_str[i].length();j++){
      if(in_str[i][j] == ' '){
        sample = in_str[i].substr(0,j);
        text_complete = in_str[i].substr(j,in_str[i].length());
        break;
      }
    }
    //cout << sample << "\t" << text << "\n";
    vector<vector<int> > a(sample.length()+1,vector<int>(text.length()+1,0));
    transform(sample.begin(),sample.end(),sample.begin(),::tolower);
    a[0][0]=1;
    for(int k = 0; k < text.length(); k++){
      a[0][k]=1;
    }
    for(int s = 0; s < sample.length(); s++){
      for(int k = 0; k < text.length(); k++){
        if(sample[s] == text[k]){
          if(a[s][k] >= 1)
            a[s+1][k+1] = a[s+1][k] + 1;
        }else{
            a[s+1][k+1] = a[s+1][k];
        }
        cout<<a[s+1][k+1]<<"\t";
      }
      cout<<"\n";
    }
    int num = a[sample.length()][text.length()];
    transform(sample.begin(),sample.end(),sample.begin(),::toupper);
    if(num >= 1){
      cout << sample << " can be formed in " << num <<" ways"<<"\n";
    }else{
      cout << sample << " is not a valid abbreviation\n";
    }
  }
  return 0;
}


/*
2
and
of
ACM academy of computer makers
RADAR radio detection and ranging
LAST CASE
2
a
an
APPLY an apple a day
LAST CASE
0
*/
