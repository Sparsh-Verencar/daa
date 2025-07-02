#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* struct Job
{
    int profit;
    int deadline;
    int id;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSeq(vector<Job> jobs)
{
    int maxDeadline = 0;
    int maxProfit = 0;

    sort(jobs.begin(), jobs.end(), compare);
    int n = jobs.size();

    for (auto job : jobs)
    {
        if (job.deadline > maxDeadline)
        {
            maxDeadline = job.deadline;
        }
    }

    vector<int> schedule(maxDeadline, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = min(jobs[i].deadline, maxDeadline) - 1; j >= 0; j--)
        {
            if (schedule[j] == -1)
            {
                maxProfit += jobs[i].profit;
                schedule[j] = jobs[i].id;
                break;
            }
        }
    }
    for (auto id : schedule)
    {
        cout << id << "\t ";
    }
} */

struct Job
{
    int profit;
    int deadline;
    int id;
};

/* bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSeq(vector<Job> jobs)
{
    sort(jobs.begin(), jobs.end(), compare);
    int maxDeadline = 0;
    int maxProfit = 0;
    int n = jobs.size();

    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    vector<int> schedule(maxDeadline, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = min(jobs[i].deadline, maxDeadline)-1; j >= 0; j--)
        {
            if (schedule[j] == -1)
            {
                maxProfit += jobs[i].profit;
                schedule[j] = jobs[i].id;
                break;
            }
        }
    }

    for(auto id:schedule)
    {
        cout<<id<<"\t";
    }
    cout<<endl;
    cout<<"maxProfit"<<maxProfit<<endl;
} */

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSeq(vector<Job> jobs)
{
    int maxProfit = 0;
    int maxDeadline = 0;
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), compare);

    for (int i = 0; i < n; i++)
    {
        if (maxDeadline < jobs[i].deadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    vector<int> schedule(maxDeadline, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = min(jobs[i].deadline, maxDeadline)-1; j >= 0;j--)
        {
            if (schedule[j]==-1)
            {
                maxProfit+=jobs[i].profit;
                schedule[j] =jobs[i].id;
                break;
            }
            
        }
        
    }
     for(auto id:schedule)
    {
        cout<<id<<"\t";
    }
    cout<<endl;
    cout<<"maxProfit"<<maxProfit<<endl;
    
}

int main()
{
    // jobs are in (profit, deadline, id) format
    vector<Job> jobs = {
        {100, 2, 1}, {19, 1, 2}, {27, 2, 3}, {25, 1, 4}, {15, 3, 5}};

    jobSeq(jobs);
    return 0;
}
