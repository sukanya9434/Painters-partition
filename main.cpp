#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
// Q:maxblocks , each of some length(in meter) for each painter to paint to get it done in min time
//maxblocks for each painter to paint
bool validsinglepainterblocks(vector <int> &timeblock,int m,int n,int maxallowedtime){ //m=totalblocks,n=totalpainters
int time=0; //1 block/minute
int painters=1;
    for (int i=0;i<m;i++){
  
    if (timeblock[i]+time<=maxallowedtime){
    time+=timeblock[i];

    }
    else{
      painters++;
    time=timeblock[i];
    }
  
} 
return painters<=n;
}

//searching minimum time
int allocatedblocks(vector <int> &timeblock,int m,int n){
    int maxval=INT_MIN;
    int totalsum=0;
  
    for(int i=0;i<m;i++) {
      totalsum+=timeblock[i];
      maxval=max(timeblock[i],maxval);
    }
       int st=maxval;
       int end=totalsum;
        int ans=-1;
      while(st<=end){
      int mid= st+(end-st)/2;
              

if (validsinglepainterblocks(timeblock,m,n,mid)){ //isValid
       ans=mid;
       end=mid-1;
}
else { //isInvalid
    st=mid+1;
}
}
return ans;
}
*/

bool isPossible(vector <int> &cowstalls,int s,int c,int minAllowedDifference)
{int cows=1,stallno=cowstalls[0];
  for(int i=1;i<s;i++){
  if (cowstalls[i]-stallno >=minAllowedDifference){
 cows++;
 stallno=cowstalls[i];
  } 
  if (cows==c){//as the condition is inside for loop ,as soon as the cows becomes =c it will return true it won't let it cross the value and be greater than C,in which case the search pointer moves to left again
    return true;//alternative code: to be written outside for loop:if (cows<c){return false;}
 } 
  }//else:
  return false;

}
int getDistance(vector <int> &cowstalls,int s,int c)
{
  sort(cowstalls.begin(),cowstalls.end());
  int st=1,end=cowstalls[s-1]-cowstalls[0];//making minimumdifference scale for binary search
  int ans=-1;
  while (st<=end){
  int mid=st+(end-st)/2;
  if (isPossible(cowstalls,s,c,mid)){//right
    ans=mid;
    st=mid+1;
  }
  else{//left
    end=mid-1;
  }
}
return ans;
}
int main(){
  vector <int> timeblock={40,30,10,20}; //lengths
   int m=4; //totalblocks
    int n=2;//totalpainters
   // cout<<allocatedblocks(timeblock,m,n)<<endl;
   vector <int> cowstalls={1,2,8,4,9};
   int s=5;
   int c=3;
   cout<<getDistance(cowstalls,s,c)<<endl;
return 0;
}