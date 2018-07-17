#include<bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define pb(x) push_back(x)
#define pd(x) printf("%d\n",x)
#define INF 1000000000
#define lim 1010

int arr[lim];
int n,len;

void printArr() {
	for(int i=0;i<n;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void maxHeapify(int s,int l) {
	int largest=s;
	int left=(2*s)+1;
	int right=(2*s)+2;
	if(left<l&&arr[left]>arr[s]) {
		largest=left;
	}
	if(right<l&&arr[right]>arr[largest]) {
		largest=right;
	}
	if(largest!=s) {
		int tmp=arr[s];
		arr[s]=arr[largest];
		arr[largest]=tmp;
		maxHeapify(largest,l);
	}
}

void buildMaxHeap() {
	for(int i=(n/2)-1;i>=0;i--) {
		maxHeapify(i,n);
	}
}

void heapsort() {
	buildMaxHeap();
	for(int i=n-1;i>0;i--) {
		int tmp=arr[i];
		arr[i]=arr[0];
		arr[0]=tmp;
		len--;
		maxHeapify(0,len);
	}
}

int main() {
	sd(n);
	len=n;
	for(int i=0;i<n;i++) {
		sd(arr[i]);
	}
	heapsort();
	printArr();
	return 0;
}