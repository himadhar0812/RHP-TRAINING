N, M = map(int, input().split())
diff = [0] * (N + 2)
for _ in range(M):
    L, R = map(int, input().split())
    diff[L] += 1
    diff[R + 1] -= 1
coverage = 0
answer = float('inf')
for i in range(1, N + 1):
    coverage += diff[i]
    answer = min(answer, coverage)
print(answer)
