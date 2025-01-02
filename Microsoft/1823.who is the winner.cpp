//we can solve this question through multiple approches
//1. simple Array simulation
class Solution {
public:
    //T.C = O(n)^2
    int findTheWinner(int n, int k) {
        vector<int>arr;
        for(int i= 1; i <= n ;i++){
            arr.push_back(i);
        }
                    
        //the index of first player where the game start
        int i=0;

        while(arr.size() > 1){
            int idx = (i+k-1) % arr.size();
            arr.erase(arr.begin() + idx);
            i=idx;
        }

        return arr[0];

    }
};

//2.simulation using queue

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i <=n ;i++){
            q.push(i);
        }

        while(q.size() > 1) {
            for(int count = 1; count <= k-1; count++){
                q.push(q.front());
                q.pop();
            }

            q.pop();
        }
        return q.front();
    }
};
