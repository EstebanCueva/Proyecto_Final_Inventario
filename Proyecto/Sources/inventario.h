#define MAX_VACUNAS 50
#define MAX_NOMBRE 50
#define MAX_CODIGO 10
#define MAX_FECHA 20
#define NOMBRE_ARCHIVO "inventario_vacunas.txt"

struct Vacuna {
  char codigo[MAX_CODIGO];
  char nombre[MAX_NOMBRE];
  int cantidad;
  char fechaExpiracion[MAX_FECHA];
};

void guardarInventario(struct Vacuna inventario[], int numVacunas);
void cargarInventario(struct Vacuna inventario[], int *numVacunas);
void agregarVacuna(struct Vacuna inventario[], int *numVacunas);
void mostrarInventario(struct Vacuna inventario[], int numVacunas);
void buscarVacunaPorNombre(struct Vacuna inventario[], int numVacunas);
void buscarVacunaPorCodigo(struct Vacuna inventario[], int numVacunas);
void actualizarInventario(struct Vacuna inventario[], int numVacunas);
int validarFechaExpiracion(char fechaExpiracion[]);
void eliminarVacuna(struct Vacuna inventario[], int *numVacunas,
                    const char codigoEliminar[]);
