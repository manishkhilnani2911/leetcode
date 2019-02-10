/*
 Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 

Note:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
 */
class Solution {
  //Fa_Nu_Ub_Mi_Go_Ap
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<int> pq;
        for (pair<char, int> count : counts) {
            pq.push(count.second);
        }
        //cout<<pq.size()<<"\n";
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for (int i = 0; i < cycle; i++) {
              //schedule all the unique task in each cycle
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            //decrement the count of each task and add it again in the queue
            for (int cnt : tmp) {
                if (--cnt) {
                    pq.push(cnt);
                }
            }
            //cout<<pq.empty()<<" "<<cycle<<" "<<time<<"\n";
          //if we have enough unique task to schedule each cycle then add cycle to the all time
          //else just add the number of tasks that ran in the current cycle
          //basically everytime we just add cycle to all time because if we do not have enough unique tasks to schedule per cycle then after scheduling all the tasks in a cycle we will have to sit idle for the rest of the time in that cycle.
          //only for the last cycle since after scheduling all the task we just need to add the time spent in executing those tasks and not the idle time of the cycle.
            alltime += !pq.empty() ? cycle : time;
            //cout<<alltime<<"\n";
        }
        return alltime;
    }
};
