#include "adri_timer.h"

	// unsigned long	_adri_timer_millis;	
adri_timer::adri_timer(int max, String title, boolean activate){
	unsigned long 	tNow = millis();
	_title 			= title;
	_activate 		= activate;
	_duration_max 	= max;
	_duration 		= tNow;
}
// ~adri_timer::adri_timer(){};
/**
 * @brief      TIMER LOOP
 *
 */
void adri_timer::loop(boolean & statu){
	if (!_activate) {statu = false; return;}

	unsigned long  tNow = millis();
	if ((tNow - _duration) > _duration_max) {
		statu = true;
		_duration = tNow;
		return;
	}
	statu = false;
}
boolean adri_timer::loop(){
	if (!_activate) return false;

	unsigned long tNow = millis();
	if ((tNow - _duration) > _duration_max) {
		_duration = tNow;
		return true;
	}
	return false;	
}
boolean adri_timer::loop(int v){
	if (!_activate) return false;

	unsigned long tNow = millis();
	if ( (tNow - _duration) > v) {
		_duration = tNow;
		return true;
	}
	return false;	
}
boolean adri_timer::loop_stop(){
	if (!_activate) return false;

	unsigned long tNow = millis();
	if ((tNow - _duration) > _duration_max) {
		_activate = false;
		return true;
	}
	return false;	
}
boolean adri_timer::loop_wait(){
	if (!_activate) return false;

	unsigned long tNow = millis();
	if ((tNow - _duration) > _duration_max) {
		return true;
	}
	return false;	
}
void adri_timer::loop_getTime(unsigned long & v) {

	unsigned long tNow = millis();	
	v =  (tNow - _duration);
}

void 	adri_timer::set_duration_max(int val) 			{_duration_max = val;}
void 	adri_timer::set_duration(unsigned long val) 	{_duration = val;}
boolean adri_timer::isActivate()						{return _activate;}
void adri_timer::activate(boolean val){
	if (val) {
	} else {
		_duration = 0;
	}
	_activate = val;
}
void adri_timer::activate(){
	unsigned long tNow = millis();	
	_duration = tNow;
	_activate = true;
}


