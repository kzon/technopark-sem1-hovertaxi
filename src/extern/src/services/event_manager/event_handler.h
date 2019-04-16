#pragma once

namespace hovertaxi{

class IEventHandler{
public:
    virtual void Notify() = 0;
};

template <typename Class>
class EventHandler: public IEventHandler {

    typedef void (Class::*Func)();

public:
    Class *obj;
    Func func;

    EventHandler(Class *obj_, Func func_) : obj(obj_), func(func_) {}
    ~EventHandler(){}

    void Notify() override {
        (obj->*func)();
    }

};

}