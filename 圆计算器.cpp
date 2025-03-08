#include <iostream>
#include <cmath>
#include <conio.h> // 用于获取键盘输入
#include <windows.h> // 用于清屏和设置文本颜色、打开网址
#include <Shellapi.h> // 添加这个头文件

using namespace std;

const double PI = 3.14;

void clearScreen() {
    system("cls"); // 清屏函数
}

// 设置文本颜色
void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void displayMainOptions();
void displayCircleOptions();
void displayCylinderOptions();
void displayConeOptions();
void displaySphereOptions();

void calculateCircleArea();
void calculateCircleCircumference();
void calculateCircleDiameterFromCircumference();
void calculateCircleRadiusFromArea();

void calculateCylinderVolume();
void calculateCylinderSurfaceArea();
void calculateCylinderLateralArea();
void calculateCylinderBaseArea();
void calculateCylinderHeightFromVolume();
void calculateCylinderRadiusFromVolume();
void calculateCylinderRadiusFromSurfaceArea();
void calculateCylinderVolumeFromSurfaceArea();

void calculateConeVolume();
void calculateConeSurfaceArea();
void calculateConeLateralArea();
void calculateConeBaseArea();
void calculateConeHeightFromVolume();
void calculateConeRadiusFromVolume();
void calculateConeRadiusFromSurfaceArea();
void calculateConeVolumeFromSurfaceArea();

void calculateSphereVolume();
void calculateSphereSurfaceArea();
void calculateSphereRadiusFromVolume();
void calculateSphereRadiusFromSurfaceArea();
void calculateSphereVolumeFromSurfaceArea();

// 新的计算页面函数，用于处理特定计算的多次计算并保留结果
void calculationPage(void (*calculationFunction)()) {
    while (true) {
        calculationFunction();
        cout << "按 Esc 返回上一级，按任意其他键继续计算..." << endl;
        char input;
        while (true) {
            if (_kbhit()) {
                input = _getch();
                if (input == 27) {
                    // 清空输入缓冲区
                    while (_kbhit()) {
                        _getch();
                    }
                    return;
                }
                else {
                    break;
                }
            }
        }
    }
}

int main() {
    displayMainOptions();
    return 0;
}

void displayMainOptions() {
    while (true) {
        clearScreen();
        cout << "请选择计算项目：";
        setTextColor(8); // 设置为灰色
        cout << " by xingyue" << endl;
        setTextColor(7); // 恢复默认颜色
        cout << "1. 圆的计算" << endl;
        cout << "2. 圆柱的计算" << endl;
        cout << "3. 圆锥的计算" << endl;
        cout << "4. 球的计算" << endl;
        cout << "5. 彩蛋" << endl;
        cout << "0. 退出程序" << endl;

        char input = _getch(); // 获取用户输入的字符
        while (input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != '0' && input != 27) {
            cout << "无效的选项，请重新输入！" << endl;
            input = _getch(); // 等待用户重新输入
        }

        if (input == '1') {
            displayCircleOptions();
        }
        else if (input == '2') {
            displayCylinderOptions();
        }
        else if (input == '3') {
            displayConeOptions();
        }
        else if (input == '4') {
            displaySphereOptions();
        }
        else if (input == '5') {
            SHELLEXECUTEINFO sei = { sizeof(sei) };
            sei.fMask = SEE_MASK_FLAG_NO_UI;
            sei.lpVerb = L"open";  // 使用宽字符字符串
            sei.lpFile = L"https://www.bilibili.com/video/BV1bi421h79s";  // 使用宽字符字符串
            sei.nShow = SW_SHOWNORMAL;

            if (!ShellExecuteEx(&sei)) {
                DWORD errorCode = GetLastError();
                wcout << L"打开网页失败，错误代码: " << errorCode << L". 请检查网络或浏览器设置。" << endl;  // 使用 wcout 输出宽字符
                system("pause");
            }
        }
        else if (input == '0') {
            clearScreen();
            cout << "感谢使用“圆”计算器，再见！" << endl;
            exit(0); // 退出程序
        }
        else if (input == 27) { // 检测 Esc 键
            continue; // 保持在主菜单
        }
    }
}

void displayCircleOptions() {
    while (true) {
        clearScreen();
        cout << "请选择圆的计算项目：" << endl;
        cout << "1. 圆的面积" << endl;
        cout << "2. 圆的周长" << endl;
        cout << "3. 已知周长求直径" << endl;
        cout << "4. 已知面积求半径" << endl;
        cout << "按 Esc 返回上一级" << endl;

        char input = _getch(); // 获取用户输入的字符
        while (input != '1' && input != '2' && input != '3' && input != '4' && input != 27) {
            cout << "无效的选项，请重新输入！" << endl;
            input = _getch(); // 等待用户重新输入
        }

        if (input == '1') {
            clearScreen();
            calculationPage(calculateCircleArea);
        }
        else if (input == '2') {
            clearScreen();
            calculationPage(calculateCircleCircumference);
        }
        else if (input == '3') {
            clearScreen();
            calculationPage(calculateCircleDiameterFromCircumference);
        }
        else if (input == '4') {
            clearScreen();
            calculationPage(calculateCircleRadiusFromArea);
        }
        else if (input == 27) { // 检测 Esc 键
            return; // 返回上一级
        }
    }
}

void displayCylinderOptions() {
    while (true) {
        clearScreen();
        cout << "请选择圆柱的计算项目：" << endl;
        cout << "1. 圆柱的体积" << endl;
        cout << "2. 圆柱的表面积" << endl;
        cout << "3. 圆柱的侧面积" << endl;
        cout << "4. 圆柱的底面积" << endl;
        cout << "5. 已知体积求高" << endl;
        cout << "6. 已知体积求半径" << endl;
        cout << "7. 已知表面积求半径" << endl;
        cout << "8. 已知表面积求体积" << endl;
        cout << "按 Esc 返回上一级" << endl;

        char input = _getch(); // 获取用户输入的字符
        while (input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != '6' && input != '7' && input != '8' && input != 27) {
            cout << "无效的选项，请重新输入！" << endl;
            input = _getch(); // 等待用户重新输入
        }

        if (input == '1') {
            clearScreen();
            calculationPage(calculateCylinderVolume);
        }
        else if (input == '2') {
            clearScreen();
            calculationPage(calculateCylinderSurfaceArea);
        }
        else if (input == '3') {
            clearScreen();
            calculationPage(calculateCylinderLateralArea);
        }
        else if (input == '4') {
            clearScreen();
            calculationPage(calculateCylinderBaseArea);
        }
        else if (input == '5') {
            clearScreen();
            calculationPage(calculateCylinderHeightFromVolume);
        }
        else if (input == '6') {
            clearScreen();
            calculationPage(calculateCylinderRadiusFromVolume);
        }
        else if (input == '7') {
            clearScreen();
            calculationPage(calculateCylinderRadiusFromSurfaceArea);
        }
        else if (input == '8') {
            clearScreen();
            calculationPage(calculateCylinderVolumeFromSurfaceArea);
        }
        else if (input == 27) { // 检测 Esc 键
            return; // 返回上一级
        }
    }
}

void displayConeOptions() {
    while (true) {
        clearScreen();
        cout << "请选择圆锥的计算项目：" << endl;
        cout << "1. 圆锥的体积" << endl;
        cout << "2. 圆锥的表面积" << endl;
        cout << "3. 圆锥的侧面积" << endl;
        cout << "4. 圆锥的底面积" << endl;
        cout << "5. 已知体积求高" << endl;
        cout << "6. 已知体积求半径" << endl;
        cout << "7. 已知表面积求半径" << endl;
        cout << "8. 已知表面积求体积" << endl;
        cout << "按 Esc 返回上一级" << endl;

        char input = _getch(); // 获取用户输入的字符
        while (input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != '6' && input != '7' && input != '8' && input != 27) {
            cout << "无效的选项，请重新输入！" << endl;
            input = _getch(); // 等待用户重新输入
        }

        if (input == '1') {
            clearScreen();
            calculationPage(calculateConeVolume);
        }
        else if (input == '2') {
            clearScreen();
            calculationPage(calculateConeSurfaceArea);
        }
        else if (input == '3') {
            clearScreen();
            calculationPage(calculateConeLateralArea);
        }
        else if (input == '4') {
            clearScreen();
            calculationPage(calculateConeBaseArea);
        }
        else if (input == '5') {
            clearScreen();
            calculationPage(calculateConeHeightFromVolume);
        }
        else if (input == '6') {
            clearScreen();
            calculationPage(calculateConeRadiusFromVolume);
        }
        else if (input == '7') {
            clearScreen();
            calculationPage(calculateConeRadiusFromSurfaceArea);
        }
        else if (input == '8') {
            clearScreen();
            calculationPage(calculateConeVolumeFromSurfaceArea);
        }
        else if (input == 27) { // 检测 Esc 键
            return; // 返回上一级
        }
    }
}

void displaySphereOptions() {
    while (true) {
        clearScreen();
        cout << "请选择球的计算项目：" << endl;
        cout << "1. 球的体积" << endl;
        cout << "2. 球的表面积" << endl;
        cout << "3. 已知体积求半径" << endl;
        cout << "4. 已知表面积求半径" << endl;
        cout << "5. 已知表面积求体积" << endl;
        cout << "按 Esc 返回上一级" << endl;

        char input = _getch(); // 获取用户输入的字符
        while (input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != 27) {
            cout << "无效的选项，请重新输入！" << endl;
            input = _getch(); // 等待用户重新输入
        }

        if (input == '1') {
            clearScreen();
            calculationPage(calculateSphereVolume);
        }
        else if (input == '2') {
            clearScreen();
            calculationPage(calculateSphereSurfaceArea);
        }
        else if (input == '3') {
            clearScreen();
            calculationPage(calculateSphereRadiusFromVolume);
        }
        else if (input == '4') {
            clearScreen();
            calculationPage(calculateSphereRadiusFromSurfaceArea);
        }
        else if (input == '5') {
            clearScreen();
            calculationPage(calculateSphereVolumeFromSurfaceArea);
        }
        else if (input == 27) { // 检测 Esc 键
            return; // 返回上一级
        }
    }
}

void calculateCircleArea() {
    double radius;
    cout << "请输入圆的半径：";
    cin >> radius;
    double area = PI * radius * radius;
    cout << "圆的面积为：" << area << endl;
}

void calculateCircleCircumference() {
    double radius;
    cout << "请输入圆的半径：";
    cin >> radius;
    double circumference = 2 * PI * radius;
    cout << "圆的周长为：" << circumference << endl;
}

void calculateCircleDiameterFromCircumference() {
    double circumference;
    cout << "请输入圆的周长：";
    cin >> circumference;
    double diameter = circumference / PI;
    cout << "圆的直径为：" << diameter << endl;
}

void calculateCircleRadiusFromArea() {
    double area;
    cout << "请输入圆的面积：";
    cin >> area;
    double radius = sqrt(area / PI);
    cout << "圆的半径为：" << radius << endl;
}

void calculateCylinderVolume() {
    double radius, height;
    cout << "请输入圆柱的半径和高（用空格隔开）：";
    cin >> radius >> height;
    double volume = PI * radius * radius * height;
    cout << "圆柱的体积为：" << volume << endl;
}

void calculateCylinderSurfaceArea() {
    double radius, height;
    cout << "请输入圆柱的半径和高（用空格隔开）：";
    cin >> radius >> height;
    double surfaceArea = 2 * PI * radius * (radius + height);
    cout << "圆柱的表面积为：" << surfaceArea << endl;
}

void calculateCylinderLateralArea() {
    double radius, height;
    cout << "请输入圆柱的半径和高（用空格隔开）：";
    cin >> radius >> height;
    double lateralArea = 2 * PI * radius * height;
    cout << "圆柱的侧面积为：" << lateralArea << endl;
}

void calculateCylinderBaseArea() {
    double radius;
    cout << "请输入圆柱的底面半径：";
    cin >> radius;
    double baseArea = PI * radius * radius;
    cout << "圆柱的底面积为：" << baseArea << endl;
}

void calculateCylinderHeightFromVolume() {
    double radius, volume;
    cout << "请输入圆柱的半径和体积（用空格隔开）：";
    cin >> radius >> volume;
    double height = volume / (PI * radius * radius);
    cout << "圆柱的高为：" << height << endl;
}

void calculateCylinderRadiusFromVolume() {
    double height, volume;
    cout << "请输入圆柱的高和体积（用空格隔开）：";
    cin >> height >> volume;
    double radius = sqrt(volume / (PI * height));
    cout << "圆柱的半径为：" << radius << endl;
}

void calculateCylinderRadiusFromSurfaceArea() {
    double surfaceArea, height;
    cout << "请输入圆柱的表面积和高（用空格隔开）：";
    cin >> surfaceArea >> height;
    double radius = sqrt((surfaceArea / (2 * PI)) - (height / 2));
    cout << "圆柱的半径为：" << radius << endl;
}

void calculateCylinderVolumeFromSurfaceArea() {
    double surfaceArea, height;
    cout << "请输入圆柱的表面积和高（用空格隔开）：";
    cin >> surfaceArea >> height;
    double radius = sqrt((surfaceArea / (2 * PI)) - (height / 2));
    double volume = PI * radius * radius * height;
    cout << "圆柱的体积为：" << volume << endl;
}

void calculateConeVolume() {
    double radius, height;
    cout << "请输入圆锥的半径和高（用空格隔开）：";
    cin >> radius >> height;
    double volume = (1.0 / 3) * PI * radius * radius * height;
    cout << "圆锥的体积为：" << volume << endl;
}

void calculateConeSurfaceArea() {
    double radius, height;
    cout << "请输入圆锥的半径和高（用空格隔开）：";
    cin >> radius >> height;
    double slantHeight = sqrt(radius * radius + height * height);
    double surfaceArea = PI * radius * (radius + slantHeight);
    cout << "圆锥的表面积为：" << surfaceArea << endl;
}

void calculateConeLateralArea() {
    double radius, height;
    cout << "请输入圆锥的半径和高（用空格隔开）：";
    cin >> radius >> height;
    double slantHeight = sqrt(radius * radius + height * height);
    double lateralArea = PI * radius * slantHeight;
    cout << "圆锥的侧面积为：" << lateralArea << endl;
}

void calculateConeBaseArea() {
    double radius;
    cout << "请输入圆锥的底面半径：";
    cin >> radius;
    double baseArea = PI * radius * radius;
    cout << "圆锥的底面积为：" << baseArea << endl;
}

void calculateConeHeightFromVolume() {
    double radius, volume;
    cout << "请输入圆锥的半径和体积（用空格隔开）：";
    cin >> radius >> volume;
    double height = (3 * volume) / (PI * radius * radius);
    cout << "圆锥的高为：" << height << endl;
}

void calculateConeRadiusFromVolume() {
    double height, volume;
    cout << "请输入圆锥的高和体积（用空格隔开）：";
    cin >> height >> volume;
    double radius = sqrt((3 * volume) / (PI * height));
    cout << "圆锥的半径为：" << radius << endl;
}

void calculateConeRadiusFromSurfaceArea() {
    double surfaceArea, height;
    cout << "请输入圆锥的表面积和高（用空格隔开）：";
    cin >> surfaceArea >> height;
    double radius = sqrt((surfaceArea * height) / (PI * (height + sqrt(height * height + 4 * surfaceArea))));
    cout << "圆锥的半径为：" << radius << endl;
}

void calculateConeVolumeFromSurfaceArea() {
    double surfaceArea, height;
    cout << "请输入圆锥的表面积和高（用空格隔开）：";
    cin >> surfaceArea >> height;
    double radius = sqrt((surfaceArea * height) / (PI * (height + sqrt(height * height + 4 * surfaceArea))));
    double volume = (1.0 / 3) * PI * radius * radius * height;
    cout << "圆锥的体积为：" << volume << endl;
}

void calculateSphereVolume() {
    double radius;
    cout << "请输入球的半径：";
    cin >> radius;
    double volume = (4.0 / 3) * PI * radius * radius * radius;
    cout << "球的体积为：" << volume << endl;
}

void calculateSphereSurfaceArea() {
    double radius;
    cout << "请输入球的半径：";
    cin >> radius;
    double surfaceArea = 4 * PI * radius * radius;
    cout << "球的表面积为：" << surfaceArea << endl;
}

void calculateSphereRadiusFromVolume() {
    double volume;
    cout << "请输入球的体积：";
    cin >> volume;
    double radius = cbrt((3 * volume) / (4 * PI));
    cout << "球的半径为：" << radius << endl;
}

void calculateSphereRadiusFromSurfaceArea() {
    double surfaceArea;
    cout << "请输入球的表面积：";
    cin >> surfaceArea;
    double radius = sqrt(surfaceArea / (4 * PI));
    cout << "球的半径为：" << radius << endl;
}

void calculateSphereVolumeFromSurfaceArea() {
    double surfaceArea;
    cout << "请输入球的表面积：";
    cin >> surfaceArea;
    double radius = sqrt(surfaceArea / (4 * PI));
    double volume = (4.0 / 3) * PI * radius * radius * radius;
    cout << "球的体积为：" << volume << endl;
}