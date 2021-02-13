

#ifndef FILE_MANAGER_H_
	#define FILE_MANAGER_H_

	#include <Arduino.h>	
	#include <FS.h>


	class sfm {		
		private:
			String file_name;
		public:
			sfm(String file_name);
			boolean read_line(int line_number, String * result);
			boolean read_file(String * result);
	
	};

	void readFile(fs::FS &fs, String path);
	void readFile(fs::FS &fs, String path, String * result);
	void writeFile(fs::FS &fs, String path, String value);
#endif 
