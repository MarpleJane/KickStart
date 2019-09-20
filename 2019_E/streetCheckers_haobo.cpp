#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int prime[10]={2,3,5,7,11,13,17,19,23,29},T;
int Quick_Power(int a,int b,int c){
    long long ans=1,res=a;
    while(b){
        if(b&1)
          ans=ans*res%c;
        res=res*res%c; 
        b>>=1;
    }
    return (int)ans;
}
bool Miller_Rabin(int x){
    int i,j,k;
    int s=0,t=x-1;
    if(x<=2)  return true;
    //if(x<2||!(x&1))  return false;
    while(!(t&1)){
        s++;
        t>>=1;
    }
    for(i=0;i<10&&prime[i]<x;++i){
        int a=prime[i];
        int b=Quick_Power(a,t,x);
        for(j=1;j<=s;++j){
            k=(long long )b*b%x;
            if(k==1&&b!=1&&b!=x-1)
              return false;
            b=k;
        }
        if(b!=1)  return false; 
    }
    return true; 
}
bool check(int x){
   int num2=0;
   while(!(x&1))
      x>>=1,num2++;
   if(num2==3&&x==1)return true;
   if(num2>=3)return false;
   if(num2==1)return true;
   bool flag=Miller_Rabin(x);
   if(flag)return true;
   return false;
}
int main(){
   scanf("%d",&T);
   for(int testcase=1;testcase<=T;testcase++){
      printf("Case #%d: ",testcase);
      int l,r;
      scanf("%d%d",&l,&r);
      int ans=0;
      for(int i=l;i<=r;i++)
         if(check(i))
            ans++;
      printf("%d\n",ans);
   }
   return 0;
} 
