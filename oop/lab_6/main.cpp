#include "tv.hpp"
#include "remote.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

class Remote;
class Tv;

int main() {
    try {
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
    }
    catch (logic_error e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
