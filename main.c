#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  printf("\nTESTING MATRIX FUNCTIONS\n");

  struct matrix * a  = new_matrix(4, 4);
  struct matrix * b = new_matrix(4,4);
  a->lastcol=4;
  b->lastcol=4;
  

  printf("\n Testing ident(a):\n");
  ident(a);
  print_matrix(a);

  a->m[0][0]=5;
  a->m[0][1]=65;
  a->m[3][2]=15;
  a->m[2][2]=25;

  printf("\n Matrix a with values:\m");
  print_matrix(a);

  printf("\nTesting matrix_mult with identity matrix\nbefore:\n");
  matrix_mult(b,a);
  print_matrix(n);

  printf("\nTesting matrix_mult with different  matrix\n");
  b->m[0][2]=1;
  b->m[1][0]=3;
  b->m[3][1]=2
  b->m[2][2]=5;
  print_matrix(b);
  printf("\n Multipled by\n");
  print_matrix(a);
  matrix_mult(b,a);
  printf("\nEquals:\n");
  print_matrix(a);


  free_matrix(a);
  free_matrix(b);

  struct matrix *edges;
  edges = new_matrix(4, 1);

  c.red = 75;
  c.green = 0;
  c.blue = 100;
  add_edge(edges, 100, 175, 0, 100, 375, 0);
  add_edge(edges, 400, 175, 0, 400, 375, 0);
  add_edge(edges, 100, 175, 0, 250, 100, 0);
  add_edge(edges, 400, 175, 0, 250, 100, 0);
  add_edge(edges, 250, 100, 0, 250, 300, 0);
  add_edge(edges, 100, 375, 0, 250, 300, 0);
  add_edge(edges, 400, 375, 0, 250, 300, 0);
  add_edge(edges, 100, 375, 0, 250, 450, 0);
  add_edge(edges, 400, 375, 0, 250, 450, 0);

  draw_lines(edges, s, c);
  free(edges);


  
  draw_lines(edges, s, c);
  save_ppm(s,"image.ppm");
  display(s);
  free_matrix( edges );
}
