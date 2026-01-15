const int N = 1e5+5;
const int LG = 20;

int f[LG][N], logn[N];

void init(){
    logn[2] = 1;
    for(int i=3; i<N; i++)logn[i] = logn[i/2]+1;
}

for(int i=0; i<n-1; i++)f[0][i] = val[i];
for(int j=1; j<LG; j++)for(int i=0; i+(1<<j)-1<=n-1; i++)f[j][i] = max(f[j-1][i], f[j-1][i+(1<<(j-1))]);

int s = logn[r-l+1];
cout << max(f[s][l], f[s][r-(1<<s)+1]) << " ";