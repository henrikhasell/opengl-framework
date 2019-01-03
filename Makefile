pong:
	gcc -opong -O3 application.c main.c pong.c vector.c -lSDL2 -lGL -lm

.PHONY: clean
clean:
	$(RM) -f pong
