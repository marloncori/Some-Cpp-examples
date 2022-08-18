OBJS	= main.o all_states.o fsm.o event_gen.o
SOURCE	= main.cpp all_states.cpp fsm.cpp event_gen.cpp
HEADER	= state.h all_states.h state_machine.h fsm.h event_gen.h
OUT	= fsm.out
CC	 = g++
FLAGS	 = -g -c -Wall -Werror
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $< -o $@ $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

all_states.o: all_states.cpp
	$(CC) $(FLAGS) all_states.cpp 

state_machine.o: state_machine.cpp
	$(CC) $(FLAGS) state_machine.cpp 

fsm.o: fsm.cpp
	$(CC) $(FLAGS) fsm.cpp 

event_gen.o: event_gen.cpp
	$(CC) $(FLAGS) event_gen.cpp 


clean:
	rm -rf $(OBJS) $(OUT)

.PHONY:
	all clean