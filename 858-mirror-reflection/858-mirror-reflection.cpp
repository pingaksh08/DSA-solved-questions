class Solution {
public:
    /*
     obs based question -->
     m*p = n*q --> roughly draw on sheet for better under.
     --> if m is even and n is odd, it will strike 0,
     --> if m is odd and n is odd, it will strike 1,
     --> if m is odd and n is even, it will strike 2
    */
    int hcf(int a, int b){
        while(b){
            a = a%b;
            swap(a,b);
        }
        return a;
    }
    
    int mirrorReflection(int p, int q) {
        int lcm = p*q/hcf(p, q); // as p*q = lcm*hcf
        int m = lcm/p;
        int n = lcm/q;
        
        if(m%2==0 and n%2==1) return 0;
        if(m%2==1 and n%2==1) return 1;
        if(m%2==1 and n%2==0) return 2;
        return -1;
    }
};