all: Quest_3

Quest_3: main_executable_module.o data_io.o data_process.o data_stat.o decision.o
	gcc main_executable_module.o data_io.o data_process.o data_stat.o decision.o -o ../../build/Quest_3 -lm

main_executable_module.o: ../../src/main_executable_module/main_executable_module.c
	gcc -c -o main_executable_module.o ../../src/main_executable_module/main_executable_module.c

data_io.o: ../../src/data_libs/data_io.c
	gcc -c -o data_io.o ../../src/data_libs/data_io.c

data_process.o: ../../src/data_module/data_process.c
	gcc -c -o data_process.o ../../src/data_module/data_process.c

data_stat.o: ../../src/data_libs/data_stat.c
	gcc -c -o data_stat.o ../../src/data_libs/data_stat.c

decision.o: ../../src/yet_another_decision_module/decision.c
	gcc -c -o decision.o ../../src/yet_another_decision_module/decision.c

clean:
	rm -f *.o Quest_3

rebuild: clean all
