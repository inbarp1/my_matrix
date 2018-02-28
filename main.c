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

 struct matrix * m=new_matrix(4,4);
  struct matrix * n=new_matrix(4,3);
  m->lastcol=4;
  n->lastcol=3;
  

  printf("\ntesting ident(m)\n");
  ident(m);
  print_matrix(m);

  n->m[0][0]=4;
  n->m[0][1]=37;
  n->m[3][2]=9;
  n->m[2][2]=10;
  printf("\nmatrix with values\n");
  print_matrix(n);

  printf("\ntesting matrix_mult with identity matrix\nbefore:\n");
  print_matrix(n);
  matrix_mult(m,n);
  printf("\nafter:\n");
  print_matrix(n);

  printf("\ntesting matrix_mult with not identity matrix\n");
  m->m[0][2]=14;
  m->m[1][0]=8;
  m->m[2][2]=17;
  print_matrix(m);
  printf("\nmultipled by\n");
  print_matrix(n);
  matrix_mult(m,n);
  printf("\nresult\n");
  print_matrix(n);

  free_matrix(m);
  free_matrix(n);
  

  struct matrix *edges;
  edges = new_matrix(4, 1);

  c.red = 255;
  c.green = 215;
  c.blue = 0;
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
  save_ppm(s,"image.ppm");
  display(s);
  free_matrix( edges );
}
