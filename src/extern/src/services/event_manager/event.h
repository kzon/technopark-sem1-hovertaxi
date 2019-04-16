#pragma once

#include <vector>

#include "event_handler.h"

namespace hovertaxi {

class Event{

    typedef std::vector<IEventHandler*>  EventHandlerVec;

public:
    Event() {}

    template <typename Class>
    void AddEventListener(Class *obj, void (Class::*func)()){
        handlers.push_back(new EventHandler<Class>(obj, func));
    }

    void Notify() {
        for(size_t i = 0; i < handlers.size(); i++){
            handlers[i]->Notify();
        }
    }

    size_t GetListenersCount(){
        return handlers.size();
    }

private:
    EventHandlerVec handlers;
};

}