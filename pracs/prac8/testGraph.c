/* Look familiar? good!
 *
 * Question from 2013s2
 *
 * Given an st array.c, complete drawAllPaths, which given
 * a source, st and ncities of the st arrays, prints all
 * connecting paths from the src to all cities
 *
 * if there's no connecting paths, output a line saying "no path found"
 *
 * for example, drawAllPath(src, st, ncities) on below:
 * 1 ---- 2 ---- 3 ---- 5
 *        |
 *        4      0
 * should call drawAllPaths(2, [-1. 2, 2, 2, 2, 3], 6)
 * which prints out:
 * no path found
 * [2]->[1]
 * [2]
 * [2]->[3]
 * [2]->[4]
 * [2]->[3]->[5]
 *
 * note all expected outputs can be found in the "expected" directory.
 * compile with: gcc -Wall -Werror -O -o testGraph testGraph.c Graph.c Queue.c
 * test with: ./mark
 */

// modified travel.c ... client for Graph ADT
// Written by John Shepherd, May 2013

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Graph.h"

// make some assumptions on much data is supplied
#define MAXCITIES 40
#define MAXNAME   20

/* EDIT THIS FUNCTION */
void drawAllPaths(int src, int *st, int ncities) {


/* IGNORE EVERYTHING BELOW THIS LINE */
void usage(char *argv0);  void fatal(char *);

int main(int argc, char *argv[])
{
	Graph world;           // graph of world/distances
	FILE *data;            // file handle
	char  name[MAXNAME+2]; // input buffer to hold city name lines
	int   ncities;         // how many cities

	// check command-line params
	if (argc != 2) usage(argv[0]);

	// get array of city names (assumes < MAXCITIES names)
	if ((data = fopen("ha30_name.txt","r")) == NULL) {
		fatal("Couldn't open file: ha30_name.txt");
	}

	ncities = 0;
	while (fgets(name,MAXNAME,data) != NULL) {
		name[strlen(name)-1] = '\0';
		ncities++;
	}
	fclose(data);

	// make empty Graph
	world = newGraph(ncities);

	// get distances and populate Graph edges
	if ((data = fopen("ha30_dist.txt","r")) == NULL) {
		fatal("Couldn't open file: ha30_dist.txt");
	}
	int n=0, fromCity, toCity, distance;
	while (fscanf(data,"%d",&distance) == 1) {
		fromCity = n / ncities;
		toCity = n % ncities;
		// convert miles to km
		distance = distance * 100 * 1.609344;
		insertEdge(world, toCity, fromCity, distance);
		n++;
	}
	fclose(data);

    int src = atoi(argv[1]);

    /* populate st */
    int *st = malloc(sizeof(int) * ncities);
    populateSt(world,src,5000,st);
    drawAllPaths(src, st, ncities);
    free(st);


    dropGraph(world);
	return 0;
}

// print usage message and stop
void usage(char *argv0)
{
	fprintf(stderr, "Usage: %s [Start-city Destination-city]]\n", argv0);
	exit(1);
}

// print message for unrecoverable error and stop
void fatal(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

