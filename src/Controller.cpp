// MaaNTE - Input controller (simulated human input)
#include "../modules/MaaNTE.h"
#include <windows.h>
#include <random>

namespace MaaNTE {

void Controller::Click(int x, int y) {
    // Human-like click with slight position jitter and delay
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> jitter(-3, 3);
    int jx = x + jitter(gen);
    int jy = y + jitter(gen);

    INPUT input = {};
    input.type = INPUT_MOUSE;
    SetCursorPos(jx, jy);
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(input));
    Sleep(50 + jitter(gen) + 30);
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(input));
}

void Controller::KeyPress(int vk) {
    INPUT input = {};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = vk;
    SendInput(1, &input, sizeof(input));
    Sleep(60);
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void Controller::Swipe(int x1, int y1, int x2, int y2, int durationMs) {
    SetCursorPos(x1, y1);
    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(input));

    int steps = durationMs / 16;
    for (int i = 1; i <= steps; ++i) {
        int cx = x1 + (x2 - x1) * i / steps;
        int cy = y1 + (y2 - y1) * i / steps;
        SetCursorPos(cx, cy);
        Sleep(16);
    }

    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(input));
}

} // namespace MaaNTE
