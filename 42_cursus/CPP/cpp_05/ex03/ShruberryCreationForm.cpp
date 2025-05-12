#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(std::string target) :
		AForm("Shruberry_Creation_form", 145, 137)
{
	std::cout << "sf creqted" << std::endl;
	this->_target = target;
	return;
}

ShruberryCreationForm::ShruberryCreationForm(ShruberryCreationForm const & copy) :
		AForm(copy)
{
	this->_target = copy.getTarget();
	return;
}

ShruberryCreationForm::~ShruberryCreationForm(void)
{
	return;
}

ShruberryCreationForm	&ShruberryCreationForm::operator=(ShruberryCreationForm const & assign)
{
	AForm::operator=(assign);
	if (this != &assign)
		this->_target = assign.getTarget();
	return *this;
}

void		ShruberryCreationForm::executed(void)const
{
	std::ofstream	output;

	output.open((this->_target + "_shruberry").c_str(), std::fstream::app);
	if (!output)
	{
		std::cout << "Could not create ASCII tree in : " << this->_target;
		std::cout << "_shruberry" << std::endl;
		return;
	}
	else
	{
		if (std::time(NULL) % 2 == 0)
		{
			output << "               ,@@@@@@@," << std::endl;
			output << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			output << "    ,&&%&%&&%,@@@@@/@@@@@@,8888/88/8o" << std::endl;
			output << "   ,%&/%&&%&&%,@@@/@@@/@@@88/88888/88'" << std::endl;
			output << "   %&&%&%&/%&&%@@/@@/ /@@@88888/88888'" << std::endl;
			output << "   %&&%/ %&%%&&@@/ V /@@' `88/8 `/88'" << std::endl;
			output << "   `&%/ ` /%&'    |.|        / '|8'" << std::endl;
			output << "       |o|        | |         | |" << std::endl;
			output << "       |.|        | |         | |" << std::endl;
			output << "jgs \\/ ._///_/__/  ,/_//__\\/.  /_//__/_" << std::endl;
		}
		else
		{
			output << "###########################'`################################" << std::endl;
			output << "###########################  V##'############################" << std::endl;
			output << "#########################V'  `V  ############################" << std::endl;
			output << "########################V'      ,############################" << std::endl;
			output << "#########`#############V      ,A###########################V" << std::endl;
			output << "########' `###########V      ,###########################V',#" << std::endl;
			output << "######V'   ###########l      ,####################V~~~~'',###" << std::endl;
			output << "#####V'    ###########l      ##P' ###########V~~'   ,A#######" << std::endl;
			output << "#####l      d#########l      V'  ,#######V~'       A#########" << std::endl;
			output << "#####l      ##########l         ,####V''         ,###########" << std::endl;
			output << "#####l        `V######l        ,###V'   .....;A##############" << std::endl;
			output << "#####A,         `######A,     ,##V' ,A#######################" << std::endl;
			output << "#######A,        `######A,    #V'  A########'''''##########''" << std::endl;
			output << "##########,,,       `####A,           `#''           '''  ,,," << std::endl;
			output << "#############A,                               ,,,     ,######" << std::endl;
			output << "######################oooo,                 ;####, ,#########" << std::endl;
			output << "##################P'                   A,   ;#####V##########" << std::endl;
			output << "#####P'    ''''       ,###             `#,     `V############" << std::endl;
			output << "##P'                ,d###;              ##,       `V#########" << std::endl;
			output << "##########A,,   #########A              )##,    ##A,..,ooA###" << std::endl;
			output << "#############A, Y#########A,            )####, ,#############" << std::endl;
			output << "###############A ############A,        ,###### ##############" << std::endl;
			output << "###############################       ,#######V##############" << std::endl;
			output << "###############################      ,#######################" << std::endl;
			output << "##############################P    ,d########################" << std::endl;
			output << "##############################'    d#########################" << std::endl;
			output << "##############################     ##########################" << std::endl;
			output << "##############################     ##########################" << std::endl;
			output << "#############################P     ##########################" << std::endl;
			output << "#############################'     ##########################" << std::endl;
			output << "############################P      ##########################" << std::endl;
			output << "###########################P'     ;##########################" << std::endl;
			output << "###########################'     ,###########################" << std::endl;
			output << "##########################       ############################" << std::endl;
			output << "#########################       ,############################" << std::endl;
			output << "########################        d###########P'    `Y#########" << std::endl;
			output << "#######################        ,############        #########" << std::endl;
			output << "######################        ,#############        #########" << std::endl;
			output << "#####################        ,##############b.    ,d#########" << std::endl;
			output << "####################        ,################################" << std::endl;
			output << "###################         #################################" << std::endl;
			output << "##################          #######################P'  `V##P'" << std::endl;
			output << "#######P'     `V#           ###################P'" << std::endl;
			output << "#####P'                    ,#################P'" << std::endl;
			output << "###P'                      d##############P''" << std::endl;
			output << "##P'                       V##############'" << std::endl;
			output << "#P'                         `V###########'" << std::endl;
			output << "#'                             `V##P'" << std::endl;
			output << "" << std::endl;
			output << "                                                        GNN94" << std::endl;
		}
	}
	output.close();
	return;
}

std::string	ShruberryCreationForm::getTarget(void)const
{
	return this->_target;
}
