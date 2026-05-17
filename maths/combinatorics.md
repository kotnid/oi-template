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