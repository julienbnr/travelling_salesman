#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants for indexs. */
const int INDEX_ZIP_CODE_CITY                 = 0;
const int INDEX_NAME_CITY                     = 1;
const int INDEX_NB_NEIGHBOR_CITY              = 2;
const int INDEX_ADJACENTS_ZIP_CODE_CITITES    = 3;
const int INDEX_ADJACENTS_NAME_CITITES        = 4;
const int INDEX_ADJACENTS_DISTANCE_CITITES    = 5;

/* Structure of an adjacent city. */
typedef struct AdjacentCity
{
  char * name;
  char * zipCode;
  double distance;
} AdjacentCity;

/* Structure of a city. */
typedef struct City
{
  char * name;
  char * zipCode;
  int nbNeighbor;
  AdjacentCity ** adjacentCities;
} City;


void read_file(char * filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    perror("Unable to open file.");
    exit(1);
  }

  char line[1000];
  int lineCount = 0;
  while (fgets(line, sizeof(line), file)) {
    char *token;

    token = strtok(line, ",");

    City *city = malloc(sizeof(struct City));
    char *eptr;

    int columnCount = 0;
    while (token != NULL) {
      if (columnCount == INDEX_ZIP_CODE_CITY) {
        //printf("Zipcode = %s\n", token);
        city->zipCode = token;
      }

      else if (columnCount == INDEX_NAME_CITY) {
        //printf("Name = %s\n", token);
        city->name = token;
      }

      else if (columnCount == INDEX_NB_NEIGHBOR_CITY) {
        //printf("Number of neighbor(s) = %s\n", token);
        city->nbNeighbor = atoi(token);
      }

      else if (columnCount == INDEX_ADJACENTS_ZIP_CODE_CITITES) {
        //printf("Adjacent zipcode cities = %s\n", token);
      }

      else if (columnCount == INDEX_ADJACENTS_NAME_CITITES) {
        //printf("Adjacent name cities = %s\n", token);
      }

      else if (columnCount == INDEX_ADJACENTS_DISTANCE_CITITES) {
        //printf("Adjacent distance cities = %s\n", token);
      }

      else {
        printf("Error\n");
      }

      token = strtok(NULL, ",");
      columnCount++;
    }
    printf("City = %s, Zipcode = %s, Nb Neighbor = %i \n", city->name, city->zipCode, city->nbNeighbor);

    //printf("\n");
    lineCount++;
  }

  printf("Lines %i\n", lineCount);
}

/* Create an AjdacentCity. */
AdjacentCity * create_adjacent_city(char * name, char * zipCode,
  double distance) {
    AdjacentCity * city;
    city = malloc(sizeof(struct AdjacentCity));
    if (city == NULL) {
      exit(127);
    }
    city->name = name;
    city->zipCode = zipCode;
    city->distance = distance;
    return city;
}

/* Create a City. */
City * create_city(char * name, char * zipCode, int nbNeighbor) {
  City * city;
  city = malloc(sizeof(struct City));
  if (city == NULL) {
    exit(127);
  }

  city->name = name;
  city->zipCode = zipCode;
  city->nbNeighbor = nbNeighbor;
  return city;
}

int main(void) {
  printf("Welcome to The travelling salesman's problem!\n");

  read_file("communes_adjacentes_91.csv");

  printf("End \n");
  return 0;
}
