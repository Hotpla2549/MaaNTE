// MaaNTE - Core types and app shell
#pragma once
#include <string>
#include <vector>

namespace MaaNTE {

struct ScreenRegion {
    int x = 0, y = 0, width = 0, height = 0;
};

class Recognizer {
public:
    bool MatchTemplate(const ScreenRegion& region, const std::string& templateName, float threshold);
    ScreenRegion FindText(const std::string& text);
    bool WaitFor(const std::string& templateName, int timeoutMs);
};

class Controller {
public:
    void Click(int x, int y);
    void KeyPress(int vk);
    void Swipe(int x1, int y1, int x2, int y2, int durationMs);
};

class Pipeline {
public:
    void LoadAll(const std::string& dir);
    bool RunTask(const std::string& name);
    const std::vector<std::string>& Tasks() const { return m_tasks; }
private:
    std::vector<std::string> m_tasks;
};

class App {
public:
    bool Initialize();
    void LoadPipelines(const std::string& dir);
    int Run();
private:
    Recognizer m_recognizer;
    Controller m_controller;
    Pipeline m_pipeline;
};

} // namespace MaaNTE
