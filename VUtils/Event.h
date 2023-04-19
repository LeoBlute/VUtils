#pragma once
#include <vector>

template<typename... Args>
class Event
{
public:
    using Function = void (*)(Args...);

    Event& operator+=(const Function func)
    {
        AddFunc(func);
        return *this;
    }

    Event& operator-=(const Function func)
    {
        RemoveFunc(func);
        return *this;
    }

    void operator()(Args... params)
    {
        Invoke(params...);
    }

    void AddFunc(const Function func)
    {
        for (auto f : mFunctions)
        {
            if (f == func) return;
        }
        mFunctions.push_back(func);
    }

    void RemoveFunc(const Function func)
    {
        auto it = std::find(mFunctions.begin(), mFunctions.end(), func);
        if (it != mFunctions.end())
        {
            mFunctions.erase(it);
        }
    }

    void Invoke(Args... params)
    {
        for (auto function : mFunctions)
        {
            function(params...);
        }
    }

    inline const std::vector<Function>& GetFunctions() { return mFunctions; };
private:
    std::vector<Function> mFunctions;
};