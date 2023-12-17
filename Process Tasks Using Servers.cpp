/*Process Tasks Using Servers

You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.

Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty.

At second j, the jth task is inserted into the queue (starting with the 0th task being inserted at second 0). As long as there are free servers and the queue is not empty, the task in the front of the queue will be assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index.

If there are no free servers and the queue is not empty, we wait until a server becomes free and immediately assign the next task. If multiple servers become free at the same time, then multiple tasks from the queue will be assigned in order of insertion following the weight and index priorities above.

A server that is assigned task j at second t will be free again at second t + tasks[j].

Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.

Return the array ans​​​​.

 */

 vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> avail, busy;
    vector<int> res;
    for (int i = 0; i < servers.size(); ++i)
        avail.push({ 0, servers[i], i });
    for (long t = 0; t < tasks.size(); ++t) {
        while(!busy.empty() && (busy.top()[0] <= t || avail.empty())) {
            auto [time, w, i] = busy.top(); busy.pop();
            avail.push({ time <= t ? 0 : time, w, i });
        }
        auto [time, w, s] = avail.top(); avail.pop();
        busy.push({ max(time, t) + tasks[t], w, s });
        res.push_back(s);
    }
    return res;
}