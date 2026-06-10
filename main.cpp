#include "test.h"
#include <iostream>
#include <sstream>

int main(){

    DoTest();

    bool stopFlag = false;
    bool subStopFlag = false;
    bool noHelpNotice = false;

    std::string enteredLine;
    std::istringstream lineInput;
    char enteredChar = 0;
    char yesNoChar = 0;
    double *items = nullptr;

    double lfSubserv1;
    double lfSubserv2;
    double lfSubserv3;
    double lfSubserv4;
    std::size_t sizeSubserv1;
    std::size_t sizeSubserv2;

    Vector<double> *vec = nullptr;
    Vector<double> *vecSubserv1;
    Vector<double> *vecSubserv2;
    IEnumerable<double>::IEnumerator *enumSubserv;

    MutableListSequence<Registering::ModulusAngleTraj> *registeringOutput;
    IEnumerable<Registering::ModulusAngleTraj>::IEnumerator *registeringEnumSubserv;
    IEnumerable<Vector<double>>::IEnumerator *trajectoryEnumSubserv;

    do{

        if(noHelpNotice) noHelpNotice = false;
        else std::cout << "For help, enter 0." << std::endl;

        do{
            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                lineInput.clear();
                lineInput.str(enteredLine);
                if(lineInput >> enteredChar) break;
            }
        }while(1);

        switch(enteredChar){
            case '0':
                std::cout << "For vector creation, enter 1.\n";
                std::cout << "For vector operations, enter 2.\n";
                std::cout << "For a registering of a thrower, enter 3.\n";
                std::cout << "For exit from the program, enter any other symbol." << std::endl;
                noHelpNotice = true;
                break;
            case '1':

                do{

                    std::cout << "Enter a size of the vector, or enter a nonnumeric symbol to exit." << std::endl;

                    enteredChar = 0;
                    do{
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> sizeSubserv1) break;
                            lineInput.clear();
                            if(lineInput >> enteredChar) break;
                        }
                    }while(1);

                    if(!enteredChar){
                        break;
                    }else{

                        std::cout << "Exit? [y/n]" << std::endl;

                        do{
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                if(lineInput >> yesNoChar) break;
                            }
                        }while(1);

                        if(yesNoChar == 'y') break;

                    }

                }while(1);
                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    yesNoChar = 0;
                    break;
                }

                if(sizeSubserv1 > 0){

                    std::cout << "Enter items of the vector, or enter a nonnumeric symbol to exit." << std::endl;

                    items = new double[sizeSubserv1];
                    sizeSubserv2 = 0;
                    do{

                        do{
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                break;
                            }
                        }while(1);

                        enteredChar = 0;
                        while(sizeSubserv2 < sizeSubserv1){
                            if(!(lineInput >> items[sizeSubserv2])){
                                lineInput.clear();
                                lineInput >> enteredChar;
                                break;
                            }
                            sizeSubserv2++;
                        }

                        if(!(sizeSubserv2 < sizeSubserv1)){
                            break;
                        }
                        if(enteredChar){
                                
                            std::cout << "Exit? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y') break;
                            else std::cout << "Continue entering." << std::endl;

                        }

                    }while(1);
                    if(yesNoChar == 'y'){

                        delete []items;
                        items = nullptr;

                        std::cout << "Exiting." << std::endl;
                        yesNoChar = 0;
                        break;

                    }

                }

                if(vec) delete vec;

                vec = new Vector<double>(items, sizeSubserv1);
                delete []items;
                items = nullptr;

                std::cout << "The vector created." << std::endl;

                break;
            
            case '2':

                if(!vec){
                    std::cout << "The vector doesn't exist." << std::endl;
                    break;
                }
                
                do{

                    if(noHelpNotice) noHelpNotice = false;
                    else std::cout << "For help, enter 0." << std::endl;

                    do{
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> enteredChar) break;
                        }
                    }while(1);

                    switch(enteredChar){
                        case '0':
                            std::cout << "To get an element of the vector, enter 1.\n";
                            std::cout << "To get the vector's size, enter 2.\n";
                            std::cout << "To get the vector, enter 3.\n";
                            std::cout << "To add another vector to this one, enter 4.\n";
                            std::cout << "To multiply a number to the vector, enter 5.\n";
                            std::cout << "To multiply this vector by another one, enter 6.\n";
                            std::cout << "To get the vector's norm, enter 7.\n";
                            std::cout << "To exit, enter any other symbol." << std::endl;
                            noHelpNotice = true;
                            break;
                        case '1':

                            if(!(vec->GetCount())){
                                std::cout << "The vector is empty." << std::endl;
                                break;
                            }

                            do{

                                std::cout << "Enter an index, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> sizeSubserv1) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }
                            if(sizeSubserv1 >= vec->GetCount()){
                                std::cout << "The index is out of range." << std::endl;
                                break;
                            }

                            std::cout << vec->Get(sizeSubserv1) << std::endl;
                            break;

                        case '2':
                            std::cout << vec->GetCount() << std::endl;
                            break;
                        case '3':

                            if(!(vec->GetCount())){
                                std::cout << "The sequence is empty." << std::endl;
                                break;
                            }

                            enumSubserv = vec->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;

                            break;

                        case '4':

                            
                            std::cout << "Enter items of the other vector, or enter a nonnumeric symbol to exit." << std::endl;

                            items = new double[vec->GetCount()];
                            sizeSubserv2 = 0;
                            do{

                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        break;
                                    }
                                }while(1);

                                enteredChar = 0;
                                while(sizeSubserv2 < vec->GetCount()){
                                    if(!(lineInput >> items[sizeSubserv2])){
                                        lineInput.clear();
                                        lineInput >> enteredChar;
                                        break;
                                    }
                                    sizeSubserv2++;
                                }

                                if(!(sizeSubserv2 < vec->GetCount())){
                                    break;
                                }
                                if(enteredChar){
                                        
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;
                                    else std::cout << "Continue entering." << std::endl;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){

                                delete []items;
                                items = nullptr;

                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;

                            }

                            vecSubserv2 = new Vector<double>(items, vec->GetCount());
                            delete []items;
                            items = nullptr;

                            vecSubserv1 = new Vector<double>(*vec + *vecSubserv2);
                            delete vecSubserv2;

                            std::cout << "The new vector is:\n";
                            enumSubserv = vecSubserv1->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;
                            
                            std::cout << "Do you want to change the current vector to this? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y'){

                                yesNoChar = 0;

                                delete vec;
                                vec = vecSubserv1;

                                std::cout << "Done." << std::endl;
                                
                            }else{
                                delete vecSubserv1;
                            }

                            break;

                        case '5':
                            
                            do{

                                std::cout << "Enter a value, or enter a nonnumeric symbol to exit." << std::endl;

                                enteredChar = 0;
                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        if(lineInput >> lfSubserv1) break;
                                        lineInput.clear();
                                        if(lineInput >> enteredChar) break;
                                    }
                                }while(1);

                                if(!enteredChar){
                                    break;
                                }else{
                                    
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;
                            }

                            vecSubserv1 = new Vector<double>(lfSubserv1 * *vec);

                            std::cout << "The new vector is:\n";
                            enumSubserv = vecSubserv1->GetEnumerator();
                            while(enumSubserv->HasNext()){
                                std::cout << enumSubserv->Current() << " ";
                                enumSubserv->MoveNext();
                            }
                            std::cout << enumSubserv->Current() << std::endl;
                            delete enumSubserv;
                            
                            std::cout << "Do you want to change the current vector to this? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y'){

                                yesNoChar = 0;

                                delete vec;
                                vec = vecSubserv1;

                                std::cout << "Done." << std::endl;
                                
                            }else{
                                delete vecSubserv1;
                            }

                            break;

                        case '6':
                            
                            std::cout << "Enter items of the other vector, or enter a nonnumeric symbol to exit." << std::endl;

                            items = new double[vec->GetCount()];
                            sizeSubserv2 = 0;
                            do{

                                do{
                                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                        lineInput.clear();
                                        lineInput.str(enteredLine);
                                        break;
                                    }
                                }while(1);

                                enteredChar = 0;
                                while(sizeSubserv2 < vec->GetCount()){
                                    if(!(lineInput >> items[sizeSubserv2])){
                                        lineInput.clear();
                                        lineInput >> enteredChar;
                                        break;
                                    }
                                    sizeSubserv2++;
                                }

                                if(!(sizeSubserv2 < vec->GetCount())){
                                    break;
                                }
                                if(enteredChar){
                                        
                                    std::cout << "Exit? [y/n]" << std::endl;

                                    do{
                                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                            lineInput.clear();
                                            lineInput.str(enteredLine);
                                            if(lineInput >> yesNoChar) break;
                                        }
                                    }while(1);

                                    if(yesNoChar == 'y') break;
                                    else std::cout << "Continue entering." << std::endl;

                                }

                            }while(1);
                            if(yesNoChar == 'y'){

                                delete []items;
                                items = nullptr;

                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                break;

                            }

                            vecSubserv2 = new Vector<double>(items, sizeSubserv1);
                            delete []items;
                            items = nullptr;

                            std::cout << *vec * *vecSubserv2 << std::endl;
                            delete vecSubserv2;

                            break;

                        case '7':
                            std::cout << vec->GetNorm() << std::endl;
                            break;
                        default:

                            std::cout << "Exit? [y/n]" << std::endl;

                            do{
                                if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                    lineInput.clear();
                                    lineInput.str(enteredLine);
                                    if(lineInput >> yesNoChar) break;
                                }
                            }while(1);

                            if(yesNoChar == 'y'){
                                std::cout << "Exiting." << std::endl;
                                yesNoChar = 0;
                                subStopFlag = true;
                            }

                            break;

                    }

                }while(!subStopFlag);

                subStopFlag = false;

                break;

            case '3':

                do{

                    std::cout << "Enter the left bound, or enter a nonnumeric symbol to exit." << std::endl;

                    enteredChar = 0;
                    do{
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> lfSubserv1) break;
                            lineInput.clear();
                            if(lineInput >> enteredChar) break;
                        }
                    }while(1);

                    if(!enteredChar){
                        break;
                    }else{
                        
                        std::cout << "Exit? [y/n]" << std::endl;

                        do{
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                if(lineInput >> yesNoChar) break;
                            }
                        }while(1);

                        if(yesNoChar == 'y') break;

                    }

                }while(1);
                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    yesNoChar = 0;
                    break;
                }

                do{

                    std::cout << "Enter the right bound, or enter a nonnumeric symbol to exit." << std::endl;

                    enteredChar = 0;
                    do{
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> lfSubserv2) break;
                            lineInput.clear();
                            if(lineInput >> enteredChar) break;
                        }
                    }while(1);

                    if(!enteredChar){
                        break;
                    }else{
                        
                        std::cout << "Exit? [y/n]" << std::endl;

                        do{
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                if(lineInput >> yesNoChar) break;
                            }
                        }while(1);

                        if(yesNoChar == 'y') break;

                    }

                }while(1);
                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    yesNoChar = 0;
                    break;
                }

                do{

                    std::cout << "Enter the velocity delta, or enter a nonnumeric symbol to exit." << std::endl;

                    enteredChar = 0;
                    do{
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> lfSubserv3) break;
                            lineInput.clear();
                            if(lineInput >> enteredChar) break;
                        }
                    }while(1);

                    if(!enteredChar){
                        break;
                    }else{
                        
                        std::cout << "Exit? [y/n]" << std::endl;

                        do{
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                if(lineInput >> yesNoChar) break;
                            }
                        }while(1);

                        if(yesNoChar == 'y') break;

                    }

                }while(1);
                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    yesNoChar = 0;
                    break;
                }

                do{

                    std::cout << "Enter the gravitation, or enter a nonnumeric symbol to exit." << std::endl;

                    enteredChar = 0;
                    do{
                        if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                            lineInput.clear();
                            lineInput.str(enteredLine);
                            if(lineInput >> lfSubserv4) break;
                            lineInput.clear();
                            if(lineInput >> enteredChar) break;
                        }
                    }while(1);

                    if(!enteredChar){
                        break;
                    }else{
                        
                        std::cout << "Exit? [y/n]" << std::endl;

                        do{
                            if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                                lineInput.clear();
                                lineInput.str(enteredLine);
                                if(lineInput >> yesNoChar) break;
                            }
                        }while(1);

                        if(yesNoChar == 'y') break;

                    }

                }while(1);
                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    yesNoChar = 0;
                    break;
                }

                registeringOutput = Registering::RegisterThrower(lfSubserv1, lfSubserv2, lfSubserv3, lfSubserv4);

                std::cout << "The final modulus and angle is:" << std::endl;
                std::cout << registeringOutput->GetLast().modulus << ", ";
                std::cout << registeringOutput->GetLast().angle << std::endl;

                std::cout << "Do you want to get the final trajectory? [y/n]" << std::endl;

                do{
                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                        lineInput.clear();
                        lineInput.str(enteredLine);
                        if(lineInput >> yesNoChar) break;
                    }
                }while(1);

                if(yesNoChar == 'y'){

                    yesNoChar = 0;

                    trajectoryEnumSubserv = registeringOutput->GetLast().traj->GetEnumerator();
                    while(trajectoryEnumSubserv->HasNext()){
                        std::cout << '(' << trajectoryEnumSubserv->Current().Get(0) << ", ";
                        std::cout  << trajectoryEnumSubserv->Current().Get(1) << "), ";
                        trajectoryEnumSubserv->MoveNext();
                    }
                    std::cout << '(' << trajectoryEnumSubserv->Current().Get(0) << ", ";
                    std::cout  << trajectoryEnumSubserv->Current().Get(1) << ")." << std::endl;
                    delete trajectoryEnumSubserv;
                    
                }

                std::cout << "Do you want to get the intermediate moduli, angles, and trajectories? [y/n]" << std::endl;

                do{
                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                        lineInput.clear();
                        lineInput.str(enteredLine);
                        if(lineInput >> yesNoChar) break;
                    }
                }while(1);

                if(yesNoChar == 'y'){

                    yesNoChar = 0;

                    registeringEnumSubserv = registeringOutput->GetEnumerator();

                    do{
                        
                        std::cout << registeringEnumSubserv->Current().modulus << ", ";
                        std::cout << registeringEnumSubserv->Current().angle << std::endl;
                        
                        trajectoryEnumSubserv = registeringEnumSubserv->Current().traj->GetEnumerator();
                        while(trajectoryEnumSubserv->HasNext()){
                            std::cout << '(' << trajectoryEnumSubserv->Current().Get(0) << ", ";
                            std::cout  << trajectoryEnumSubserv->Current().Get(1) << "), ";
                            trajectoryEnumSubserv->MoveNext();
                        }
                        std::cout << '(' << trajectoryEnumSubserv->Current().Get(0) << ", ";
                        std::cout  << trajectoryEnumSubserv->Current().Get(1) << ")." << std::endl;
                        delete trajectoryEnumSubserv;

                    }while(registeringEnumSubserv->MoveNext());
                    delete registeringEnumSubserv;
                    
                }

                registeringEnumSubserv = registeringOutput->GetEnumerator();

                do{
                    delete registeringEnumSubserv->Current().traj;
                }while(registeringEnumSubserv->MoveNext());
                delete registeringEnumSubserv;
                
                delete registeringOutput;

                break;

            default:
                
                std::cout << "Exit? [y/n]" << std::endl;

                do{
                    if(std::getline(std::cin, enteredLine) && !enteredLine.empty()){
                        lineInput.clear();
                        lineInput.str(enteredLine);
                        if(lineInput >> yesNoChar) break;
                    }
                }while(1);

                if(yesNoChar == 'y'){
                    std::cout << "Exiting." << std::endl;
                    stopFlag = true;
                }

                break;

        }
    }while(!stopFlag);

    delete vec;

    return 0;
    
}