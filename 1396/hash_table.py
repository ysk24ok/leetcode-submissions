class UndergroundSystem:

    def __init__(self):
        self._customers = {}
        self._stats = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self._customers[id] = stationName, t

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStationName, inTime = self._customers[id]
        route = startStationName + ":" + stationName
        if route not in self._stats:
            self._stats[route] = {"time": 0, "count": 0}
        self._stats[route]["time"] += t - inTime
        self._stats[route]["count"] += 1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        route = startStation + ":" + endStation
        return self._stats[route]["time"] / self._stats[route]["count"]


if __name__ == '__main__':
    undergroundSystem = UndergroundSystem()
    undergroundSystem.checkIn(45, "Leyton", 3)
    undergroundSystem.checkIn(32, "Paradise", 8)
    undergroundSystem.checkIn(27, "Leyton", 10)
    undergroundSystem.checkOut(45, "Waterloo", 15)
    undergroundSystem.checkOut(27, "Waterloo", 20)
    undergroundSystem.checkOut(32, "Cambridge", 22)
    assert undergroundSystem.getAverageTime("Paradise", "Cambridge") == 14.0
    assert undergroundSystem.getAverageTime("Leyton", "Waterloo") == 11.0
    undergroundSystem.checkIn(10, "Leyton", 24)
    assert undergroundSystem.getAverageTime("Leyton", "Waterloo") == 11.0
    undergroundSystem.checkOut(10, "Waterloo", 38)
    assert undergroundSystem.getAverageTime("Leyton", "Waterloo") == 12.0

    undergroundSystem = UndergroundSystem()
    undergroundSystem.checkIn(10, "Leyton", 3)
    undergroundSystem.checkOut(10, "Paradise", 8)
    assert undergroundSystem.getAverageTime("Leyton", "Paradise") == 5.0
    undergroundSystem.checkIn(5, "Leyton", 10)
    undergroundSystem.checkOut(5, "Paradise", 16)
    assert undergroundSystem.getAverageTime("Leyton", "Paradise") == 5.5
    undergroundSystem.checkIn(2, "Leyton", 21)
    undergroundSystem.checkOut(2, "Paradise", 30)
    assert undergroundSystem.getAverageTime("Leyton", "Paradise") == 20 / 3
