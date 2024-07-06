#pragma once

#include <event2/event.h>
#include <event2/event_struct.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void timer_callback(evutil_socket_t fd, short event, void *arg)
{
    printf("Timer callback triggered!\n");
}

void test_libevent()
{
#ifdef _WIN32
    WSADATA wsa_data;
    if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
    {
        fprintf(stderr, "Failed to initialize Winsock: %d\n", WSAGetLastError());
        // return 1;
    }
#endif
    // 初始化 libevent
    struct event_base *base = event_base_new();
    if (!base)
    {
        fprintf(stderr, "Failed to create event base\n");
        return;
    }

    // 创建一个定时器事件
    struct event *timer_event = event_new(base, -1, EV_TIMEOUT, timer_callback, NULL);
    if (!timer_event)
    {
        fprintf(stderr, "Failed to create timer event\n");
        event_base_free(base);
        return;
    }

    // 设置定时器延迟时间为 2 秒
    struct timeval delay = {2, 0};
    event_add(timer_event, &delay);

    // 启动事件循环
    event_base_dispatch(base);

    // 清理资源
    event_free(timer_event);
    event_base_free(base);
#ifdef _WIN32
    WSACleanup();
#endif
}
