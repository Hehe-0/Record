#include <bits/stdc++.h>
using namespace std;
int n;
double a[15][15], ans[15], b[15], c[15][15];
void work() {
	for(int i = 1;i <= n;i++) {
		int maxx = i;
		for(int j = i + 1;j <= n;j++) {
			if(a[maxx][i] < a[j][i])
				maxx = j;
		}
		swap(a[maxx], a[i]);
		swap(b[maxx], b[i]);
		for(int j = 1;j <= n;j++) {
			if(j == i)
				continue;
/*
			double _ = a[i][i] / a[j][i];
			for(int k = i;k <= n;k++) 
				a[j][k] = a[j][k] * _ - a[i][k];
			b[j] = b[j] * _ - b[i];
		-*/
			double _ = a[j][i] / a[i][i];
			for(int k = i;k <= n;k++) 
				a[j][k] -= a[i][k] * _;
			b[j] -= b[i] * _;
		}
	}
	for(int i = 1;i <= n;i++) {
		cout<<b[i]<<'b'<<endl;
		cout<<a[i][1]<<"   "<<a[i][2]<<'a'<<endl;
		ans[i] = b[i] / a[i][i];
	}
}
int main() {
	cin >> n;
	for(int i = 1;i <= n + 1;i++) {
		for(int j = 1;j <= n;j++) {
			cin >> c[i][j]; 
		}
		if(i == 1) 
			continue;
		for(int j = 1;j <= n;j++) {
			a[i-1][j] = (c[i-1][j] - c[i][j]) * 2;
			b[i-1] += (c[i-1][j] * c[i-1][j] - c[i][j] * c[i][j]);
		} 
	} 
	work();
	for(int i = 1;i <= n;i++) {
		printf("%.3lf ", ans[i]);
	}
	return 0;
} 
