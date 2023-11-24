#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Bienvenido\n");

  int cantidad;
  printf("Ingrese la cantidad de productos: ");
  scanf("%d", &cantidad);

  char validar[4];
  char Validar[] = "Si";
  char validar2[] = "No";
  char nombres[cantidad][50];
  float preciosUnitarios[cantidad];
  int cantidades[cantidad];
  int menu;
  int indiceProducto;

  for (int i = 0; i < cantidad; ++i) {
    printf("\nProducto %d:\n", i + 1);
    printf("Nombre: ");
    scanf("%s", nombres[i]);
    printf("Precio unitario: ");
    scanf("%f", &preciosUnitarios[i]);
    printf("Cantidad comprada: ");
    scanf("%d", &cantidades[i]);
  }
  for (int i = 0; i < cantidad; ++i) {

    printf("%-20s%-20.2f%-20d\n", nombres[i], preciosUnitarios[i],
           cantidades[i]);
  }

  printf("Deseas Modificar o eliminar algun parametro dado \n");
  scanf("%s", validar);

  if (strcmp(validar, Validar) == 0) {
    printf("Que Deseas hacer editar un parametro o elimarlo\n");
    printf("1. Eliminar\n");
    printf("2. Editar\n");
    scanf("%d", &menu);

    switch (menu) {
    case 1: // Eliminar
      printf("Que producto desea Eliminar? ");
      scanf("%d", &indiceProducto);
      if (indiceProducto >= 1 && indiceProducto <= cantidad) {
        // Eliminar el producto seleccionado
        for (int i = indiceProducto - 1; i < cantidad - 1; ++i) {
          strcpy(nombres[i], nombres[i + 1]);
          preciosUnitarios[i] = preciosUnitarios[i + 1];
          cantidades[i] = cantidades[i + 1];
        }

        cantidad--;

        printf("Producto eliminado exitosamente.\n");
      } else {
        printf("Número de producto inválido\n");
      }
      break;
    case 2: // Editar
      printf("Que producto desea editar? ");
      scanf("%d", &indiceProducto);
      if (indiceProducto >= 1 && indiceProducto <= cantidad) {
        printf("Ingrese el nuevo nombre del producto: ");
        scanf("%s", nombres[indiceProducto - 1]);
        printf("Ingrese el nuevo precio del producto: ");
        scanf("%f", &preciosUnitarios[indiceProducto - 1]);
        printf("Ingrese la nueva cantidad del producto: ");
        scanf("%d", &cantidades[indiceProducto - 1]);

      } else {
        printf("Número de producto inválido\n");
      }
      break;
    }
  }
  printf("%-20s%-20s%-20s\n", "Nombre", "Precio", "Cantidad");
  for (int i = 0; i < cantidad; ++i) {

    printf("%-20s%-20.2f%-20d\n", nombres[i], preciosUnitarios[i],
           cantidades[i]);
  }

  return 0;
}
