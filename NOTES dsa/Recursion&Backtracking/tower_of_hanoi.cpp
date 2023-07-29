//https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1/

//https://www.youtube.com/watch?v=l45md3RYX7c&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=11&ab_channel=AdityaVerma



// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    long long toh(int N, int from, int to, int aux) {
        if(N==1)
        {
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
            return 1;
        }
        toh(N-1,from,aux,to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        toh(N-1,aux,to,from);
        return pow(2,N)-1;
    }

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}
