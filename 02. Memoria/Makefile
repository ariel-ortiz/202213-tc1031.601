CC=g++ -g

all: ejemplo_memoria ejemplo_apuntadores_referencias errores_memoria ejemplo_memoria_dinamica

ejemplo_memoria: ejemplo_memoria.cpp
	$(CC) -o ejemplo_memoria ejemplo_memoria.cpp

ejemplo_apuntadores_referencias: ejemplo_apuntadores_referencias.cpp
	$(CC) -o ejemplo_apuntadores_referencias ejemplo_apuntadores_referencias.cpp

errores_memoria: errores_memoria.cpp
	$(CC) -o errores_memoria errores_memoria.cpp

ejemplo_memoria_dinamica: ejemplo_memoria_dinamica.cpp
	$(CC) -o ejemplo_memoria_dinamica ejemplo_memoria_dinamica.cpp

clean:
	rm -f ejemplo_memoria ejemplo_apuntadores_referencias errores_memoria ejemplo_memoria_dinamica
