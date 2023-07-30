#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &arr, int startIndex, int endIndex){
    // base condition
    if((endIndex - startIndex) < 1){
        return;
    }

    int pivotIndex = endIndex;

    int i = -1, j = 0;

    while(j < pivotIndex){
        // increment j
        if(arr[j] > arr[pivotIndex]){
            j++;
        }
        else{
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    i++;
    int temp = arr[i];
    arr[i] = arr[pivotIndex];
    arr[pivotIndex] = temp;

    temp = i;
    quickSort(arr, startIndex, temp-1);
    temp = i;
    quickSort(arr, i + 2, j);
}

int main(){
    vector<int> arr = {3, 9, 6, 5, 3, 22, 77, 1, 0, 3, 5};

    quickSort(arr, 0, arr.size() - 1);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
