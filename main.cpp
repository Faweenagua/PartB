//
// Created by Francis and Jones
//
#include <iostream>

using namespace std;

#include "AshesiAsALivingLab.h"  // defines

void userInteraction(){
    //initialized variables to store data on Ashesi campus
    AshesiAsALivingLab a;
    int mainMenuChoice;
    int scaleChoice;
    double temperature;
    string temperatureUnit;
    double relativeHumidity;
    double waterPH;
    int spaceCheck;
    int roomAddChoice;
    int roomRemoveChoice;
    int roomCheckChoice;

    cout<<"\n<<<<>>>> WELCOME TO ASHESI AS A LIVING LAB <<<<>>>>\n";

    while (true) {
        cout << "Select an option below\n";
        cout << " 1. Check scale\n 2. Room Occupancy\n 0. To exit\n";

        cin >> mainMenuChoice;
        while(mainMenuChoice  < 0 or mainMenuChoice > 2){
            cin >> mainMenuChoice;
        }


        if (mainMenuChoice == 0){
            break;
        }
            switch (mainMenuChoice) {
                case 1:
                    cout << "Select Scale\n 1. Temperature Scale\n 2. Humidity Scale\n 3. Water PH Level Scale\n";
                    cin >> scaleChoice;
                    while(scaleChoice  < 1 or scaleChoice > 3){
                        cin >> scaleChoice;
                    }

                    switch (scaleChoice) {
                        case 1:
                            cout << "Input Temperature Value: \n";//input temperature value
                            cin >> temperature;
                             while(temperature >58 || temperature < -89.2){
                                 cout << "\nPlease inputted temperature value should be between 58 and -89.2\n";
                                    cin >> temperature;
                            }

                            cout << "Input Temperature Unit [F/C]: \n";//input temperature unit
                            char tempUnit;
                            cin >> tempUnit;
                            cout << tempUnit;
                            while(cin.fail() || (tempUnit != 'F' && tempUnit != 'C' && tempUnit != 'c' && tempUnit != 'C')){
                                cout << "Input F or C:  \n";
                                cin >> tempUnit;
                            }
                            temperatureUnit.push_back(tempUnit);
                            a.setTemperature(temperature, temperatureUnit);
                            cout << "The temperature is " << a.temperatureScale() << "\n";
                            break;

                        case 2:
                            cout << "Input Relative Humidity Value: \n";//input relative humidity
                            cin >> relativeHumidity;
                            while(relativeHumidity >100 || relativeHumidity < 0){
                                cout << "Please inputted relative humidity value should be from 0 and 100\n";
                                cin >> relativeHumidity;
                            }
                            a.relativeHumidityValue = relativeHumidity;
                            cout << "The Humidity is " << a.relativeHumidityScale() << "\n";
                            break;
                        case 3:
                            cout << "Input Water PH Value: \n";//input ph value
                            cin >> waterPH;
                            while(waterPH >14 || waterPH < 0){
                                cout << "\nPlease inputted water PH value should be from 0 and 14";
                                cin >> waterPH;
                            }
                            a.waterPHLevel = waterPH;
                            cout << "The Water is " << a.waterPHLevelScale() << "\n";
                            break;
                        default:
                            break;
                    }

                    break;

                case 2:
//NEXT ONEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                    cout
                            << "Select an action\n 1. Add person to room\n 2. Remove person from room\n 3. Check for space\n";
                    cin >> spaceCheck;
                    while(spaceCheck  < 1 or spaceCheck > 3){
                        cin >> spaceCheck;
                    }

                    switch (spaceCheck) {
                        case 1 :
                            cout
                                    << "Select room to add person\n 1. Lecture Hall\n 2. BigBen\n 3. Akorno\n 4. Library\n 5. Car Park\n 6. Washroom\n";
                            cin >> roomAddChoice;
                            while(roomAddChoice < 1 or roomAddChoice > 6){
                                cin >> roomAddChoice;
                            }
                            //This switch case adds data to the various sectors like lecture hall, big ben queue etc
                            switch (roomAddChoice) {
                                case 1:
                                    if (a.addpersonToLectureHall()) {
                                        cout << "Person added\n";
                                    }
                                    break;
                                case 2:
                                    if (a.addPersonToBigBenQueue()) {
                                        cout << "Person added\n";
                                    }
                                    break;
                                case 3:
                                    if (a.addPersonToAkornoQueue()) {
                                        cout << "Person added\n";
                                    }
                                    break;
                                case 4:
                                    if (a.addPersonToLibrary()) {
                                        cout << "Person added\n";
                                    }
                                    break;
                                case 5:
                                    if (a.addCarToCarPark()) {
                                        cout << "Person added\n";
                                    }
                                    break;
                                case 6:
                                    if (a.addPersonToWashRoom()) {
                                        cout << "Person added\n";
                                    }
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case 2:
                            cout
                                    << "Select room to remove person\n 1. Lecture Hall\n 2. BigBen\n 3. Akorno\n 4. Library\n 5. Car Park\n 6. Washroom\n";
                            cin >> roomRemoveChoice;
                            while(roomRemoveChoice < 1 or roomRemoveChoice > 6){
                                cin >> roomRemoveChoice;
                            }
                            //removes data from sectors on campus
                            switch (roomRemoveChoice) {
                                case 1:
                                    if (a.removePersonFromLectureHall()) {
                                        cout << "Person removed\n\n";
                                    }
                                    break;
                                case 2:
                                    if (a.removePersonFromoBigBenQueue()) {
                                        cout << "Person removed\n\n";
                                    }
                                    break;
                                case 3:
                                    if (a.removePersonFromAkornoQueue()) {
                                        cout << "Person removed\n\n";
                                    }
                                    break;
                                case 4:
                                    if (a.removePersonFromLibrary()) {
                                        cout << "Person removed\n\n";
                                    }
                                    break;
                                case 5:
                                    if (a.removeCarFromCarPark()) {
                                        cout << "Person removed\n\n";
                                    }
                                    break;
                                case 6:
                                    if (a.removePersonFromWashRoom()) {
                                        cout << "Person removed\n\n";
                                    }
                                    break;
                                default:
                                    break;
                            }
                            break;
                            //outputs available spaces
                        case 3:
                            cout
                                    << "Check for space in \n 1. Lecture Hall\n 2. BigBen\n 3. Akorno\n 4. Library\n 5. Car Park\n 6. Washroom\n";
                            cin >> roomCheckChoice;
                            while(roomCheckChoice < 1 or roomCheckChoice > 6){
                                cin >> roomCheckChoice;
                            }
                            switch (roomCheckChoice) {
                                case 1:
                                    cout << "The space available in Lecture Hall is " << a.spaceAvailableInLectureHall()
                                         << " out of " << a.lectureHallSize << "\n\n";
                                    break;
                                case 2:
                                    cout << "The space available at BigBen is " << a.spaceAvailableAtBigBen()
                                         << " out of " << a.bigBenSize << "\n\n";
                                    break;
                                case 3:
                                    cout << "The space available at Akorno is " << a.spaceAvailableAtAkorno()
                                         << " out of " << a.akornoSize << "\n\n";
                                    break;
                                case 4:
                                    cout << "The space available in the Library is " << a.spaceAvailableInLibrary()
                                         << " out of " << a.librarySize << "\n\n";
                                    break;
                                case 5:
                                    cout << "The space available at the Car park is " << a.spaceAvailableAtCarPark()
                                         << " out of " << a.parkingSize << "\n";
                                    break;
                                case 6:
                                    cout << "The space available in the Washroom is " << a.spaceAvailableInWashroom()
                                         << " out of " << a.washRoomSize << "\n\n";
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }

                    break;
                default:
                    break;
            }
        }

    }


int main()
{

    userInteraction();

    return 0;
}
