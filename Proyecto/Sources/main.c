#include "inventario.h"
#include <stdio.h>

int main() {
  struct Vacuna inventario[MAX_VACUNAS];
  int numVacunas = 0;
  int opcion;
  int posicion;

  cargarInventario(inventario, &numVacunas);

  do {
    printf("\nMenú:\n");
    printf("1. Agregar vacuna\n");
    printf("2. Mostrar inventario\n");
    printf("3. Buscar vacuna por nombre\n");
    printf("4. Buscar vacuna por código\n");
    printf("5. Actualizar inventario\n");
    printf("6. Eliminar vacuna\n");
    printf("7. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      agregarVacuna(inventario, &numVacunas);
      break;
    case 2:
      mostrarInventario(inventario, numVacunas);
      break;
    case 3:
      buscarVacunaPorNombre(inventario, numVacunas);
      break;
    case 4:
      buscarVacunaPorCodigo(inventario, numVacunas);
      break;
    case 5:
      actualizarInventario(inventario, numVacunas);
      break;
    case 6: {
      char codigoEliminar[MAX_CODIGO];
      printf("Ingrese el código de la vacuna a eliminar: ");
      scanf("%s", codigoEliminar);
      eliminarVacuna(inventario, &numVacunas, codigoEliminar);
    } break;
    case 7:
      printf("Saliendo del programa.\n");
      break;
    default:
      printf("Opción no válida. Por favor, seleccione una opción válida.\n");
    }
  } while (opcion != 7);

  return 0;
}
