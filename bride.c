#include <stdio.h>
#include <stdlib.h>
struct charac{
	int x,y,c;
};

struct Max{
	int x,y;
};

int count=0;
int qcount=0;
int main(){
	int n,m,i,j,k,l;
	scanf("%d %d",&n,&m);
	int arr[n][m];
	struct charac *data=(struct charac *)malloc((n*m)*sizeof(struct charac));
	struct Max *max=(struct Max *)malloc((n*m)*sizeof(struct Max));
	for(i=0;i<n;i++)			//input
	for(j=0;j<m;j++)
	scanf("%d",&arr[i][j]);
	int maxq=0;
	for(i=0;i<n;i++){			//finding qualities
		for(j=0;j<m;j++){
			if(arr[i][j]!=1)continue;
			else{
				if (i == 0 && j == 0)continue;
				else{
					data[count].x=i; data[count].y=j;data[count].c=0;
					if(i==0){
						if(j==m-1){
						for(k=i;k<i+2;k++){
							for(l=j-1;l<j+1;l++){
								if(arr[k][l]==1)data[count].c++;
							}
						}							
						}
						else{
							for(k=i;k<i+2;k++){
							for(l=j-1;l<j+2;l++){
								if(arr[k][l]==1)data[count].c++;
							}
						};
						}
						count++;
					}
					else if(i==n-1){
						if(j==0){
							for(k=i-1;k<i+1;k++){
							for(l=j;l<j+2;l++){
								if(arr[k][l]==1)data[count].c++;
							}
						};
						}
						else if(j==m-1){
							for(k=i-1;k<i+1;k++){
							for(l=j-1;l<j+1;l++){
								if(arr[k][l]==1)data[count].c++;
							}
						};
						}
						else{
							for(k=i-1;k<i+1;k++){
							for(l=j-1;l<j+2;l++){
								if(arr[k][l]==1)data[count].c++;
							}
						};
						}
						count++;
					}
					else if(j==0){
						for(k=i-1;k<i+2;k++){
							for(l=j;l<j+2;l++){
								if(arr[k][l]==1)data[count].c++;
							}
						};
						count++;
					}
					else if(j==m-1){
						for(k=i-1;k<i+2;k++){
							for(l=j-1;l<j+1;j++){
								if(arr[k][l]==1)data[count].c++;
							}
						};
						count++;
					}
					else{
						for(k=i-1;k<i+2;k++){
							for(l=j-1;l<j+2;l++){
								if(arr[k][l]==1)data[count].c++;
							}
						};
						count++;
					}
				}
			}
		}
	}
	for(i=0;i<(n*m -1);i++){		//finding max quality
		if(data[i].c>maxq)maxq=data[i].c;
	}	
	for(i=0;i<(n*m -1);i++){		//finding coordinates with max quality
		if(data[i].c==maxq){
			max[qcount].x=data[i].x;
			max[qcount].y=data[i].y;
			qcount++;
		}
	}
	if(qcount==1)printf("%d:%d:%d",max[0].x,max[0].y,maxq);			//output
	else{
		int steps=n+m-2;
		for(i=0;i<qcount;i++){
			if((max[i].x+max[i].y-2)<steps){
				steps=(max[i].x+max[i].y-2);
				max[0].x=max[i].x;
				max[0].y=max[i].y;
			}
		}
		printf("%d:%d:%d",max[0].x+1,max[0].y+1,maxq-1);	
	}
	return 0;
}
