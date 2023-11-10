#pragma once
#include "Base.h"

enum class EventType
{
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender, 
    KeyPressed, KeyRelased, KeyTyped,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EventCategory
{
    None = 0,
    EventCategoryApplication = BIT(1),
    EventCategoryInput = BIT(2),
    EventCategoryKeyboard = BIT(3),
    EventCategoryMouseButton = BIT(4)
};

class Event {
    public:
        virtual ~Event() = default;

        bool Handle = false;
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const {return GetName();}
        bool IsInCategory(EventCategory category){
            return GetCategoryFlags() & category;
        }
};

class EventDispatcher {
    EventDispatcher(Event& event): m_Event(event) {

    }

    template<typename T, typename F>
    bool Dispatch(const F& func) {
        if (m_Event,GetEventType() == T::GetStaticType()){
            m_Event.Handled |= func(static_cast<T&>(m_Event));
            return true;
        }
        return false;
    }

    private:
        Event& m_Event;
}

inline std::ostream& operator<<(std::ostream& os, const Event& e){
    return os << e.ToString();
}