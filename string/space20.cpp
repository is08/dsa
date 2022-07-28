#include<iostream>
#include<string>
using namespace std;

string replaceSpace(string str){
    int spaceCount = 0;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            spaceCount++;
        }
    }

    int updatedIndex = str.size() + (2 * spaceCount);

    char newStr[updatedIndex] = {};
    newStr[updatedIndex] = '\0';

    for(int i = (str.size() - 1); i >= 0; i--){
        if(str[i] == ' '){
            newStr[updatedIndex - 1] = '0';
            newStr[updatedIndex - 2] = '2';
            newStr[updatedIndex - 3] = '%';

            updatedIndex -= 3;
        }
        else{
            newStr[updatedIndex - 1] = str[i];
            updatedIndex--;
        }
    }

    return newStr;

}

int main(){
    string str = "hello world";

    cout << replaceSpace(str) << "\n";

    return 0;
}
