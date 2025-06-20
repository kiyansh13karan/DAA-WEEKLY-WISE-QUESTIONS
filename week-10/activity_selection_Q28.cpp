/*
 Givenalistofactivitieswiththeirstartingtimeandfinishingtime.
 Your goal is to select maximumnumber of activities that can be
 performedbyasinglepersonsuchthatselectedactivitiesmustbenon
conflicting.Anyactivityissaidtobenon-conflictingifstartingtimeofan
 activityisgreaterthanorequal tothefinishingtimeof theotheractivity.
 Assume that a person can only work on a single activity at a time.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an activity
struct Activity {
    int start, end;
};

// Comparator to sort activities by finish time
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected non-conflicting activities (start - end):\n";

    int count = 1;
    int lastEnd = activities[0].end;
    cout << activities[0].start << " - " << activities[0].end << endl;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastEnd) {
            cout << activities[i].start << " - " << activities[i].end << endl;
            lastEnd = activities[i].end;
            count++;
        }
    }

    cout << "Maximum number of non-conflicting activities: " << count << endl;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter start and end time of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].end;
    }

    activitySelection(activities);

    return 0;
}
