#include<bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define pb(x) push_back(x)
#define pf(x) printf("%d\n",x)
#define INF 1000000000
#define lim 1010

/*
Sorting : merge sort
test case : 
10
5 4 6 2 1 7 8 9 11 17
*/

int arr[lim];
int n,i,j,k;

void printarr() {
	for(i=0;i<n;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void merge(int s,int mid,int e) {
	int tmp[lim];
	memset(tmp,0,sizeof(tmp));
	int ptr1,ptr2,ptr;
	ptr1=s;
	ptr2=mid+1;
	ptr=0;
	while(ptr1<=mid&&ptr2<=e) {
		if(arr[ptr1]<arr[ptr2]) {
			tmp[ptr]=arr[ptr1];
			ptr1++;
		}
		else {
			tmp[ptr]=arr[ptr2];
			ptr2++;
		}
		ptr++;
	}
	while(ptr1<=mid) {
		tmp[ptr]=arr[ptr1];
		ptr++;
		ptr1++;
	}
	while(ptr2<=e) {
		tmp[ptr]=arr[ptr2];
		ptr++;
		ptr2++;
	}
	ptr=s;
	for(i=0;i<e-s+1;i++) {
		arr[i+s]=tmp[i];
	}
}

void mergesort(int s,int e) {
	if(s<e) {
		int mid=s+((e-s)/2);
		mergesort(s,mid);
		mergesort(mid+1,e);
		merge(s,mid,e);
	}
}

int main() {
	sd(n);
	for(i=0;i<n;i++) {
		sd(arr[i]);
	}
	mergesort(0,n-1);
	printarr();
	return 0;
}