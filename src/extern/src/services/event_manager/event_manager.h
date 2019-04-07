#ifndef HOVERTAXI_EVENTMANAGER_H
#define HOVERTAXI_EVENT_MANAGER_H

namespace hovertaxi {

class EventManager {

public:

    void addEventListener(Observer *obs) {
        views.push_back(obs);
    }

    void removeEventListener(Observer *obs) {

    }

    void notify();

private:
    std::vector<class Observer *> views;
};

}

#endif //HOVERTAXI_EVENTMANAGER_H
