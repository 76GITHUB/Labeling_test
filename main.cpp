#include <iostream>
#include <time.h>
#include <vector>
using namespace std;



class A {
public:
	int a, b, c;
	A(int a_, int b_, int c_) :a(a_), b(b_), c(c_) {};
};

void rsort(int* arr) {
	for(int i=0; i<9; i++)
		for (int j = 0; j < 9 - (i + 1); j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
}


vector<A>& vsort(int *a, vector<A> &v) {
	int k = 1;
	for(int i=0; i<v.size(); i++)
		for (int j = 0; j < v.size() - (i + 1); j++) {
			if (v[j].a > v[j + 1].a)
				swap(v[j], v[j + 1]);
		}
	for (vector<A>::iterator iter = v.begin(); iter != v.end(); iter++) {
		if ((iter + 1) == v.end()) {
			iter->a = k;
			continue;
		}
		if (iter->a == (iter+1)->a) {
			iter->a = k;
		}
		else {
			iter->a = k++;
			++*a;
		}
	}

	return v;
}

void change(int (*data)[10], vector<A> &f) {
	for (vector<A>::iterator iter = f.begin(); iter != f.end(); iter++) {
		if (data[iter->b - 1][iter->c - 1] == 0 || data[iter->b - 1][iter->c - 1] > iter->a) { data[iter->b - 1][iter->c - 1] = iter->a; }
		if (data[iter->b - 1][iter->c] == 0 || data[iter->b - 1][iter->c] > iter->a) { data[iter->b - 1][iter->c] = iter->a; }
		if (data[iter->b - 1][iter->c + 1] == 0 || data[iter->b - 1][iter->c + 1] > iter->a) { data[iter->b - 1][iter->c + 1] = iter->a; }

		if (data[iter->b][iter->c - 1] == 0 || data[iter->b][iter->c - 1] > iter->a) { data[iter->b][iter->c - 1] = iter->a; }
		if (data[iter->b][iter->c] == 0 || data[iter->b][iter->c] > iter->a) { data[iter->b][iter->c] = iter->a; }
		if (data[iter->b][iter->c + 1] == 0 || data[iter->b][iter->c + 1] > iter->a) { data[iter->b][iter->c + 1] = iter->a; }

		if (data[iter->b + 1][iter->c - 1] == 0 || data[iter->b + 1][iter->c - 1] > iter->a) { data[iter->b + 1][iter->c - 1] = iter->a; }
		if (data[iter->b + 1][iter->c] == 0 || data[iter->b + 1][iter->c] > iter->a) { data[iter->b + 1][iter->c] = iter->a; }
		if (data[iter->b + 1][iter->c + 1] == 0 || data[iter->b + 1][iter->c + 1] > iter->a) { data[iter->b + 1][iter->c + 1] = iter->a; }
	}
}

void print(int (*arr)[10]){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	int num=1;
	srand((unsigned int)time(0));
	int data[10][10] = {};
	int read[9] = {};
	vector<A> v;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			data[i][j] = 0;


	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++)
			data[i][j] = (rand() % 100);
	cout << "===========================맨처음 데이터======================" << endl;
	print(data);

	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++) {
			read[0] = data[i - 1][j - 1];
			read[1] = data[i - 1][j];
			read[2] = data[i - 1][j + 1];

			read[3] = data[i][j - 1];
			read[4] = data[i][j];
			read[5] = data[i][j + 1];

			read[6] = data[i + 1][j - 1];
			read[7] = data[i + 1][j];
			read[8] = data[i + 1][j + 1];

			rsort(read);
			if (data[i][j] == read[0])
				v.push_back(A(read[0], j, i));

		}
	cout << "지역의 최소점:(값, 행, 렬)" << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i].a << " " << v[i].b << " " << v[i].c << endl;
	cout << endl;

	v = vsort(&num, v);
	int arr[10][10] = { {0, }, };
	for (int i = 0; i < v.size(); i++)
		cout << v[i].a << " " << v[i].b << " " << v[i].c << endl;
	cout << endl;

	//cout <<num<< endl;

	change(arr, v);

	print(arr);

	cout << endl;

	vector<A> v2;

	bool check = true;
	int star;

	while (check) {
		star = 0;
		for (int k = 1; k <= num; k++) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (arr[i][j] == k)
						v2.push_back(A(k, i, j));
				}
			}
		}


		for (int i = 0; i < v2.size(); i++) {
			if (( v2[i].b >=1 && v2[i].b <= 8 ) & (v2[i].c >= 1 && v2[i].c <= 8)) {
				if (arr[v2[i].b - 1][v2[i].c - 1] == 0)arr[v2[i].b - 1][v2[i].c - 1] = v2[i].a;
				if (arr[v2[i].b - 1][v2[i].c] == 0)arr[v2[i].b - 1][v2[i].c] = v2[i].a;
				if (arr[v2[i].b - 1][v2[i].c + 1] == 0)arr[v2[i].b - 1][v2[i].c + 1] = v2[i].a;

				if (arr[v2[i].b][v2[i].c - 1] == 0)arr[v2[i].b][v2[i].c - 1] = v2[i].a;
				if (arr[v2[i].b][v2[i].c] == 0)arr[v2[i].b][v2[i].c] = v2[i].a;
				if (arr[v2[i].b][v2[i].c + 1] == 0)arr[v2[i].b][v2[i].c + 1] = v2[i].a;

				if (arr[v2[i].b + 1][v2[i].c - 1] == 0)arr[v2[i].b + 1][v2[i].c - 1] = v2[i].a;
				if (arr[v2[i].b + 1][v2[i].c] == 0)arr[v2[i].b + 1][v2[i].c] = v2[i].a;
				if (arr[v2[i].b + 1][v2[i].c + 1] == 0)arr[v2[i].b + 1][v2[i].c + 1] = v2[i].a;
			}
		}

		v2.clear();
		//cout << "v2size=" << v2.size();
		cout << endl;
		print(arr);
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (arr[i][j] == 0) { star++; }
			}
		}

		cout << "0의 갯수:" << star << endl;

		if (star == 0)check = false;
		else check = true;
	}
	cout << "레이블링 완료!" << endl;
}