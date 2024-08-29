# Minitalk

El proyecto `minitalk` implementa un sistema de comunicación simple entre un cliente y un servidor utilizando señales UNIX. El objetivo es enviar y recibir mensajes entre dos procesos en un entorno UNIX.

## Descripción

El proyecto consiste en dos ejecutables:
- **server**: El servidor, que recibe mensajes del cliente y los muestra en la consola.
- **client**: El cliente, que envía un mensaje al servidor utilizando señales UNIX.

### Características

- **Servidor**: 
  - Se lanza primero y muestra su PID.
  - Puede recibir mensajes de múltiples clientes de manera consecutiva sin necesidad de reiniciar.
  - Recibe y muestra strings enviadas por el cliente.
  
- **Cliente**:
  - Se lanza con dos parámetros: el PID del servidor y la string que se quiere enviar.
  - Envía la string al servidor utilizando solo las señales `SIGUSR1` y `SIGUSR2`.

## Instalación

Este proyecto incluye un `Makefile` para compilar los archivos fuente de manera eficiente. Para compilar el proyecto, asegúrate de tener `make` instalado en tu sistema. Luego, puedes compilar los ejecutables con el siguiente comando:
`make`. Esto generará dos ejecutables llamados client y server.

Para limpiar los archivos objeto y los ejecutables generados durante la compilación, puedes usar:
`make clean`. Para una limpieza completa, incluyendo los archivos binarios, puedes usar:
`make fclean`.

### Uso
1. Lanzar el servidor
Primero, debes iniciar el servidor. Esto mostrará el PID del servidor, que necesitarás para el cliente:
```
./server
```
2. Enviar un mensaje desde el cliente
Con el servidor en ejecución, puedes enviarle un mensaje utilizando el cliente. Necesitarás el PID del servidor y la string que deseas enviar:
```
./client <PID_del_servidor> "Tu mensaje aquí"
```

### Ejemplo
```
bash-server$> ./server
bash-server$> 9854
-------------------------------------------
bash-client$> ./client 9854 "Hola, mundo!"
-------------------------------------------
bash-server$> Hola, mundo!
