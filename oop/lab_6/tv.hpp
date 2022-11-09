#pragma once

#include "remote.hpp"
#include <iostream>
#include "tv_exception.hpp"

class Remote;

class Tv {
	private:
		friend class Remote;
		int state;
		int volume;
		int channel;
		int mode;
		int maxChannel;
		
	public:
		enum {Off, On};
		enum {MinVal, MaxVal = 20};
		enum {TV, DVD};

		Tv(): state(On),volume(5),channel(1), mode(TV),maxChannel(125) {};
		
		void onoff() {state ^= On;};
		bool ison() const {return state == On;};
		bool volup();
		bool voldown();
		void channelup();
		void channeldown();
		
		void set_mode() {mode ^= DVD;};
		void settings() const;
		void switchRemote(Remote &remote);
};