import sys
input = sys.stdin.readline

def init_stair(size):
    
    stair = [0]
    
    for _ in range(size):
        stair_weight = int(input())
        stair.append(stair_weight)
        
    return stair


def main():
    stair_size = int(input())
    stair = init_stair(stair_size)
    
    
    # jump 생각 안하고 그냥 계단까지 갔을때 나오는 최댓값
    # 그니까 3칸 jump한거 생각 안하고 그냥 단일 계단까지 도착할수있는 경우의 최대값 저장한거임
    dp = [0] * (stair_size + 1)

    if stair_size >= 1:
        dp[1] = stair[1]
    if stair_size >= 2:
        dp[2] = stair[1] + stair[2]
    if stair_size >= 3:
        dp[3] = max(stair[1] + stair[3], stair[2] + stair[3])


    for i in range(4, stair_size + 1):
        dp[i] = max(
            dp[i-2] + stair[i],
            dp[i-3] + stair[i-1] + stair[i]
        )

    print(dp[stair_size])    


if __name__ == "__main__":
    main()
