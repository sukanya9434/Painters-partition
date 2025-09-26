#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

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
 


int main(){
  vector <int> timeblock={40,30,10,20}; //lengths
   int m=4; //totalblocks
    int n=2;//totalpainters
    cout<<allocatedblocks(timeblock,m,n)<<endl;
 

return 0;

}
