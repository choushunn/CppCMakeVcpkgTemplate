#pragma once


#include <vtkActor.h>
#include <vtkAutoInit.h>
#include <vtkConeSource.h>
#include <vtkCubeSource.h>
#include <vtkCylinderSource.h>
#include <vtkDiskSource.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkVideoSource.h>
#include <vtkTransform.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType)


int test_vtk()
{
    //圆锥模型
    vtkSmartPointer<vtkConeSource> cone = vtkSmartPointer<vtkConeSource>::New();
    cone->SetHeight(3.0);
    cone->SetRadius(1.0);
    cone->SetResolution(10);
    vtkNew<vtkDiskSource> diskSource;
    diskSource->SetInnerRadius(0.5);
    diskSource->SetOuterRadius(1.0);
    diskSource->SetRadialResolution(20);
    diskSource->SetCircumferentialResolution(20);

    vtkNew<vtkCylinderSource> cylinderSource;
    cylinderSource->SetRadius(1.0);
    cylinderSource->SetHeight(3.0);
    cylinderSource->SetResolution(20);
    vtkNew<vtkCubeSource> cubeSource;
    cubeSource->SetXLength(2.0);
    cubeSource->SetYLength(2.0);
    cubeSource->SetZLength(2.0);
    vtkNew<vtkSphereSource> sphereSource;
    sphereSource->SetRadius(1.0);
    sphereSource->SetPhiResolution(20);
    sphereSource->SetThetaResolution(20);
    // 创建一个多边形数据映射器
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(cubeSource->GetOutputPort());

    // 创建一个演员
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    // 设置演员的位置和方向
    vtkNew<vtkTransform> transform;
    transform->Translate(2.0, 1.0, 0.0);  // 设置位置
    // transform->RotateZ(45.0);            // 绕 Z 轴旋转 45 度
    // transform->RotateX(45.0);            // 绕 X 轴旋转 45 度
    transform->RotateY(30.0);               // 绕 Y 轴旋转 45 度
    
    actor->SetUserTransform(transform);

   // 创建渲染器和渲染窗口
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);
    renderer->SetBackground(0.0, 1.0, 1.0);

    //渲染窗口
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    renderWindow->SetSize(600, 400);
    renderWindow->SetWindowName("VTK Cone Example");
    //交互
    vtkSmartPointer<vtkRenderWindowInteractor> renderInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderInteractor->SetRenderWindow(renderWindow);

    //交互风格
    vtkSmartPointer<vtkInteractorStyleTrackballCamera> style =
        vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
    renderInteractor->SetInteractorStyle(style);

    renderInteractor->Initialize();
    renderInteractor->Start();

    return 0;
}