#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  clear_screen(s);
  color c;

  printf("\n TESTING MATRIX STUFF\n");
  struct matrix * a=new_matrix(4,4);
  struct matrix * b=new_matrix(4,3);
  a->lastcol=4;
  b->lastcol=3;
  
  
  printf("\nTesting identity matrix:\n");
  ident(a);
  print_matrix(a);

  a->m[0][0]=1;
  a->m[0][1]=3;
  a->m[2][0]=4;
  a->m[1][2]=7;
  a->m[3][1]=9;
  a->m[2][2]=5;
  printf("\nMatrix A with values \n");
  print_matrix(a);
 
  printf("\nTesting multiplying matrix A with identity matrix\n");
  matrix_mult(b,a);
  print_matrix(a);
  a->m[0][0]=1;
  a->m[0][1]=3;
  a->m[2][0]=4;
  a->m[1][2]=7;
  a->m[3][1]=9;
  a->m[2][2]=5;

  printf("\n Testing multiplying matrix A by matrix B \n");
  b->m[0][2]=5;
  b->m[1][0]=6;
  b->m[0][0]=2;
  b->m[1][2]=3;
  b->m[2][2]=7;
  print_matrix(b);
  printf("\nmultipled by\n");
  print_matrix(a);
  matrix_mult(b,a);
  printf("\nequals\n");
  print_matrix(a);

  free_matrix(a);
  free_matrix(b);
  
  struct matrix *edges;

  edges = new_matrix(4, 4);

  c.red = 255;
  
  add_edge(edges,0,350,0,50,400,0);
  add_edge(edges,50,400,0,100,350,0);
  add_edge(edges,0,350,0,100,350,0);

  add_edge(edges,100,400,0,150,350,0);
  add_edge(edges,150,350,0,200,400,0);
  add_edge(edges,100,400,0,200,400,0);
 
  add_edge(edges,200,350,0,250,400,0);
  add_edge(edges,250,400,0,300,350,0);
  add_edge(edges,200,350,0,300,350,0);

  add_edge(edges,300,400,0,350,350,0);
  add_edge(edges,350,350,0,400,400,0);
  add_edge(edges,300,400,0,400,400,0);
  
  add_edge(edges,400,350,0,450,400,0);
  add_edge(edges,450,400,0,500,350,0);
  add_edge(edges,400,350,0,500,350,0);

  draw_lines(edges, s, c);
  
  free_matrix(edges);
  edges = new_matrix(4, 4);

  c.red=0;
  c.blue=255;

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
