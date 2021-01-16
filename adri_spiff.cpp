#include "adri_spiff.h"

#include <adri_tools.h>


sfm::sfm(String fn) {
	file_name=fn;
}


boolean sfm::read_line(int line_number, String * result) {
	File f = SPIFFS.open(file_name,"r");
	if (!f) {  
		f.close(); 
		return false;
	}

	int 	pos;
	int 	len;
	String 	r;

	f.seek(0, SeekSet);
	r=f.readStringUntil('\n');

	if (line_number == 0){
		* result = r;
		f.close(); 
		return true;
	}

	for (int i = 0; i < line_number; ++i) {

		if ( i == 0) 	len = r.length();
		else 			len += r.length();

		pos=(len)+(i+1);

		f.seek(pos, SeekSet);

		r = f.readStringUntil('\n');
	}


	* result = r;
	f.close(); 
	return true;
}
boolean sfm::read_file(String * result) {
	File f = SPIFFS.open(file_name,"r");
	if (!f) {  
		f.close(); 
		return false;
	}
	String r;
   	while (f.available()) {r += char(f.read());}

	* result = r;
	f.close(); 
	return true;
}

void readFile(fs::FS &fs, String path){
   String s = "\n[readFile]\n";
   s += info_parm("file", path);
   File file = fs.open(path, "r");
   if(!file){
      s += info_parm("result", "failed to open file for reading");
      fsprintf("%s\n", s.c_str());
      return;
   }
   s += "Start reading line by line:\n";
   fsprintf("%s", s.c_str());
   while (file.position()<file.size()) {
         String xml = file.readStringUntil('\n');
         fsprintf("%s\n", xml.c_str());
    }
   file.close();
   fsprintfs("[readFile] Done\n");
}

void readFile(fs::FS &fs, String path, String * result){
	File file = fs.open(path, "r");
	if(!file){
		return;
	}
	String ret;
	while (file.position()<file.size()) {
		String xml = file.readStringUntil('\n');
		if (xml!="")ret+=xml;
	}
	*result=ret;
	file.close();
}
void writeFile(fs::FS &fs, String path, String value){
	File file = fs.open(path, "w");
	if(!file){
		return;
	}
	file.print(value);
	file.close();
}