/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map< int,vector<int> > connections;
        map< int,int > values;
        for (auto emp : employees){
            values[emp->id] = emp->importance;
            for (auto i : emp->subordinates){
                if (!connections.count(emp->id)){
                    vector< int > v;
                    connections[emp->id] = v;
                }
                connections[emp->id].push_back(i);
                if (!connections.count(i)){
                    vector< int > v;
                    connections[i] = v;
                }
                // connections[i].push_back(emp->id);
            }
        }
        
        return helper(connections,values,id);
    }
    
    int helper(map< int,vector<int> > &connections,map< int,int > &values,int id){
        cout<<id<<endl;
        int res = 0;
        res += values[id];
        for (auto i : connections[id]){
            res += helper(connections,values,i);
        }
        return res;
    }
};