ExcelTextual:lexTP.c GramaticaTP.c Excel.c
	gcc -o ExcelTextual lexTP.c GramaticaTP.c Excel.c -lm

lexTP.c:lexTP.l
	flex -o lexTP.c lexTP.l

GramaticaTP.h GramaticaTP.c:GramaticaTP.y
	bison -d -o GramaticaTP.c GramaticaTP.y
