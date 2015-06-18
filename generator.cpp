#include <iostream>
#include <fstream>

#define TEMPLATE_CPP ".TEMPLATE.cpp"
#define TEMPLATE_HPP ".TEMPLATE.hpp"
#define TEMPLATE_CLASS_NAME "THIS_IS_A_CLASS"
#define TEMPLATE_CLASS_PATH "THIS_IS_A_PATH"
#define TEMPLATE_CLASS_PROTECTION "THIS_IS_A_PROTECTION"
#define PROGRAM_NAME "templator"

std::string		replace_in_string(std::string str, std::string before, std::string after)
{
	size_t			index = 0;

	while (true) {
		index = str.find(before, index);
		if (index == std::string::npos)
			break;
		str.replace(index, before.size(), after);
		index += after.size();
	}
	return (str);
}

std::string		file_to_string(std::string path)
{
	std::ifstream	ifs(path);
	std::string		content;

	content.assign( (std::istreambuf_iterator<char>(ifs) ),
					(std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return (content);
}

void			string_to_file(std::string string, std::string path) {
	std::ofstream	file;

	file.open(path);
	if (!file.good())
		std::cout << "Error: " << strerror(errno) << std::endl;
	else
		file << string;
	file.close();
}

std::string		str_to_upper(std::string str)
{
	size_t			i = 0;

	while (i < str.size()) {
		str[i] = toupper(str[i]);
		++i;
	}	
	return (str);
}

void			generate_cpp(std::string class_name, std::string destination)
{
	std::string		file;

	file = file_to_string(TEMPLATE_CPP);
	if (file.empty())
			std::cout << PROGRAM_NAME << ": " << strerror(errno) << std::endl;
	else {
		file = replace_in_string(file, TEMPLATE_CLASS_NAME, class_name);
		file = replace_in_string(file, TEMPLATE_CLASS_PATH, destination);
		string_to_file(file, destination + ".cpp");
	}
}

void			generate_hpp(std::string class_name, std::string destination)
{
	std::string		file;
	std::string		protection;

	file = file_to_string(TEMPLATE_HPP);
	if (file.empty())
			std::cout << PROGRAM_NAME << ": " << strerror(errno) << std::endl;
	else {
		protection = replace_in_string(destination + ".hpp", ".", "_");
		protection = str_to_upper(protection);
		file = replace_in_string(file, TEMPLATE_CLASS_NAME, class_name);
		file = replace_in_string(file, TEMPLATE_CLASS_PATH, destination);
		file = replace_in_string(file, TEMPLATE_CLASS_PROTECTION, protection);
		string_to_file(file, destination + ".hpp");
	}
}

int		generator(std::string class_name, std::string class_path)
{
	generate_cpp(class_name, class_path);
	generate_hpp(class_name, class_path);
	return (0);
}