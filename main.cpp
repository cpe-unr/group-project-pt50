/** @file */
#include <iostream>
#include <string>
#include <fstream>

#include "processor.h"
#include "wavheader.h"
#include "wav.h"
#include "normalization.h"
#include "noisegate.h"
#include "echo.h"

using namespace std;

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

int main(int argc, char* const argv[]){

    if (argc != 2){
        std::cout << "Correct Usage:" << std::endl;
        std::cout << argv[0] << "filename" << std::endl;
        return 0;
    }
    
    int userChoice, userChoice2, userChoice3, userChoice4, userChoice5;
    int YN, YN2, YN3, YN4, YN5, YN6, YN7, YN8, YN9;
    string fileName, userFile;
    
    do{
        std::cout << "*** PT50 Audio File Management System ***" << std::endl;
        std::cout << "[1] Modify/Add Metadata" << std::endl;
        std::cout << "[2] Process Files" << std::endl;
        std::cout << "[3] Export Files" << std::endl;
        std::cout << "[0] EXIT" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cin >> userChoice;
        
        switch(userChoice){
            case 1:
                std::cout << "Creating Metadata" << std::endl;
                break;
            case 2:
                //file processing
                cout << "How would you like to process your files?" << endl;
                cout << "[1] Normalization" << endl;
                cout << "[2] Noise Gate" << endl;
                cout << "[3] Echo" << endl;
                cout << "Select one: " << endl;
                cin >> userChoice2;
            
                switch(userChoice2){
                    case 1:
                    cout << "Creating Normalization, if you would like to process another way: enter 1 for YES and 2 for NO" << endl;
                    cin >> YN;
                        if(YN == 1){
                            cout << "How would you like to process your files?" << endl;
                            cout << "[1] Noise Gate" << endl;
                            cout << "[2] Echo" << endl;
                            cout << "Select one: " << endl;
                            cin >> userChoice3;

                            switch(userChoice3){
                                case 1:
                                    cout << "Creating Noise Gate, would you like an Echo file? (enter 1 for YES and 2 for NO)" << endl;
                                    cin >> YN2;
                                    if(YN2 == 1){
                                        cout << "Creating Echo" << endl;
                                        break;
                                    }else if(YN2 == 2){
                                        break;
                                    }
                                case 2:
                                    cout << "Creating Echo, would you like a Noise Gate file? (enter 1 for YES and 2 for NO)" << endl;
                                    cin >> YN3;
                                    if(YN3 == 1){
                                        cout << "Creating Noise Gate" << endl;
                                        break;
                                    }else if(YN3 == 2){
                                        break;
                                    }
                            }
                        }else if(YN == 2){
                                break;
                        }
                        
                    case 2:
                    cout << "Creating Noise Gate, if you would like to process another way: enter 1 for YES and 2 for NO" << endl;
                    cin >> YN4;
                        if(YN4 == 1){
                            cout << "How would you like to process your files?" << endl;
                            cout << "[1] Normalization" << endl;
                            cout << "[2] Echo" << endl;
                            cout << "Select one: " << endl;
                            cin >> userChoice4;
                            
                            switch(userChoice4){
                                case 1:
                                    cout << "Creating Normalization, would you like an Echo file? (enter 1 for YES and 2 for NO)" << endl;
                                    cin >> YN5;
                                    
                                    if(YN5 == 1){
                                        cout << "Creating Echo" << endl;
                                        break;
                                    }
                                    else if(YN5 == 2){
                                        break;
                                    }
                                case 2:
                                    cout << "Creating Echo, would you like a Normalization file? (enter 1 for YES and 2 for NO)" << endl;
                                    cin >> YN6;
                                    
                                    if(YN6 == 1){
                                        cout << "Creating Normalization" << endl;
                                        break;
                                    }
                                    else if(YN6 == 2){
                                        break;
                                    }
                            }
                        }else if(YN4 == 2){
                            break;
                        }
                    case 3:
                    cout << "Creating Echo, if would you like to process another way: enter 1 for YES and 2 for NO" << endl;
                    cin >> YN7;
                        if(YN7 == 1){
                            cout << "How would you like to process your files?" << endl;
                            cout << "[1] Normalization" << endl;
                            cout << "[2] Noise Gate" << endl;
                            cout << "Select one: " << endl;
                            cin >> userChoice5;

                            switch(userChoice5){
                                case 1:
                                    cout << "Creating Normalization, would you like a Noise Gate file? (enter 1 for YES and 2 for NO)" << endl;
                                    cin >> Yn8;
                                    
                                    if(YN8 == 1){
                                        cout << "Creating Noise Gate" << endl;
                                        break;
                                }
                                else if(YN8 == 2){
                                    break;
                                }
                            case 2:
                                cout << "Creating Noise Gate, would you like a Normalization file? (enter 1 for YES and 2 for NO)" << endl;
                                cin >> YN9;
                                    
                                    if(YN9 == 1){
                                        cout << "Creating Normalization" << endl;
                                        break;
                                    }else if(YN9 == 2){
                                        break;
                                    }
                            }
                        }
                }

                cout << "Processing Files..." << endl;
                break;
            case 3:
                //exportFiles function
                cout << "Exporting Files..." << endl;
                break;
            case 0:
                break;
            default:
                cout << "Not a valid option, please select another option!" << endl;
                break;
            }
        }while(userChoice != 0);
    }
        }
    }
}
