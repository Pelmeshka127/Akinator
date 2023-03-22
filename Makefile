all: akinatortask

FLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++\
 -Wc++14-compat -Wmissing-declarations\
  -Wcast-align -Wcast-qual -Wchar-subscripts\
   -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal\
    -Wformat-nonliteral -Wformat-security -Wformat=2\
	 -Winline -Wlong-long -Wnon-virtual-dtor -Wopenmp\
	 -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow\
	   -Wsign-conversion -Wsign-promo -Wstrict-overflow=2\
		 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef\
		  -Wunreachable-code -Wunused -Wvariadic-macros\
		   -Wno-literal-range -Wno-missing-field-initializers -Wno-narrowing\
		    -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new\
			 -fsized-deallocation -fstack-protector -fstrict-overflow -fno-omit-frame-pointer\
			  -Wlarger-than=8192 -fPIE\
			   -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,\
			   -fsanitize=float-divide-by-zero,integer-divide-by-zero,nonnull-attribute,null,\
			   -fsanitize=address,signed-integer-overflow,undefined,unreachable,vla-bound,vptr,

akinatortask: main.o tree.o dump.o parser.o stack.o debug.o akinator.o
	g++ obj/main.o obj/tree.o obj/dump.o obj/parser.o obj/stack.o obj/debug.o obj/akinator.o $(FLAGS) -o akinator

main.o: ./main.cpp
	g++ -c ./main.cpp $(FLAGS) -o obj/main.o

tree.o: ./Tree/tree.cpp
	g++ -c ./Tree/tree.cpp $(FLAGS) -o obj/tree.o

dump.o: ./Tree/dump.cpp
	g++ -c ./Tree/dump.cpp $(FLAGS) -o obj/dump.o

parser.o: ./Parsering/parser.cpp
	g++ -c ./Parsering/parser.cpp $(FLAGS) -o obj/parser.o

stack.o: ./Stack/stack.cpp
	g++ -c ./Stack/stack.cpp $(FLAGS) -o obj/stack.o

debug.o: ./Stack/debug.cpp 
	g++ -c ./Stack/debug.cpp $(FLAGS) -o obj/debug.o

akinator.o: ./Akinator_func/akinator.cpp
	g++ -c ./Akinator_func/akinator.cpp $(FLAGS) -o obj/akinator.o

.PHONY: clean

clean:
	rm *.o list