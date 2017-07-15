#include <bits/stdc++.h>
using namespace std;
char a[100][100];
int counnt;
bool vicinity(char tof,int *i,int *j,int r,int s,bool visited[][100],bool*  a1){
	int t=*i,y=*j;
	r--; 
	if(*j<s-1 && a[*i][*j+1]==tof && visited[*i][*j+1]==false && !a1[t*s+y+1]){
		(*j)++; 
		return true;
	}
	if( *j>0 && a[*i][*j-1]==tof && visited[*i][*j-1]==false && !a1[t*s+y-1]){
		(*j)--;
		return true;
	}
	if(*i>0 && *j>0 && a[*i-1][*j-1]==tof && visited[*i-1][*j-1]==false && !a1[(t-1)*s+y-1]){
		(*i)--; (*j)--;
		return true;
	}
	if(*i>0 && a[*i-1][*j]==tof && visited[*i-1][*j]==false && !a1[(t-1)*s+y]){
		(*i)--;
		return true;
	}
	if(*i>0 && *j<s-1 && a[*i-1][*j+1]==tof && visited[*i-1][*j+1]==false && !a1[(t-1)*s+y+1]){
		(*i)--; (*j)++;
		return true;
	}
	if(*i<r && a[*i+1][*j] ==tof && visited[*i+1][*j]==false && !a1[(t+1)*s+y]){
		(*i)++;
		return true;
	}
	if(*i<r && *j>0 && a[*i+1][*j-1]==tof && visited[*i+1][*j-1]==false && !a1[(t+1)*s+y-1]){
		(*i)++; (*j)--;
		return true;
	}
	if(*i<r && *j<s-1 && a[*i+1][*j+1]==tof && visited[*i+1][*j+1]==false && !a1[(t+1)*s+y+1]){
		(*i)++; (*j)++;
		return true;
	}
	return false;	
}


bool back_track(char ss,int* i,int *j, int r,int s,int* level,bool visited[][100]){
	//cout<<*i<<" "<<*j<<endl;
	counnt++;
	//if(counnt==20) exit(1);
	char tof;
	(*level)++;
	visited[*i][*j]=true;
	int cpi=*i,cpj=*j;
	if(ss=='A') tof='L';
	if(ss=='L' && *level==2) tof='L';
	if(ss=='L' && *level==3) tof='I';
	if(ss=='I') tof='Z';
	if(ss=='Z' && *level==5) tof='Z';
	if(ss=='Z' && *level==6) tof='W';
	if(ss=='W') tof='E';
	if(ss=='E') tof='L';
	if(ss=='L' && *level==9) tof='L';
	bool a1[10000]={false};
 	while(vicinity(tof,i,j,r,s,visited,a1)){
		if(*level==9) return true;
		//cout<<*i<<" ij "<<*j<<endl;
		 a1[(*i)*s+(*j)]=true;
		//cout<<endl;
		bool vg=back_track(tof,i,j,r,s,level,visited);
		if(vg==true) return true;
		else {

			visited[*i][*j]=false;
			*i=cpi;
			*j=cpj;	
		}	 
	}
	*i=cpi; *j=cpj;
	(*level)--;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int r,s;
		cin>>r>>s;
		for(int i=0;i<r;i++){
			for(int j=0;j<s;j++){
				cin>>a[i][j];
			}
		}
		bool flag=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<s;j++){
				if(a[i][j]=='A'){
					int level=0;
					bool visited[100][100]={0};
					bool val=back_track('A',&i,&j,r,s,&level,visited);
					if(val==true) {
					cout<<"YES\n";
					flag=1;
					i=r+1;
					break;
					}
				}
			}
		}
		if(flag==0) cout<<"NO\n";
	}
}
