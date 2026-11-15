#pragma once
#include <Sexy/Delegate.h>
#include <vector>

typedef std::vector<Sexy::TDelegate<void(Sexy::GC::*)()>> DelegatesVec;

class MessageRouter
{
public:
    virtual void Function0() {};
    virtual void Function1() {};
    virtual void Function2() {};

    virtual DelegatesVec& GetListenersForMessage(void* msgId) {
        return CallFunc<DelegatesVec&, MessageRouter*, void*>(0x96DB84, this, msgId);
    }

    template <typename T, typename F>
    void RegisterCallback(void* msgId, T& obj, F func)
    {
        auto dlgt = Sexy::make_delegate(func, obj);
        CallFunc<void, MessageRouter*, void*, void*>(0x96C4D8, this, msgId, &dlgt);
    }

    void DeregisterCallbacksOwnedByObject(void* obj)
    {
        CallFunc<void, MessageRouter*, void*>(0x96CAD4, this, obj);
    }

    template <typename... Params>
    void ExecuteMessage(void* msgId, Params... args)
    {
        DelegatesVec& listeners = GetListenersForMessage(msgId);

        m_unkInt++;

        for (auto it = listeners.begin(); it != listeners.end(); ++it)
        {
            auto* dlgtPtr = reinterpret_cast<Sexy::TDelegate<void(Sexy::GC::*)(Params...)>*>(&(*it));

            if (dlgtPtr->initialized != 0 && dlgtPtr->executeCallbackFunc_ != nullptr)
            {
                dlgtPtr->executeCallbackFunc_(dlgtPtr, args...);
            }
        }

        m_unkInt--;
        if (m_unkInt == 0)
        {
            CallFunc<void, MessageRouter*>(0x96C98C, this);
        }
    }

    static MessageRouter* GetInstance()
    {
        return *(MessageRouter**)getActualOffset(0x2513070);
    }

private:
    char padding[72];
    int m_unkInt;
};