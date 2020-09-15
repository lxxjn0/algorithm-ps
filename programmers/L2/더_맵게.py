from heapq import heapify, heappop, heappush

# result = 2
scoville = [1, 2, 3, 9, 10, 12]
k = 7


def solution(_scoville, _k):
    mix_count = 0
    heapify(_scoville)

    while True:
        first = heappop(_scoville)

        if first >= _k:
            return mix_count

        if len(_scoville) == 0:
            return -1

        second = heappop(_scoville)
        heappush(_scoville, first + second * 2)
        mix_count += 1


print(solution(scoville, k))
