/************************************************************************************
    Converts datafiles of color swatches to an html file that can be opened in a web
    browser.
	John Dolan				September 2009
*********************************************************************************/

#include <iostream>
#include<fstream>
#include<string>
#include "swatches.h"

using namespace std;

int main(int argc, char *argv[]){

	ifstream fin;
	ofstream fout;
	string filename,ofilename;
	string separator;
	Swatch tmp;
        int rowcount=0;
        if(argc >1){
		filename = argv[1];
	}
	else{
		cout<<"Enter input filename:";
		cin>>filename;
	}

	fin.open(filename.c_str());
        if(fin.fail()){
		cout<<"Unable to open input file.\n";
		return (-1);
	}

	ofilename = filename+=".html";
        fout.open(ofilename.c_str());
	if(fout.fail()){
		cout<<"Unable to open output file.\n";
		return -1;
	}

        fout<<"<html><head><title> Colors Project by "<<filename;
	fout<<"</title></head><body><table><tr>";
/*        if(isalpha(fin.peek())){
		getline(fin,separator);
		fout<<"<td align = center>"<<separator<<"</td></tr>";
	} */
        fin>>tmp;
	while(!fin.eof()){
	     fout<<"<td align=center> <table bgcolor = #"<<tmp.color_string()<<"><tr><td width= "
		<<tmp.get_width()<<" height = "<<tmp.get_length()<<"></td></tr></table></td>";
             rowcount++;
             if(rowcount%20 == 0)
		fout<<"</tr><tr>";
             if(fin.peek() == '\n') 
		{fin.ignore();
		 while(fin.peek() == '\n'){
			rowcount=0;
			fin.ignore();
			fout<<"</tr><tr><td width = 16 height = 16>OOOO</td></tr><tr><td>OOOO</td></tr><tr>";
		  }
		}
/*	     if(isalpha(fin.peek())){
                getline(fin,separator);
                fout<<"<td align = center>"<<separator<<"</td></tr>";
        	} */

	     fin>>tmp;
         }

	fin.close();
	fout<<"</tr></table></body></html>\n";

	fout.close();

return 0;
}
