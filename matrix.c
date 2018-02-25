#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"


/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m 
Returns: 
print the matrix
*/
void print_matrix(struct matrix *m) {
  int row, col;
  row=0;
  col=0;
  while(row<m->rows){
    while(col<m->lastcol){
      printf("\t%06.2lf|",(m->m)[row][col]);
      col++;
    }
    printf("\n");
    row++;
    col=0;
  }
}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix
Returns: 
turns m in to an identity matrix
*/
void ident(struct matrix *m) {
  int row, col;
  row=0;
  col=0;
  while(row < m->rows){
    while(col < m->cols){
      if(row == col){
	m->m[row][col] = 1;
      }
      else{
	m->m[row][col] = 0;
      }
      col++;
    }
    col=0;
    row++;
  }
  m->lastcol = m->cols;
}


/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 
a*b -> b
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
  int r_one, r_two,c_one, c_two;
  int temp;
  r_one = 0;
  r_two = 0;
  c_one = 0;
  c_two = 0;
  temp = 0;

  struct matrix * temporary_copy = new_matrix(b->rows,b->cols);

  while(r_one < a->rows){
    while(c_two < b->cols){
      while(r_two < b->rows){
	temp += a->m[r_one][r_two] * b->m[r_two][c_two];
	r_two++;
      }
      temporary_copy->m[r_one][c_two] = temp;
      c_two++;
      r_two = 0;
      temp = 0;
    }
    c_two = 0;
    r_one++;
  }
  copy_matrix(temporary_copy,b);
  free_matrix(temporary_copy);    
}



/*===============================================
  These Functions do not need to be modified
  ===============================================*/

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols 
Returns: 
Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)... 
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i=0;i<rows;i++) {
    tmp[i]=(double *)malloc(cols * sizeof(double));
  }

  m=(struct matrix *)malloc(sizeof(struct matrix));
  m->m=tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = 0;

  return m;
}


/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m 
Returns: 
1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {

  int i;
  for (i=0;i<m->rows;i++) {
    free(m->m[i]);
  }
  free(m->m);
  free(m);
}


/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols 
Returns: 
Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {
  
  int i;
  for (i=0;i<m->rows;i++) {
    m->m[i] = realloc(m->m[i],newcols*sizeof(double));
  }
  m->cols = newcols;
}


/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 
copy matrix a to matrix b
*/
void copy_matrix(struct matrix *a, struct matrix *b) {

  int r, c;

  for (r=0; r < a->rows; r++) 
    for (c=0; c < a->cols; c++)  
      b->m[r][c] = a->m[r][c];  
}
