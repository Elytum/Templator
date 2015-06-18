#include <templator.hpp>

#define HEADER "\
     _____                        _         _ \n\
    |_   _|   Made by Achazal    | |       | |\n\
      | |  ___  _ __ ___   _ __  | |  __ _ | |_  ___   _ __ \n\
      | | / _ \\| '_ ` _ \\ | '_ \\ | | / _` || __|/ _ \\ | '__|\n\
      | ||  __/| | | | | || |_) || || (_| || |_| (_) || |\n\
      \\_/ \\___||_| |_| |_|| .__/ |_| \\__,_| \\__|\\___/ |_|\n\
                          | |\n\
   to generate c++ files  |_|   in canonical form.\n\
"
#define CLASS_NAME_REQUEST "What's the name of the class ?"

#define CLASS_SUFFIX_REQUEST "Do you want class files terminated by \".class\" ? (y/n)"

int		main(void)
{
  std::string   class_name;
  std::string   suffix;

  std::cout << HEADER << std::endl;
  std::cout << CLASS_NAME_REQUEST << std::endl;
  std::getline (std::cin, class_name);
  std::cout << CLASS_SUFFIX_REQUEST << std::endl;
  std::getline (std::cin, suffix);
  generator(class_name, class_name + ((suffix == "y" ? ".class" : "")));
	return (0);
}
