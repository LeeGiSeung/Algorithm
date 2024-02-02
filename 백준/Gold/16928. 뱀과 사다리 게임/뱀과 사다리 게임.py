from collections import deque

# 사다리의 수, 뱀의 수 입력받기
n, m = map(int, input().split())

# 1부터 100번째 칸 방문횟수
board = [0] * 101
# 맵 방문표시
visited = [False] * 101

# 사다리, 뱀 딕셔너리 선언
ladder = dict()
snake = dict()
# 사다리 정보 입력받기
for _ in range(n):
    a, b = map(int, input().split())
    ladder[a] = b
# 뱀 정보 입력받기
for _ in range(m):
    a, b = map(int, input().split())
    snake[a] = b


# 큐 구현
q = deque([1])

# 큐가 빌 때까지 반복
while q:
    x = q.popleft()
    # 100번 칸에 도착했다면
    if x == 100:
        # 주사위 굴린 횟수 출력
        print(board[x])
        # 반복문 탈출
        break
    # 주사위에 있는 1부터 6까지 차례대로 입력받아
    for dice in range(1, 7):
        # 다음으로 이동할 위치 보기
        next_place = x + dice
        # 맵을 벗어나지 않거나 아직 방문하지 않은 칸이라면
        if next_place <= 100 and not visited[next_place]:
            # 이동할 위치에 사다리가 있다면
            if next_place in ladder.keys():
                next_place = ladder[next_place]
            # 이동할 위치에 뱀이 있다면
            if next_place in snake.keys():
                next_place = snake[next_place]
            # 이동할 위치에 아무것도 없다면
            if not visited[next_place]:
                # 방문 표시
                visited[next_place] = True
                # 주사위 굴린 횟수 추가
                board[next_place] = board[x] + 1
                # 큐에 이동한 위치 삽입
                q.append(next_place)