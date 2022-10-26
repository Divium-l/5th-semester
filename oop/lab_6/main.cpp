#include <iostream>
#include <stdexcept>

using namespace std;

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
    void switchRemote(Remote& remote) {
        if (state == Off)
            return;
        
        if (remote.remoteMode == Remote::RemoteMode::NORMAL)
            remote.remoteMode = Remote::RemoteMode::INTERACTIVE;
        else
            remote.remoteMode = Remote::RemoteMode::NORMAL;
    }

};

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
    cout<<"TV is " << (state == Off ? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Channel: " << channel << endl;
        cout << "Volume: " << volume << endl;
        cout << "mode: " << (mode == TV ? "TV" : "DVD") << endl;
    }
}

class Remote {
    public:
        enum RemoteMode {
            NORMAL, 
            INTERACTIVE
        };

   private:
        int mode;
        RemoteMode remoteMode;

   public:

        friend class Tv;
        Remote(int m = Tv::TV): mode(m) {}
        bool volup(Tv& t) {return t.volup();}
        bool voldown(Tv& t) {return t.voldown();}
        void onoff(Tv& t) {t.onoff();}
        void channelup(Tv& t) {t.channelup();}
        void channeldown(Tv& t) {t.channeldown();}
        void set_channel(Tv& t,int ch) {t.channel=ch;}
        void set_mode(Tv& t) {t.set_mode();}
        void showMode() const {
            cout << (remoteMode == RemoteMode::INTERACTIVE ? "interactive" : "normal") << endl;
        }
};

class except1: public logic_error {

}


int main() {
    Tv SamsungTV;
    cout<<"Initialisation settings:"<<endl;
    SamsungTV.settings();
    
    SamsungTV.onoff();
    SamsungTV.channelup();
    SamsungTV.volup();
    SamsungTV.volup();
    cout<<endl<<"new settings:"<<endl;
    SamsungTV.settings();
    
    Remote whiteRemote;
    whiteRemote.set_channel(SamsungTV,56);
    whiteRemote.volup(SamsungTV);
    whiteRemote.volup(SamsungTV);
    cout<<endl<<"new remote settings:"<<endl;
    SamsungTV.settings();
    return 0;
}