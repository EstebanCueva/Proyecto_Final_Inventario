#include "inventario.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void obtenerFechaActual(char fechaActual[]) {
  time_t tiempoActual;
  struct tm *infoTiempo;

  time(&tiempoActual);
  infoTiempo = localtime(&tiempoActual);

  strftime(fechaActual, MAX_FECHA, "%d/%m/%Y", infoTiempo);
}

int verificarFechaExpiracion(const char fechaExpiracion[]) {
  char fechaActual[MAX_FECHA];
  obtenerFechaActual(fechaActual);

  if (strcmp(fechaExpiracion, fechaActual) >= 0) {
    return 1;
  } else {
    return 0;
  }
}

void guardarInventario(struct Vacuna inventario[], int numVacunas) {
  FILE *archivo = fopen(NOMBRE_ARCHIVO, "w");

  if (archivo == NULL) {
    printf("Error al abrir el archivo para escritura.\n");
    return;
  }

  for (int i = 0; i < numVacunas; i++) {
    fprintf(archivo, "%s %s %d %s\n", inventario[i].codigo,
            inventario[i].nombre, inventario[i].cantidad,
            inventario[i].fechaExpiracion);
  }

  fclose(archivo);
}

void actualizarInventario(struct Vacuna inventario[], int numVacunas) {
  char codigoActualizacion[MAX_CODIGO];
  printf("Ingrese el código de la vacuna a actualizar: ");
  scanf("%s", codigoActualizacion);

  for (int i = 0; i < numVacunas; i++) {
    if (strcmp(inventario[i].codigo, codigoActualizacion) == 0) {
      printf("Vacuna encontrada:\n");
      printf("Código: %s\n", inventario[i].codigo);
      printf("Nombre: %s\n", inventario[i].nombre);
      printf("Cantidad actual: %d\n", inventario[i].cantidad);

      int nuevaCantidad;
      printf("Ingrese la nueva cantidad de vacunas disponibles: ");
      scanf("%d", &nuevaCantidad);

      if (nuevaCantidad < 0) {
        printf("Error: La cantidad no puede ser negativa.\n");
        return;
      }

      inventario[i].cantidad = nuevaCantidad;

      if (verificarFechaExpiracion(inventario[i].fechaExpiracion)) {
        guardarInventario(inventario, numVacunas);
        printf("Inventario actualizado con éxito.\n");
      } else {
        printf("Error: La fecha de expiración no es válida. Inventario no "
               "actualizado.\n");
      }

      return;
    }
  }

  printf("No se encontró ninguna vacuna con ese código para actualizar.\n");
}

void cargarInventario(struct Vacuna inventario[], int *numVacunas) {
  FILE *archivo = fopen(NOMBRE_ARCHIVO, "r");

  if (archivo == NULL) {
    printf("No se encontró el archivo de inventario. Creando uno nuevo.\n");
    return;
  }

  while ((*numVacunas < MAX_VACUNAS) &&
         fscanf(archivo, "%s %s %d %s", inventario[*numVacunas].codigo,
                inventario[*numVacunas].nombre,
                &inventario[*numVacunas].cantidad,
                inventario[*numVacunas].fechaExpiracion) == 4) {
    (*numVacunas)++;
  }

  fclose(archivo);
}

void agregarVacuna(struct Vacuna inventario[], int *numVacunas) {
  if (*numVacunas < MAX_VACUNAS) {
    printf("Ingrese el código de la vacuna: ");
    scanf("%s", inventario[*numVacunas].codigo);

    printf("Ingrese el nombre de la vacuna: ");
    scanf("%s", inventario[*numVacunas].nombre);

    printf("Ingrese la cantidad de vacunas disponibles: ");
    scanf("%d", &inventario[*numVacunas].cantidad);

    printf("Ingrese la fecha de expiración de la vacuna (DD/MM/YYYY): \n");
    char fechaActual[MAX_FECHA];
    obtenerFechaActual(fechaActual);
    printf("Fecha actual: %s\n", fechaActual);
    scanf("%s", inventario[*numVacunas].fechaExpiracion);

    if (verificarFechaExpiracion(inventario[*numVacunas].fechaExpiracion)) {
      (*numVacunas)++;
      guardarInventario(inventario, *numVacunas);
      printf("Vacuna agregada con éxito.\n");
    } else {
      printf(
          "Error: La fecha de expiración no es válida. Vacuna no agregada.\n");
    }
  } else {
    printf("Ya se alcanzó el límite de vacunas en el inventario.\n");
  }
}

void mostrarInventario(struct Vacuna inventario[], int numVacunas) {
  printf("\nInventario de Vacunas:\n");
  for (int i = 0; i < numVacunas; i++) {
    printf("Vacuna %d:\n", i + 1);
    printf("Código: %s\n", inventario[i].codigo);
    printf("Nombre: %s\n", inventario[i].nombre);
    printf("Cantidad: %d\n", inventario[i].cantidad);
    printf("Fecha de Expiración: %s\n", inventario[i].fechaExpiracion);
    printf("------------------------\n");
  }
}

void buscarVacunaPorNombre(struct Vacuna inventario[], int numVacunas) {
  char nombreBusqueda[MAX_NOMBRE];
  printf("Ingrese el nombre de la vacuna a buscar: ");
  scanf("%s", nombreBusqueda);

  int encontrada = 0;
  for (int i = 0; i < numVacunas; i++) {
    if (strcmp(inventario[i].nombre, nombreBusqueda) == 0) {
      printf("Vacuna encontrada:\n");
      printf("Código: %s\n", inventario[i].codigo);
      printf("Nombre: %s\n", inventario[i].nombre);
      printf("Cantidad: %d\n", inventario[i].cantidad);
      printf("Fecha de Expiración: %s\n", inventario[i].fechaExpiracion);
      printf("------------------------\n");
      encontrada = 1;
      break;
    }
  }

  if (!encontrada) {
    printf("No se encontró ninguna vacuna con ese nombre.\n");
  }
}

void buscarVacunaPorCodigo(struct Vacuna inventario[], int numVacunas) {
  char codigoBusqueda[MAX_CODIGO];
  printf("Ingrese el código de la vacuna a buscar: ");
  scanf("%s", codigoBusqueda);

  int encontrada = 0;
  for (int i = 0; i < numVacunas; i++) {
    if (strcmp(inventario[i].codigo, codigoBusqueda) == 0) {
      printf("Vacuna encontrada:\n");
      printf("Código: %s\n", inventario[i].codigo);
      printf("Nombre: %s\n", inventario[i].nombre);
      printf("Cantidad: %d\n", inventario[i].cantidad);
      printf("Fecha de Expiración: %s\n", inventario[i].fechaExpiracion);
      printf("------------------------\n");
      encontrada = 1;
      break;
    }
  }

  if (!encontrada) {
    printf("No se encontró ninguna vacuna con ese código.\n");
  }
}

void eliminarVacuna(struct Vacuna inventario[], int *numVacunas,
                    const char codigoEliminar[]) {
  int posicion = -1;

  for (int i = 0; i < *numVacunas; i++) {
    if (strcmp(inventario[i].codigo, codigoEliminar) == 0) {
      posicion = i;
      break;
    }
  }

  if (posicion != -1) {
    for (int i = posicion; i < *numVacunas - 1; i++) {
      strcpy(inventario[i].codigo, inventario[i + 1].codigo);
      strcpy(inventario[i].nombre, inventario[i + 1].nombre);
      inventario[i].cantidad = inventario[i + 1].cantidad;
      strcpy(inventario[i].fechaExpiracion, inventario[i + 1].fechaExpiracion);
    }

    (*numVacunas)--;
    guardarInventario(inventario, *numVacunas);
    printf("Vacuna con código %s eliminada con éxito.\n", codigoEliminar);
  } else {
    printf("Error: No se encontró ninguna vacuna con ese código.\n");
  }
}
