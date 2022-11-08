#include "remote.hpp"

void Remote::showMode() const {
    std::cout << (remoteMode == RemoteMode::INTERACTIVE ? "interactive" : "normal") << std::endl;
}