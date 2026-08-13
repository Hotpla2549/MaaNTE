// MaaNTE - App shell implementation
#include "MaaNTE.h"
#include <iostream>

namespace MaaNTE {

bool App::Initialize() {
    std::cout << "[MaaNTE] MaaFramework v5.12.3 init\n";
    return true;
}

void App::LoadPipelines(const std::string& dir) {
    m_pipeline.LoadAll(dir);
}

int App::Run() {
    std::cout << "[MaaNTE] Select a task to run:\n";
    for (const auto& t : m_pipeline.Tasks()) {
        std::cout << "  - " << t << "\n";
    }
    return 0;
}

} // namespace MaaNTE
