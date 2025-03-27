#include <iostream>
#include <climits>

using namespace std;

int main(){
  int n_int = INT_MAX; 
  short n_short = SHRT_MAX; 
  long n_long = LONG_MAX;
  long long n_llong=LLONG_MAX;

  cout << "int는" << sizeof n_int <<"바이트이다." << endl;
  cout <<"이 바이트의 최댓값은" <<n_int <<"이다."<<endl;

  cout << "short은" << sizeof n_short <<"바이트이다." << endl;
  cout <<"이 바이트의 최댓값은" <<n_short <<"이다."<<endl;

  
  cout << "long은" << sizeof n_long <<"바이트이다." <<endl;
  cout <<"이 바이트의 최댓값ㄲ은" <<n_long <<"이다."<<endl;

  
  cout << "long long은ㄲ" << sizeof n_llong <<"바이트이다." <<endl;
  cout <<"이 바이트의 최댓값은" <<n_llong <<"이다."<<endl;


  unsigned int a;
  unsigned short b =-1; //unsigned 하면 음수부를 양수로 올림
  cout << b <<endl; //65535
}