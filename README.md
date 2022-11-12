# PROCESADOR ARC
## Compilación 
Para poder compilar el procesador únicamente debes
introducir el comando 
```bash
make
```
Desde la carpeta raíz del proyecto y lo ejecutas con
```bash
make run
```
## Consideraciones de código 
### 1. La primera ejecución debe ser una burbuja 
Es decir, siempre debe ser 
``` bash
addi x0,x0,0
```
### 2. Branching
Para los saltos, el campo de immGen debe ser el número de la línea a saltar multiplicado por 4
Esto sin ejecutar las etiquetas de RiscV

### 3. Culminación 
El Instruction Memory considera una línea vacía como
El fin del archivo. Por lo que hay que tener cuidado 
Al manejarlo, sino queda en bucle infinito.
