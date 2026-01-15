// round down n/(ai+b)
for(int l=1; r; l<=n; l=r+1){
    int k = n/(a*l+b);
    r = (n / (n / (a*l + b) - b)) / a;
} 

// round up n/(ai+b)
for(int l=1, r; l<=n; l=r+1){
    int k = (n+l-1)/l ;
    int m = n + a*l + b - 1;
    r = (m/(m/(a*l+b))-b)/a;
}

// round down (n/i)*(m/j) (n<=m)
for(int l = 1, r; l <= n;l=r+1){
    int k = (n/l) * (m/l);
    r = min({n,n/(n/l),m/(m/l)});
}

// round down (a[0]/i)*(a[1]/i)*(a[2]/i)...*(a[m-1]/i)
for(int l = 1, r; l <= n;l=r+1){
    int k = 1, r = n;
    for(int i=0; i<m; i++){
        int v = a[i]/l;
        k *= v;
        r = min(r, a[i]/v);
    }
}



