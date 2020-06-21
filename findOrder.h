#include "head.h"

//深度优先搜索解决拓扑
class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> status;
    vector<int> result;
    bool invalid;
public:
    void dfs(int i){
        status[i]=1;//已访问过
        for(auto x:edges[i]){
            if(status[x]==1){
                invalid=true;
                return;
            }else if(status[x]==0){
                dfs(x);
                if(invalid)return;
            }
        }
        status[i]=2;//已完成;
        result.push_back(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {   
        int size=prerequisites.size();
        invalid=false;
        edges.resize(numCourses);
        status.resize(numCourses,0);
        for(int i=0;i<size;++i){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses&&!invalid;++i){
            if(status[i]==0){
                dfs(i);
            }
        }
        if(invalid){
            return {};
        }
        reverse(result.begin(),result.end());
        return result;
    }
};


//深度优先搜索，总结节点的入度