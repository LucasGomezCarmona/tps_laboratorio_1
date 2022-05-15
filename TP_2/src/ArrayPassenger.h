/*
 * ArrayPassenger.h
 *
 *  Created on: 9 may 2022
 *      Author: Lucas
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

//===========================================================================

typedef struct
{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

//===========================================================================

/// @brief To indicate that all position in the array are empty,
/// this function put the flag (isEmpty) in TRUE in
/// all position of the array.
/// @param list Array of passenger.
/// @param len Arrays length.
/// @return Return (-1) if Error [Invalid length] - (0) if Ok
int initPassengers(Passenger list[], int len);

//===========================================================================

/// @brief add in a existing list of passengers the values received as parameters
/// in the first empty position
/// @param list Passenger
/// @param len int
/// @param id int
/// @param name[] char
/// @param lastName[] char
/// @param price float
/// @param typePassenger int
/// @param flycode[] char
/// @return int Return (-1) if Error [Invalid length or NULL pointer or without
/// free space] - (0) if Ok
int addPassenger(Passenger list[], int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[]);

//===========================================================================

/// @brief find a Passenger by Id en returns the index position in array.
///
/// @param list[] Passenger
/// @param len int
/// @return Return passenger index position or (-1) if [Invalid length or
/// NULL pointer received or passenger not found]
int loadPassenger(Passenger list[], int len);

//===========================================================================

/// @brief console print OK or ERROR.
///
/// @param r int 0 -1
void printReturn(int r);

//===========================================================================

/// @brief find a Passenger by Id en returns the index position in array.
/// @param list Passenger
/// @param len int
/// @param id int
/// @return Return passenger index position or (-1) if [Invalid length or NULL pointer
/// received or passenger not found]
int findPassengerById(Passenger list[], int len,int id);

//===========================================================================

/// @brief modify any passenger found by id
///
/// @param list Passenger
/// @param len int
/// @return Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
int modifyPassenger(Passenger list[], int len);

//===========================================================================

/// @brief Remove a Passenger by Id (put isEmpty Flag in 1)
///
/// @param list Passenger
/// @param len int
/// @param id int
/// @return Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
int removePassenger(Passenger list[], int len, int id);

//===========================================================================

/// @brief swap between two positions of array
///
/// @param list Passenger
/// @param i int
/// @param j int
void passFromTo(Passenger list[],int i, int j);

//===========================================================================

/// @brief Sort the elements in the array of passengers, the argument order
/// indicate UP or DOWN order.
///
/// @param list Passenger
/// @param len int
/// @param order int [1] indicate UP - [0] indicate DOWN
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengers(Passenger list[], int len, int order);

//===========================================================================

/// @brief print passenger list
///
/// @param list Passenger
/// @param len int
void printPassengers(Passenger list[], int len);

//===========================================================================

/// @brief calculate total amount prices and the average
///
/// @param list Passenger
/// @param len int
/// @return turn (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int totalAndAveragePrice(Passenger list[], int len);

//===========================================================================

/// @brief Sort the elements in the array of passengers, the argument order
/// indicate UP or DOWN order
///
/// @param list Passenger
/// @param len int
/// @param order int
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int sortPassengersByCode(Passenger list[], int len, int order);

//===========================================================================

#endif /* ARRAYPASSENGER_H_ */
