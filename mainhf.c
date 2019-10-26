#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
extern char * mcodestring(int aschiicode);
int main(void) {
	FILE *LEDHandle = NULL;
	const char *LEDBrightness = "/sys/class/leds/beaglebone:green:usr0/brightness";
	char morse[] = "Welcome";
	char * str;
	int i = 0;
	int p;
	int len = 0;
	for(i =0; i < strlen(morse); i++){
		p = (int) morse[i];
		str = mcodestring(p);
		len = strlen(str);
		int j ;
		for (j =0; j < len; j ++){
			if (str[j] == '.' && j != len-1){
				//("its a point\n");
				if((LEDHandle = fopen(LEDBrightness, "r+")) != 					NULL){
					fwrite("1", sizeof(char), 1, LEDHandle);
					fclose(LEDHandle);
				}
				usleep(500000);
				if((LEDHandle = fopen(LEDBrightness, "r+")) != 					NULL){
					fwrite("0", sizeof(char), 1, LEDHandle);
				    fclose(LEDHandle);
				}
				usleep(250000);


			}else if(str[j]== '-' && j != len -1){
				//"its a dash
				if((LEDHandle = fopen(LEDBrightness, "r+")) != 					NULL){
					fwrite("1", sizeof(char), 1, LEDHandle);
					fclose(LEDHandle);
				}
				usleep(1500000);
				if((LEDHandle = fopen(LEDBrightness, "r+")) != 					NULL){
					fwrite("0", sizeof(char), 1, LEDHandle);
					fclose(LEDHandle);
				}
				usleep(250000);

			}else if (str[i] == '.'&& j == len -1){
				//"its a point and is the end
				if((LEDHandle = fopen(LEDBrightness, "r+")) != 					NULL){
					fwrite("1", sizeof(char), 1, LEDHandle);
					fclose(LEDHandle);
				}
				usleep(500000);
				if((LEDHandle = fopen(LEDBrightness, "r+")) != 					NULL){
					fwrite("0", sizeof(char), 1, LEDHandle);
					fclose(LEDHandle);
				}
				usleep(2000000);
			}
			else if(str[i] == '-' && j == len -1){
				//"its a dash and is the end
				if((LEDHandle = fopen(LEDBrightness, "r+")) != 					NULL){
					fwrite("1", sizeof(char), 1, LEDHandle);
					fclose(LEDHandle);
				}
				usleep(1500000);
				if((LEDHandle = fopen(LEDBrightness, "r+")) != 					NULL){
					fwrite("0", sizeof(char), 1, LEDHandle);
					fclose(LEDHandle);
				}
				usleep(2000000);
			}
		}
	}
	return EXIT_SUCCESS;
}
