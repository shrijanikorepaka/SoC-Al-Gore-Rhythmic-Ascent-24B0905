MOD = 10**9 + 7

n, m = map(int, input().split())
x = list(map(int, input().split()))

dp_prev = [0] * (m+2)  # index 1..m
dp_curr = [0] * (m+2)

# Base case
if x[0]==0:
    for v in range(1, m+1):
        dp_prev[v]=1
else:
    dp_prev[x[0]]=1

# DP
for i in range(1, n):
    dp_curr = [0]*(m+2)
    if x[i]==0:
        for v in range(1, m+1):
            dp_curr[v]= (dp_prev[v-1]+dp_prev[v]+dp_prev[v+1])%MOD
    else:
        y = x[i]
        dp_curr[y]= (dp_prev[y-1]+dp_prev[y]+dp_prev[y+1])%MOD
    dp_prev = dp_curr

# Answer
if x[-1]==0:
    result = sum(dp_prev[1:m+1])%MOD
else:
    result = dp_prev[x[-1]]%MOD

print(result)
