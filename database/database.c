#include <stdio.h>
#include <mysql.h>

/*
gcc database.c -o ejemplo `mysql_config --cflags --libs`
*/

int main(void){
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *server = "192.168.22.197";
    const char *user = "testc";
    const char *password = "testc.2025";
    const char *database = "testc";

    // Inicializa estructura
    conn = mysql_init(NULL);

    // Conexión
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "Error al conectar: %s\n", mysql_error(conn));
        return 1;
    }

    printf("Conexión exitosa a MySQL!\n");

    // Ejecutar consulta
    if (mysql_query(conn, "SELECT * FROM alumno")) {
        fprintf(stderr, "Error en consulta: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    res = mysql_store_result(conn);
    int num_filas = mysql_num_fields(res);

    // Mostrar resultados
    while ((row = mysql_fetch_row(res))) {
        for(int i = 0; i < num_filas; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    
    // Obtener ID autoincrement de la tabla
    int id = mysql_insert_id(conn);
    
    // --- Crear consulta INSERT ---
    char query[256];   // buffer para la consulta
    snprintf(query, sizeof(query), "INSERT INTO alumno VALUES (%d, 'Juan', 67)", id);

    // --- Ejecutar la consulta ---
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error en INSERT: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }
    printf("Insert realizado correctamente.\n");

    // Liberar memoria y cerrar conexión  
    mysql_free_result(res);
    mysql_close(conn);

    return 0;

}