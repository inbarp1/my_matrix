#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
  if(points->lastcol == points->cols){
    grow_matrix(points,points->cols+1);
  }
  points->m[0][points->lastcol] = x;
  points->m[1][points->lastcol] = y;
  points->m[2][points->lastcol] = z;
  points->m[3][points->lastcol] = 1;
  points->lastcol++;
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
          int x0, int y0, int z0, int x1, int y1, int z1
Returns: 
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points, 
	       double x0, double y0, double z0, 
	       double x1, double y1, double z1) {
  add_point(points,x0,y0,z0);
  add_point(points,x1,y1,z1);
}

/*======== void draw_lines() ==========
Inputs:   struct matrix * points
         screen s
         color c 
Returns: 
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines( struct matrix * points, screen s, color c) {
  int col, x0, y0, x1, y1;
  col=0;
  while(col<points->lastcol){
    x0 = points->m[0][col];
    y0 = points->m[1][col];
    col++;
    x1 = points->m[0][col];
    y1 = points->m[1][col];
    draw_line(x0,y0,x1,y1,s,c);
    col++;
  }   
}

int octant_num(int x0, int y0, int x1, int y1){
  double s = ((double)y1-y0)/(x1-x0);
  if(x0==x1 || s>=1){
    return 2;
  }
  if(s>=0){
    return 1;
  }
  if(s>=-1){
    return 8;
  }
  return 7;
}
/* 
//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if(x0>x1){
    int X= x0;
    int Y =y0;
    x0=x1;
    x1=X;
    y0=y1;
    y1=Y;
  }
  else if(x0==x1 && y0>y1){
    int Y =y0;
    y0=y1;
    y1=Y;
  }
  //switches the values if neccesary
  //bc we always draw the line left to right
  int x= x0;
  int y =y0;
  int A = y1-y0;
  int B= -(x1-x0);
  int d;  
  int octant = octant_num(x0,y0,x1,y1);

  if(octant == 1){
    d = 2 * A + B;
    while(x <= x1){
      plot(s,c,x,y);
      if(d > 0){
	y++;
	d += 2 * B;
      }
      x++;
      d += 2 * A;
    }
  }
  if(octant == 8){
    d = 2 * A - B;
    while(x <= x1){
      plot(s,c,x,y);
      if(d < 0){
	y--;
	d += 2 * B;
      }
      x++;
      d += 2 * A;
    }
  }
  if (octant == 2){
    d = A + 2 * B;
    while(y <= y1){
      plot(s,c,x,y);
      if(d < 0){
	x++;
	d += 2 * A;
      }
      y++;
      d += 2 * B;
    }
  }
  if (octant == 7){
    d = A - 2 * B;
    while(y >= y1){
      plot(s,c,x,y);
      if(d > 0){
	x++;
	d += 2 * A;
      }
      y--;
      d += 2 * B;
    }
  }  

}
*/

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //swap x0,y0 and x1,y1 if necessary
  if (x0>x1) {
    int temp=x0;
    x0=x1;
    x1=temp;
    temp=y0;
    y0=y1;
    y1=temp;
  }else if (x0==x1 && y0>y1) {
    int temp=y0;
    y0=y1;
    y1=temp;
  }
  
  int x,y,A,B,d;
  x=x0;
  y=y0;
  A=y1-y0;
  B=-(x1-x0);

  if (A*B<=0) {
    //positive slope octant 1
    if (abs(A)<=abs(B)) {
      d=2*A+B;
      while (x<=x1) {
	plot(s,c,x,y);
	if (d>0) {
	  y++;
	  d+=2*B;
	}
	x++;
	d+=2*A;
      }
    }

    else if (abs(A)>abs(B)) {
      d=A+2*B;
      while(y<=y1) {
	plot(s,c,x,y);
	if (d<0) {
	  x++;
	  d+=2*A;
	}
	y++;
	d+=2*B;
      }
    }
  }
  else {
    if (abs(A)<=abs(B)) {
      //octant 8, -1<m<0
  
      d=2*A-B;
      while (x<=x1) {
	plot(s,c,x,y);
	if (d<0) {
	  y--;
	  d-=2*B;
	}
	x++;
	d+=2*A;
      }
    }
    else if (abs(A)>abs(B)) {
      //octant 7, m<-1
      d=A-2*B;
      while (y>=y1) {
	plot(s,c,x,y);
	if (d>0) {
	  x++;
	  d+=2*A;
	}
	y--;
	d-=2*B;
      }
    }
  }
}
