#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace
    // unit test for merge
    /* your code here */

    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    /* your code here */
    mergeSort(v,t,0,length);
    //mergeSortedLists(v,t,0,length/2,length - 1);

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

/* your code here */

void mergeSort(vector<int>& v,vector<int>& t, int left, int right){
    int center;
    if((right - left) == 1){
        return;
    }
    else{
        center = (left + right)/2;
        mergeSort(v,t,left,center);
        mergeSort(v,t,center,right);
        mergeSortedLists(v,t,left,center,right);


    }
}

void mergeSortedLists(vector<int>& v,vector<int>& t, int left, int middle,  int right){
    //t = v;
    int temp;
    for(int i = 0; i < (v.size() - 1); i++){
        if(v.at(i) > v.at(i + 1)){
            temp = v.at(i);
            v.at(i) = v.at(i +1);
            v.at(i + 1) = temp;
        }
    }
}
