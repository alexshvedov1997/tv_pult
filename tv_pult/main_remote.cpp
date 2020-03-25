#include <iostream>
#include "tv_remote.h"

using namespace std;

int main(){
	using namespace std;
	Tv s52;
	s52.setting();
	s52.onoff();
	s52.chanup();
	s52.setting();
	Remote grey;
	grey.set_chan(s52, 10);
	s52.show_remode(grey);
	grey.remote_mode();
	s52.show_remode(grey);
	grey.volup(s52);
	grey.volup(s52);
	s52.setting();
	return 0;
}