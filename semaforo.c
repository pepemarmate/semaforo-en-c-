#include <stdio.h>
#include <unistd.h> 


struct LuzSemaforo {
	char color[10];
	int tiempo;
};

// Función para mostrar el estado del semáforo
void mostrarSemaforo(struct LuzSemaforo luzRoja, struct LuzSemaforo luzAmarilla, struct LuzSemaforo luzVerde) {
	printf("Luz Roja: %s durante %d segundos\n", luzRoja.color, luzRoja.tiempo);
	printf("Luz Amarilla: %s durante %d segundos\n", luzAmarilla.color, luzAmarilla.tiempo);
	printf("Luz Verde: %s durante %d segundos\n", luzVerde.color, luzVerde.tiempo);
}

int main() {
	struct LuzSemaforo luzRoja = {"Rojo", 5};        
	struct LuzSemaforo luzAmarilla = {"Amarillo", 2};  
	struct LuzSemaforo luzVerde = {"Verde", 5};      
	
	int intervalo;
	
	printf("Configuración predeterminada del semáforo:\n");
	mostrarSemaforo(luzRoja, luzAmarilla, luzVerde);
	
	printf("Ingrese el nuevo tiempo para la luz roja: ");
	scanf("%d", &intervalo);
	luzRoja.tiempo = intervalo;
	
	printf("Ingrese el nuevo tiempo para la luz amarilla: ");
	scanf("%d", &intervalo);
	luzAmarilla.tiempo = intervalo;
	
	printf("Ingrese el nuevo tiempo para la luz verde: ");
	scanf("%d", &intervalo);
	luzVerde.tiempo = intervalo;
	
	printf("\nConfiguración actualizada del semáforo:\n");
	mostrarSemaforo(luzRoja, luzAmarilla, luzVerde);
	
	printf("\nSimulación del semáforo:\n");
	
	while (1) {
		printf("Luz %s encendida\n", luzRoja.color);
		sleep(luzRoja.tiempo);
		
		printf("Luz %s encendida\n", luzAmarilla.color);
		sleep(luzAmarilla.tiempo);
		
		printf("Luz %s encendida\n", luzVerde.color);
		sleep(luzVerde.tiempo);
	}
	
	return 0;
}
