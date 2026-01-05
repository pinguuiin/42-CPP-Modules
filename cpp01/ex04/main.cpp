#include <iostream>
#include <fstream>

static int	read_input_file(char *infileName, std::string &buffer)
{
	std::ifstream infile(infileName);
	if (!infile) {
		std::cerr << "Unable to open input file" << std::endl;
		return 1;
	}
	std::getline(infile, buffer, (char)EOF);
	infile.close();
	return 0;
}

static void	replace_string(const std::string &s1, const std::string &s2, std::string &buffer)
{
	std::size_t lenS1 = s1.length();
	std::size_t lenS2 = s2.length();
	std::size_t pos = 0;

	while (1) {
		pos = buffer.find(s1, pos);
		if (pos != std::string::npos) {
			buffer.erase(pos, lenS1);
			buffer.insert(pos, s2);
			pos += lenS2;
			continue ;
		}
		break ;
	}
}

int	main(int argc, char **argv)
{
	std::string buffer = "";
	if (argc != 4) {
		std::cerr << "Please input 3 arguments in the order: input_file old_string new_string" << std::endl;
		return 1;
	}
	if (read_input_file(argv[1], buffer))
		return 1;

	std::string outfileName = std::string(argv[1]) + ".replace";
	std::ofstream outfile(outfileName);
	if (!outfile) {
		std::cerr << "Unable to open output file" << std::endl;
		return 1;
	}
	replace_string(std::string(argv[2]), std::string(argv[3]), buffer);
	outfile << buffer;
	outfile.close();
	return 0;
}
