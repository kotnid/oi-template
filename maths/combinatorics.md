## 1. Standard Absorption Identity 
- "Absorb" a multipler into binomial to eliminate variable

**Formula:**
$$ k \binom{n}{k} = n \binom{n-1}{k-1} $$

## 2. Upper-Index Absorption (Star & Bars)
- "Absorb" a multiplier from upper

**Formula:**
$$ w \binom{i+w}{w} = (i+1) \binom{i+w}{w-1} $$

## 3. Vandermonde's Convolution
- Squash $O(N)$ summation of 2 binomal into 1 single binomal 

**Formula:**
$$ \sum_{k=0}^{n}\binom{m}{k}\binom{p}{k} = \binom{m+p}{n} $$ 

## 4. Upper-Index Vandemonde's Convolution
- Squash summation but for moving upper-index 

**Formula:**
$$ \sum_{k=0}^{n}\binom{A+k}{k}\binom{B+n-k}{n-k} = \binom{A+B+n+1}{n} $$

## 5. Master Theorem 
- Find recursion time complexity 

**Formula:** 
$$T(n) = aT\left(\frac{n}{b}\right) + O(n^d)$$

### Case 1: Bottom-Heavy (Branching dominates)
If branching creates more work than the merge step can shrink, the time complexity is dominated by the leaves of the recursion tree.
* **Condition:** $a > b^d \quad \iff \quad d < \log_b a$
* **Complexity:** $$T(n) = O(n^{\log_b a})$$

### Case 2: Balanced (Work is evenly distributed)
If the branching matches the merge work perfectly, every level of the tree does the exact same amount of work. We multiply the work per level by the tree's height ($\log n$).
* **Condition:** $a = b^d \quad \iff \quad d = \log_b a$
* **Complexity:** $$T(n) = O(n^d \log n) \quad \text{or} \quad O(n^{\log_b a} \log n)$$

### Case 3: Top-Heavy (Merging dominates)
If the merge step is so expensive that it overshadows the branching, the time complexity is entirely determined by the very first merge at the root of the tree.
* **Condition:** $a < b^d \quad \iff \quad d > \log_b a$
* **Complexity:** $$T(n) = O(n^d)$$

## 6. Lagrange's four-square theorem
Sample question: [CF2231F](https://codeforces.com/contest/2231/problem/F)
For every natural number $n$, there exist integers $a, b, c,$ and $d$ such that:
$$ n = a^2 + b^2 + c^2 + d^2 $$
$$ \forall n \in \mathbb{N}, \exists a, b, c, d \in \mathbb{Z} : n = a^2 + b^2 + c^2 + d^2 $$