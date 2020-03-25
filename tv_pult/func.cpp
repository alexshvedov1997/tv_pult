
#include<iostream>
#include"tv_remote.h"

bool Tv::volup(){
	if(volume < MaxVal){
	volume++;
	return true;
	}
	else
	return false;
}

bool Tv::voldown(){
	if( volume > MinVal){
	volume--;
	return true;
	}
	else
		return false;
}

void Tv::chanup(){
	if( channel < maxchannel){
	channel++;
	}
	else
	channel = 1;
}

void Tv::chandown(){
	if(channel > 1)
		channel--;
	else
		channel = maxchannel;
}

void Tv::setting() const{
	using std::cout;
	using std::endl;
	cout<<"Tv is " << (state == Off? "Off" : "On") << endl;
	if( state == On){
	cout << " Volume setting ="<< volume << endl;
	cout<<" Channel setting = " << channel << endl;
	cout << " Mode = " << (mode == Antenna? "Antenna":"Cable")<<endl;
	cout <<" Input= " <<(input == TV?"TV":"DVD")<<endl;
	}
}

void Remote::show_remode(){
	using std::cout;
	using std::endl;
	cout<<"Remore interactive mode="<<(remode == Normal? "Normal":"Iteractive")<<endl; 
}