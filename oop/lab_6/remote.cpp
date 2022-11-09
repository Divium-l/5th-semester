#include "remote.hpp"

void Remote::showMode() const {
    std::cout << (remoteMode == RemoteMode::INTERACTIVE ? "interactive" : "normal") << std::endl;
}

bool Remote::volup(Tv t) 
{
    return t.volup();
}
bool Remote::voldown(Tv t) 
{
    return t.voldown();
}

void Remote::onoff(Tv t) 
{
    t.onoff();
}
void Remote::channelup(Tv t)
{
    t.channelup();
}

void Remote::channeldown(Tv t)
{
    t.channeldown();
}

void Remote::set_channel(Tv t,int ch) 
{
    t.channel=ch;
}

void Remote::set_mode(Tv t)
{
    t.set_mode();
}