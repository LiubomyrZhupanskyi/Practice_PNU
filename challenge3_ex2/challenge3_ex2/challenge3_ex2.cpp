#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

struct Event {
    std::string startTime;
    std::string endTime;
    int travelTime;
    int participants;
};

bool compareEvents(const Event& e1, const Event& e2) {
    return e1.participants > e2.participants;
}

int main() {
    std::string wakeUpTime;
    std::cin >> wakeUpTime;

    int N;
    std::cin >> N;

    std::vector<Event> events(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> events[i].startTime >> events[i].endTime >> events[i].travelTime >> events[i].participants;
    }

    // We sort the events by the number of participants in descending order
    std::sort(events.begin(), events.end(), compareEvents);

    int maxParticipants = 0;
    for (const auto& event : events) {
        // We are checking whether a teenager can attend this event
        if (event.endTime <= wakeUpTime)
            continue;
        int currentTime, eventStartTime, eventEndTime;
        std::stringstream(wakeUpTime) >> currentTime;
        std::stringstream(event.startTime) >> eventStartTime;
        std::stringstream(event.endTime) >> eventEndTime;
        if (currentTime + event.travelTime >= eventStartTime) {
            int participants = event.participants * std::min((eventEndTime - currentTime - event.travelTime), (eventEndTime - eventStartTime)) / (eventEndTime - eventStartTime);
            maxParticipants += participants;
        }
    }

    std::cout << "The maximum number of people a teenager can meet: " << maxParticipants << std::endl;

    return 0;
}
