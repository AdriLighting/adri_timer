#ifndef ADRI_TIMER_H
	#define ADRI_TIMER_H 
	#include <arduino.h>

	class adri_timer
	{
		String 			_title;
		boolean 		_activate;

	public:
		int				_duration_max;	
		unsigned long 	_duration;	
		
		adri_timer(int max, String title, boolean activate);
		~adri_timer(){}

		void 	loop(boolean & statu);
		boolean loop();
		boolean loop(int v);
		boolean loop_stop();
		boolean loop_wait();
		void 	loop_getTime(unsigned long & v);
		
		void 	set_duration(unsigned long val);
		void 	set_duration_max(int val);
		void 	activate();
		void 	activate(boolean val);
		boolean isActivate();

	};
	extern unsigned long TEST_currentMillis;
#endif