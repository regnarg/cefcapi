all:
	rm -f Release/cefcapi.out
	clear
	gcc -g -Wall -Werror -o Release/cefcapi.out -I. -Wl,-rpath,. -L../cef main_linux.c -lcef `pkg-config --libs --cflags gtk+-2.0`
	cd Release/ && ./cefcapi.out && cd ../
