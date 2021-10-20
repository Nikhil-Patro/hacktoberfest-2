//Note- (A.B)%m=1  we have to find such integer B.
//For B to exist it is necessaery that gcd(a, m)==1 i.e a and m must be co-prime.
#include <iostream>
using namespace std;
class triplet
{
public:
    int x, y, gcd;
};
triplet extended_euclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = b;
        ans.gcd = a;
        return ans;
    }
    triplet small_ans = extended_euclid(b, a % b);
    triplet ans;
    ans.gcd = small_ans.gcd;
    ans.x = small_ans.y;
    ans.y = small_ans.x - small_ans.y * (a / b);
    return ans;
}
int Multiplicative_Modulo_Inverse(int a, int m)
{   
    triplet ans=extended_euclid(a, m);
    if(ans.gcd==1) return ans.x;
    else return 0;//we know 0 can't be an answer as integer * 0=0...so here 0 is used as " answer does not exist".
    
}
int main()
{
    int a=5;
    int m=12;
    int ans=Multiplicative_Modulo_Inverse(a, m);
    cout<<ans<<endl;
}