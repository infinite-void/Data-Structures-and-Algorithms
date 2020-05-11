
#include<iostream>
#include<algorithm>

using namespace std;
long long mat[100][100];
int minn(int a[100],int n,bool vis[100]) {
    int i=0,p=32767;
    for(int j=0;j<n;j++) {
        if(a[j]<p && vis[j]==false) {
            p=a[j];
            i=j;
        }
    }
    return i;
}
void djikstra(int n,int src) {
    int dist[n];
    bool vis[n];
    for(int i=0;i<n;i++)  {
        dist[i]=32767;
        vis[i]=false;
    }
    dist[src]=0;
    
    for(int i=0;i<n-1;i++) {
        int sh = minn(dist,n,vis);
        vis[sh]= true;
        for(int j=0;j<n;j++) {
         
            if(!vis[j] && mat[sh][j]!= 0 && dist[j]>mat[sh][j]+dist[sh]) {
                dist[j]=mat[sh][j]+dist[sh];
            }
        }
    }
    for(int i=0;i<n;i++) {
	if(dist[i]==32767) cout<<0<<" ";
	else     cout<<dist[i]<<" ";
    }
}
int main() {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>mat[i][j];
            }
        }
        
        for(int i=0;i<n;i++) {
            
            djikstra(n,i);
            cout<<endl;
        }
    
    return 0;
}
