#include <stdio.h>

#include "screen.h"

FILE* stdin = (FILE*)-1;
FILE* stdout = (FILE*)-2;
FILE* stderr = (FILE*)-3;

FILE* fopen(const char * filename, const char * mode) {
	write_str_halt("fopen\n");
	return NULL;
}

int fclose(FILE* stream) {
	write_str_halt("fclose\n");
	return -1;
}

size_t fread(void * ptr, size_t size, size_t count, FILE* stream) {
	write_str_halt("fread\n");
	return -1;
}

size_t fwrite(const void * ptr, size_t size, size_t count, FILE* stream) {
	if (stream == stdout || stream == stderr) {
		write_str_n(ptr, size * count);
		return count;
	}
	else {
		write_str("fwrite to: ");
		write_int((long)stream);
		write_str("\n");
		write_str_halt(":(");
		return 0;
	}
}

int sprintf(char * str, const char * format, ...) {
	write_str_halt("sprintf\n");
	return -1;
}

int fputc(int character, FILE * stream) {
	if (stream == stdout || stream == stderr) {
		write_char(character);
		return character;
	} else {
		write_str_halt("fputc to: ");
		write_int((long)stream);
		write_str("\n");
		write_str_halt(":(");
		return 0;
	}
}

int fputs(const char * str, FILE * stream) {
	if (stream == stdout || stream == stderr) {
		write_str(str);
		return 1;
	} else {
		write_str_halt("fputs to: ");
		write_int((long)stream);
		write_str("\n");
		write_str_halt(":(");
		return 0;
	}
}

int fflush(FILE * stream) {
	if (stream == stdout || stream == stderr)
		return 0; // do nothing
	
	write_str_halt("fflush on: ");
	write_int((long)stream);
	write_str("\n");
	write_str_halt(":(");
}

int feof(FILE * stream) {
	write_str_halt("feof\n");
	return -1;
}

int ferror(FILE * stream) {
	write_str_halt("fputc\n");
	return -1;
}

int putchar(int character) {
	write_char(character);
	return character;
}