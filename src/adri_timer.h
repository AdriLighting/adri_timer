#ifndef ADRI_TIMER_H
	#define ADRI_TIMER_H 
	#include <arduino.h>

	class adri_timer
	{
		unsigned long 	_millis;
		String 			_title;
		unsigned long	_duration_max;	
		boolean 		_activate;

	public:
		adri_timer(unsigned long max, String title, boolean activate);
		unsigned long 	_duration;	

		void 	loop(boolean & statu);
		boolean loop();
		boolean loop(unsigned long v);
		boolean loop_stop();
		boolean loop_wait();
		void 	loop_getTime(unsigned long & v);
		
		void 	set_duration(unsigned long val);
		void 	activate();
		void 	activate(boolean val);
		boolean isActivate();
	};
#endif