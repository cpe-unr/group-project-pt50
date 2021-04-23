/** @file */
#include <iostream>

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

int main() {

do{
	int menuPick = getMenuChoice();
	string = fileName, userFile;

	swtich(menuPick){
	case 1:
	break;
	case 2:
		//cout << "Please choose a file:\n";
		
	break;
	case 3:
		//cout << "Please choose a file:\n";

		//cout << "Enter a new name for the edited file: "
		//cin >> userFile;
	break;
	case 4:
	break;
	case 0;
	break;
	default:
		cout << "Please input a valid option.\n";
	break;
	}



}

	while(menuPick != 0);
	return 0;
}


int getMenuChoice(){

	int userChoice;

	cout << "PT50's AUDIO PROCESSOR\n1. Read Files\n2. Modify Metadata\n3. Process File\n4. Create CSV Display of All Files\n0. Exit Program\n";
	
	cin >> userChoice;

return userChoice;
}
