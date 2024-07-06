#pragma once
#include "signals2_test.h"
#include "vtk_test.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <spdlog/spdlog.h>
#include "event_test.h"
void example_sqlite3()
{
}

void example_spdlog()
{
    spdlog::info("info");
    spdlog::critical("critical");
}


int test_opencv_videoio()
{

    // 创建一个 VideoCapture 对象来访问默认摄像头
    cv::VideoCapture cap(0);

    // 检查摄像头是否成功打开
    if (!cap.isOpened())
    {
        spdlog::error("Failed to open default camera");
        return -1;
    }
    cv::Mat frame;
    // 无限循环读取和显示视频帧
    while (true)
    {

        cap >> frame;

        // 显示视频帧
        cv::imshow("Frame", frame);

        // 按下 'q' 键退出循环
        if (cv::waitKey(1) == 'q')
            break;
    }

    // 释放资源
    cap.release();
    cv::destroyAllWindows();
}