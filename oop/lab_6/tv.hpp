#pragma once

#include <iostream>
#include "tv_exception.hpp"
#include "remote.hpp"

class Tv {
  public:
    friend class Remote; 
    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {TV, DVD};

  private:
    int state;
    int volume;
    int channel;
    int mode;
    int maxChannel;
    
  public:
    Tv(int s = Off, int mc = 125): state(s),volume(5),channel(1),
        mode(TV),maxChannel(mc) {};
    void onoff() {state ^= On;}
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void channelup();
    void channeldown();
    void set_mode() {mode ^= DVD;}
    void settings() const;
    void switchRemote(Remote &remote);
};