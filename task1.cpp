#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<string>
using namespace std;

void task1_1() {
    map <string,int> mp;
    int n;

    ifstream input("Input task1.txt");

    while (!input.eof()) {
        input >> n;
        mp.insert(make_pair(to_string(2023-n),n));
    }
    input.close();

    map<string, int>::iterator it,it2 = mp.begin();

    while(it2!=mp.end()){
        it=mp.find(to_string(it2->second));
        if (it != mp.end()) {
            cout << it->second << endl << it->first << endl;
            it2 = mp.end();
        }
        else it2++;
    }

}

vector <int> func(vector<int>& values1, vector<int>& values2) {
    vector <int> result(values1.size()+values2.size());
    int i = 0, j = 0, k = 0;

    while (i < values1.size() && j < values2.size()) {
        if (values1[i] <= values2[j]) {
            result[k++] = values1[i++];
        }
        else {
            result[k++] = values2[j++];
        }
    }

    while (i < values1.size()) {
        result[k++] = values1[i++];
    }

    while (j < values2.size()) {
        result[k++] = values2[j++];
    }

    for (int i = 0;i < result.size();i++) {
        cout << result[i]<<" ";
    }

    return result;
}

void task1_2() {
    vector <int> arr1 = {1,1,3,7,9};
    vector <int> arr2 = {1,4,12,12,76};
    func(arr1, arr2);
}

int main() {
    cout << "Task 1:" << endl;
    task1_1();
    cout << "Task 2:" << endl;
    task1_2();
}

