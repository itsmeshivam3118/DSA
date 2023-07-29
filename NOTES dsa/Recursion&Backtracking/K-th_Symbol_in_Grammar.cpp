//https://leetcode.com/problems/k-th-symbol-in-grammar/

//https://www.youtube.com/watch?v=5P84A0YCo_Y&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=10&ab_channel=AdityaVerma




class Solution {
public:
int kthGrammar(int n, int k) {

    /*
        2^0 elements -> 0
        2^1 elements -> 0 1
        2^2 elements -> 0 1 1 0
        2^3 elements -> 0 1 1 0 1 0 0 1
        2^4 elements -> 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
    */
    
    // Base Condition
    if(n==1 && k==1){
        return 0;
    }
    
    int mid = pow(2, n-1)/2; // half of total elements in a row
    
    if(k <= mid){
        return kthGrammar(n-1, k); // elements are same as previous rows
    }
    else{
        return not kthGrammar(n-1, k-mid); // elements are complement of first half of previous rows
    }
}
};