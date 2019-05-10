#pragma once

#include <string>
#include <utility>
#include <vector>

#include "event.h"
#include "event_handler.h"

namespace hovertaxi {

class EventManager {
  struct EventType {
    Event *event;
    std::string name;

    explicit EventType(std::string name_) : name(std::move(name_)) {
      event = new Event();
    }
  };

 public:

  static EventManager *GetInstance() {
    if (!instance_) {
      instance_ = new EventManager();
    }
    return instance_;
  }

  void CreateEvent(std::string name) {
    for (auto &event : events_) {
      if (event.name == name) {
        return;
      }
    }

    EventType e(name);
    events_.push_back(e);
  }

  template<typename Class>
  bool AddEventListener(std::string name, Class *obj, void (Class::*func)()) {
    for (auto &event : events_) {
      if (event.name == name) {
        event.event->AddEventListener(obj, func);
        return true;
      }
    }
    return false;
  }

  void Notify(std::string name) {
    for (auto &event : events_) {
      if (event.name == name) {
        event.event->Notify();
      }
    }
  }

  size_t GetListenersCount(std::string name) {
    for (auto &event : events_) {
      if (event.name == name) {
        return event.event->GetListenersCount();
      }
    }
    return 0;
  }

  size_t GetEventsCount() {
    return events_.size();
  }

 protected:
  static EventManager *instance_;
  std::vector<EventType> events_;

  EventManager() { instance_ = static_cast <EventManager *> (this); }
  ~EventManager() {}

};

EventManager *EventManager::instance_ = 0;

}