def backtrack(arr):
	if len(arr) == 2:
		return 0

	ans = 1
	for i in range(1, len(arr)-1):
		ans = max(ans, arr[i-1]*arr[i+1] + backtrack(arr[:i] + arr[i+1:]))

	return ans


n = int(input())
arr = [int(x) for x in input().split()]
print(backtrack(arr));