#pragma once

#include <iostream>
#include "tv.hpp"

class Remote {
    public:
        friend class Tv;
        enum RemoteMode {
            NORMAL, 
            INTERACTIVE
        };

   private:
        int mode;
        RemoteMode remoteMode;

   public:
        Remote(int m = Tv::TV): mode(m) {}
        bool volup(Tv& t) {return t.volup();}
        bool voldown(Tv& t) {return t.voldown();}
        void onoff(Tv& t) {t.onoff();}
        void channelup(Tv& t) {t.channelup();}
        void channeldown(Tv& t) {t.channeldown();}
        void set_channel(Tv& t,int ch) {t.channel=ch;}
        void set_mode(Tv& t) {t.set_mode();}
        void showMode() const;
};