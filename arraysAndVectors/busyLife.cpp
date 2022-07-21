#include<vector>
#include<algorithm>
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}


int countActivites(vector<pair<int,int> > activities){

    sort(activities.begin(), activities.end(), sortbysec);
    int i = 1, countOfActivities = 1, currActivity = 0;

    while(i < activities.size()){
        if(activities[i].first >= activities[currActivity].second){
            currActivity = i;
            countOfActivities++;
        }
        i++;
    }
    return countOfActivities;


}
