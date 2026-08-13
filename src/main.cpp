// MaaNTE - Main entry point
// Neverness to Everness automation on MaaFramework v5.12.3
#include "../modules/MaaNTE.h"
#include <iostream>

int main(int argc, char* argv[]) {
    MaaNTE::App app;
    if (!app.Initialize()) {
        std::cerr << "[MaaNTE] Failed to initialize MaaFramework\n";
        return 1;
    }
    std::cout << "[MaaNTE] v1.1.0 ready. Loading pipeline tasks...\n";
    app.LoadPipelines("pipeline");
    return app.Run();
}
