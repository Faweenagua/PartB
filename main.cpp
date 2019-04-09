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
        cout << " 1 => Check scale\n 2 => Room Occupancy\n 0 => To exit\n";
        
        cout << "Enter an option: ";
        cin >> mainMenuChoice;
        
        while(cin.fail() or mainMenuChoice  < 0 or mainMenuChoice > 2){
            cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Check your option and enter the correct option: ";
            cin >> mainMenuChoice;
        }


        if (mainMenuChoice == 0){
            break;
        }
            switch (mainMenuChoice) {
                case 1:
                    cout << "\n--------------------------------------\n";
                    cout << "Select Scale\n 1 => Temperature Scale\n 2 => Humidity Scale\n 3 => Water PH Level Scale\n 0 => Main menu\n";
                    cout << "Enter an option: ";
                    cin >> scaleChoice;
                    while(cin.fail() or scaleChoice  < 0 or scaleChoice > 3){
                        cin.clear();
	                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Enter the correct option: ";
                        cin >> scaleChoice;
                    }

                    switch (scaleChoice) {
                        case 1:
                            cout << "Input Temperature Value: ";//input temperature value
                            cin >> temperature;
                             while(temperature >58 || temperature < -89.2){
                                cout << "\nPlease inputted temperature value should be between 58 and -89.2\n";
                                cout << "Enter a new value: ";
                                cin >> temperature;
                            }

                            cout << "Input Temperature Unit [F/C]: ";//input temperature unit
                            char tempUnit;
                            cin >> tempUnit;
                            cout << tempUnit;
                            while(cin.fail() || (tempUnit != 'F' && tempUnit != 'C' && tempUnit != 'c' && tempUnit != 'f')){
                                cin.clear();
	                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Input F or C: ";
                                cin >> tempUnit;
                            }
                            temperatureUnit.push_back(tempUnit);
                            a.setTemperature(temperature, temperatureUnit);
                            cout << "The temperature is " << a.temperatureScale() << "\n";
                            cout << "\n----------------------------\n";
                            break;

                        case 2:
                            cout << "Input Relative Humidity Value: ";//input relative humidity
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
                                cout << "\nPlease inputted water PH value should be from 0 and 14: ";
                                cin >> waterPH;
                            }
                            a.waterPHLevel = waterPH;
                            cout << "The Water is " << a.waterPHLevelScale() << "\n";
                            break;
                        case 0:
                            cout << "\n----------------------------\n";
                            break;
                        default:
                            cout << "\n----------------------------\n";
                            break;
                    }

                    break;

                case 2:
                         cout << "\n----------------------------\n";
                    cout
                            << "Select an action\n 1 => Add person to room\n 2 => Remove person from room\n 3 => Check for space\n 0 => Main menu\n";
                    cout << "Select an option: ";
                    cin >> spaceCheck;
                    while(cin.fail() or spaceCheck  < 0 or spaceCheck > 3){
                        cin.clear();
	                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	                    cout << "Enter a correct option: ";
                        cin >> spaceCheck;
                    }

                    switch (spaceCheck) {
                        case 0:
                            cout << "\n----------------------------\n";
                            break;
                        case 1 :
                            cout << "\n----------------------------\n";
                            cout
                                    << "Select room to add person\n 1 => Lecture Hall\n 2 => BigBen\n 3 => Akorno\n 4 => Library\n 5 => Car Park\n 6 => Washroom\n 0 => Main menu\n" ;
                            cout << "Select an option: ";
                            cin >> roomAddChoice;
                            while(cin.fail() or roomAddChoice < 0 or roomAddChoice > 6){
                                cin.clear();
	                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
	                            cout << "Enter a correct option: ";
                                cin >> roomAddChoice;
                            }
                            //This switch case adds data to the various sectors like lecture hall, big ben queue etc
                            switch (roomAddChoice) {
                                case 0:
                                    cout << "\n----------------------------\n";
                                    break;
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
                                    cout << "\n----------------------------\n";
                                    break;
                            }
                            break;
                        case 2:
                            cout << "\n----------------------------\n";
                            cout
                                    << "Select room to remove person\n 1 => Lecture Hall\n 2 => BigBen\n 3 => Akorno\n 4 => Library\n 5 => Car Park\n 6 => Washroom\n 0 => Main menu\n";
                            cout << "Select an option: ";
                            cin >> roomRemoveChoice;
                            while(cin.fail() or roomRemoveChoice < 0 or roomRemoveChoice > 6){
                                cin.clear();
	                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
	                            cout << "Enter a correct option: ";
                                cin >> roomRemoveChoice;
                            }
                            //removes data from sectors on campus
                            switch (roomRemoveChoice) {
                                case 0:
                                cout << "\n----------------------------\n";
                                    break;
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
                                    cout << "\n----------------------------\n";
                                    break;
                            }
                            break;
                            //outputs available spaces
                        case 3:
                            cout << "\n----------------------------\n";
                            cout
                                    << "Check for space in \n 1 => Lecture Hall\n 2 => BigBen\n 3 => Akorno\n 4 => Library\n 5 => Car Park\n 6 => Washroom\n 0 => Main menu\n";
                            cout << "Select an option: ";
                            cin >> roomCheckChoice;
                            while(cin.fail() or roomCheckChoice < 0 or roomCheckChoice > 6){
                                cin.clear();
	                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
	                            cout << "Enter a correct option: ";
                                cin >> roomCheckChoice;
                            }
                            switch (roomCheckChoice) {
                                case 0:
                                    cout << "\n----------------------------\n";
                                    break;
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
                            cout << "\n----------------------------\n";
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
