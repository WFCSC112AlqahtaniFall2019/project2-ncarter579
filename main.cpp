//Nathan Carter

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

    vector<int> v(length);      // vector to be sorted
    vector<int> t(length);      // temporary workspace
    // unit test for merge
    /* your code here */
    vector<int> a{5,3,9,1};                             //setting up a vector with fixed numbers to test if mergeSort is working
    vector<int> b(4);                               //setting up a temporary vector that is the same length as vector a
    mergeSort(a,b,0,a.size() - 1);  //calling mergeSort with these 2 vectors
    for(int i = 1; i < a.size(); i++) {                 //iterating over the sorted vector and checking that the vector is in ascending order
        assert(a.at(i-1) <= a.at(i));                   //will fail this assertion if its not in ascending order
    }


    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    /* your code here */
    mergeSort(v,t,0,length - 1);  //calling mergeSort with the real vectors this time

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
    int center;             //setting up a center variable so that we can find the center of each vector were working in every time we call the function
    if(right <= left){      //checking to see if its in the correct order
        return;             //if its in the right order we can return because no further action is needed
    }
    else{
        center = (left + right)/2;                          //finding center of the vector
        mergeSort(v,t,left,center);                 //calls mergeSort recursively the first time to get the left side of the split
        mergeSort(v,t,center + 1,right);        //calls mergeSort recursively the second time to get the right side
        mergeSortedLists(v,t,left,center,right);     //calls mergeSortedLists to combine the vectors after they are broken down


    }
}

void mergeSortedLists(vector<int>& v,vector<int>& t, int left, int middle,  int right){
    int temp = left;                                //setting up a temp value that is initialised to the leftmost value in the vector
    int tempL = left;                           //setting up a temp value that will be used as the left side of each vector we're working with
    int tempR = middle + 1;                         //setting up a temp value that will be used as the right side of each vector we're working with
    while(tempL <= middle && tempR <= right ){      //will correct one side of the vector first
        if(v.at(tempL) > v.at(tempR)){          //if the left value is greater then the right value do this
            t.at(temp) = v.at(tempR);           //setting the temporary vector with the correct number
            temp = temp + 1;                    //iterating the variables used
            tempR = tempR + 1;
        }
        else{
            t.at(temp) = v.at(tempL);       //setting the temporary vector with the correct number
            temp = temp + 1;            //iterating the variables used
            tempL = tempL + 1;
        }
    }
    while(tempR <= right){          //checking the right side
        t.at(temp) = v.at(tempR);       //setting the temporary vector with the correct number
        temp = temp + 1;            //iterating the variables used
        tempR = tempR + 1;
    }
    while(tempL <= middle){         //checking the left side
        t.at(temp) = v.at(tempL);       //setting the temporary vector with the correct number
        temp = temp + 1;            //iterating the variables used
        tempL = tempL + 1;
    }
    for(int i = left; i <= right; i++ ){        //resetting vector v with the correct values that had been stored in vector t
        v.at(i) = t.at(i);
    }
}
