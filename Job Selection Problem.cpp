// Job Selection Problem

#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on
                // deadline
};

void printJobScheduling(Job arr[], int n){
    sort(arr, arr + n, [](Job &a, Job &b){
        return a.profit > b.profit;
    });

    int mx_dead = 0;
    for(int i = 0; i < n; ++i){
        mx_dead = max(mx_dead, arr[i].dead);
    }

    char slot[mx_dead + 1];
    for(int i = 0; i <= mx_dead; ++i){
        slot[i] = -1;
    }

    int count = 0, profit = 0;
    for(int i = 0; i < n; ++i){
        for(int j = arr[i].dead; j > 0; --j){
            if(slot[j] == -1){
                slot[j] = arr[i].id;
                count++;
                profit += arr[i].profit;
                break;
            }
        }
    }

    for(int i = 1; i <= mx_dead; ++i){
        cout << slot[i] << " ";
    }
}

int main()
{
    Job arr[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";
 
    // Function call
    printJobScheduling(arr, n);
    return 0;
}