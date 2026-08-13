// MaaNTE - Pipeline task runner (YAML-driven)
#include "../modules/MaaNTE.h"
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

namespace MaaNTE {

void Pipeline::LoadAll(const std::string& dir) {
    m_tasks.clear();
    if (!fs::exists(dir)) return;
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.path().extension() == ".yaml") {
            m_tasks.push_back(entry.path().stem().string());
        }
    }
    std::cout << "[Pipeline] Loaded " << m_tasks.size() << " tasks\n";
}

bool Pipeline::RunTask(const std::string& name) {
    std::cout << "[Pipeline] Running task: " << name << "\n";
    // MaaFramework pipeline execution - CV recognition + input actions
    return true;
}

} // namespace MaaNTE
