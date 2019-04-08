//
// Created by Jones and Francis
//

//importing classes or files for use
#ifndef ICPLAB6_ASHESIASALIVINGLAB_H
#define ICPLAB6_ASHESIASALIVINGLAB_H
#include<algorithm>
#include <iostream>

using namespace std;

/*This class is use to store data about temperature and water PH level and
other useful data about life on Ashesi Campus*/
class AshesiAsALivingLab {
public:
    double temperatureValueInCelsius;//initialized to store temperature in celsius
    double relativeHumidityValue;   //initialized to store humidity
    double waterPHLevel;            //initialized to store PH level of water
    const int lectureHallSize = 65; //stores the carrying capacity of lecture halls in Ashesi
    int numberOfPeopleInLectureHall = 0;//people in lecture halls
    const int bigBenSize = 34;          //carrying capacity of big ben cafeteria
    int numberOfPeopleAtBigBen = 0;     //people at big ben
    const int librarySize = 70;         //carrying capacity of the Ashesi Library
    int numberOfPeopleInLibrary = 0;    //people in the library
    const int washRoomSize = 12;        //carrying capacity of washrooms
    int numberOfPeopleInWashRoom = 0;    //people in the washrooms
    const int akornoSize = 45;          //carrying capacity of Arkornor cafeteria
    int numberOfPeopleAtAkorno = 0;     //people at Arkornor
    const int parkingSize = 28;         //carrying capacity of car parks
    int numberOfCarsParked = 0;         //number of cars parked





    AshesiAsALivingLab()= default;//default constructor

    /* This method computes the space available in lecture hall using
    the difference between the carrying capacity of the lecture hall and
    the people in the lecture hall at any point in time*/

    int spaceAvailableInLectureHall(){
        return lectureHallSize-numberOfPeopleInLectureHall;
    }
    /* This method computes the space available at big ben using
    the difference between the carrying capacity of big ben and
    the people at big ben at any point in time*/
    int spaceAvailableAtBigBen(){
        return bigBenSize-numberOfPeopleAtBigBen;
    }

    /* This method computes the space available in the library using
    the difference between the carrying capacity of the library and
    the people in the library at any point in time*/
    int spaceAvailableInLibrary(){
        return librarySize-numberOfPeopleInLibrary;
    }

    /*This method computes the space available in the washroom using
    the difference between the carrying capacity of the washroom and
    the people in the washroom at any point in time*/
    int spaceAvailableInWashroom(){
        return washRoomSize-numberOfPeopleInWashRoom;
    }

    /*method computes the space available at Arkornor cafeteria using
    the difference between the carrying capacity of Arkornor cafeteria and
    the peopleat Arkornor cafeteria at any point in time*/
    int spaceAvailableAtAkorno(){
        return akornoSize-numberOfPeopleAtAkorno;
    }

    /*This method computes the space available at the car park using
   the difference between the carrying capacity of the car park and
   the cars parked at any point in time*/
    int spaceAvailableAtCarPark(){
        return parkingSize-numberOfCarsParked;
    }
    /*This method adds people to lecture hall as long as
    its carrying capacity is greater than the
    people available in the lecture hall at that point in time*/
    bool addpersonToLectureHall(){
        if (numberOfPeopleInLectureHall < lectureHallSize){//checks current lecture hall occupancy
            numberOfPeopleInLectureHall +=1;//increase occupancy
            return true;
        } else{
            cout<<"Can't add at the moment, Lecture Hall is full\n\n";
            return false;
        }

    }
    // reduction of the number people in the lecture hall as far as the lecture hall is not empty
    bool removePersonFromLectureHall(){
        if (numberOfPeopleInLectureHall > 0){
            numberOfPeopleInLectureHall -=1;
            return true;
        } else{
            cout<<"Can't remove at the moment, Lecture Hall is empty\n\n";
            return false;
        }

    }
    //increment queue at big ben if its carrying capacity is not full
    bool addPersonToBigBenQueue(){

        if (numberOfPeopleAtBigBen < bigBenSize){
            numberOfPeopleAtBigBen +=1;
            return true;
        } else{
            cout<<"Can't add at the moment, Big Ben is full\n\n";
            return false;
        }
    }
    /*reduction of the number of people from big ben queue if number of people
    available is not zero*/
    bool removePersonFromoBigBenQueue(){

        if (numberOfPeopleAtBigBen > 0){
            numberOfPeopleAtBigBen -=1;
            return true;
        } else{
            cout<<"Can't remove at the moment, Big Ben is empty\n\n";
            return false;
        }
    }

//add a person to Arkornor's queue
    bool addPersonToAkornoQueue(){

        if (numberOfPeopleAtAkorno < akornoSize){
            numberOfPeopleAtAkorno +=1;
            return true;
        } else{
            cout<<"Can't add at the moment, Akorno is full\n\n";
            return false;
        }
    }
    //removes person from Arkornor's queue
    bool removePersonFromAkornoQueue(){

        if (numberOfPeopleAtAkorno > 0){
            numberOfPeopleAtAkorno -=1;
            return true;
        } else{
            cout<<"Can't remove at the moment, Akorno is empty\n\n";
            return false;
        }
    }
    //add person to library
    bool addPersonToLibrary(){

        if (numberOfPeopleInLibrary< librarySize){
            numberOfPeopleInLibrary +=1;
            return true;
        } else{
            cout<<"Can't add at the moment, Library is full\n\n";
            return false;
        }
    }
    //removes person from library
    bool removePersonFromLibrary(){

        if (numberOfPeopleInLibrary > 0){
            numberOfPeopleInLibrary -=1;
            return true;
        } else{
            cout<<"Can't remove at the moment, Library is empty\n\n";
            return false;
        }
    }

    //add person to washroom
    bool addPersonToWashRoom(){
        if (numberOfPeopleInWashRoom < washRoomSize){
            numberOfPeopleInWashRoom +=1;
            return true;
        } else{
            cout<<"Can't add at the moment, Washroom is full\n\n";
            return false;
        }

    }
    //removes person from washroom
    bool removePersonFromWashRoom(){
        if (numberOfPeopleInWashRoom > 0){
            numberOfPeopleInWashRoom -=1;
            return true;
        } else{
            cout<<"Can't remove at the moment, Washroom is empty\n\n";
            return false;
        }

    }
    //add cars to car park
    bool addCarToCarPark(){
        if (numberOfCarsParked < parkingSize){
            numberOfCarsParked +=1;
            return true;
        } else{
            cout<<"Can't add at the moment, Parking space is full\n\n";
            return false;
        }

    }
    //removes cars from car park
    bool removeCarFromCarPark(){
        if (numberOfCarsParked > 0){
            numberOfCarsParked -=1;
            return true;
        } else{
            cout<<"Can't remove at the moment, Parking space is empty\n\n";
            return false;
        }

    }

/*conversion temperature from Fahreint to degree celsius*/
    void setTemperature(double temp, string unit){
        transform(unit.begin(), unit.end(), unit.begin(), ::toupper);
        if (unit == "F"){
            temperatureValueInCelsius = (temp - 32)*(static_cast<float >(5)/9);
        }else if (unit == "C"){
            temperatureValueInCelsius = temp;
        } else{
            cout<<"Invalid input try again";
        }
    }

//records on ph level of water on Ashesi campus
    string waterPHLevelScale(){
        string output = "Optimal";

        if(waterPHLevel >= 0 && waterPHLevel < 7){//checks if water is acidic
            output = "Acidic";
        }else if (waterPHLevel == 7){//checs if water is neutral
            output = "Optimal";
        }else if (waterPHLevel >7 && waterPHLevel<= 14){//checks if water is alkaline
            output = "Alkaline";
        }

        return output;
    }

    //records on humidity level on Ashesi campus
    string relativeHumidityScale(){
        string output = "Less Humid";
        if(relativeHumidityValue >0 && relativeHumidityValue <= 25){//checks for no himidity
            output = "No Humidity";
        }else if (relativeHumidityValue >25 && relativeHumidityValue <= 50){//checks for less humidity
            output = "Less Humid";
        }else if (relativeHumidityValue >50 && relativeHumidityValue <= 75){//checks if it is humid
            output = "Humid";
        }else if (relativeHumidityValue >75 && relativeHumidityValue <= 100){//checks if it is more humid
            output = "Very Humid";
        } else{
            cout<<"Please input a value between 0 and 100";
        }

        return output;
    }
    //records on temperature on Ashesi Campus
    string temperatureScale(){
        string output = "Optimal";

        if(temperatureValueInCelsius <= 0){//checks for very cold temperature
            output = "Very Cold";
        }else if (temperatureValueInCelsius >0 && temperatureValueInCelsius <= 16){//checks for cold temperature
            output = "Cold";
        }else if (temperatureValueInCelsius >16 && temperatureValueInCelsius <= 26){
            output = "Moderately Cold";
        }else if (temperatureValueInCelsius >26 && temperatureValueInCelsius <= 32){
            output = "Optimal";
        }else if (temperatureValueInCelsius < 32){
            output = "Too Hot";
        }

        return output;
    };
};




#endif //ICPLAB6_ASHESIASALIVINGLAB_H
