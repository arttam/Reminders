#include <iostream>
#include "Runner.h"

int main(int argc, char **argv) {
    std::cout << "Welcome to reminder!" << std::endl;

    const char *_dbPath = nullptr;
    Runner runner;
    if (argc > 1)
        _dbPath = argv[1];

    bool _runResult = runner.run(_dbPath);

    if (!_runResult) {
        std::cerr << "Execution failed: " << std::endl;
        for(auto errStr : runner.getErrors())
            std::cerr << errStr << std::endl;
    }
    else {
        std::cout << "Execution succeeded" << std::endl;
    }

    return 0;
}