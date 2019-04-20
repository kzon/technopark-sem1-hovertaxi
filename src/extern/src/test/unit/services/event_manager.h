#pragma once

#include <gtest/gtest.h>

#include "services/event_manager/event_manager.h"

using namespace hovertaxi;

static std::string TEST_STRING;
static const std::string EXPECTED_STRING = "TestString";
static const std::string EVENT_NAME = "TestEvent";

class A {
 public:
  A() {
    EventManager *manager = EventManager::GetInstance();
    manager->CreateEvent(EVENT_NAME);
  }

  void executeEvent() {
    EventManager *manager = EventManager::GetInstance();
    manager->Notify(EVENT_NAME);
  }
};

class B {
 public:

  B() {}

  void process1() {
    TEST_STRING = EXPECTED_STRING;
  }

  void process2() {
    TEST_STRING = EXPECTED_STRING + EXPECTED_STRING;
  }

  void connectProcessToEvent() {
    EventManager *manager = EventManager::GetInstance();
    manager->AddEventListener(EVENT_NAME, this, &B::process1);
  }

  void connectAnotherProcessToEvent() {
    EventManager *manager = EventManager::GetInstance();
    manager->AddEventListener(EVENT_NAME, this, &B::process2);
  }
};

class EventManagerTest : public ::testing::Test {
 protected:
  A *a;
  B *b;

  virtual void SetUp() {
    a = new A;
    b = new B;
  }
  virtual void TearDown() {}
};

TEST_F(EventManagerTest, Notify) {

  b->connectProcessToEvent();
  a->executeEvent();

  ASSERT_EQ(EXPECTED_STRING, TEST_STRING);

}

TEST_F(EventManagerTest, CreateEvent) {

  EventManager *manager = EventManager::GetInstance();

  ASSERT_EQ(1, manager->GetEventsCount());
}

TEST_F(EventManagerTest, AddEventListener) {

  EventManager *manager = EventManager::GetInstance();
  int count = manager->GetListenersCount(EVENT_NAME);

  ASSERT_EQ(1, count);

  b->connectAnotherProcessToEvent();
  count = manager->GetListenersCount(EVENT_NAME);

  ASSERT_EQ(2, count);
}