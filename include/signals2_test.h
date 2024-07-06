#pragma once

#include <boost/signals2.hpp>
#include <spdlog/spdlog.h>

// 定义一个信号类型
typedef boost::signals2::signal<void(int)> MySignal;

// 定义一个函数,作为信号的槽函数
void mySlotFunction(int value)
{
    spdlog::info("Slot function called with value: {}", value);
}

int test_signals()
{
    // 创建一个信号对象
    MySignal mySignal;

    // 连接信号和槽函数
    mySignal.connect(mySlotFunction);

    // 触发信号
    mySignal(42);

    // 再次触发信号,但不会调用槽函数
    mySignal(24);

    return 0;
}