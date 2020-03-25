#ifndef TV_REMOTE_H_
#define TV_REMOTE_H_

#include <iostream>

class Tv;

class Remote{
public:
	friend class Tv;
	enum State{Off, On};
	enum{MinVal, MaxVal = 20};
	enum{Antenna, Cabel};
	enum{TV,DVD};
	enum{Normal, Interactive};
private:
	int mode;
	int remode;
public:
	
	Remote(int m = TV):mode(m){}
	void remote_mode(){remode = (remode == Normal)? Interactive:Normal;}
	void show_remode();
	bool volup(Tv &t);
	bool voldown(Tv &t);
	void onoff(Tv &t);
	void chanup(Tv &t);
	void chapdown(Tv &t);
	void set_mode(Tv &t);
	void set_input(Tv &t);
	void set_chan(Tv &t, int c);
};

class Tv{
public:
	friend class Remote;
	//friend void Remote::set_chan(Tv &t, int c);
	enum State{Off, On};
	enum{MinVal, MaxVal = 20};
	enum{Antenna, Cable};
	enum{TV,DVD};
	Tv(int s = Off, int mc = 125):state(s),volume(5),maxchannel(125),channel(2),mode(Cable),input(TV){}
	void onoff(){state = (state == On)? Off : On;}
	bool ison() const{return state == On;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode(){mode = ( mode == Antenna)? Cable:Antenna;}
	void set_input(){input = (input == TV)? DVD : TV;}
	void setting() const;
	void show_remode(Remote & r);
private:
	int state;
	int volume;
	int mode;
	int channel;
	int input;
	int maxchannel;
	
};

inline bool Remote::volup(Tv &t){ return t.volup();}
inline bool Remote::voldown(Tv &t){ return t.voldown();}
inline void Remote::chanup(Tv &t){  t.chanup();}
inline void Remote::chapdown(Tv &t){t.chandown();}
inline void Remote::onoff(Tv &t){t.onoff();}
inline void Remote::set_chan(Tv &t, int c){  t.channel = c;}
inline void Remote::set_input(Tv &t){t.set_input();}
inline void Tv::show_remode(Remote &r){r.show_remode();}

#endif