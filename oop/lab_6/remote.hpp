#pragma once

#include "tv.hpp"

class Tv;

class Remote {

   public:
		enum RemoteMode {
				NORMAL, 
				INTERACTIVE
			};
		Remote(): mode(0) {};
		bool volup(Tv t);
		bool voldown(Tv t);
		void onoff(Tv t);
		void channelup(Tv t);
		void channeldown(Tv t);
		void set_channel(Tv t,int ch);
		void set_mode(Tv t);
		void showMode() const;
   private:
		friend class Tv;
		int mode;
		RemoteMode remoteMode;
};