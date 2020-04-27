build: my_bib

my_bib: o1 o2 o3 o4 o5 o6 o7 o8 o9 o10 o11 o12 o13 o14
	gcc -shared so_fopen.o so_fclose.o so_fgetc.o so_fputc.o so_fread.o so_fwrite.o so_fseek.o so_ftell.o so_fflush.o so_fileno.o so_feof.o so_ferror.o so_popen.o so_pclose.o -o libso_stdio.so


o1:
	gcc -fPIC -c so_fopen.c
o2:
	gcc -fPIC -c so_fclose.c
o3:
	gcc -fPIC -c so_fgetc.c
o4:
	gcc -fPIC -c so_fputc.c
o5:
	gcc -fPIC -c so_fread.c
o6:
	gcc -fPIC -c so_fwrite.c
o7:
	gcc -fPIC -c so_fseek.c
o8:
	gcc -fPIC -c so_ftell.c
o9:
	gcc -fPIC -c so_fflush.c
o10:
	gcc -fPIC -c so_fileno.c
o11:
	gcc -fPIC -c so_feof.c
o12:
	gcc -fPIC -c so_ferror.c
o13:
	gcc -fPIC -c so_popen.c
o14:
	gcc -fPIC -c so_pclose.c

clean:
	rm -rf *.o *.so main
