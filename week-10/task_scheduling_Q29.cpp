/*
Given a long list of tasks. Each task takes specific time to
 accomplishitandeachtaskhasadeadlineassociatedwithit.Youhave
 todesignanalgorithmandimplementitusingaprogramtofindmaximum
 numberof tasksthatcanbecompletedwithoutcrossingtheirdeadlines
 and also find list of selected tasks.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int id;
    int deadline;
    int duration;
};

// Sort tasks by deadline (earliest first)
bool compare(Task a, Task b) {
    return a.deadline < b.deadline;
}

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<Task> tasks(n);
    cout << "Enter task ID, duration and deadline for each task:\n";
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].id >> tasks[i].duration >> tasks[i].deadline;
    }

    // Sort tasks by deadline
    sort(tasks.begin(), tasks.end(), compare);

    int currentTime = 0;
    vector<Task> selected;

    for (int i = 0; i < n; i++) {
        if (currentTime + tasks[i].duration <= tasks[i].deadline) {
            selected.push_back(tasks[i]);
            currentTime += tasks[i].duration;
        }
    }

    cout << "\nMaximum number of tasks completed: " << selected.size() << endl;
    cout << "Selected tasks (ID, duration, deadline):\n";
    for (Task t : selected) {
        cout << "Task " << t.id << " (" << t.duration << " unit, deadline " << t.deadline << ")\n";
    }

    return 0;
}
