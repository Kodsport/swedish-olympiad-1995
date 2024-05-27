#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

void elapse(vector<int>& books){
	int ns = books.size();
	vector<int> nbooks;
	for(int i = 0; i < books.size(); ++i){
		if(books[i] != 1)
			nbooks.push_back(books[i]-1);
	}
	nbooks.push_back(ns);
	books.swap(nbooks);
}

int main(){
	int n;
	cin >> n;
	vector<int> books(n);
	for(int i = 0; i < n; i++){
		cin >> books[i];
	}
	map<vector<int>, int> seen;
	seen[books] = 1;
	for(int i = 2;; ++i) {
		elapse(books);
		assert(books.size() <= 15);
		int t = seen[books];
		if(t != 0) {
			assert(i <= 100);
			cout << t << " " << i << endl;
			break;
		}
		seen[books] = i;
	}
}
