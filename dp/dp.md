# optimization # 
## Matrix Optimization ##
Use when transition repeated for many times  
-> Use fast power to optimize 

#### Question list ####
https://codeforces.com/contest/1970/problem/E2

## Bitset Optimization ##
Floyd warshall when weight only 0/1 (reachability)
    
#### Question list ####
https://atcoder.jp/contests/abc287/tasks/abc287_h

## Prefix sum optimization ##
Transition O(n^2) -> O(n)

#### Question list ####
https://atcoder.jp/contests/arc160/tasks/arc160_c 


## Submask Enumeration ## 
useful when bitmask dp transition is according to subset (precompute subset value (sum?) first)
O(n^4) -> O(n^3)
```c++
// s|t = s2 
for(int s2=0; s2<(1<<n); s2++){
  for(int t=s2; t>=0; t = (t-1)&s2){
    int s = s2^t;
    dp[s2] = max(dp[s2], dp[s]+1);
  }
}
```

#### Question list ####
https://codeforces.com/contest/2229/problem/F

--- 

# Common Tricks # 
## Swapping key and value ##
Use when key is large while value is small   
E.g. knapsack large capacity small number of item 

#### Question list ####
https://atcoder.jp/contests/abc364/tasks/abc364_e


## Size of DP Trick ##
Usually combine with math trick
E.g. product of X has length smaller than log(X)
-> O(N^2) become O(NlogX)

#### Question list ####
https://codeforces.com/contest/2060/problem/F

## Montonic trick ##
if we have a dp state dp[i][j] = 1/0
and we know if dp[i][j] =1, dp[i][j+1] = 1
we can transfer this into linear dp 
dp[i] = minimum possible j
-> O(N^2) become O(N) yay

#### Question list ####
https://codeforces.com/contest/1579/problem/G

## power ##
w(i) = num. of prime factor
find w(i*j)^k
w(i*j) = w(i) + w(j) - w(gcd(i,j))
dp[g][sum] = num of pair such that w(i)+w(j) = sum, gcd(i,j) = g
-> try to split the term and do counting dp
-> inclusion-exclusion dp[g] -= dp[2*g] + dp[3*g] ...

#### Question list ####
https://codeforces.com/contest/2176/problem/F


# Counting / Probability/ Expected Value # 

## Catalan number ## 
Usual form : 2d grid with line x = y 

#### Question list ####
https://atcoder.jp/contests/abc205/tasks/abc205_e?lang=en (line x+k = y, use reflection to count number of invalid path)

## Expected Value Convertion ##
E[x] 
= 1p1 + 2p2 + 3p3 ... + npn
= (p1+p2+...+pn) + (p2+p3+...+pn) + ... + pn
Useful when hard to find P[x=i] but easy to find P[x>=i]

#### Question list ####
https://atcoder.jp/contests/abc295/tasks/abc295_e?lang=en

## Linearity of Expectation ##
Using formula
E[X+Y] = E[X] + E[Y] (work even X Y dependent)
When ev of single random var is hard compute, we can transform it as sum of other random vars

E.g. (Independent event)
flip N coin, if total X coin, then need to pay X dollar, find ev  
E[Ci] = ev of coin i = 1/2 
E[X] = E[C1] + E[C2] + ... + E[Cn] = n/2

E.g. (Dependent event)
4 digits (1,2,3,4) form 2 2-digit number(AB and CD), find ev of AB*CD 
E[AB*CD] = E[100AC + 10AD + 10BC + BD] = 100E[AC] + 10E[AD] + 10E[BC] + E[BD]
Impossible case won't happen (E.g. 3 4 3 4) : [3 4] must be matched with [1 2], so we don't have a case of [3 4] with [3 4]

E.g. (Indicator random var)
Given n items, find ev of total items chosen 
E[X] = E[item 1 chosen] + E[item 2 chosen] + ... + E[item n chosen]

#### Question list ####
https://atcoder.jp/contests/arc114/tasks/arc114_e?lang=en (indicator random var)


## counting to expected value trick 
prob = count/total count 
count = prob*total count 

Use when count hard get but prob is ok (count need update O(N) state, but prob only update O(1) state)
E.g. swap 2 element (affect N state for count, but only 2 state for prob)

#### Question list #### 
https://atcoder.jp/contests/agc030/tasks/agc030_d?lang=en


## n element remove 
given n element, we may remove element, find probability of all n element
instead of storing all index, for each index store left how many element, right how many element, target element prob

#### Question list 
https://atcoder.jp/contests/agc050/tasks/agc050_d

## EV^2
E[X^2] where X is number of substring palindrome in string
Set indicator variable Xi,j , Xi,j=1 where s[i...j] is palindrome
E[X^2] 
= E[X*X]
= S1S2(E[Xs1 * Xs2])
= S1S2(P[S1^S2])

#### Questoin list
https://codeforces.com/problemset/problem/2174/C2

# GCD

## Inclusion-Exclusion on GCD


void f(3, 4){
}

int main(){
    int x = 3, y = 4;
    f(3,4);
}

# SOS DP 
bitwise, counting with certain bit properties 


#### Question list
https://codeforces.com/contest/1903/problem/D2

