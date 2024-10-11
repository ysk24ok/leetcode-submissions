from heapq import heappop, heappush
from typing import List

ARRIVED = 1
LEFT = -1

class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        events = []
        for friend in range(len(times)):
            # Placing the event type (ARRIVED or LEFT) in the second,
            # LEFT events come earlier than ARRIVED events of the same time.
            events.append((times[friend][0], ARRIVED, friend))
            events.append((times[friend][1], LEFT, friend))
        events.sort()
        # print(events)

        who_sit_where = {}
        max_empty_seat = 0
        heap = [max_empty_seat]  # to track empty seats
        for time, event_type, friend in events:
            if event_type == LEFT:
                seat = who_sit_where[friend]
                # print(f"{friend} left {seat} at {time}")
                del who_sit_where[friend]
                heappush(heap, seat)
            elif event_type == ARRIVED:
                seat = heappop(heap)
                # print(f"{friend} sat {seat} at {time}")
                who_sit_where[friend] = seat
                if len(heap) == 0:
                    max_empty_seat += 1
                    heap.append(max_empty_seat)
                if friend == targetFriend:
                    break
        return seat


if __name__ == '__main__':
    sol = Solution()

    times, targetFriend, expected = [[1,4],[2,3],[4,6]], 1, 1
    assert sol.smallestChair(times, targetFriend) == expected

    times, targetFriend, expected = [[3,10],[1,5],[2,6]], 0, 2
    assert sol.smallestChair(times, targetFriend) == expected

    times, targetFriend, expected = [[18,19],[10,11],[21,22],[5,6],[2,3],[6,7],[43,44],[48,49],[53,54],[12,13],[20,21],[34,35],[17,18],[1,2],[35,36],[16,17],[9,10],[14,15],[25,26],[37,38],[30,31],[50,51],[22,23],[3,4],[27,28],[29,30],[33,34],[39,40],[49,50],[15,16],[4,5],[46,47],[51,52],[32,33],[11,12],[28,29],[47,48],[36,37],[40,41],[42,43],[52,53],[41,42],[31,32],[23,24],[8,9],[19,20],[24,25],[26,27],[45,46],[44,45],[7,8],[13,14],[38,39]], 8, 0
    assert sol.smallestChair(times, targetFriend) == expected
