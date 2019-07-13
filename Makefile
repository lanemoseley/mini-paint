# Simplest possible makefile.  Notice that comments in makefiles are lines
# that start with a hash symbol.  Also notice that there is a tab character
# before the g++ compilation command.  The tab is required:
#
# target: dependency1 dependency2 . . . dependencyn
# <tab> command1
# <tab> command2
 
main:
	g++ -o main *.cpp -lglut -lGL -lGLU -lpthread -std=c++11 -Wall -g

clean:
	rm -rf main *.o
