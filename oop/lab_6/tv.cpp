#include "tv.hpp"

bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    }
    return false;
}
        
bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    }
    return false;
}

void Tv::channelup() {
    if (channel<maxChannel)
        channel++;
    else 
        channel=maxChannel;
}

void Tv::channeldown() {
    if (channel > 1)
        channel--;
    else 
        channel = 1;
}

void Tv::settings() const {
    std::cout << "TV is " << (state == Off ? "Off" : "On") << std::endl;
    if (state == On) {
        std::cout << "Channel: " << channel << std::endl;
        std::cout << "Volume: " << volume << std::endl;
        std::cout << "mode: " << (mode == TV ? "TV" : "DVD") << std::endl;
    }
    else 
        throw TvIsOffException();
}

void Tv::switchRemote(Remote &remote) {
    if (state == Off)
        throw TvIsOffException();

    if (remote.remoteMode == Remote::RemoteMode::NORMAL)
        remote.remoteMode = Remote::RemoteMode::INTERACTIVE;
    else
        remote.remoteMode = Remote::RemoteMode::NORMAL;
}