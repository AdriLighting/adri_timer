#ifndef ADRI_TIMER_H
	#define ADRI_TIMER_H 
	#include <arduino.h>

	class adri_timer
	{
		String 			_title;
		boolean 		_activate;

	public:
		unsigned long	_duration_max;	

		
		adri_timer(int max, String title, boolean activate);
		~adri_timer(){}
		unsigned long 	_duration;	

		void 	loop(boolean & statu);
		boolean loop();
		boolean loop(unsigned long v);
		boolean loop_stop();
		boolean loop_wait();
		void 	loop_getTime(unsigned long & v);
		
		void 	set_duration(unsigned long val);
		void 	set_duration_max(unsigned long val);
		void 	activate();
		void 	activate(boolean val);
		boolean isActivate();

	};
	extern unsigned long TEST_currentMillis;
#endif