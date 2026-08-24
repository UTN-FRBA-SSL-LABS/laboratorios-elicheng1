#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_compra_con_descuento(){
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p={"Pan", 200, 3};
    Producto L={"Leche", 350, 2};
    carrito_agregar(&c, p);
    carrito_agregar(&c, L);
    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}
/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_agregar_hasta_llenar(){
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    Producto x = {"Manteca", 350, 1};
    Producto y = {"Yogurt", 350, 1};
    Producto z = {"Crema", 350, 1};
    Producto t = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    carrito_agregar(&c, x);
    carrito_agregar(&c, y);
    carrito_agregar(&c, z);
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));       
    ASSERT_IGUAL(0, carrito_agregar(&c, t));            
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c)); 
}
/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
