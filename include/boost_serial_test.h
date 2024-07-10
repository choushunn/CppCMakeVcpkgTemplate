#include <Windows.h>
#include <iostream>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <vector>

std::vector<std::string> get_available_serial_ports()
{
    std::vector<std::string> port_names;
    char port_name[12];

    // 枚举系统中可用的串口
    for (DWORD i = 0; i < 256; i++)
    {
        sprintf_s(port_name, sizeof(port_name), "\\\\.\\COM%lu", i);
        HANDLE hPort = CreateFileA(port_name, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (hPort != INVALID_HANDLE_VALUE)
        {
            port_names.push_back(port_name);
            CloseHandle(hPort);
        }
    }

    return port_names;
}

int test_serial()
{
    // 初始化 spdlog
    spdlog::set_pattern("[%H:%M:%S.%e] [%n] [%l] %v");
    spdlog::set_level(spdlog::level::info);
    auto logger = spdlog::stdout_color_mt("serial_port_logger");

    // 获取可用的串口
    auto available_ports = get_available_serial_ports();

    // 输出可用的串口
    logger->info("Available serial ports:");
    for (const auto &port : available_ports)
    {
        logger->info("- {}", port);
    }

    return 0;
}