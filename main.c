#include <stdio.h>
#include <stdlib.h>

/* Structure of an adjacent city. */
typedef struct AdjacentCity
{
  char * name;
  char * zipCode;
  int adjacenceNb;
} AdjacentCity;

/* Structure of a city. */
typedef struct City
{
  char * name;
  char zipCode[5];
  int nbNeighbor;
  AdjacentCity ** adjacentCities;
} City;


/* Create an AjdacentCity. */
AdjacentCity * create_adjacent_city(char * name, char * zipCode,
  int adjacenceNb) {
    AdjacentCity * city;
    city = malloc(sizeof(struct AdjacentCity));
    if (city == NULL) {
      exit(127);
    }
    city->name = name;
    city->zipCode = zipCode;
    city->adjacenceNb = adjacenceNb;
    return city;
}

int main(void) {
  printf("Welcome to The travelling salesman's problem!\n");

  // Create an adjacent city
  AdjacentCity * adjacentCity = create_adjacent_city("Sevran", "93270", 4);

  printf("AjdacentCity - Name : %s, ZipCode : %s, AdjacentCityNumber: %i\n",
    adjacentCity->name,
    adjacentCity->zipCode,
    adjacentCity->adjacenceNb
  );


  printf("End \n");
  return 0;
}
