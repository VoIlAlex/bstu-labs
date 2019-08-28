/* File: kplot.c
 *
 *	 	Commented examples of graph drawing with
 *		the koolplot library, version 1.1.
 *
 * Date:	July 2005
 * 
 * This file is in the public domain and can be used without any
 * restriction.
 */

#include "koolplot.h"

/* Function prototypes. They give the form (signature) of functions
 * that can be used in the code below in main().
 */
double sinc(double x);
double tanLessThan(double x, double max);

const double DEG_TO_RAD = M_PI / 180;

int main()
{
	/* give range of X axis, then define Y as x^2 + 3x + 3 */
	plotdata x(-5.0, 2.0),  
			 y = x*x + 3*x + 3;

	/* Plot the graph */
    plot(x, y); 


	/**********************************************************/
	/* Points may be entered one at a time into the axes data */
	/* .. a "point-by-point" data entry method.               */

 	/* Erase previous data in axes X and Y so they can be re-used.*/	
	clear(x);
	clear(y); 
	
	/* 
	 * Enter each curve point as a coordinate pair using the plotdata 
	 * insertion operator "<<" ( or use the "point" function instead).
	 */
	for (int i = -180 ; i <= 180; i++)
	{
		double y_value = i / 180.0 + cos(DEG_TO_RAD * i);
		x << i;
		y << y_value;
		
		/* "<<" inserts a new value into the plot data.
		 * You could instead use the point function, with
		 * point(x, y, x_value, y_value); if you prefer.
		 */
	}
	
	/* Graph drawn in blue colour (Each data point is joined to
	 * the preceding and following points, forming the curve.). 
	 */
    plot(x, y, BLUE);
		

	/**********************************************/	
	/* Plot function y = sin(x) between 0 and 360 */
	x = plotdata(0.0, 360.0); 
	y = sin(x * DEG_TO_RAD);
	/* Give the function name to be printed as the window label */
	plot(x, y, CRIMSON, "sin(x)");


	/*****************************************************************/
	/* Plot user-defined unary function f(x) = sinc between -6 and 6 */
	x 	 = plotdata(-6.0, 6.0);
	f(x) = sinc;  	  /* sinc is defined at the bottom of this file. */
	plot(x, f(x), "sinc(x)");
	

	/*****************************************************************/      
	/* Plot user-defined binary function y = tanLessThan(x, max)     */
	/* Read tanLessThan code to see how values > max are not plotted */
	x = plotdata(-270.0, 270.0); 
	f2(x) = tanLessThan;
	/* Do not plot y values greater than 20 */
	plot(x, f2(x, 20), "tan(x)", REDRED);


	/*********************************************************************/
	/* Plot 2 functions on same graph (could be any number of functions) */
	/* Define Y as two functions */
	clear(x); /* Re-use old X, but change its range to -75..245 degrees  */
	x << plotdata(-80.0, 255.0);
	y = f2(x, 3); /* First function */
	
	breakplot(x, y);    /* Break the plot between functions */
	/* You could also use x << NOPLOT; y << NOPLOT; instead.*/
	
	/* Define second function (2cos(2x)) on same range "point-by-point"  */
	for(int i = -80; i <= 255; i++)
	{
		x << i;
		y << 2 * cos(2 * i * DEG_TO_RAD);
	}

	plot(x, y, "tan(x) and 2cos(2x)", BLUEBLUE);
	

	/***********************************************************
	 * You can also use the << operator to insert data at the end
	 * of already entered plot data in order to draw 2 or more
	 * functions.
	 *
	 * Use NOPLOT to separate different function data in both X 
	 * and Y, but be careful of the order of insertion! Each NOPLOT
	 * in X must correspond to a NOPLOT in Y.
	 *
	 * Koolplot does not plot NOPLOT values.
	 */
	x =  plotdata(-315.0, 45.0);
	y = sin(x * DEG_TO_RAD);
    plotdata z = cos(x * DEG_TO_RAD);
    plotdata p = sin(2 * (x - 45) * DEG_TO_RAD);
    plotdata q = cos(2 * x * DEG_TO_RAD);
    setColor(x, y, CRIMSON); // Will also break the plot
	x << plotdata(-315.0, 45.0);
	y << z;  
    setColor(x, y, DARKORANGE );
	x << plotdata(-315.0, 45.0);
	y << p;  
    setColor(x, y, BLUEBLUE );
	x << plotdata(-315.0, 45.0);
	y << q;  
    
    // Default plot colour is green
	plot(x, y, COLOR(0,160,0), 
         " sin(x) -green-, cos(x) -red-, sin(2x - 45) -orange-, cos(2x) -blue-");

	/*************************************************/


	return 0;
}


/*
 * Sinc: user-defined unary function y = sin(PI + x) / (PI * x),
 * except for x = 0 when y = 1.
 * Sinc is an important function in science and engineering.
 */
double sinc(double x)
{
	if (fabs(x) < 0.0001)
		return 1.0;
	else 
		return sin(M_PI * x) / (M_PI * x);
}


/*
 * tanLessThan: User-defined binary function.
 *
 * Returns tan(x) values below max.
 *
 * - Any value of tan(x) above "max" is returned as NOPLOT (a special 
 *   value known as NaN (not a number) in C).
 * - This is done because tan x grows very fast towards infinity (or minus
 *   infinity) at some values. Of course infinity cannot be plotted!
 * - Koolplot never attempts to draw NOPLOT values.
 */
double tanLessThan(double x, double max)
{	 
	double y = tan(x * DEG_TO_RAD);
	
	if(fabs(y) > max)
		return NOPLOT; // This point will not be on the graph
	else
		return y;
}

