#include "adri_timer.h"


adri_timer::adri_timer(unsigned long max, String title, boolean activate){
	_title 			= title;
	_activate 		= activate;
	_duration_max 	= max;
	_duration 		= millis();
}

/**
 * @brief      TIMER LOOP
 *
 */
void adri_timer::loop(boolean & statu){
	if (!_activate) {statu = false; return;}

	_millis = millis();
	if ((_millis - _duration) > _duration_max) {
		statu = true;
		_duration = millis();
		return;
	}
	statu = false;
}
boolean adri_timer::loop(){
	if (!_activate) return false;

	_millis = millis();
	if ((_millis - _duration) > _duration_max) {
		_duration = millis();
		return true;
	}
	return false;	
}
boolean adri_timer::loop(unsigned long v){
	if (!_activate) return false;

	_millis = millis();
	if ((_millis - _duration) > v) {
		_duration = millis();
		return true;
	}
	return false;	
}
boolean adri_timer::loop_stop(){
	if (!_activate) return false;

	_millis = millis();
	if ((_millis - _duration) > _duration_max) {
		_activate = false;
		return true;
	}
	return false;	
}
boolean adri_timer::loop_wait(){
	if (!_activate) return false;

	_millis = millis();
	if ((_millis - _duration) > _duration_max) {
		return true;
	}
	return false;	
}
void adri_timer::loop_getTime(unsigned long & v) {
	v =  (millis() - _duration);
}

void 	adri_timer::set_duration(unsigned long val) {_duration = val;}
boolean adri_timer::isActivate()					{return _activate;}
void adri_timer::activate(boolean val){
	if (val) {
	} else {
		_duration = 0;
	}
	_activate = val;
}
void adri_timer::activate(){
	_duration = millis();
	_activate = true;
}


