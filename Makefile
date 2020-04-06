#Choix du compilateur.
CP = gcc 
#choix des inclusions


proGM:obj/proGM.o obj/libtext.o obj/libmat.o obj/kuhn.o obj/etape0.o obj/etape1.o obj/etape2.o obj/etape3.o 
	$(CP) $^ -o $@ -lm
install:proGM
	cp proGM /usr/bin/proGM
	cp doc/proGM.1 /usr/share/man/fr/man1/proGM.1
obj/proGM.o: src/proGM.c
	$(CP) $^ -o $@ -c
obj/libtext.o: src/libtext.c
	$(CP) $^ -o $@ -c
obj/libmat.o: src/libmat.c
	$(CP) $^ -o $@ -c
obj/kuhn.o: src/kuhn.c
	$(CP) $^ -o $@ -c
obj/etape0.o: src/etape0.c
	$(CP) $^ -o $@ -c
obj/etape1.o: src/etape1.c
	$(CP) $^ -o $@ -c
obj/etape2.o: src/etape2.c
	$(CP) $^ -o $@ -c
obj/etape3.o: src/etape3.c
	$(CP) $^ -o $@ -c
clean:
	rm -vf obj/*
	rm -vf proGM
	rm -vf src/*~
uninstall:
	rm /usr/bin/proGM
	rm /usr/share/man/proGM
